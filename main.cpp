/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       meredithgreen                                             */
/*    Created:      Sun Apr 07 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::competition
vex::competition Competition;

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {

    //start the ritual
    littleCeasars();
    
    //wait for VEX to not be a dumb :P
    LF.setStopping(vex::brakeType::coast);
    LB.setStopping(vex::brakeType::coast);
    RF.setStopping(vex::brakeType::coast);
    RB.setStopping(vex::brakeType::coast);
    lift.setStopping(vex::brakeType::hold);
    puncherLeft.setStopping(vex::brakeType::brake);
    puncherRight.setStopping(vex::brakeType::brake);
    intake.setStopping(vex::brakeType::coast);

    vex::task Sel (selFun);

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {

  vex::task Ramping (Drive_Ramping); //starts ramping to run in the background
  //vex::task AutoInt (Auto_Intaking); //starts auto intake task

  AtonPots();

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void usercontrol( void ) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo 
    // values based on feedback from the joysticks.

    Brain.Screen.clearScreen();

    DriveRampingEnabled=false; //turn off ramping for driver control
    //vex::task AutoInt (Auto_Intaking);

    DriveCont();
    LiftCont();
    PuncherCont();
    IntakeCont();

    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
    //Set up callbacks for autonomous and driver control periods.

    //Run the pre-autonomous function. 
    pre_auton();

    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}
