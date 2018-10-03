#include "ros/ros.h"
#include "testhelper/simple_service_server.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "SimpleServiceServer");
  ros::NodeHandle nh;

  SimpleServiceServer server(nh);

  ROS_INFO("Server Startet");

  ros::spin();

  //ros::AsyncSpinner spinner(2); // Use 4 threads
  //spinner.start();
  //ros::waitForShutdown();

  return 0;
}