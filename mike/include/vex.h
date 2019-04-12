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

int verifyLeftJoy(){
  int count=0;

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

  Brain.Screen.print("count = ");
  Brain.Screen.print(count);
  Brain.Screen.newLine();

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

  Brain.Screen.print("count = ");
  Brain.Screen.print(count);
  Brain.Screen.newLine();

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
    if(verifyLeftJoy()==1){
      LF.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
      LB.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct); 
    }else if(verifyLeftJoy()==2){
      LF.spin(vex::directionType::fwd, Controller1.Axis4.value()*1, vex::velocityUnits::pct);
      LB.spin(vex::directionType::fwd, Controller1.Axis4.value()*-1, vex::velocityUnits::pct);
      RF.spin(vex::directionType::fwd, Controller1.Axis4.value()*-1, vex::velocityUnits::pct);
      RB.spin(vex::directionType::fwd, Controller1.Axis4.value()*1, vex::velocityUnits::pct);    
    }

    if(verifyRightJoy()==1){
      RF.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
      RB.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);        
    }else if(verifyRightJoy()==2){
      LF.spin(vex::directionType::fwd, Controller1.Axis1.value()*1, vex::velocityUnits::pct);
      LB.spin(vex::directionType::fwd, Controller1.Axis1.value()*-1, vex::velocityUnits::pct);
      RF.spin(vex::directionType::fwd, Controller1.Axis1.value()*-1, vex::velocityUnits::pct);
      RB.spin(vex::directionType::fwd, Controller1.Axis1.value()*1, vex::velocityUnits::pct);  
    }
    
    if(verifyRightJoy()==0 and verifyLeftJoy()==0){
      if(Controller1.ButtonR1.pressing()){
        LF.stop(vex::brakeType::hold);
        LB.stop(vex::brakeType::hold);
        RF.stop(vex::brakeType::hold);
        RB.stop(vex::brakeType::hold);
      }else{
        LF.stop(vex::brakeType::coast);
        LB.stop(vex::brakeType::coast);
        RF.stop(vex::brakeType::coast);
        RB.stop(vex::brakeType::coast);
      }
    }
  
    if(reverseDrive){
        if(verifyRightJoy()==1){
        LF.spin(vex::directionType::fwd, Controller1.Axis3.value()*-1, vex::velocityUnits::pct);
        LB.spin(vex::directionType::fwd, Controller1.Axis3.value()*-1, vex::velocityUnits::pct); 
      }else if(verifyRightJoy()==2){
        LF.spin(vex::directionType::fwd, Controller1.Axis4.value()*-1, vex::velocityUnits::pct);
        LB.spin(vex::directionType::fwd, Controller1.Axis4.value()*1, vex::velocityUnits::pct);
        RF.spin(vex::directionType::fwd, Controller1.Axis4.value()*1, vex::velocityUnits::pct);
        RB.spin(vex::directionType::fwd, Controller1.Axis4.value()*-1, vex::velocityUnits::pct);    
      }

      if(verifyLeftJoy()==1){
        RF.spin(vex::directionType::fwd, Controller1.Axis2.value()*-1, vex::velocityUnits::pct);
        RB.spin(vex::directionType::fwd, Controller1.Axis2.value()*-1, vex::velocityUnits::pct);        
      }else if(verifyLeftJoy()==2){
        LF.spin(vex::directionType::fwd, Controller1.Axis1.value()*-1, vex::velocityUnits::pct);
        LB.spin(vex::directionType::fwd, Controller1.Axis1.value()*1, vex::velocityUnits::pct);
        RF.spin(vex::directionType::fwd, Controller1.Axis1.value()*1, vex::velocityUnits::pct);
        RB.spin(vex::directionType::fwd, Controller1.Axis1.value()*-1, vex::velocityUnits::pct);  
      }
      
      if(verifyRightJoy()==0 and verifyLeftJoy()==0){
        LF.stop(vex::brakeType::hold);
        LB.stop(vex::brakeType::hold);
        RF.stop(vex::brakeType::hold);
        RB.stop(vex::brakeType::hold);
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
 }
 else { //hold in place
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
//math vars
double abs(double Var) {
    if (Var < 0) Var = Var * (-1);
    return Var;
  }
double sgn(double number){
 if (number > 0) number = 1;
 else number = -1;
 return number;
}

//set drive power
void setLeftFrontPower (int power){
 if(power==0) LF.stop(vex::brakeType::coast);
 else{
 LF.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
 }
}
void setLeftBackPower (int power){
 if(power==0) LB.stop(vex::brakeType::coast);
 else{
 LB.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
 }
}
void setRightFrontPower (int power){
 if(power==0) RF.stop(vex::brakeType::coast);
 else{
 RF.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
 }
}
void setRightBackPower (int power){
 if(power==0) RB.stop(vex::brakeType::coast);
 else{
 RB.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
 }
}
void setMechDrivePower(int LF,int LB,int RF,int RB){
 setLeftFrontPower(LF);
 setLeftBackPower(LB);
 setRightFrontPower(RF);
 setRightBackPower(RB);
 }
 void DriveMechPowerSend(int j1,int j2,int j3=0,int j4=0){//left,right,side1,side2
 int LF=j1;//left
 int RF=j2;//right
 int SD=(j3+j4)/2;//side

 setMechDrivePower(//left go apart && right go into when going right
 LF+SD,
 LF-SD,
 RF-SD,
 RF+SD);
 }
 void setDrivePower(int left, int right){
 setLeftFrontPower(left);
 setLeftBackPower(left);
 setRightFrontPower(right);
 setRightBackPower(right);
 }
//drive with ramping
bool DriveRampingEnabled;

class Ramping{
 public:
 int ChangePct=1; //the amout of Pct change per loop
 int ChangeMsec=1; //the amount of time in between loops

 int RequestedPct=0; //used to request Pct value change
 int Pct=0; //Pct output
 int MinUpPct=0; //used as moveing up StillSpeed
 int MinDownPct=0; //used as moving down StillSpeed
 int MaxPct=100; //the max pct value

 Ramping(); //object specifer

 Ramping(int CP,int CM,int MaxP=100,int MinDP=0,int MinUP=0){
 //ChangePct,ChangeMsec,MaxPct
 ChangePct=CP;
 ChangeMsec=CM;
 MaxPct=MaxP;
 MinUpPct=MinUP;
 MinDownPct=MinDP;
 }

 void TaskRun(){
 if(RequestedPct>Pct){ //ramp up
 Pct=Pct+ChangePct;
 }
 else if(RequestedPct<Pct){ //ramp down
 Pct=Pct-ChangePct;
 }
 //limit Pct
 if(Pct>MaxPct)  Pct=MaxPct;
 if(Pct<-MaxPct) Pct=-MaxPct;
 if(Pct>0 && Pct<MinUpPct) Pct=MinUpPct;
 if(Pct<0 && Pct>MinDownPct) Pct=MinDownPct;
 }
}; //end of task

Ramping LFDR(1,5); //first value = pct of pwr change after each interval passed
Ramping RFDR(1,5); //second value = number of Msec between each pct change
Ramping LBDR(1,5); //after every 5 Msec passed, power to motor will be changed by 1 pct
Ramping RBDR(1,5);

 int Drive_Ramping(){
 DriveRampingEnabled=true;
 while(DriveRampingEnabled){
 LFDR.TaskRun();
 RFDR.TaskRun();
 LBDR.TaskRun();
 RBDR.TaskRun();
 setMechDrivePower(LFDR.Pct,LBDR.Pct,RFDR.Pct,RBDR.Pct);
 vex::task::sleep(LFDR.ChangeMsec);
 }
 return 1;
 }
void SetDRpower(int LFpower,int LBpower,int RFpower,int RBpower){
 LFDR.RequestedPct = LFpower;
 RFDR.RequestedPct = RFpower;
 LBDR.RequestedPct = LBpower;
 RBDR.RequestedPct = RBpower;
}
void DI(int Lpower,int Rpower){
 LFDR.RequestedPct=Lpower;
 RFDR.RequestedPct=Rpower;
 LBDR.RequestedPct=Lpower;
 RBDR.RequestedPct=Rpower;
 LFDR.Pct=Lpower;
 RFDR.Pct=Rpower;
 LBDR.Pct=Lpower;
 RBDR.Pct=Rpower;
 setDrivePower(LBDR.Pct,RBDR.Pct);
}
//drive ramping with auto straightening
void driveRamp(double Distance,int Pct=100,int EndWait=200, int Correction=1){

 //update ramping speed
 LFDR.ChangeMsec = 5;
 RFDR.ChangeMsec = 5;
 LBDR.ChangeMsec = 5;
 RBDR.ChangeMsec = 5;

 double Direction=sgn(Distance);
 int LFPowerSend=0;
 int LBPowerSend=0;
 int RFPowerSend=0;
 int RBPowerSend=0;
 
 //clear encoder
 LF.resetRotation();
 LB.resetRotation();
 RF.resetRotation();
 RB.resetRotation();
 
 //is it there yet?
 while(abs(LF.rotation(vex::rotationUnits::deg))<abs(Distance)){
 double LEncValue=LF.rotation(vex::rotationUnits::deg);
 double REncValue=RF.rotation(vex::rotationUnits::deg);
 //straighten
 if(abs(LEncValue)>abs(REncValue)){
 LFPowerSend=Pct-Correction;
 LBPowerSend=Pct-Correction;
 RFPowerSend=Pct;
 RBPowerSend=Pct;
 }
 else if(abs(LEncValue)<abs(REncValue)){
 LFPowerSend=Pct;
 LBPowerSend=Pct;
 RFPowerSend=Pct-Correction;
 RBPowerSend=Pct-Correction;
 }
 else if(abs(LEncValue)==abs(REncValue)){
 LFPowerSend=Pct;
 LBPowerSend=Pct;
 RFPowerSend=Pct;
 RBPowerSend=Pct;
 }
 //correct direction
 LFPowerSend=LFPowerSend*Direction;
 LBPowerSend=LBPowerSend*Direction;
 RFPowerSend=RFPowerSend*Direction;
 RBPowerSend=RBPowerSend*Direction;
 //send to SetDRpower
 SetDRpower(LFPowerSend,LBPowerSend,RFPowerSend,RBPowerSend);
 vex::task::sleep(1);
 }
}
//aton strafing
void strafe(double Distance,int Pct=100,int EndWait=500,int Correction=2){
 //update ramping speed
 LFDR.ChangeMsec = 8;
 RFDR.ChangeMsec = 8;
 LBDR.ChangeMsec = 8;
 RBDR.ChangeMsec = 8;
 //calculate direction and set L & R PowerSend
 double Direction=sgn(Distance);
 int LFPowerSend=0;
 int LBPowerSend=0;
 int RFPowerSend=0;
 int RBPowerSend=0;
 //clear enc
 LB.resetRotation();
 RB.resetRotation();
 LF.resetRotation();
 RF.resetRotation();
 //is it there yet?
 while(abs(RB.rotation(vex::rotationUnits::deg))<abs(Distance)){
 double LEncValue=LB.rotation(vex::rotationUnits::deg);
 double REncValue=RB.rotation(vex::rotationUnits::deg);
 //straiten
 if(abs(LEncValue)>abs(REncValue)){
 LFPowerSend=Pct-Correction;
 LBPowerSend=Pct-Correction;
 RFPowerSend=Pct;
 RBPowerSend=Pct;
 }
 else if(abs(LEncValue)<abs(REncValue)){
 LFPowerSend=Pct;
 LBPowerSend=Pct;
 RFPowerSend=Pct-Correction;
 RBPowerSend=Pct-Correction;
 }
 else if(abs(LEncValue)==abs(REncValue)){
 LFPowerSend=Pct;
 LBPowerSend=Pct;
 RFPowerSend=Pct;
 RBPowerSend=Pct;
 }
 //correct direction
 if(Direction == 1){
 LFPowerSend=LFPowerSend;
 LBPowerSend=LBPowerSend*(-1);
 RFPowerSend=RFPowerSend*(-1);
 RBPowerSend=RBPowerSend;
 }
 if(Direction == -1){
 LFPowerSend=LFPowerSend*(-1);
 LBPowerSend=LBPowerSend;
 RFPowerSend=RFPowerSend;
 RBPowerSend=RBPowerSend*(-1);
 }
 //send to SetDRpower
 SetDRpower(LFPowerSend,LBPowerSend,RFPowerSend,RBPowerSend);
 vex::task::sleep(1);
 }
 SetDRpower(0,0,0,0);
 vex::task::sleep(EndWait);
 }
//aton turning-- no gyro
void atonTurn(double deg,int LPowerSend=40,int RPowerSend=40,int waitTime=200){ //-left,+right
 int Dir=sgn(deg);
 deg=abs(deg)/12.56;
 LPowerSend=LPowerSend*Dir;
 RPowerSend=RPowerSend*Dir;

 LF.resetRotation();
 LB.resetRotation();
 RF.resetRotation();
 RB.resetRotation();

 while((abs(LF.rotation(vex::rotationUnits::rev))) <abs(deg)){
 DI(LPowerSend,-RPowerSend);

 vex::task::sleep(1);
 }
 DI(0,0);
 vex::task::sleep(waitTime);
}

//set lift power
void setLiftMotorPower (int power){
 if(power==0) intake.stop(vex::brakeType::coast);
 else{
 intake.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
 }
}
void setLiftPower (int pow){
 setLiftMotorPower(pow);
}
//lift
void liftUp(int rotations, int power = 100){
 int direction = sgn(rotations);
 
 intake.resetRotation();

 //lift up a certain amount of degrees then hold in place using brakeType::hold
 while(abs(intake.rotation(vex::rotationUnits::deg))<abs(rotations)){
 setLiftPower(power*direction); 
 }
 setLiftPower(0);
}
void liftDown(int rotations, int power = -100){
 int direction = sgn(rotations);
 
 intake.resetRotation();

 //set down a certain amount of degrees then hold in place using brakeType::hold
 while(abs(intake.rotation(vex::rotationUnits::deg))<abs(rotations)){
 setLiftPower(power*direction); 
 }
 setLiftPower(0);
}

//set puncher power
void setPuncherLeftPower (int power){
 if(power==0) puncherLeft.stop(vex::brakeType::hold);
 else{
 puncherLeft.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
 }
}
void setPuncherRightPower (int power){
 if(power==0) puncherRight.stop(vex::brakeType::hold);
 else{
 puncherRight.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
 }
}
void setPuncherPower (int left, int right){
 setPuncherLeftPower(left);
 setPuncherRightPower(right);
}
//puncher
void shoot(int rotations = 360, int power = 100){
 int direction = sgn(rotations);
 
 puncherLeft.resetRotation();
 puncherRight.resetRotation();
 
 //rotate puncher for 360deg and then hold in place using brakeType::hold
 while(abs(puncherLeft.rotation(vex::rotationUnits::deg))<abs(rotations)){
 setPuncherPower(power*direction, power*direction);
 }
 setPuncherPower(0,0);
}
void pull(int rotations = 180, int power = 100){
 int direction = sgn(rotations);
 
 puncherLeft.resetRotation();
 puncherRight.resetRotation();
 
 //rotate puncher for 180deg and then hold in place using brakeType::hold
 while(abs(puncherLeft.rotation(vex::rotationUnits::deg))<abs(rotations)){
 setPuncherPower(power*direction, power*direction);
 }
 setPuncherPower(0,0);
}

//set intake power
void setIntakeMotorPower (int power){
 if(power==0) intake.stop(vex::brakeType::coast);
 else{
 intake.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
 }
}
void setIntakePower (int pow){
 setIntakeMotorPower(pow);
}
//intake
void autoIn(int rotations, int power = 100){
 int direction = sgn(rotations);
 
 intake.resetRotation();
 
 //intake for a certain about of degrees then stop using brakeType::coast
 while(abs(intake.rotation(vex::rotationUnits::deg))<abs(rotations)){
 setIntakePower(power*direction);
 }
 setIntakePower(0);
}
void autoIntake(bool ON, bool In){
 if(ON){
 if(In){ //(true, true) = intake
 setIntakePower(100);
 } 
 if(!In){ //(true, false) = detake
 setIntakePower(-100);
 } 
 }
 if(!ON){ //(false, true/false) = stop
 intake.stop();
 }
}

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
void frontRedAton(){ 
 pull();
 autoIntake(true,true);
 driveRamp(800);
 autoIntake(false,false);
}

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


