#include <ros/ros.h>
#include <std_srvs/Trigger.h>

class SimpleServiceServer
{
  public:
    SimpleServiceServer(ros::NodeHandle nh);

  private:
    bool serviceCallback(std_srvs::Trigger::Request&, std_srvs::TriggerResponse&);

    ros::NodeHandle nh_;
    ros::ServiceServer service_server_;
};