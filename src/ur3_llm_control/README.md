# UR3e: lệnh tự nhiên, camera và Robotiq 2F-85

Luồng chính: **lệnh người dùng → LLM planner → JSON plan → validator → robot skills → MoveIt 2 → UR3e + gripper**. LLM chỉ chọn skill và tham số; MoveIt tính quỹ đạo.

## Mô phỏng

Gazebo Classic có UR3e, camera gắn ở cổ tay, bàn, ba zone và năm cube. Khi khởi động, **cả năm cube đều nằm ngoài zone trên bàn**. Model Robotiq 2F-85 lấy từ package `robotiq_description` của ROS Humble. Adapter của repo gắn cố định vào `tool0`; đế gripper gắn vào adapter, nên tay và gripper là một chuỗi khớp liên tục, không có khe hở. `pick()` mở sáu khớp ngón, di chuyển đến cube, đóng các khớp theo cùng một mức và chỉ tạo fixed joint khi Gazebo ghi nhận cả hai đầu ngón chạm cube. Sau khi gắp, tay nâng thẳng lên cao độ an toàn rồi đi tới chỗ đặt; sau khi đặt, tay về tư thế quan sát để cập nhật toàn bàn. `place()` mở ngón trước, rồi tháo fixed joint khi cube đã được đưa tới vị trí đích. Không có lệnh đổi trực tiếp pose cube. `buffer` không có thành khay. Blue cube khởi tạo ở `(0.35, -0.13)` trên bàn, cách xa buffer `(0.48, 0.025)`. Purple cube ở `(0.40, 0.12)`, gần tâm vùng làm việc hơn vị trí cũ `(0.48, 0.30)`.

Camera `/task_camera/image_raw` nhận dạng màu và cung cấp vị trí qua `/camera_world_state`; `/get_world_state` kết hợp dữ liệu ảnh với trạng thái đang cầm. Skill đọc lại ảnh trước khi gắp/đặt. Validator chặn kế hoạch đặt vào vị trí có vật. Lưới va chạm của đầu ngón Robotiq kéo dài khoảng 0,16 m từ `tool0`; điểm gắp giữ cổ tay cao hơn tâm cube 0,17 m. Kiểm tra quỹ đạo chặn thao tác đưa đầu ngón xuyên qua mặt bàn. SRDF cho phép các khớp nội bộ của gripper và adapter tiếp xúc như thiết kế; các vật khác vẫn được kiểm tra va chạm. Camera nằm trên giá gắn cố định với `tool0`, có frame `wrist_camera_optical_frame`. Perception dùng `/task_camera/camera_info` và TF tại thời điểm chụp để chiếu pixel xuống mặt trên của cube; không dùng pose camera cố định hay tọa độ khởi tạo cube. Task manager gọi `detect_objects()` để đi từ Home đến pose quan sát, chụp trạng thái và ở lại đó trong lúc lập kế hoạch. Không tự quay về Home sau khi chụp. Nếu chưa có bản đồ camera, `/get_world_state` cũng khởi tạo quan sát này. Các thao tác quan sát và gắp/đặt được khóa để tránh điều khiển đồng thời.

Plan hiển thị và thực thi đủ các bước `detect_objects`, `check_zone`, `find_object`, `find_free_position`, `pick`, `place`, `home`. `detect_objects` đưa camera về tư thế nhìn bàn `(tool0: x=0.25, y=0, z_world=0.99, hướng xuống)`, chờ ảnh mới và nhận dạng các cube. `check_zone(zone)` trả về danh sách vật chắn hoặc trạng thái trống. `find_object(object)` trả tọa độ đo từ ảnh. `find_free_position(zone)` xác minh slot tạm do LLM chọn bằng ảnh hiện tại, dừng nếu slot bị chiếm. Các slot được định nghĩa theo hình học bàn, nhưng độ trống được tính từ vị trí cube đo bằng camera. Validator yêu cầu quan sát trước gắp/đặt; mọi `place` làm mất hiệu lực các kiểm tra trước đó. Robot đọc lại camera lúc chạy. Các cube bị che khuất trong ảnh cận cảnh giữ vị trí từ lần quan sát toàn bàn gần nhất; không thay bằng tọa độ khởi tạo. Sau mỗi `place`, robot nâng thẳng lên cao độ di chuyển 0,99 m rồi về pose quan sát để xác nhận vật đã đặt và cập nhật toàn bàn. `pick` chỉ nâng thẳng một lần, không quay về staging/pose quan sát; `check_zone`, `find_object`, `find_free_position` sau đó đọc ảnh và bản đồ camera mà không tự chuyển pose. Task manager xác nhận trạng thái cuối trước khi gọi `home()`, để Home là chuyển động cuối.

## Build và chạy

```bash
cd ~/pick_and_place_ur3e_innovation
source /opt/ros/humble/setup.bash
rosdep install --from-paths src --ignore-src -r -y
python3 -m pip install --user openai
colcon build --packages-up-to ur3_llm_control --symlink-install
source install/setup.bash
ros2 launch ur3_llm_control llm_robot.launch.py
```

Launch tự thêm thư mục mesh của `robotiq_description` vào `GAZEBO_MODEL_PATH` để Gazebo Classic vẽ được gripper. Góc nhìn ban đầu của Gazebo bao gồm cả UR3e và bàn. Chỉ chạy một phiên launch của workspace này; các phiên chạy đồng thời dùng chung tên controller sẽ gửi lệnh chồng lên nhau. Khi thay đổi URDF hoặc launch, dừng phiên cũ bằng `Ctrl+C` rồi chạy lại.

File `.env` ở gốc workspace được đưa lên Git với key mẫu `abcxyz` và comment hướng dẫn. Thay `abcxyz` bằng key 9Router, giữ hoặc sửa ID model theo dashboard. Chương trình tự đọc, không cần `source .env`, và ưu tiên `.env.local` nếu có. Không commit key thật; có thể dùng `.env.local` hoặc chọn file khác bằng `ROBOT_LLM_ENV_FILE` để giữ key riêng.

Ở terminal khác, cấu hình `NINEROUTER_API_KEY`, `ROBOT_LLM_MODEL` và `ROBOT_LLM_BASE_URL` trong `.env` ở gốc workspace, rồi chạy:

```bash
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 run ur3_llm_control task_manager.py
```

Nhập lệnh như `Put the red cube in Zone B.` hoặc `Đưa khối màu tím vào zone A`. Planner hiểu tên màu tiếng Việt và yêu cầu sinh lại tối đa hai lần nếu JSON hoặc plan bị validator từ chối. Nếu Zone B đang có vật, LLM phải chọn vị trí tạm trống và dời vật chắn trước. Task manager kiểm tra trạng thái camera cuối trước khi báo thành công.

## Demo zone bị chiếm

Sau khi khởi động Gazebo từ trạng thái ban đầu, chạy:

```bash
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 run ur3_llm_control demo_occupied_zone.py
```

Script kiểm tra cả 5 cube ở trên bàn và trạng thái khớp ngón Robotiq, dùng robot đưa blue cube vào Zone B để tạo tình huống bị chiếm, sau đó thực hiện `pick(blue) → place(blue, buffer) → pick(red) → place(red, zone_b) → home`. Camera được kiểm tra sau mỗi skill. Script là bài kiểm tra vật lý không cần API key; luồng lệnh người dùng vẫn đi qua LLM planner.

## Kiểm tra camera cổ tay và khối tím

Sau khi mở mô phỏng mới, có thể chạy kiểm tra vật lý cục bộ (không gọi LLM):

```bash
ros2 run ur3_llm_control demo_purple_zone.py
```

Plan tương ứng:

```text
detect_objects()
check_zone(zone_a)
find_object(purple_cube)
pick(purple_cube)
place(purple_cube, zone_a)
home()
```

`find_free_position` chỉ cần khi phải chọn chỗ tạm để dời vật chắn. Demo zone bị chiếm dùng `ros2 run ur3_llm_control demo_occupied_zone.py` trên một mô phỏng mới.

## Vị trí tạm và chuyển động

`temp_1=(0.26,-0.13)` và `temp_2=(0.26,0.13)` nằm gần tâm vùng với của robot. Perception, validator và robot skills cùng đọc tọa độ từ `config/scene.yaml`; prompt mô tả các tọa độ tương ứng. Camera vẫn xác nhận slot trống trước khi dùng. Vị trí tạm không có thành khay.

Lệnh đi thẳng đứng không bị đổi thành một lượt nâng lên rồi hạ xuống. Cao độ quan sát và di chuyển ngang thống nhất ở 0,99 m. Khi tay đã ở pose đích, hàm di chuyển trả về ngay.

## Gắp lại cube từ zone

Camera xác định tâm cube từ hai cạnh mặt trên hướng xa camera, với kích thước cube trong `scene.yaml`. Nếu gripper che một cạnh, hệ thống dùng cạnh mặt trên còn đầy đủ, đồng thời yêu cầu có cạnh song song đối diện để loại bỏ đường biên do che khuất. Không dùng tâm toàn bộ mask màu (gồm mặt bên, gây lệch vị trí gắp) và không ép vị trí về tâm zone. TF và intrinsics vẫn lấy tại thời điểm chụp; ảnh được chờ TF tương ứng trước khi xử lý.

Gripper chỉ duyệt `GetContactCount()` contact hợp lệ của Gazebo. Hai đầu ngón phải cùng tiếp xúc cube trong từng bước vật lý liên tục ít nhất 10 ms. Actuator dừng đóng trong lúc xác nhận; nếu một contact mất thì quá trình xác nhận bị hủy và ngón tiếp tục đóng. Không cộng contact của hai thời điểm khác nhau. Cube chỉ được giữ sau bước xác nhận này, không thay đổi trực tiếp pose cube.

Kiểm tra vật lý trên một mô phỏng mới:

```bash
ros2 run ur3_llm_control demo_zone_regrasp.py --zone zone_a
```

Có thể chọn `zone_b` hoặc `zone_c`. Demo gắp Green, đặt vào zone, gắp lại khỏi zone và đặt vào `temp_1`. Log Gazebo phải ghi `Simultaneous fingertip contacts stable for 10 ms` trước mỗi lần gắp thành công.
