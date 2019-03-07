#define MOTOR_PORT 11 //left front
#define MOTOR_PORT 12 //left back
#define MOTOR_PORT 13 //right front
#define MOTOR_PORT 14 //right back
#define MOTOR_PORT 15 //puncher
#define MOTOR_PORT 16 //intake

void opcontrol() {

  
  
  while (true) {
    //calls opDrive void which controls the drive
    opDrive();
  
    pros::delay(2);
  }
}
