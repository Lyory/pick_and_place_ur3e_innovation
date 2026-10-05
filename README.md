# UR3e ROS 2 workspace

Project mô phỏng UR3e với gripper, camera trên cao, năm cube, ba zone và bàn thao tác. Lệnh ngôn ngữ tự nhiên được LLM đổi thành plan skill; validator kiểm tra plan; MoveIt 2 tính quỹ đạo. Robotiq 2F-85 gắn với UR3e bằng adapter cố định; các khớp ngón đóng/mở trong Gazebo và fixed joint giữ cube khi gắp.

Xem [hướng dẫn package](src/ur3_llm_control/README.md) để build, chạy bằng 9Router và chạy demo Zone B bị chiếm.

Yêu cầu: Ubuntu 22.04, ROS 2 Humble, Gazebo Classic, MoveIt 2, `python3-opencv`, `python3-numpy` và các dependency trong `package.xml`.
