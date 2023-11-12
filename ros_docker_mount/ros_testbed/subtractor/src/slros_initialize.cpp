#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "subtractor";

// For Block subtractor/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_subtractor_std_msgs_Float64> Sub_subtractor_1;

// For Block subtractor/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_subtractor_std_msgs_Float64> Sub_subtractor_15;

// For Block subtractor/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_subtractor_std_msgs_Float64> Pub_subtractor_4;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

