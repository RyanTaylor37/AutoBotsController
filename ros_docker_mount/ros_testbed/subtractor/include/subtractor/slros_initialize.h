#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "subtractor_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block subtractor/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_subtractor_std_msgs_Float64> Sub_subtractor_1;

// For Block subtractor/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_subtractor_std_msgs_Float64> Sub_subtractor_15;

// For Block subtractor/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_subtractor_std_msgs_Float64> Pub_subtractor_4;

void slros_node_init(int argc, char** argv);

#endif
