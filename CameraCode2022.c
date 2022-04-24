#include <kipr/wombat.h>
int x;
int y;
int channel = 0; //pom pom located around 78, 39 or 82, 35 final: 69, 74
int inPosition = 0;
int claw = 0;
int height = 0;
int main()
{
    printf("Hello World\n");
    create_connect();
    //create_drive_direct(-100, -100);
    //create_drive_direct(100, 100);
   // msleep(10000);
    //motor(0, -50);
    //msleep(14000); //from claw touching end until box
    //create_drive_direct(-100,-100);
    //msleep(1500);
    //set_create_total_angle(0);
    //while(get_create_total_angle() < 180) {
    	//create_drive_direct(-200,200);
    //}
    //create_stop();
   	//int distance = get_create_distance();
    //printf("Distance Traveled: %d\n", distance);
    //printf("Should have printed by now");
    camera_open();
    while (inPosition == 0) {
        x = get_object_center(channel, 0).x;
        y = get_object_center(channel, 0).y;
        if (get_object_count(channel) > 0) {
            display_printf(channel, 1, "Center of largest blob: (%d, %d)  ", x,y);
            //printf("center of camera is: (%d, %d) ", get_camera_width()/2, get_camera_height()/2);
            if (x > 73) {  //turn right
                //create_drive_direct(75,-75);
                msleep(75);
                create_stop();
            } else if (x < 65) { //turn left
                //create_drive_direct(-100,100);
                msleep(75);
                create_stop();
            } else if (y > 78) {//move up 
                //create_drive_direct(100,100);
                msleep(75);
                create_stop();
            } else if (y < 70) { //back up
             	//create_drive_direct(-75,-75);
                msleep(75);
                create_stop();
            } else {
            	inPosition = 1;   
            }
        } else {
            display_printf(channel, 1,"No object in sight 			");
        }
        msleep(200);
        camera_update();
    }
    camera_close();
    /*enable_servo(claw);
    set_servo_position(claw, 1500);
    create_drive_direct(-100, -100);
    msleep(400);
    create_stop();
    set_servo_position(claw, 1024);
    disable_servo(claw);
    */create_disconnect();
    return 0;
    
}
