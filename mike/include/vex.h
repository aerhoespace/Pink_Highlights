/*----------------------------------------------------------------------------*/
/* */
/* Module: vex.h */
/* Author: Vex Robotics */
/* Created: 1 Feb 2019 */
/* Description: Default header for V5 projects */
/* */
/*----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "v5.h"
#include "v5_vcs.h"

vex::brain Brain;
vex::controller Controller1 = vex::controller();

//drive
vex::motor LF = vex::motor(vex::PORT1,vex::gearSetting::ratio18_1,false); 
vex::motor LB = vex::motor(vex::PORT2,vex::gearSetting::ratio18_1,false);
vex::motor RF = vex::motor(vex::PORT9,vex::gearSetting::ratio18_1,true); //true=reversed
vex::motor RB = vex::motor(vex::PORT10,vex::gearSetting::ratio18_1,true);
//lift
vex::motor lift = vex::motor(vex::PORT4,vex::gearSetting::ratio18_1,false);
//puncher
vex::motor puncherLeft = vex::motor(vex::PORT5,vex::gearSetting::ratio36_1,true);
vex::motor puncherRight = vex::motor(vex::PORT6,vex::gearSetting::ratio36_1,false);
//intake
vex::motor intake = vex::motor(vex::PORT7,vex::gearSetting::ratio18_1,true);

bool reverseDrive=false;

//motivational quote
void littleCeasars(){
 Controller1.Screen.print("lEtS gEt tHiS bReAd");
}

/*---------------------------------------------------------------------------*/
/* */
/* User Control Functions */
/* */
/*---------------------------------------------------------------------------*/

int verifyJoy(bool left = true){
  int count=0;
  if(left){
    if(-((Controller1.Axis4.value()*Controller1.Axis4.value())/31.75)+31.75>=Controller1.Axis3.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
      count++;
    }

    if(((Controller1.Axis4.value()*Controller1.Axis4.value())/31.75)-31.75<=Controller1.Axis3.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
      count++;

    }

    if(-((Controller1.Axis3.value()*Controller1.Axis3.value())/31.75)+31.75>=Controller1.Axis4.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
      count++;
    }

    if(((Controller1.Axis3.value()*Controller1.Axis3.value())/31.75)-31.75<=Controller1.Axis4.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
      count++;
    }

    if(count==1){
      if(-((Controller1.Axis4.value()*Controller1.Axis4.value())/31.75)+31.75>=Controller1.Axis3.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
        return 1;
        Brain.Screen.print("Left Quad = Down");
      }else if(((Controller1.Axis4.value()*Controller1.Axis4.value())/31.75)-31.75<=Controller1.Axis3.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
        return 1;
        Brain.Screen.print("Left Quad = Up");
      }else if(-((Controller1.Axis3.value()*Controller1.Axis3.value())/31.75)+31.75>=Controller1.Axis4.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
        return 2;
        Brain.Screen.print("Left Quad = Right");
      }else if(((Controller1.Axis3.value()*Controller1.Axis3.value())/31.75)-31.75<=Controller1.Axis4.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
        return 2;
        Brain.Screen.print("Left Quad = Left");
      }
    }else{
      return 0;
      Brain.Screen.print("Left Quad = Deadzone");
    }
  }else if(!left){
    if(-((Controller1.Axis1.value()*Controller1.Axis1.value())/31.75)+31.75>=Controller1.Axis2.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
      count++;
    }

    if(((Controller1.Axis1.value()*Controller1.Axis1.value())/31.75)-31.75<=Controller1.Axis2.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
      count++;

    }

    if(-((Controller1.Axis2.value()*Controller1.Axis2.value())/31.75)+31.75>=Controller1.Axis1.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
      count++;
    }

    if(((Controller1.Axis2.value()*Controller1.Axis2.value())/31.75)-31.75<=Controller1.Axis1.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
      count++;
    }

    if(count==1){
      if(-((Controller1.Axis1.value()*Controller1.Axis1.value())/31.75)+31.75>=Controller1.Axis2.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
        return 1;
        Brain.Screen.print("Right Quad = Down");
      }else if(((Controller1.Axis1.value()*Controller1.Axis1.value())/31.75)-31.75<=Controller1.Axis2.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
        return 1;
        Brain.Screen.print("Right Quad = Up");
      }else if(-((Controller1.Axis2.value()*Controller1.Axis2.value())/31.75)+31.75>=Controller1.Axis1.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
        return 2;
        Brain.Screen.print("Right Quad = Right");
      }else if(((Controller1.Axis2.value()*Controller1.Axis2.value())/31.75)-31.75<=Controller1.Axis1.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
        return 2;
        Brain.Screen.print("Right Quad = Left");
      }
    }else{
      return 0;
      Brain.Screen.print("Right Quad = Deadzone");
    }
  }  
}

int verifyRightJoy(){
  int count=0;

  if(-((Controller1.Axis1.value()*Controller1.Axis1.value())/31.75)+31.75>=Controller1.Axis2.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
    count++;
  }

  if(((Controller1.Axis1.value()*Controller1.Axis1.value())/31.75)-31.75<=Controller1.Axis2.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
    count++;

  }

  if(-((Controller1.Axis2.value()*Controller1.Axis2.value())/31.75)+31.75>=Controller1.Axis1.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
    count++;
  }

  if(((Controller1.Axis2.value()*Controller1.Axis2.value())/31.75)-31.75<=Controller1.Axis1.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
    count++;
  }

  if(count==1){
    if(-((Controller1.Axis1.value()*Controller1.Axis1.value())/31.75)+31.75>=Controller1.Axis2.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
      return 1;
      Brain.Screen.print("Right Quad = Down");
    }else if(((Controller1.Axis1.value()*Controller1.Axis1.value())/31.75)-31.75<=Controller1.Axis2.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
      return 1;
      Brain.Screen.print("Right Quad = Up");
    }else if(-((Controller1.Axis2.value()*Controller1.Axis2.value())/31.75)+31.75>=Controller1.Axis1.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
      return 2;
      Brain.Screen.print("Right Quad = Right");
    }else if(((Controller1.Axis2.value()*Controller1.Axis2.value())/31.75)-31.75<=Controller1.Axis1.value()){  //check out https://www.desmos.com/calculator/p4fucwmiqb
      return 2;
      Brain.Screen.print("Right Quad = Left");
    }
  }else{
    return 0;
    Brain.Screen.print("Right Quad = Deadzone");
  }
}

//strafing with joystick control
void tankStrafe(){
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);

  if(!reverseDrive)
    if(verifyJoy()==1){
      LF.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
      LB.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct); 
    }else if(verifyJoy()==2){
      LF.spin(vex::directionType::fwd, Controller1.Axis4.value()*1, vex::velocityUnits::pct);
      LB.spin(vex::directionType::fwd, Controller1.Axis4.value()*-1, vex::velocityUnits::pct);
      RF.spin(vex::directionType::fwd, Controller1.Axis4.value()*-1, vex::velocityUnits::pct);
      RB.spin(vex::directionType::fwd, Controller1.Axis4.value()*1, vex::velocityUnits::pct);    
    }

    if(verifyJoy(false)==1){
      RF.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
      RB.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);        
    }else if(verifyJoy(false)==2){
      LF.spin(vex::directionType::fwd, Controller1.Axis1.value()*1, vex::velocityUnits::pct);
      LB.spin(vex::directionType::fwd, Controller1.Axis1.value()*-1, vex::velocityUnits::pct);
      RF.spin(vex::directionType::fwd, Controller1.Axis1.value()*-1, vex::velocityUnits::pct);
      RB.spin(vex::directionType::fwd, Controller1.Axis1.value()*1, vex::velocityUnits::pct);  
    }
    
    if(verifyJoy(false)==0 and verifyJoy()==0){
      if(Controller1.ButtonR2.pressing() or Controller1.ButtonL1.pressing()){
        LF.stop(vex::brakeType::coast);
        LB.stop(vex::brakeType::coast);
        RF.stop(vex::brakeType::coast);
        RB.stop(vex::brakeType::coast);
      }else{
        LF.stop(vex::brakeType::hold);
        LB.stop(vex::brakeType::hold);
        RF.stop(vex::brakeType::hold);
        RB.stop(vex::brakeType::hold);
      }
    }
  
    if(reverseDrive){
      if(verifyJoy(false)==1){
        LF.spin(vex::directionType::fwd, Controller1.Axis2.value()*-1, vex::velocityUnits::pct);
        LB.spin(vex::directionType::fwd, Controller1.Axis2.value()*-1, vex::velocityUnits::pct); 
      }else if(verifyJoy(false)==2){
        LF.spin(vex::directionType::fwd, Controller1.Axis1.value()*-1, vex::velocityUnits::pct);
        LB.spin(vex::directionType::fwd, Controller1.Axis1.value()*1, vex::velocityUnits::pct);
        RF.spin(vex::directionType::fwd, Controller1.Axis1.value()*1, vex::velocityUnits::pct);
        RB.spin(vex::directionType::fwd, Controller1.Axis1.value()*-1, vex::velocityUnits::pct);    
      }

      if(verifyJoy()==1){
        RF.spin(vex::directionType::fwd, Controller1.Axis3.value()*-1, vex::velocityUnits::pct);
        RB.spin(vex::directionType::fwd, Controller1.Axis3.value()*-1, vex::velocityUnits::pct);        
      }else if(verifyJoy()==2){
        LF.spin(vex::directionType::fwd, Controller1.Axis4.value()*-1, vex::velocityUnits::pct);
        LB.spin(vex::directionType::fwd, Controller1.Axis4.value()*1, vex::velocityUnits::pct);
        RF.spin(vex::directionType::fwd, Controller1.Axis4.value()*1, vex::velocityUnits::pct);
        RB.spin(vex::directionType::fwd, Controller1.Axis4.value()*-1, vex::velocityUnits::pct);  
      }
      
    if(verifyJoy(false)==0 and verifyJoy()==0){
      if(Controller1.ButtonR2.pressing() or Controller1.ButtonL1.pressing()){
        LF.stop(vex::brakeType::coast);
        LB.stop(vex::brakeType::coast);
        RF.stop(vex::brakeType::coast);
        RB.stop(vex::brakeType::coast);
      }else{
        LF.stop(vex::brakeType::hold);
        LB.stop(vex::brakeType::hold);
        RF.stop(vex::brakeType::hold);
        RB.stop(vex::brakeType::hold);
      }
    }
  }
}

//basic tank drive
void drive(){
 LF.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
 LB.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
 RF.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
 RB.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
}
void driveCont(){
 tankStrafe(); //this can be changed to tankStrafe();, or drive();
}

/*joystick button map:
L1-- top left trigger
L2-- bottom left trigger
R1-- top right trigger
R2-- bottom right trigger*/
//driver reverse func
void driveReverseFunc(){
  if(Controller1.ButtonA.pressing()){
    while(Controller1.ButtonA.pressing()){
      if(!Controller1.ButtonA.pressing()){
        break;
      }
    }
    reverseDrive=!reverseDrive;
  }
}

//lift
void liftCont(){
 if(Controller1.ButtonL2.pressing()){ //if buttonL2, liftUp
 lift.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
 }
 else if(Controller1.ButtonDown.pressing()){ //if buttonDown, liftDown
 lift.spin(vex::directionType::fwd, -100, vex::velocityUnits::pct);
 }
 else { //hold in place
 lift.stop(vex::brakeType::hold);
 }
}

//puncher
void puncherCont(){ //if buttonR1, shoot
 if(Controller1.ButtonR1.pressing()){
 puncherLeft.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
 puncherRight.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
 }else { //hold in place
 puncherLeft.stop(vex::brakeType::hold);
 puncherRight.stop(vex::brakeType::hold);
 }
}

//intake
void intakeCont(){ //if buttonR2, intake
 if(Controller1.ButtonR2.pressing()){
 intake.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
 }
 else if (Controller1.ButtonL1.pressing()){ //if buttonL1, detake
 intake.spin(vex::directionType::fwd, -100, vex::velocityUnits::pct);
 }
 else { //stop
 intake.stop(vex::brakeType::coast);
 }
}

/*---------------------------------------------------------------------------*/
/* */
/* Autonomous Functions */
/* */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* */
/* Autonomous Modes */
/* */
/*---------------------------------------------------------------------------*/

/* functions
drive- driveRamp, atonTurn
lift- sett, liftUp, liftDown
puncher- shoot, pull
intake- autoIn, autoIntake
*/

//front red

/*---------------------------------------------------------------------------*/
/* */
/* Notes */
/* */
/*---------------------------------------------------------------------------*/
//note 1-- front aton
/*shoot top, lift up, middle, bottom
next row-- middle, lift down, top, bottom (save time with less angling and same result)*/


/*---------------------------------------------------------------------------*/
/* */
/* Autonomous Selector */
/* */
/*---------------------------------------------------------------------------*/


