#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "autobotscontroller_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block autobotscontroller/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_autobotscontroller_std_msgs_Float64> Sub_autobotscontroller_36;

// For Block autobotscontroller/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_autobotscontroller_std_msgs_Float64> Sub_autobotscontroller_48;

// For Block autobotscontroller/Subscribe2
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_autobotscontroller_std_msgs_Float64> Sub_autobotscontroller_121;

// For Block autobotscontroller/Subscribe3
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_autobotscontroller_std_msgs_Float64> Sub_autobotscontroller_123;

// For Block autobotscontroller/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_autobotscontroller_std_msgs_Float64> Pub_autobotscontroller_37;

void slros_node_init(int argc, char** argv);

#endif
