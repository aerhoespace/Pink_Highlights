#define MOTOR_PORT 11 //left front
#define MOTOR_PORT 12 //left back
#define MOTOR_PORT 13 //right front
#define MOTOR_PORT 14 //right back
#define MOTOR_PORT 15 //puncher
#define MOTOR_PORT 16 //intake

void opcontrol() {
  //setup controller
  pros::Controller master (E_CONTROLLER_MASTER);
  
  //setup motors
  pros::Motor leftFront (11); //all of these take additional conditions check: https://pros.cs.purdue.edu/v5/tutorials/topical/motors.html
  pros::Motor leftBack (12);
  pros::Motor rightFront (13);
  pros::Motor rightBack (14);
  pros::Motor puncher (15);
  pros::Motor intake (16);
  
  
  while (true) {
    //calls opDrive void which controls the drive
    opDrive();
  
    pros::delay(2);
  }
}
