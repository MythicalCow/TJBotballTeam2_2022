#include <kipr/wombat.h>

void reset(){
   	set_servo_position(1, 0);
    set_servo_position(0, 325);
    set_servo_position(2, 2047);
}

int main()
{
    printf("Hello World\n");
    
    
    //Servo 1 Open to Close 0 to 1023
    //Servo 0 Rotational 1293 Vertical 325 Horizontal
    //Servo 2 1317 Down 2047 Up
    
    enable_servo(0);
    enable_servo(1);
    enable_servo(2);
    
    //Reseting
    reset();
    msleep(100);
    
    set_servo_position(2, 1450);
    msleep(1000);
	set_servo_position(1, 1400);
    msleep(1000);
    set_servo_position(2, 2047);
    msleep(1000);
    set_servo_position(0, 1293);
    msleep(1000);
    set_servo_position(2, 1700);
    msleep(5000);
    set_servo_position(0, 325);
    msleep(1000);
    reset();
    msleep(500);
    
    
    //ao();
    return 0;
}

