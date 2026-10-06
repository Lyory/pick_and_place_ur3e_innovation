update
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

Trong file `.env` mẫu đã có ở **gốc workspace** (cùng cấp với `src`) sau khi clone hãy: 

```bash
cd ~/pick_and_place_ur3e_innovation
chmod 600 .env
nano .env
```

Thay `NINEROUTER_API_KEY=abcxyz` bằng key từ dashboard 9Router và `ROBOT_LLM_MODEL` bằng đúng ID model đã bật trong 9Router. `ROBOT_LLM_BASE_URL` mặc định là `http://127.0.0.1:20128/v1`. 


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
