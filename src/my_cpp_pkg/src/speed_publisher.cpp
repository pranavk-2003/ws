#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/float32.hpp"
using namespace std;

class rpm_sub : public rclcpp::Node
{
    public:
        rpm_sub() : Node("rpm_subscriber"){
            subscription_=this->create_subscription<std_msgs::msg::Float32>(
                "rpm_p",10,bind(&rpm_sub::sub_callback,this,std::placeholders::_1)
            );
        }
        
    private:
        void sub_callback(const std_msgs::msg::Float32 & msg){
            // std::cout<<msg.data<<std::endl;
            RCLCPP_INFO(this->get_logger(),"%f",msg.data/60);
        }
        
        rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscription_;
};

// class speed_p : public rclcpp::Node{
//     public:
//          speed_p(): Node("/speed"){
//             publisher_=this->create_publisher<std_msgs::msg::Int32>("/speed",10);
//             timer_=this->create_wall_timer(1s,bind(&speed_p::publish_speed,this));

//          }

    
//     private:
//     void publish_speed(){
//         auto message =std_msgs::msg::Int32();
//         message.data=rpm/60;
//         publisher_->publish(message);



        

//     }
//         rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
//         rclcpp::TimerBase::SharedPtr timer_;


// };

int main(int argc,char *argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(make_shared<rpm_sub>());
    rclcpp::shutdown();
    return 0;
}