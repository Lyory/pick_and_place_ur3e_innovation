#include <algorithm>
#include <array>
#include <chrono>
#include <future>
#include <memory>
#include <mutex>
#include <string>
#include <utility>
#include <gazebo/common/Events.hh>
#include <gazebo/common/Plugin.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/physics/ContactManager.hh>
#include <gazebo/physics/Contact.hh>
#include <gazebo_ros/node.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include "ur3_llm_control/srv/set_attachment.hpp"

namespace gazebo {
// Drives the six joints of the Robotiq 2F-85 macro in Gazebo Classic. The
// included xacro's gz_ros2_control backend targets modern Gazebo, so the
// existing ROS skill service drives synchronized gripper joint positions here.
class PhysicalGripper : public WorldPlugin {
public:
  void Load(physics::WorldPtr world, sdf::ElementPtr sdf) override {
    world_ = world;
    contact_manager_ = world_->Physics()->GetContactManager();
    contact_manager_->SetNeverDropContacts(true);
    node_ = gazebo_ros::Node::Get(sdf);
    joint_pub_ = node_->create_publisher<sensor_msgs::msg::JointState>("/joint_states", 10);
    service_ = node_->create_service<ur3_llm_control::srv::SetAttachment>(
      "/set_gripper",
      [this](const std::shared_ptr<ur3_llm_control::srv::SetAttachment::Request> req,
             std::shared_ptr<ur3_llm_control::srv::SetAttachment::Response> resp) {
        auto job = std::make_shared<Job>();
        job->action = req->action;
        job->object = req->object;
        auto future = job->done.get_future();
        {
          std::lock_guard<std::mutex> lock(mutex_);
          if (busy_) { resp->message = "Gripper busy"; return; }
          busy_ = true;
          pending_ = job;
        }
        if (future.wait_for(std::chrono::seconds(8)) != std::future_status::ready) {
          resp->message = "Robotiq action timed out";
          return;
        }
        const auto result = future.get();
        resp->success = result.first;
        resp->message = result.second;
      });
    update_ = event::Events::ConnectWorldUpdateBegin(
      [this](const common::UpdateInfo &) { OnUpdate(); });
  }
private:
  struct Job {
    std::string action, object;
    std::promise<std::pair<bool, std::string>> done;
  };
  struct JointSpec {
    const char *name;
    double direction;
    physics::JointPtr joint;
  };
  void Finish(bool success, const std::string &message) {
    active_->done.set_value({success, message});
    active_.reset();
    std::lock_guard<std::mutex> lock(mutex_);
    busy_ = false;
  }
  bool LoadJoints(const physics::ModelPtr &robot) {
    if (!wrist_) wrist_ = robot->GetLink("wrist_3_link");
    if (!wrist_) return false;
    for (auto &spec : joints_) {
      if (!spec.joint) spec.joint = robot->GetJoint(spec.name);
      if (!spec.joint) return false;
    }
    return true;
  }
  std::pair<bool, bool> FingerContacts() {
    bool left = false, right = false;
    if (!cube_) return {left, right};
    for (const auto *contact : contact_manager_->GetContacts()) {
      if (!contact || !contact->collision1 || !contact->collision2) continue;
      const auto first = contact->collision1->GetLink();
      const auto second = contact->collision2->GetLink();
      if (!first || !second) continue;
      const std::string a = first->GetName();
      const std::string b = second->GetName();
      if (first->GetModel() == cube_ || second->GetModel() == cube_) {
        const auto other = first->GetModel() == cube_ ? b : a;
        left |= other == "robotiq_85_left_finger_tip_link";
        right |= other == "robotiq_85_right_finger_tip_link";
      }
    }
    return {left, right};
  }
  void OnUpdate() {
    auto robot = world_->ModelByName("ur");
    if (!robot || !LoadJoints(robot)) return;
    std::shared_ptr<Job> incoming;
    {
      std::lock_guard<std::mutex> lock(mutex_);
      incoming.swap(pending_);
    }
    if (incoming) {
      active_ = incoming;
      started_ = world_->SimTime();
      if (active_->action == "close") {
        if (grasp_) { Finish(false, "Already holding " + held_); return; }
        cube_ = world_->ModelByName(active_->object);
        block_ = cube_ ? cube_->GetLink("link") : nullptr;
        if (!block_) { Finish(false, "Cube unavailable"); return; }
        const auto target = wrist_->WorldPose().Pos() +
          wrist_->WorldPose().Rot().RotateVector(ignition::math::Vector3d(0, 0, 0.17));
        if ((target - block_->WorldPose().Pos()).Length() > 0.06) {
          Finish(false, "Cube is outside open Robotiq fingers"); return;
        }
        desired_ = 0.75;
        last_left_contact_ = common::Time();
        last_right_contact_ = common::Time();
      } else if (active_->action == "open") {
        if (grasp_ && !active_->object.empty() && held_ != active_->object) {
          Finish(false, "Gripper holds a different cube"); return;
        }
        // Keep the cube fixed until both jaws have cleared it.
        desired_ = 0.0;
      } else {
        Finish(false, "Unknown gripper action"); return;
      }
    }
    // One actuator command drives the paired fingers and their mimic joints.
    // Move no faster than the joint's rated speed so the pads close together.
    const double dt = std::clamp((world_->SimTime() - last_update_).Double(), 0.0, 0.02);
    last_update_ = world_->SimTime();
    const double step = 0.5 * dt;
    commanded_ += std::clamp(desired_ - commanded_, -step, step);
    for (auto &spec : joints_) {
      spec.joint->SetPosition(0, spec.direction * commanded_, true);
      spec.joint->SetVelocity(0, 0.0);
      spec.joint->SetForce(0, 0.0);
    }
    if (world_->SimTime() - last_publish_ >= common::Time(0.033)) {
      sensor_msgs::msg::JointState state;
      state.header.stamp = node_->now();
      for (const auto &spec : joints_) {
        state.name.emplace_back(spec.name);
        state.position.push_back(spec.joint->Position(0));
      }
      joint_pub_->publish(state);
      last_publish_ = world_->SimTime();
    }
    if (!active_) return;
    const double elapsed = (world_->SimTime() - started_).Double();
    const double left = joints_[0].joint->Position(0);
    const double right = joints_[1].joint->Position(0);
    if (active_->action == "open") {
      if (commanded_ < 0.01 && std::abs(left) < 0.05 && std::abs(right) < 0.05) {
        if (grasp_) {
          grasp_->Detach();
          grasp_.reset();
          for (const auto &collision : block_->GetCollisions()) collision->SetCollideBits(0xffff);
          block_.reset();
          cube_.reset();
          held_.clear();
        }
        Finish(true, "Robotiq fingers opened and cube released"); return;
      }
    } else if (elapsed > 0.35 && left > 0.25 && right < -0.25) {
      const auto [touch_left, touch_right] = FingerContacts();
      if (touch_left) last_left_contact_ = world_->SimTime();
      if (touch_right) last_right_contact_ = world_->SimTime();
      const bool both_touching = last_left_contact_.Double() && last_right_contact_.Double() &&
        (world_->SimTime() - last_left_contact_).Double() <= 0.10 &&
        (world_->SimTime() - last_right_contact_).Double() <= 0.10;
      if (both_touching) {
        // Lock the block only after both physical fingertip contacts occur.
        for (const auto &collision : block_->GetCollisions()) collision->SetCollideBits(0);
        grasp_ = world_->Physics()->CreateJoint("fixed", robot);
        grasp_->Load(wrist_, block_, ignition::math::Pose3d());
        grasp_->Init();
        held_ = active_->object;
        desired_ = commanded_;
        RCLCPP_INFO(node_->get_logger(), "Bilateral fingertip contact confirmed for %s at %.3f rad",
                    held_.c_str(), commanded_);
        Finish(true, "Both Robotiq fingertips contacted " + held_);
        return;
      }
    }
    if (elapsed > 5.0) {
      desired_ = 0.0;
      block_.reset();
      cube_.reset();
      Finish(false, "Both Robotiq fingertips did not contact the cube");
    }
  }
  physics::WorldPtr world_;
  physics::ContactManager *contact_manager_{nullptr};
  physics::LinkPtr wrist_, block_;
  physics::ModelPtr cube_;
  physics::JointPtr grasp_;
  std::array<JointSpec, 6> joints_{{
    {"robotiq_85_left_knuckle_joint", 1.0, {}},
    {"robotiq_85_right_knuckle_joint", -1.0, {}},
    {"robotiq_85_left_inner_knuckle_joint", 1.0, {}},
    {"robotiq_85_right_inner_knuckle_joint", -1.0, {}},
    {"robotiq_85_left_finger_tip_joint", -1.0, {}},
    {"robotiq_85_right_finger_tip_joint", 1.0, {}},
  }};
  std::string held_;
  double desired_{0.0}, commanded_{0.0};
  common::Time started_, last_publish_, last_update_, last_left_contact_, last_right_contact_;
  gazebo_ros::Node::SharedPtr node_;
  rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_pub_;
  rclcpp::Service<ur3_llm_control::srv::SetAttachment>::SharedPtr service_;
  event::ConnectionPtr update_;
  std::mutex mutex_;
  bool busy_{false};
  std::shared_ptr<Job> pending_, active_;
};
GZ_REGISTER_WORLD_PLUGIN(PhysicalGripper)
}  // namespace gazebo
