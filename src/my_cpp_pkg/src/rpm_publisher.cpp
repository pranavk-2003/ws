#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/float32.hpp"
using namespace std;
class rpm : public rclcpp::Node{

    public:
         rpm(): Node("rpm_p"){
            publisher_=this->create_publisher<std_msgs::msg::Float32>("rpm_p",10);
            timer_=this->create_wall_timer(1s,bind(&rpm::publish_rpm,this));

         }

    
    private:
    void publish_rpm(){
        auto message =std_msgs::msg::Float32();
        message.data=30;
        publisher_->publish(message);

    }
        rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;


};



int main(int argc ,char *argv[]){
    rclcpp::init(argc ,argv);
    rclcpp::spin(make_shared<rpm>());
    rclcpp::shutdown();

    return 0;
}