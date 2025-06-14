# ROS2 Workspace 

This is a personal ROS2 (Robotic Operating System 2) workspace containing learning experiments, sample packages, and nodes developed for practice, study, and testing. it includes publisher-subscriber exmaples, service-client architecture, and parameter uages. 

# Workspace Structure 

``` bash 
ros2_ws/
    src/ # code
        action_interface/ # cutom message/interface definition
        parameter/ # parameter handling examples
        test1/ # first node written
        test2/ # second node written with turtlse_sim publisher
        test_custom_msg_srv/ # custom message and service definition
        test_pub_sub/ # basic pub-sub
        test_srv_cli/ # basic service-client
    install/ # executable nodes
    build/ # build information
    log/ # informarion about workspace
    README.md
```

# Getting Started 
* Clone this repo
``` bash
git clone https://github.com/c-lydia/ros2_ws
cd ros2_ws
```
* Build the workspace
``` bash
source /opt/ros/<your_ros2_distro>/setup.bash
colcon build
```
* Source the setup file
``` bash
source install/setup.bash
```

# Run Examples 
* Node (Python)
``` bash
ros2 run <your_package_name> <your_executable>
```
* Parameters
``` bash
ros2 run <your_package_name> <your_executable_with_param>
```
* Custom Interface
``` bash
ros2 interface show <interface_name>
```

# Learning Goals 
This workspace is part of learning journey on ROS2 and Robotic systems. It includes: 
* Custom service definitions and interfaces
* Python nodes practice
* Parameters configuration
* Package organization in a multi-package workspace

# Tools and Tech
* ROS2 Humble
* Python 3
* Colcon build system
* Ubuntu 22.04

# Author
Chheng Lydiya 

Student at Institute of Technology Cambodia
* GitHub: https://github.com/c-lydia

# Contributing
This is a learning repository, but if you have suggestions or ideas, feel free to open an issue or PR.  
