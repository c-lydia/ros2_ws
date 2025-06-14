# ROS2 Workspace 

## Overview 
This project is a ROS2 (Robotic Operating System 2) multi-package workspace intended for learning, experimentation, and development fo robotic software. It includes publisher-subscriber examples, servicve-client architecture, parameterized nodes, and custom message/service definitions. The workspace is built with Python using ROS2 Humble and developed under Ubuntu 22.04. 

## Table of Contents
* Introduction to ROS2
* ROS2 Node Communication Models
* Workspace Structure
* System Requirements
* Package Overview
* Custom Interfaces
* Parameterized Nodes
* How to Build and Run
* Output Behavior
* Future Improvements

## Intorduction to ROS2 
ROS2 is an open-source middleware that provides tools and libraries for building robot applications. Unlike ROS1, ROS2 is built with DDS (Data Distribution Service), offering real-time capability, better security, and support for microcontrollers and distributed systems. It supports multiple communication models such as: 
* Publisher-Subscriber for asynchronous message passing
* Client-Service for synchronous tasks
* Action Server-Client for long-running processes

## ROS2 Node Communication Models
* **Publisher-Subscriber:** This model nodes to broadcast and listen to data via topics. A publisher node published messages to a topic, and a subscriber node listens to that topic to receive messages.
* **Service-Client:** This model is request-response based. A client sends a request to a service node, which processes and sends a response back.
* **Parameters:** Nodes in ROS2 can declare and use para meters, which act like configuration values that incluence the behavior of a node at runtime.
* **Custom Messages and Services:** Developers can create .msg and .srv files for custom communication needs between nodes. 

## Workspace Structure 

``` bash 
ros2_ws/
    src/ # code
        action_interface/ # cutom message/interface definition
        parameter/ # parameter handling examples
        test1/ # first node written
        test2/ # turtlse_sim publisher
        test_custom_msg_srv/ # custom message and service definition
        test_pub_sub/ # basic pub-sub
        test_srv_cli/ # basic service-client
    install/ # executable nodes
    build/ # build artifacts 
    log/ # informarion about workspace
    README.md
```

## System Requirements
* **Operating System:** Ubuntu 22.04
* **ROS2 Distribution:** Humble
* **Language:** Python 3
* **Build Tool:** Colcon

Before building, make sure to source ROS2: 
``` bash
source /opt/ros/humble/setup.bash
```

## Package Overview 
* **test_pub_sub:** This package demonstrates a basic publisher-subscriber pair usinf ROS2 topics. One node publishes a string message while another subscribes to that topic and prints the received message.
* **test_srv_cli:** This package implements a client and service. The service takes input from the client, processes it, and sends back a response. Useful for understanding synchronous communication.
* **parameter:** This package contains a node that demonstrates how to declare, retrieve, and use runtime parameters passed via command-line or launch files.
* **test_custom_msg_srv:** This pacakge introduces custom .msg and .srv files. Nodes use these definitions for communication, showcasing how to build and use custom data types in ROS2.
* **action_interface:** Defines a .action interface. Though no action node is implemented yet, this prepares the workspace for integrating long-running task systems such as robot motion control.

## Cusstom interfaces
Custom interfaces are stored in .img, .srv, and .action files and defined like this: 

* **Num.msg:**
``` text
int64 num
``` 
* **Sphere.msg:**
``` text
geometry_msgs/Point center
float64 radius
```
* **AddThreeInts.srv:**
``` text 
int64 a
int64 b
int64 c
---
int64 sum
```
* **Fibonacci.action:**
``` text
int32 order
---
int32[] sequence 
---
int32[] partial_sequence
```

To use: 
``` bash
ros2 interface show <interface_name>
```

## Parameterized Nodes 
To run a parameter node with arguments: 
``` bash
ros2 run parameter <your_executable> --ros-args -p <your_parameter>:=<value>
```

Inside the node: 
``` python
param = self.get_parameter('p1').get_parameter_value().string_value
```

This is helpful for tuning values without rewriting the code. 

## How to Build and Run
* **Build the workspace:**
``` bash
cd ros2_ws
source /opt/ros/humble/setup.bash
colcon build
source install/setup.bash
```
* **Run a node:**
``` bash
ros2 run <package_name> <executable>
```
* **Show custom interface:**
``` bash
ros2 uinterface <interface>
```

## Output Behavior
* Nodes print messages to terminal indicating communication status
* Parameters can be passed at runtime and dynamically change node behavior
* Custom services and messages behave like built-in ones once compiles
* If connected with turtlesim, the turtla responds to the published commands. 

## Future Improvements
* Add Action Server and Client implementation using action_interface
* Create a lauch files for all nodes
* Add TurtleSim simulation-based motion control
* Add logging via rclpy's get_logger()
* Integrate sensor and actuator simultaion for testing 

## Author
Chheng Lydiya 

Student at Institute of Technology Cambodia

GitHub: https://github.com/c-lydia

## Contributing
This is a learning repository, but if you have suggestions or ideas, feel free to open an issue or PR. 
