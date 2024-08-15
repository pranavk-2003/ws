#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <iostream>
using namespace std;
class mysubnode : public rclcpp::Node
{
    public:
        mysubnode() : Node("hello_world_sub_node"){
            subscription_=this->create_subscription<std_msgs::msg::String>(
                "Hello_World",10,std::bind(&mysubnode::sub_callback,this,std::placeholders::_1)
            );
        }
        
    private:
        void sub_callback(const std_msgs::msg::String & msg){
            // std::cout<<msg.data<<std::endl;
            RCLCPP_INFO(this->get_logger(),msg.data.c_str());
        }
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc,char *argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(make_shared<mysubnode>());
    rclcpp::shutdown();
    return 0;
}