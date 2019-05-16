//copy and paste main.h file here
#define MOTOR_PORT 11 //left front
#define MOTOR_PORT 12 //left back
#define MOTOR_PORT 13 //right front
#define MOTOR_PORT 14 //right back
#define MOTOR_PORT 15 //puncher
#define MOTOR_PORT 16 //intake

// Motivational quote
void littleCeasars(){
  //will display text on controller converted from VCS folder
  pros::lcd::set_text(1, "lEtS gEt tHiS bReAd");  //for documentation check: https://pros.cs.purdue.edu/v5/api/cpp/llemu.html or https://pros.cs.purdue.edu/v5/api/cpp/misc.html#set-text

}

void opDrive(){
  //simple tank drive code for opControl
  leftFront.move(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)); //for documentation check: https://pros.cs.purdue.edu/v5/api/cpp/motors.html#move-velocity or https://pros.cs.purdue.edu/v5/tutorials/topical/controller.html?highlight=controller%20analog
  leftBack.move(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y));  //for docs check: https://pros.cs.purdue.edu/v5/tutorials/topical/motors.html
  rightFront.move(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y));
  rightBack.move(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y));
}

void opIntake(){
  if(master.get_digital(E_CONTROLLER_DIGITAL_R2)){       //for docs check: https://pros.cs.purdue.edu/v5/api/c/misc.html#controller-id-e-t
    intake.move(100);
  }else if(master.get_digital(E_CONTROLLER_DIGITAL_L1)){
    intake.move(-100);
  }else{
    intake.move(0);
  }
}
