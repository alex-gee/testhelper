#include "testhelper/simple_service_server.h"
#include <thread>

SimpleServiceServer::SimpleServiceServer(ros::NodeHandle nh):
  nh_(nh)
{
  ROS_INFO("Advertising service!");

  service_server_ = nh_.advertiseService("simple_service", &SimpleServiceServer::serviceCallback, this);
}

bool SimpleServiceServer::serviceCallback(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response& resp)
{
  ROS_INFO_STREAM("Service Called! Thread id: " << std::this_thread::get_id());
  return true;
}