
# UR3e ROS 2 workspace

Workspace ROS 2 cho mô phỏng Universal Robots trong Gazebo Classic và package `ur3_llm_control`.

## Yêu cầu

- Ubuntu 22.04 và ROS 2 Humble
- `colcon`, `rosdep`, Gazebo Classic và MoveIt 2
- Các phụ thuộc ROS được khai báo trong các file `package.xml`

## Clone và build

```bash
git clone https://github.com/Lyory/pick_and_place_ur3e_innovation.git

cd pick_and_place_ur3e_innovation/

source /opt/ros/humble/setup.bash
rosdep update
rosdep install --from-paths src --ignore-src -r -y
python3 -m pip install --user openai
colcon build --symlink-install
source install/setup.bash
```

## Cấu hình API key

File `.env` mẫu đã có ở **gốc workspace** (cùng cấp với `src`) sau khi clone. Nếu có `.env.local` trong cùng thư mục, chương trình ưu tiên đọc file đó để giữ key thật ngoài Git:

```bash
cd ~/pick_and_place_ur3e_innovation
chmod 600 .env
nano .env
```

Thay `NINEROUTER_API_KEY=abcxyz` bằng key từ dashboard 9Router và `ROBOT_LLM_MODEL` bằng đúng ID model đã bật trong 9Router. `ROBOT_LLM_BASE_URL` mặc định là `http://127.0.0.1:20128/v1`. Task manager tự đọc `.env`; không cần `export` hay `source .env`. File `.env` được đưa lên Git với key mẫu `abcxyz` và comment hướng dẫn. Không commit key thật. Nếu muốn giữ key riêng, copy `.env` sang `.env.local` (được Git bỏ qua), sửa key trong đó rồi chạy `ROBOT_LLM_ENV_FILE="$PWD/.env.local" ros2 run ur3_llm_control task_manager.py`. Có thể chọn file khác bằng biến `ROBOT_LLM_ENV_FILE`.

## Robotiq trên ROS Humble

Project dùng package `robotiq_description` của ROS Humble, được cài qua `rosdep` từ khai báo trong `package.xml`. Không cần clone `ros2_robotiq_gripper`. Nếu package chưa có, cài `sudo apt install ros-humble-robotiq-description`. Xacro dùng tham số `connected_to` của adapter và link `gripper_mount_link`; plugin `ur3_physical_gripper` của project điều khiển ngón trong Gazebo Classic.

## Cài đặt 9router

```bash
npm install -g 9router

9router
```

## Chạy

Sử dụng đồng thời 3 terminal:
Terminal 1: (9router)
```bash
9router --host 127.0.0.1 --port 20128 --no-browser
```
Terminal 2: robot và gazebo

```bash
cd ~/pick_and_place_ur3e_innovation
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 launch ur3_llm_control llm_robot.launch.py
```

Terminal 3: Nhập lệnh cho robot
```bash
cd ~/pick_and_place_ur3e_innovation
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 run ur3_llm_control task_manager.py
```
