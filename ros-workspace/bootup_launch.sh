#!/bin/sh
# This is a comment!
 
sudo chmod 666 /dev/ttyTHS1
sudo chmod 666 /dev/ttyUSB0
catkin_make
source devel/setup.bash
roscd
cd ..
roslaunch fake_intelligence_bringup slam_fpv_teleop.launch
echo Live-stream video: http://192.168.99.120:8080/stream_viewer?topic=/usb_cam_node/image_raw
