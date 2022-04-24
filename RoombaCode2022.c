#include <kipr/wombat.h>
void turnRight(int degrees) {
    set_create_total_angle(0);
    while (get_create_total_angle() > (degrees * -1)) {
    	create_drive_direct(200, -200);    
    }
    create_stop();
}
void turnLeft(int degrees) {
	set_create_total_angle(0);
    while(get_create_total_angle() < degrees) {
    	create_drive_direct(-200, 200);    
    }
    create_stop();
}
int main()
{
    printf("Hello World\n");
    create_connect();
    create_drive_direct(100, 100);
    msleep(4000);  
    //drives forward some amount
    turnRight(90);
    //turns to get to middle
    create_drive_direct(100, 100);
    msleep(7700);
    create_stop();
    //drive up to botguy
    turnRight(90);
    //turn towards botguy
    enable_servo(0);
    //closes claw
    motor(0, -30);
    msleep(1220);  //1230 is max time
    ao();
    //raises claw up to botguy
    msleep(300);
    set_servo_position(0, 1024);
    //opens claw
    create_drive_direct(-100, -100); //move forward slightly more
    msleep(2000);
    //move towards botguy for claw to close on
    create_stop();
    set_servo_position(0, 230);
    msleep(100);
    //closes claw around botguy
    motor(0, -1);
    //counteracts gravity and keeps botguy up
    create_drive_direct(100,100);
    msleep(6700);
    //move towards airlock along middle line
    create_stop();
    turnRight(95);
    //turned to airlock
    create_drive_direct(-100, -100);
    msleep(7000);
    create_stop();
    //moved to airlock
    create_stop();
    //turn towards airlock
    turnRight(30);
    //moves to airlock
    create_drive_direct(-100, -100); 
    msleep(1000);
    //drops botguy on airlock
    motor(0, 20);
    msleep(750);
    //let go of claw
    set_servo_position(0, 700);
    disable_servo(1);
    create_disconnect();
    return 0;
}
