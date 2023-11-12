#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "carsimplesimulink_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block carsimplesimulink/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_carsimplesimulink_std_msgs_Float64> Sub_carsimplesimulink_20;

// For Block carsimplesimulink/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_carsimplesimulink_std_msgs_Float64> Pub_carsimplesimulink_17;

// For Block carsimplesimulink/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_carsimplesimulink_std_msgs_Float64> Pub_carsimplesimulink_35;

// For Block carsimplesimulink/Get Parameter
extern SimulinkParameterGetter<real64_T, double> ParamGet_carsimplesimulink_31;

// For Block carsimplesimulink/Get Parameter1
extern SimulinkParameterGetter<real64_T, double> ParamGet_carsimplesimulink_37;

void slros_node_init(int argc, char** argv);

#endif
