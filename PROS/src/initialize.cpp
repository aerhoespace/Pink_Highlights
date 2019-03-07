#define MOTOR_PORT 11 //left front
#define MOTOR_PORT 12 //left back
#define MOTOR_PORT 13 //right front
#define MOTOR_PORT 14 //right back
#define MOTOR_PORT 15 //puncher
#define MOTOR_PORT 16 //intake

void initialize() {
  //initialization function code
  pros::lcd::initialize();
  
    //setup controller
  pros::Controller master (E_CONTROLLER_MASTER);
  
  //setup motors
  pros::Motor leftFront  (11, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES); //for conditions check: https://pros.cs.purdue.edu/v5/tutorials/topical/motors.html
  pros::Motor leftBack   (12, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);  //E_MOTOR_GEARSET_36 = red(100RPM),	E_MOTOR_GEARSET_18 == green(200 RPM), E_MOTOR_GEARSET_06 = blue(600 RPM) for more see: https://pros.cs.purdue.edu/v5/api/c/motors.html#motor-gearset-e-t 	 
  pros::Motor rightFront (13, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
  pros::Motor rightBack  (14, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
  pros::Motor puncher    (15, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
  pros::Motor intake     (16, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
  
}
