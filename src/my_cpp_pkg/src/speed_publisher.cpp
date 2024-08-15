#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/float32.hpp"
#include <cmath>
using namespace std;
const double default_wheel_radius =12.5/100;

class rpm_sub : public rclcpp::Node
{
    public:
        rpm_sub() : Node("rpm_subscriber"){
            this->declare_parameter<double>("wheel_radius",default_wheel_radius);
            subscription_=this->create_subscription<std_msgs::msg::Float32>(
                "rpm_p",10,bind(&rpm_sub::sub_callback,this,std::placeholders::_1)
            );
            publisher_=this->create_publisher<std_msgs::msg::Float32>("speed_p",10);

        }
        
    private:
        void sub_callback(const std_msgs::msg::Float32 & msg){
            // std::cout<<msg.data<<std::endl;
            auto speed_=std_msgs::msg::Float32();
            double wheel_radius_param=default_wheel_radius;
            this->get_parameter("wheel_raduis",wheel_radius_param);
            speed_.data=msg.data*(2*M_PI*wheel_radius_param)/60;
            publisher_->publish(speed_);
        }
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscription_;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc,char *argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(make_shared<rpm_sub>());
    rclcpp::shutdown();
    return 0;
}