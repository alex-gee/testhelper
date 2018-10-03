#include "ros/ros.h"
#include "std_srvs/Trigger.h"
#include "testhelper/simple_service_client.h"

#include <thread>

SimpleServiceClient::SimpleServiceClient(ros::NodeHandle &nh):
  nh_(nh)
{
  service_client_ = nh.serviceClient<std_srvs::Trigger>("/simple_service");
}

void SimpleServiceClient::callService()
{
  std_srvs::Trigger trigger;
  service_client_.call(trigger);

  ROS_INFO_STREAM("Calling service! Thread: " << std::this_thread::get_id());
}