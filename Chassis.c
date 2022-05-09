#include <kipr/botball.h>

int main()
{
    enable_servos();
    set_servo_position(1, 0); //1024 closed, 0 open
    set_servo_position(1, 1024); 
    
    //set_servo_position(1, 1024); //299 flat, 1500 vertical
    
    printf("Hello World\n");
    return 0;
}
