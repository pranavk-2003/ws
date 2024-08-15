#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/float32.hpp"
using namespace std;
#include <iostream>
const double wheel_default_rpm=100;

class rpm : public rclcpp::Node{

    public:
         rpm(): Node("rpm_p"){
            this->declare_parameter<double>("rpm_val",wheel_default_rpm);
            publisher_=this->create_publisher<std_msgs::msg::Float32>("rpm_p",10);
            timer_=this->create_wall_timer(1s,bind(&rpm::publish_rpm,this));
            cout<<"RPM Publisher Node is Running";

         }

    
    private:
    void publish_rpm(){
        auto message =std_msgs::msg::Float32();
        this->get_parameter("rpm_val",rpm_val_param);
        message.data=rpm_val_param;
        publisher_->publish(message);

    }
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    double rpm_val_param=wheel_default_rpm;


};



int main(int argc ,char *argv[]){
    rclcpp::init(argc ,argv);
    rclcpp::spin(make_shared<rpm>());
    rclcpp::shutdown();

    return 0;
}