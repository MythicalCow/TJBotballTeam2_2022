#include <kipr/wombat.h>
void turnLeft(int degrees) {
    set_create_total_angle(0);
    while(get_create_total_angle() < degrees) {
        create_drive_direct(-200, 200);    
    }
    create_stop();
}
void turnRight(int degrees) {
    set_create_total_angle(0);
    while (get_create_total_angle() > (degrees * -1)) {
        create_drive_direct(200, -200);    
    }
    create_stop();
}
int main() //needs to be negative!
{
    create_connect();
    set_create_distance(0);
    //448 mm
    while (get_create_distance() < 448) {
        create_drive_direct(100, 100);
    }
    create_stop();
    set_create_distance(0);
    turnRight(90);
    while(get_create_distance() < 900) {
        create_drive_direct(100, 100);  //925
    }
    printf("Distance: %d", get_create_distance());
    set_create_distance(0);
    create_stop();
    turnRight(96);
    enable_servo(0);
    motor(0, -30);
    msleep(1240);  //1230 is max time
    ao();
    msleep(300);
    set_servo_position(0, 1024); 
    while (get_create_distance() > -220) {
        create_drive_direct(-100, -100); //move forward slightly more
    }
    create_stop();
    set_servo_position(0, 200);
    motor(0, -1);
    //drives down to end of platform
    set_create_distance(0);
    create_drive_direct(100, 100);
    msleep(5000);
    printf("Distance: %d", get_create_distance());
    create_stop();
    
    /*while (get_create_distance() < 600) {
        create_drive_direct(100, 100);
    }
    create_stop();
    //turn to airlock
    turnRight(90);
    //drive towards airlock
    set_create_distance(0);
    while(get_create_distance() > -1000) {
        create_drive_direct(-100, -100);
    }
    create_stop();
    //lower claw
    motor(0, -20);
    msleep(500);
    ao();
    //open claw
    set_servo_position(0, 800);
    //drive to right-edge of board
    set_create_distance(0);
    while(get_create_distance() < 2000) {
        create_drive_direct(100, 100);
    }
    create_stop();
    turnRight(90);
    set_create_distance(0);
    while(get_create_distance() < 1000) {
        create_drive_direct(100, 100);
    }
    create_stop();
    turnRight(90);
    set_create_distance(0);
    while(get_create_distance() < 1800) {
        create_drive_direct(100, 100);
    }
    create_stop();*/
    create_disconnect();
    return 0;
}
