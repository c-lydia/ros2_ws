# ros2_ws
ROS2 (Robotic Operating System 2) is a set of software development tools and libraries for building robot applications.  

## Prerequisite 
Before you go on to installing ROS2, you should be operating on linux; windows is fine, but there are a lot of issues, so my suggestion is operating it on linux like Ubuntu. For this, I will be using ROS2 humble and Ubuntu Linux - Jammy (22.04) dual boot on my laptop.

## System requirements
* Internet access 
* Operating System: Ubuntu Linux - Jammy (22.04) 64-bit

## How to dual boot 

### Prerequisite 
* A USB at least 25GB

### What is Ubuntu? 
Ubuntu is an open source Linux distribution based on Debain Linux. Linux is an operating system that consists of: 
* Bootloader: manages the boot process of the computer.
* Kernel: the core of the system that manages CPU, memory, and peripheral devices.
* Init system: a subsystem that bootstraps the user space and is charged with controlling daemons.
* Daemons: background services that startup during boot or after you logged into desktop.
* Graphical server: displays the graphics on your monitor.
* Desktop environment: the piece that the user interact with; it includes built-in applications.
* Applications

A distribution is  version of the operating system. Ubuntu is one of the linux distribution. 

### Dual booting guide 

#### Change BIOS setting

* First, restart your computer, while it’s restarting click the key F2 or F10 or F12 (based on computer model, for my laptop, I used F2).
* Find “Boot Mode”, “Boot Options”, or “Boot configuration”.
* Set the “Boot Mode” to “UEFI”
* Save the setting and exit.

#### Disk partitioning 

* Open Disk Management, then select the partition that you wanna shrink to boot Ubuntu
* Right click on that partition, then select “Shrink Volume”
* Follow the instruction on your screen, once, it’s done, the partition should be labeled “Unallocated”

#### Boot Ubuntu into USB 

* Insert USB into your laptop.
* Go to Ubuntu website (https://releases.ubuntu.com/jammy/), then install the iso file (“ubuntu-22.04.5-desktop-amd64.iso”)
* Go to Rufus website (https://rufus.ie/en/), then download and install the software.
* Once the installation is done, open it.
* Under the label “Device” click on the drop down menu, select your USB device.
* Under the label “Boot selection” select the ubuntu iso file you just downloaded.
* Under the label “Partition scheme” select “GPT”, then click “START”, you will be asked to select the mode you wanna use, select “Write in ISO image mode”, then click “OK”
* Once it’s done close the software.

#### Installing Ubuntu 

* First, hold the shift key, then restart your computer.
* Select “Use a device”, then select your USB drive, and then click Enter key to boot into Ubuntu.
* Select “Install Ubuntu”, then follow the instruction on the screen. Choose “something else” when you got asked about the partition.
* Select the partition you made for booting Ubuntu, then click “Change .>.”, next ti the label “Use as:” select “Ext4”, then click “OK”
* Click “Install now”, then follow the instruction on the screen. Once the installation is done, click “Restart Now”, then you can remove your USB, then click Enter.

## ROS2 Installation guide

### System requirements 

* Operating system: Ubuntu 22.04 (since we will be installing ROS2 humble)
* CPU: 64-bit, multi-core processor
* RAM: 4GB RAM or higher, 8GB RAM recommended
* Disk space: 20 GB or more
* Dependencies: Python 3.10 and C++ 14 or later

### Set locales 
Your locales must support UTF-8 
    
``` bash
    locale  # check for UTF-8
    sudo apt update && sudo apt install locales
    sudo locale-gen en_US en_US.UTF-8
    sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
    export LANG=en_US.UTF-8

    locale  # verify settings
```

### Setup source 
* Ensure that Ubuntu universe repository is enabled

``` bash
    sudo apt install software-properties-common
    sudo add-apt-repository universe
```

* Add ROS2 GPG key

``` bash
    sudo apt update && sudo apt install curl -y
    sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
```

* Add the repository to your sources list. 

``` bash
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
```
### Install ROS2 packages 
* Update your apt caches after setup the repository

``` bash
    sudo apt update 
```

* Ensure that ur system is up to date

``` bash 
    sudo apt upgrade 
```

* Install ROS2

``` bash
    sudo apt install ros-humble-desktop
    sudo apt install ros-humble-ros-base
    sudo apt install ros-dev-tools
```

### Environment setup 
Source the setup script 

``` bash
    source /opt/ros/humble/setup.bash
```
## VS Code Installation Guide 

Ubuntu isn't an IDE (Integrated Development Environment). We need VS Code to write, compile, and run code, so for now, after installing Ubuntu and ROS2 successfully, I will cover VS Code Installation for Ubuntu (deb package). 

* Installing VS Code

``` bash
    sudo snap install code --classic
```

To open the VS Code, run this command:

``` bash
    code
```

## SSH (optional)

When it comes to coding and controlling robots, we may need remote development extensions, so I will be shwoing how to use SSH.
* Open VS Code
* Install the extension "Remote SSH" in VS Code
* Open your terminal, search for the ip address of the port you need to connect to
Run this command:

``` bash
    ip a
```

The IP address will be shown next to "inet" in the terminal. Another way to do it, if you know the number, for exmple 192.xxx.xx.xx, then you can use this command:

``` bash
    nmap -sn 192.xxx.xx.0/24

    #before you can use nmap, you need to install it
    #to install it, run these command
    sudo apt install nmap 
```
* Now, open the command pallete on VS Code, then type "Remote-SSH: connect to host"
* Type in the IP address and hostname, "username(host)@192.xxx.xx.xx". If this is the first time, you will be asked to open config file, so accept the prompt. You will be asked to input password, type in the password, then click Enter.
* Once, connected, you can open the folder and run the code in the folder.

## Configuring Environment
When developing ROS2, you will be using combination of workspaces. The term workspace refers to the location in your system that you use top develop ROS2. But with before you develop or runnign any code, you need to configure the environement first, otherwise, you won't be able to use ROS2. Now, we will learn to setup the environment. 

#### Source the setup files 
Note that each time you open new terminal, you need to source the setup files with this command: 

``` bash
    source /opt/ros/humble/setup.bash
```

#### Add sourcing to your startup shell 

```  bash
    echo "source /opt/ros/humble/seyup.bash" >> ~/.bashrc
```

#### Check environment variables 

``` bash
    printenv | grep -i ROS
```
This command will return your ROS distro (distribution) and version; it should be something like this: 

``` bash
    ROS_VERSION=2
    ROS_PYTHON_VERSION=3
    ROS_DISTRO=humble
```

If it is not set correctly, you need to the installarion again. 

* ROS_DOMAIN_ID: when you have determined a unique integer of your group of ROS2 nodes, you can set the environment varible.

``` bash
    export ROS_DOMAIN_ID=<your domain id>
    echo "export ROS_DOMAIN_ID=<your domain id>" >> ~/.bashrc #add it to your startup script
```

* ROS_LOCALHOST_ONLY: since ROS2 communication is not limited to local host, it may disrupt your communicaation in your robots, to ensure efficient communication, you can setup the "ROS_LOCALHOST_ONLY" environment with this command:

``` bash
    export ROS_LOCALHOST_ONLY=1
    echo "export ROS_LOCALHOST_ONLY=1" >> ~/.bashrc
```

## CLI tools 

### Using turtlesim, ros2, and rqt

#### What is turtlesim? 
Turtlesim is a simulator in ROS2 which illustrate how you will use ROS2 to operate the real robots. 

#### What is ros2? 
ros2 is a tool that the user use to interact, manage, and introspect with ROS system. We can use ros2 to start nodes, set parameters, listen to topic, etc. 

#### What is rqt? 
rqt is a GUI tool in ROS2. 

#### How to use turtlesim, ros2, and rqt

* Installing turtlesim: first, source your environment, then go onto installing turtlesim
``` bash 
    sudo apt update
    sudo apt install ros-humble-turtlesim
```

Now, you can check if the package is installed
``` bash
    ros2 pkg executables turtlesim
```

* Start turtlesim: to start turtlesim, run the turtlesim node
``` bash
    ros2 run turtlesim turtlesim_node
```

There should be a windows with a turtle in the middle. 

* Use turtlesim: while the command on the terminal is running, you need to open another terminal and source your environment again as we need to keep the node open since the next command we will run required the node to be running. The command will al,low you to control the turtle you see on the window.
``` bash 
    ros2 run turtlesim turtle_teleop_key
```

This command allows you to control the turtle via keyboard. 

You can check the nodes and their associates topics, services, actions via these command
``` bash
    ros2 node list
    ros2 topic list
    ros2 service list
    ros2 action list
```
 
* Install rqt
``` bash
    sudo apt update
    sudo apt install '~nros-humble-rqt*'
```

To run rqt
``` bash
    rqt
```

* Use rqt
When running rqt, select Plugins > Services > Service Caller from the menu bar at the top. There should be a dropdown near the lebal "Service". Go to that dropdown, then select the "/spawn" service.

** Try spawn service 
The spawn service creates new turtle in the opened window with turtle on it. Now, after selecting the /spawn service in the dropdown list, you need to give each parameter a value. So click on the value of each parameter, then enter your value. After that, you can click on the "Call" button to spawn new turtle. You should see a new turtle pop up on the window. 

** Try set_pen service 
The set_pen controls the pen that draws the line when the turtle moves. To use this service, go to the dropdown list, then select /turtle1/set_pen, then you can change the color or the width of the pen. After calling the service, go back to the terminal with the teleop_key still running, and use the keyboard to control the turtle, you will see the line where the turtle moves change style to what you just set. 

* Remapping: is used to remap the ecommand to run another turtle. For example, you have two turtle named "turtle 1" and "turtle 2". So you need a new teleop_key node on another terminal to run turtle 2, but when you run the command, the turtle 1 responds. You need to remap the command to run turtle 2. Run this comman on a new terminal: 
``` bash
    ros2 run turtlesim turtle_teleop_key --ros-args --remap turtle1/cmd_vel:=turtle2/cmd_vel
```

* Close turtlesim: to close the teleop_key node, click the key "q", and for the turtlesim_node click "ctrl + c".

### Nodes

#### ROS2 graph 
The ROS2 graph is a network of ROS2 elements that processes data at the same time. 

#### What is node? 
Each node in ROS2 responsibles for a single operation. It can send and receive data from topics, services, and actions. 

#### Using nodes
* Running node: The command "ros2 run" runs executables in a node.
``` bash
    ros2 run <package name> <node name>
```
For example, to run a turtlesim node: 
``` bash
    ros2 run turtlesim turtlesim_node
```

* node list: lists all the running node:
``` bash
    ros2 node list
```

The terminal should return:
``` bash
    /turtlesim
```

Now, run the teleop_key node
``` bash
    ros2 run turtlesim turtle_teleop_key
```

If you run the command node list again, it shoukd return: 
``` bash
    /turtlesim
    /teleop_turtle
```

** Remapping: allows you to reassign the node properties. This command reassign the turtlesim node. 
``` bash
    ros2 run turtlesim turtlesim_node --ros-args --remap __node:=my_turtle
```

If you run the node list command, the terminal will return: 
``` bash
    /my_turtle
    /turtlesim
    /teleop_turtle
```

* ros2 node info
You can access more information about the node with ros2 node info:
``` bash
    ros2 node info <node name>
```

For example, if you check the information about the node /turtlesim: 
``` bash
    ros2 node info /turtlesim
```

It will return a list of publishers, subscribers, services, actions that interacts with the node. 

### Topics

#### What is a topic? 
In ROS2, a node may publish data to a topic, and in a topic, there are nodes that also act as subscription which receive the data from the nodes that publish them. The nodes that publish data are called publisher, and the node that subscribe to a topic are called subscriptions. So topics act as a medium for the publisher and subscription nodes to communicate with each other. 

#### Using topics 

* Setup
Open a new terminal, then source your environment
``` bash
    source /opt/ros/humble/setup.bash
    # or you can use this instead
    source ~/.bashrc
```

Now, run turtlesim and teleop key 
``` bash
    ros2 run turtlesim turtlesim_node
    ros2 run turtlesim turtle_teleop_key
```

* rqt graph
We will use rqt graph to see the topics, so open rqt graph
``` bash
    rqt_graph
```

There should be a graph window pops up on your screen which illustrate the topics and its peripherals. The graph shows that the node /turtlesim and /turtle_teleop are communicating through the topic /turtle1/cmd_vel where the node /turtlesim is the subscription and the node /teleop_turtle is the publisher. 

* ros2 topic list
Open a new terminal, run topic list command
``` bash
    ros2 topic list
```

It will return a list of topic that's running on your computer. 
``` bash
    /parameter_events
    /rosout
    /turtle1/cmd_vel
    /turtle1/color_sensor
    /turtle1/pose
```

The command ros2 topic list -t will give you the same list of topics but with its types
``` bash
    ros2 topic list -t
```

This is the return list
``` bash
    /parameter_events [rcl_interfaces/msg/ParameterEvent]
    /rosout [rcl_interfaces/msg/Log]
    /turtle1/cmd_vel [geometry_msgs/msg/Twist]
    /turtle1/color_sensor [turtlesim/msg/Color]
    /turtle1/pose [turtlesim/msg/Pose]
```

* ros2 topic echo
This command will return the data that's being publish ina topic, run this command
``` bash
    ros2 topic echo <topic name>
```

For example, this command will return the data that's being published in the topid /teleop_turtle
``` bash
    ros2 topic eco /teleop_turtle 
```

And this is what it returns
``` bash
    linear:
      x: 2.0
      y: 0.0
      z: 0.0
    angular:
      x: 0.0
      y: 0.0
      z: 0.0
      ---
```

* ros2 topic info
To see the communication information in a topic, run
``` bash
    ros2 topic info <topic name>
```

For example, we want to see the information about /turtle1/cmd_vel, so we run this command
``` bash
    ros2 topic info /turtle1/cmd_vel
```

Now, the terminal returns
``` bash
    Type: geometry_msgs/msg/Twist
    Publisher count: 1
    Subscription count: 2
```

* ros2 interface show 
This command show the variables that are used in a interface of a topic
``` bash
    ros2 interface show <interface name>
```

For example, this command, shows the messages of the interface geometry_msgs/msg/Twist
``` bash
    ros2 interface show geometry_msgs/msg/Twist
```

The terminal returns
``` bash
    Vector3 linear
            float64 x
            float64 y
            float64 z
    vector3 angular
            float64 x
            float64 y
            float64 z
```

* ros2 topic pub
This command publish data to a topic
``` bash
    ros2 topic pub <topic name> <interface name> <args>
```

The args here refers to the actual data that you're sending. For example, this publishes data to the topic /turtle1/cmd_vel 
``` bash
    ros2 topic pub /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

The data must be in the yaml format. 

### Services 
#### What is service?
Service is another communication method in ROS2. In topic, there are publisher and subscription nodes, in which publisher publishes the message to the subscription. Service is built on publisher-subscriber model, however, it differs from topic as service can only provide data when they are called by client while topics allow nodes to sunscribe to data streams and get continuous update. 

#### Using service 
* Setup
Open a terminal, then source your environment.
``` bash
    source ~/.bashrc
```

Now, run turtlesim
``` bash
    ros2 run turtlesim turtlesim_node
```

On another terminal, run teleop_turtle 
``` bash
    ros2 run turtlesim turtle_teleop_key
```

* ros2 service list
This command shows the active services list
``` bash
    ros2 service list
```

The terminal returns 
``` bash
    /clear
    /kill
    /teleop_turtle/describe_parameters
    /teleop_turtle/get_parameter_types
    /teleop_turtle/get_parameters
    /teleop_turtle/list_parameters
    /teleop_turtle/set_parameters
    /teleop_turtle/set_parameters_atomatically
    /turtle1/set_pen
    /turtle1/teleport_absolute
    /turtle1/teleport_relative
    /turtlesim/describe_parameters
    /turtlesim/get_parameter_types
    /turtlesim/get_parameters
    /turtlesim/list_parameters
    /turtlesim/set_parameters
    /turtlesim/set_parameters_atomically
```

* ros2 service type
Service has types that define how the request and response data is structured. It has two parts: message fro request and message fro response. To find out the service, run this command
``` bash
    ros2 service type <service name>
```

For example, we want to find out the service type of the /clear service
``` bash
    ros2 service type /clear
```

The terminal will return 
``` bash
     std_srvs/srv/Empty
```

* ros2 service list -t
This command shows the list of all service types of the active services
``` bash
    ros2 service list -t
```

* ros2 service find
This command shows the services of a specific service type
``` bash
    ros2 service find <type name>
```

For example, we want to fine all the Empty typed service 
``` bash
    ros2 service find std_srvs/srv/Empty
```

The terminal will then return 
``` bash
    /clear
    /reset
```

* ros2 interface show
This command shows the input arguments of the service type
``` bash
    ros2 interface show <type name>
```

Now, we try this on the /clear service type
``` bash
    ros2 interface show std_srvs/srv/Empty
```

The terminal will return 
``` bash
    ---
```

* ros2 service call
This commans call the service
``` bash
    ros2 service call <service name> <service type> <arguments>
```

We try this on the /spawn service 
``` bash
    ros2 service call /spawn turtlesim/srv/Spawn "{x: 2, y: 2, theta: 0.2, name: ''}"
```

### Actions 
#### What is action?

#### Using action
* Set up

* Use action

* ros2 node info

* ros2 action list

* ros2 action list -t

* ros2 action info

* ros2 interface show

* ros2 send_goal



### Parameters 

### Launch 

## Creating ROS2 workspace

### What is a workspace? 
In ROS2, workspace is where your store your packages to development robotic applications and organize them. To build a workspace, follow this instruction:

### Source ROS2 environment 
``` bash
    source /opt/ros/humble/setup.bash
```

### Create a new directory
you have to create a directory to store everything for workspace. 
``` bash
    mkdir -p ~/ros2_ws/src #ros2_ws is the dorectory name
    cd ~/ros2_ws 
```

### build the workspace 
use "colcon build" to build your workspace 
``` bash
    colcon build
```

### Source the workspace 
``` bash
    source install/setup.bash
```

To make it is sourced automatically for every terminal: 
``` bash
    echo "source install/setuo.bash" >> ~/.bashrc
    source ~/.bashrc
```

### Verify your workspace 
Now, cehck if the workspace is built correctly
``` bash
    ls
```

## Creating ROS2 package 

### What is ROS2 package? 
Package is where you store and organize your code, log, build files to develop the software. You can release the package nad allow people to use and build upon it. 

### Structure of ROS2 package
ROS2 package can be built using python or C++. For this, I will focus on building python package. 

Each package in ROS2 consist of: 
* package.xml: containing meta information of the package
* resource/<package name>: marker file for the package
* setup.cfg: when you have install, it is required for ROS2 to be able to run it
* setup.py: containing instructions how to install the package 
* <package name>: used by ROS2 to find your package; it contains "__init__.py"

When you build package, you store it in the "src" directory in your workspace, so that your workspace looks clean.

### How to build ROS2 package 
#### Create a package 
* Open your workspace
``` bash
    cd ~/ros2_ws/src
```

Note that you also need to source your workspace before doing this. If you have run this command before, it's alright as it is automatically sourced alredy. 
``` bash
    echo "source install/setuo.bash" >> ~/.bashrc
    source ~/.bashrc
``` 
* Create a package
``` bash
    ros2 pkg create <package name> --build-type ament_python --license Apache-2.0 --dependencies rclpy
    #if C++ package use "ament_cmake
    #dependencies and license can be added manually (later), but if you add it here, it's easier
```

#### Build the package 
After you writing code and make necessary changes in the package, you can build the packge using "colcon build". To correctly building the package: 

#### Return to root of the workspace 
``` bash
    cd ~/ros2_ws
```

#### Building the package 
``` bash
    colcon build
```

### Using the package 

#### Source the package 
``` bash
    source install/setup.bash
```

#### Run the package 
``` bash
    ros2 run <pacakge name> <executable name>
    #usually, <executable name> is the name the code file
```

## Writing publisher and subscriber node 

### Basic concepts 

#### What is node? 
Node is a process that performs a unique task. Each node is responsible for different tasks like sending data from sensors, controlling the wheel of the robots, etc. 

#### What is topic? 
The purpose of nodes is to exchange communication. But when we have a lot of nodes, it can be hard to keep track of everything. Topic is the datastream for exchanging communication between nodes. It acts as bus for nodes to be connected together. Topics consist of publisher, the node that send the message, and the subscription, the node that receives the message from the publisher. 

### How to write publisher and subscriber node 
We will write two nodes, one is the publisher, and another one is the subscriber. 

#### Create a package 
* Source the environment: Open a new terminal, and source your ROS2 environment
``` bash
    source /opt/ros/humble/setup.bash
```

* Creating the package: 
Navigate to your "src" directory in your workspace
``` bash
    cd ~/ros2_ws/src
```

Create a package 
``` bash
    ros2 pkg create pub_sub --build-type ament_python ---dependencies rclpy ---license Apache-2.0
```

#### Write the publisher node (code)
* Navigate into "ros2_ws/src/pub_sub/pub_sub", this is where you will store your source code 
``` bash
    cd ~/ros2_ws/src/pub_sub/pub_sub
```

* Create a python file to code the node
``` bash
    touch publisher.py
```

* Code the node: now open it on vs code, then add the code. 
``` bash
    ./code
```

This is the source code: 
``` python
    import rclpy
    from rclpy import Node
    from std_msgs.msg import String

    class Publisher(Node):
        def __init__(self):
            super().__init__('Publisher')
            self.Publisher = self.create_publisher(String, 'Publisher', 10)
            self.timer = self.create_timer(1, self.timer_callback)

        def timer_callback(self):
            msg = String()
            msg.data = "Hello, world from Publisher"
            self.Publisher.publish(msg)
            self.get_logger().info('Publishing: "%s"', %msg.data)

    def main(args = None):
        rclpy.init(args = args)
        publisher = Publisher()
        rclpy.spin(publisher)
        publisher.destroy_node()
        rclpy.shutdown()

    if __name__ = '__main__':
        main()
```

* Code explanation: 

``` python
    import rclpy
    from rclpy import Node
```
This code import the "rclpy" library and "Node" from the library, so ROS2 can access and use it

``` python
    from std_msgs.msg import String
```
This import "String" from "std_msgs.msg", allowing node to use string-message to structure the data 

``` python
    class Publisher(Node):
```
We create a class name "Publisher" which inherits from "Node"

``` python
    def __init__(self):
        super().__init__('Publisher')
        self.Publisher = self.create_publisher(String, 'Publisher', 10)
        self.timer = self.create_timer(1, self.timer_callback)
```
This function initializes and declares the publisher node and a timer. 

``` python
    super().__init__('Publisher')
```
This line in=s the constructor which calls the Node class's constructor and gives your node the name "Publisher.

``` python
    self.Publisher = self.create_publisher(String, 'Publisher', 10)
```
Next, we create the variable "Publisher" which declares that the node publishes the message and sets its data type to string. The 'Publisher' is the topic name, and the number "10" is the queue size which we need to set the limit of the amount of the queued message in case the subscriber is not receiving them fast enough. 

``` python
    self.timer = self.create_timer(1, self.timer_callback)
```
A timer is created to make the publisher execute every 1 second. 

``` python
    def timer_callback(self):
        msg = String()
        msg.data = "Hello, world from Publisher"
        self.Publisher_publish(msg)
        self.get_logger().info('Publishing: "%s"', %msg.data)
```

## Writing Service and Client package 

## Creating custom message 

## Using parameters 

## Creating action interface 

## Writing action server and client
    
## Learning resources
* Ubuntu Information: https://help.ubuntu.com/community/Installation/SystemRequirements
* Basic Ubuntu commands: https://github.com/rashakil-ds/Shell-Programming-in-Linux/blob/main/Linux%20Ubuntu%20Commands.pdf
* how to dual boot: https://gcore.com/learning/dual-boot-ubuntu-windows-setup/
* how to dual boot: https://www.linuxtechi.com/dual-boot-ubuntu-22-04-and-windows-11/
* how to dual boot: https://www.onlogic.com/blog/how-to-dual-boot-windows-11-and-linux/
* Linux basic: https://www.linux.com/what-is-linux/
* ROS2 humble documentation: https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debs.html
* ROS2 cheat sheet (basic commands): https://www.theconstruct.ai/wp-content/uploads/2021/10/ROS2-Command-Cheat-Sheets-updated.pdf
* VS Code installation: https://code.visualstudio.com/docs/setup/linux
* Building ROS2 workspace: https://automaticaddison.com/how-to-create-a-ros-2-workspace-iron/
* rclpy library (pyhton): https://docs.ros.org/en/iron/p/rclpy/
