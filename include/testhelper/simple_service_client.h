#include <ros/ros.h>

class SimpleServiceClient
{
  public:
    SimpleServiceClient(ros::NodeHandle& nh);

    void callService();

  private:
    ros::NodeHandle nh_;
    ros::ServiceClient service_client_;
};