#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "autobotscontroller";

// For Block autobotscontroller/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_autobotscontroller_std_msgs_Float64> Sub_autobotscontroller_36;

// For Block autobotscontroller/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_autobotscontroller_std_msgs_Float64> Sub_autobotscontroller_48;

// For Block autobotscontroller/Subscribe2
SimulinkSubscriber<std_msgs::Float64, SL_Bus_autobotscontroller_std_msgs_Float64> Sub_autobotscontroller_121;

// For Block autobotscontroller/Subscribe3
SimulinkSubscriber<std_msgs::Float64, SL_Bus_autobotscontroller_std_msgs_Float64> Sub_autobotscontroller_123;

// For Block autobotscontroller/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_autobotscontroller_std_msgs_Float64> Pub_autobotscontroller_37;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

