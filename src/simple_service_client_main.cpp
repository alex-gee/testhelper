#include "ros/ros.h"
#include "testhelper/simple_service_client.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "SimpleServiceClient");
  ros::NodeHandle nh;

  SimpleServiceClient client(nh);

  ROS_INFO("Client Startet");

  while(ros::ok())
  {
    client.callService();
    ros::spinOnce();
  }

  return 0;
}