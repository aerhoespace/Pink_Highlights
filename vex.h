/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
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
//sensors
//vex::analog_in BallSenseTop = vex::analog_in(Brain.ThreeWirePort.B);
//vex::analog_in BallSenseMiddle = vex::analog_in(Brain.ThreeWirePort.C);
//vex::analog_in BallSenseBottom = vex::analog_in(Brain.ThreeWirePort.D);
vex::analog_in AtonSelectOne = vex::analog_in(Brain.ThreeWirePort.B);
vex::analog_in AtonSelectTwo = vex::analog_in(Brain.ThreeWirePort.C);

//motivational quote
void littleCeasars(){
    Controller1.Screen.print("lEtS gEt tHiS bReAd");
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           User Control Functions                          */
/*                                                                           */
/*---------------------------------------------------------------------------*/

//drive-- check out https://www.desmos.com/calculator/p4fucwmiqb
int verifyLeftJoy(){
  int count=0;

  if(-((Controller1.Axis4.value()*Controller1.Axis4.value())/31.75)+31.75>=Controller1.Axis3.value()){  
    count++;
  }
  if(((Controller1.Axis4.value()*Controller1.Axis4.value())/31.75)-31.75<=Controller1.Axis3.value()){  
    count++;

  }
  if(-((Controller1.Axis3.value()*Controller1.Axis3.value())/31.75)+31.75>=Controller1.Axis4.value()){  
    count++;
  }
  if(((Controller1.Axis3.value()*Controller1.Axis3.value())/31.75)-31.75<=Controller1.Axis4.value()){  
    count++;
  }

  if(count==1){
    if(-((Controller1.Axis4.value()*Controller1.Axis4.value())/31.75)+31.75>=Controller1.Axis3.value()){  
      return 1;
    }else if(((Controller1.Axis4.value()*Controller1.Axis4.value())/31.75)-31.75<=Controller1.Axis3.value()){  
      return 1;
    }else if(-((Controller1.Axis3.value()*Controller1.Axis3.value())/31.75)+31.75>=Controller1.Axis4.value()){  
      return 2;
    }else if(((Controller1.Axis3.value()*Controller1.Axis3.value())/31.75)-31.75<=Controller1.Axis4.value()){  
      return 2;
    }
  }else{
    return 0;
  }
}

int verifyRightJoy(){
  int count=0;

  if(-((Controller1.Axis1.value()*Controller1.Axis1.value())/31.75)+31.75>=Controller1.Axis2.value()){
    count++;
  } 
  if(((Controller1.Axis1.value()*Controller1.Axis1.value())/31.75)-31.75<=Controller1.Axis2.value()){
    count++;
  } 
  if(-((Controller1.Axis2.value()*Controller1.Axis2.value())/31.75)+31.75>=Controller1.Axis1.value()){
    count++;
  } 
  if(((Controller1.Axis2.value()*Controller1.Axis2.value())/31.75)-31.75<=Controller1.Axis1.value()){
    count++;
  } 

  if(count==1){
    if(-((Controller1.Axis1.value()*Controller1.Axis1.value())/31.75)+31.75>=Controller1.Axis2.value()){
      return 1; 
    }else if(((Controller1.Axis1.value()*Controller1.Axis1.value())/31.75)-31.75<=Controller1.Axis2.value()){
      return 1; 
    }else if(-((Controller1.Axis2.value()*Controller1.Axis2.value())/31.75)+31.75>=Controller1.Axis1.value()){
      return 2; 
    }else if(((Controller1.Axis2.value()*Controller1.Axis2.value())/31.75)-31.75<=Controller1.Axis1.value()){
      return 2; 
    }
  }else{
    return 0;
  }
}

//strafing with joystick control
bool reverseDrive=false;

void DriveCont(){
  
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
      if(Controller1.ButtonR1.pressing() or Controller1.ButtonL2.pressing() or Controller1.ButtonDown.pressing() or Controller1.ButtonX.pressing()){
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
}

double sgn(double number){
    if (number > 0) number = 1;
    else number = -1;
    return number;
}

//set lift power
void setLiftMotorPower (int power){
    if(power==0) lift.stop(vex::brakeType::hold);
    else{
        lift.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}
void setLiftPower (int pow){
 setLiftMotorPower(pow);
}
//lift
void LiftCont(){ 
    if(Controller1.ButtonL2.pressing()){ //if buttonL2, lift up
     setLiftPower(100);
    }   
    else if(Controller1.ButtonDown.pressing()){ //if buttonDown, lift down
      setLiftPower(-100);
    }   
    else setLiftPower(0);
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
void PuncherCont(){ //if buttonR1, shoot
    if(Controller1.ButtonR1.pressing()){
        setPuncherPower(100,100);
    }
    else { //hold in place
        setPuncherPower(0,0);
    }
}
/*void PunchersRotateTo(double pos){
  puncherLeft.rotateTo(pos,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
  puncherRight.rotateTo(pos,vex::rotationUnits::deg,100,vex::velocityUnits::pct);

}*/
//void PunchCal(){
//  PunchersRotateTo(/*inital cal amount*/);
//}
/*bool DoubleRun=false;
void NatesDoublePunchTest(){
  if(Controller1.ButtonR1.pressing() && DoubleRun==false){
    while(Controller1.ButtonR1.pressing()){
      //shoot first time
      //shoot seconed time
      DoubleRun=true;
    }
    if((DoubleRun=false)){
      //shoot once
    }

  }
}
bool DoubleShotEnable=false;
int Double_Shot(){
  PunchCal();
  DoubleShotEnable = true;
  while(DoubleShotEnable){
    NatesDoublePunchTest();
  }
}*/

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
void IntakeCont(){ 
    if(Controller1.ButtonR2.pressing()){ //if buttonR2, intake
    setIntakePower(100);
    }   
    else if(Controller1.ButtonL1.pressing()){ //if buttonL1, detake
    setIntakePower(-100);
    }   
    else intake.stop(vex::brakeType::coast);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           Autonomous Functions                            */
/*                                                                           */
/*---------------------------------------------------------------------------*/
//math vars
double abs(double Var) {
		if (Var < 0)  Var = Var * (-1);
		return Var;
	}

//set drive power
void setLFPower (int power){
    if(power==0) LF.stop(vex::brakeType::coast);
    else{
        LF.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}
void setLBPower (int power){
    if(power==0) LB.stop(vex::brakeType::coast);
    else{
        LB.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}
void setRFPower (int power){
    if(power==0) RF.stop(vex::brakeType::coast);
    else{
        RF.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}
void setRBPower (int power){
    if(power==0) RB.stop(vex::brakeType::coast);
    else{
        RB.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}
void setMechDrivePower(int LF,int LB,int RF,int RB){
        setLFPower(LF);
        setLBPower(LB);
        setRFPower(RF);
        setRBPower(RB);
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
        setLFPower(left);
        setLBPower(left);
        setRFPower(right);
        setRBPower(right);
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
        if(Pct>MaxPct)	Pct=MaxPct;
        if(Pct<-MaxPct)	Pct=-MaxPct;
        if(Pct>0 && Pct<MinUpPct) Pct=MinUpPct;
        if(Pct<0 && Pct>MinDownPct)    Pct=MinDownPct;
    }
}; //end of task

Ramping LFDR(1,6);
Ramping LBDR(1,6);
Ramping RFDR(1,6);
Ramping RBDR(1,6);

    int Drive_Ramping(){
        DriveRampingEnabled=true;
        while(DriveRampingEnabled){
            LFDR.TaskRun();
            LBDR.TaskRun();
            RFDR.TaskRun();
            RBDR.TaskRun();
            setDrivePower(LFDR.Pct, RFDR.Pct);
            vex::task::sleep(LFDR.ChangeMsec);
        }
        return 1;
    }

void SetDRpower(int LFpower,int LBpower,int RFpower,int RBpower){ //DMR
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
void AtonDriveRamp(double Distance,int Pct=100,int EndWait=200, int Correction=1){
        //update ramping speed
        LFDR.ChangeMsec = 6;
        RFDR.ChangeMsec = 6;
        LBDR.ChangeMsec = 6;
        RBDR.ChangeMsec = 6;

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
            double REncValue=RB.rotation(vex::rotationUnits::deg);
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
        SetDRpower(0,0,0,0);
        vex::task::sleep(EndWait);
    }
void AtonTurn(double deg,int LPowerSend=50,int RPowerSend=50,int waitTime=200){ //-left, +right
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
void AtonLock(){
        LF.stop(vex::brakeType::hold);
        LB.stop(vex::brakeType::hold);
        RF.stop(vex::brakeType::hold);
        RB.stop(vex::brakeType::hold);
}

//lift
void LiftMove(int pos, int power=100){
        lift.resetRotation();

        lift.startRotateFor(pos,vex::rotationUnits::deg,power,vex::velocityUnits::pct);
        lift.setStopping(vex::brakeType::hold);
}
void AtonLift(int rotations, int power = 100){
  int direction = sgn(rotations);

    while(abs(lift.rotation(vex::rotationUnits::deg))<abs(rotations)){
      setLiftPower(power*direction);
    }
    setLiftPower(0);
  }

//puncher
void AtonFire(int rotations = 360, int power = 100){
    int direction = sgn(rotations);
        
    puncherLeft.resetRotation();
    puncherRight.resetRotation();
    
    //rotate puncher for 360deg and then hold in place using brakeType::hold
    while(abs(puncherLeft.rotation(vex::rotationUnits::deg))<abs(rotations)){
        setPuncherPower(power*direction, power*direction);
    }
    setPuncherPower(0,0);
}
void Pull(int rotations = 150, int power = 100){
    int direction = sgn(rotations);
        
    puncherLeft.resetRotation();
    puncherRight.resetRotation();
    
    //rotate puncher for 180deg and then hold in place using brakeType::hold
    while(abs(puncherLeft.rotation(vex::rotationUnits::deg))<abs(rotations)){
        setPuncherPower(power*direction, power*direction);
    }
    setPuncherPower(0,0);
}

//intake
void AtonIn(int rotations = 200, int power = 100){
    int direction = sgn(rotations);
    
    intake.resetRotation();
    
    //intake for a certain about of degrees then stop using brakeType::coast
    while(abs(intake.rotation(vex::rotationUnits::deg))<abs(rotations)){
        setIntakePower(power*direction);
    }
    setIntakePower(0);
}
void AtonTake(bool On, bool In){
    if(On){
        if(In){
            setIntakePower(100);
        } 
        if(!In){
            setIntakePower(-100);
        } 
    }
    if(!On){
        intake.stop();
    }
}

//auto intake vars
/*int	BottomLightValue;
int TopLightValue;
int MiddleLightValue;

int BottomBallInMax = 50;
int TopBallInMax = 50;

bool BallInBottom;
bool BallInTop;

bool AutoIntakeEnabled = true;
bool AutoIntakeTaskEnabled = false;
bool AutoIntakeOff = false;
bool AutoFlip=false;

void Auto_Intake() {
    BottomLightValue = BallSenseBottom.value(vex::percentUnits::pct);
    MiddleLightValue = BallSenseMiddle.value(vex::percentUnits::pct);
    TopLightValue = BallSenseTop.value(vex::percentUnits::pct);

    if (BottomLightValue < BottomBallInMax || MiddleLightValue < BottomBallInMax) BallInBottom = true;
    else BallInBottom = false;

    if (TopLightValue < TopBallInMax) BallInTop = true;
    else BallInTop = false;

    if(AutoIntakeOff){
        setIntakePower(0);
        if(AutoFlip) setIntakePower(-100);
    }
    else if(BallInBottom && BallInTop){
        setIntakePower(0);
    }
    else{
        setIntakePower(0);
    } 
}
int Auto_Intaking(){
    AutoIntakeTaskEnabled = true;
    // AutoIntakeEnabled = true;
    while(AutoIntakeTaskEnabled){
        if(AutoIntakeEnabled){Auto_Intake();}
        else if(!AutoIntakeEnabled){}
        vex::task::sleep(20);
    }
    setIntakePower(0);
    return 1;
}*/

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             Autonomous Modes                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void wait (int Msec){
  vex::task::sleep(Msec);
}

  void FrntRedFlag(){ //needs slight tuning //Q44
    Pull();
    AtonLift(-10);
    AtonDriveRamp(780);
    AtonIn();
    AtonDriveRamp(-560);
    wait(500);
    AtonTurn(-13.75);
    AtonDriveRamp(40,25);
    AtonFire();
    AtonTake(true,true);
    AtonLift(190);
    wait(100);
    AtonFire();
    AtonTurn(-0.5);
    AtonDriveRamp(900);
    AtonDriveRamp(-400);
    AtonTurn(6.5);
    AtonTake(false,false);
    AtonIn(-200);
    AtonFire();
    AtonTake(true,false);
    AtonDriveRamp(500);
    AtonTake(false,false);
  }

  void FrntRedPrk(){ //tuned
    Pull();
    AtonLift(-10);
    AtonDriveRamp(780);
    AtonIn();
    AtonDriveRamp(-570);
    wait(500);
    AtonTurn(-14);
    AtonDriveRamp(40,25);
    AtonFire();
    AtonTake(true,true);
    AtonLift(150);
    wait(100);
    AtonFire();
    AtonTurn(-0.5);
    AtonDriveRamp(900);
    AtonDriveRamp(-1565);
    AtonTake(false,false);    
    AtonTurn(-18.55);
    AtonDriveRamp(-1100);
    AtonLock();
  }

  void FrntBlueFlag(){ //needs tuning
    Pull();
    AtonLift(-10);
    AtonDriveRamp(780);
    AtonIn();
    AtonDriveRamp(-740);
    AtonTurn(12.5);
    AtonDriveRamp(100,25);
    AtonFire();
    AtonTake(true,true);
    AtonLift(150);
    wait(50);
    AtonFire();
    AtonDriveRamp(800);
    AtonDriveRamp(-400);
    AtonTurn(-11.6);
    AtonTake(false,false);
    AtonIn(-200);
    AtonFire();
    AtonTake(true,false);
    AtonDriveRamp(500);
    AtonTake(false,false);
  }

  void FrntBluePrk(){ //needs tuning //Q11
    Pull();
    AtonLift(-10);
    AtonDriveRamp(780);
    AtonIn();
    AtonDriveRamp(-550);
    wait(500);
    AtonTurn(14);
    AtonDriveRamp(50,25);
    AtonFire();
    AtonTake(true,true);
    AtonLift(150);
    wait(100);
    AtonFire();
    AtonTurn(0.35);
    AtonDriveRamp(900);
    AtonDriveRamp(-1565);
    AtonTake(false,false);    
    AtonTurn(13);
    AtonDriveRamp(-1100);
    AtonLock();
  }

  void BckRedSniper(){ //needs tuning
    Pull();
    AtonLift(-10);
    AtonDriveRamp(800);
    wait(10);
    AtonIn();
    wait(10);
    AtonDriveRamp(-221,75,500);
    AtonTurn(-7.5,50,50,500);
    AtonLift(125);
    wait(8000);
    AtonFire();
    AtonTake(true,true);
    AtonLift(350);
    AtonDriveRamp(-300);
    AtonTake(false,false);
    AtonFire();
  }

  void BckRedSnipePrk(){ //tuned //P6 //Q147
    Pull();
    AtonLift(-10);
    AtonDriveRamp(800);
    wait(10);
    AtonIn();
    wait(10);
    AtonDriveRamp(-220,75,500);
    AtonTurn(-7.5,50,50,500);
    AtonLift(125);
    wait(2500);
    AtonFire();
    AtonTake(true,true);
    AtonLift(350);
    AtonDriveRamp(-320);
    AtonTake(false,false);
    AtonFire();
    AtonTurn(24.5);
    AtonDriveRamp(-925);
    AtonTurn(11.9);
    AtonDriveRamp(-1400);
    AtonLock();
  }

  void BckBlueSniper(){ //needs tuning
    Pull();
    AtonLift(-10);
    AtonDriveRamp(780);
    AtonIn();
    AtonDriveRamp(-200,75,500);
    AtonTurn(7.4,50,50,500);
    AtonLift(125);
    wait(8000);
    AtonFire();
    AtonTake(true,true);
    AtonLift(350);
    AtonDriveRamp(-320);
    AtonTake(false,false);
    AtonFire();
  }

  void BckBlueSnipePrk(){ //needs tuning
    Pull();
    AtonLift(-10);
    AtonDriveRamp(780);
    AtonIn();
    AtonDriveRamp(-200,75,500);
    AtonTurn(7.4,50,50,500);
    AtonLift(125);
    wait(2500);
    AtonFire();
    AtonTake(true,true);
    AtonLift(350);
    AtonDriveRamp(-320);
    AtonTake(false,false);
    AtonFire();
    AtonTurn(-24.5);
    AtonDriveRamp(-900);
    AtonTurn(-18);
    AtonDriveRamp(-1800);
  }

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            Autonomous Selector                            */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void AtonPots(){
    int SelectValueOne = AtonSelectOne.value(vex::percentUnits::pct);
    int SelectValueTwo = AtonSelectTwo.value(vex::percentUnits::pct);
    
   if(SelectValueOne > 60){
       if(SelectValueTwo > 80){
          FrntRedFlag();
      }
      else if(SelectValueTwo > 50){
          FrntRedPrk();
      }
      else if(SelectValueTwo > 30){
          //none
      }
      else if(SelectValueTwo >= 0){
          //none
      }
    }
    
    else if(SelectValueOne > 40){
        if(SelectValueTwo > 80){
            BckRedSniper();
        }
        else if(SelectValueTwo > 50){
            BckRedSnipePrk();
        }
        else if(SelectValueTwo > 30){
            //none
        }
        else if(SelectValueTwo >= 0){
            //none
        }
    }
    else if(SelectValueOne > 20){
        if(SelectValueTwo > 80){
            BckBlueSniper();
        }
        else if(SelectValueTwo > 50){
            BckBlueSnipePrk();
        }
        else if(SelectValueTwo > 30){
            //none
        }
        else if(SelectValueTwo >= 0){
            //none
        }
    }
    else if(SelectValueOne >= 0){
        if(SelectValueTwo > 80){
            FrntBlueFlag();
        }
        else if(SelectValueTwo > 50){
            FrntBluePrk();
        }
        else if(SelectValueTwo > 30){
            //none
        }
        else if(SelectValueTwo >= 0){
            //none
        }
    }
}

int selFun(){
    static int SelectValueOne;
    static int SelectValueTwo;

    while(true){

    static int SelectValueOneWas = SelectValueOne;
    static int SelectValueTwoWas = SelectValueTwo;

    SelectValueOne = AtonSelectOne.value(vex::percentUnits::pct);
    SelectValueTwo = AtonSelectTwo.value(vex::percentUnits::pct);

    if(SelectValueOne!=SelectValueOneWas || SelectValueTwo!=SelectValueTwoWas){
          Brain.Screen.clearScreen();

    if(SelectValueOne > 60){
      if(SelectValueTwo > 80){
          //FrntRedFlag();
          Brain.Screen.clearLine(1, vex::color::red);
          Brain.Screen.clearLine();
          Brain.Screen.print("Front Red Flag -- First Cap, First Row Flags, One Middle Row Flag, Second Cap");
      }
        else if(SelectValueTwo > 50){
            //FrntRedPark();
            Brain.Screen.clearLine(1, vex::color::red);
            Brain.Screen.clearLine();
            Brain.Screen.print("Front Red Park -- First Cap, First Row Flags, Park");

        }
        else if(SelectValueTwo > 30){
            //none
            Brain.Screen.clearLine(1, vex::color::red);
            Brain.Screen.clearLine();
            Brain.Screen.print("N/A");
        }
        else if(SelectValueTwo >= 0){
            //none
            Brain.Screen.clearLine(1, vex::color::red);
            Brain.Screen.clearLine();
            Brain.Screen.print("N/A");
        }
    }
    else if(SelectValueOne > 40){
        if(SelectValueTwo > 80){
            //BckRedSniper();
            Brain.Screen.clearLine(1, vex::color::red);
            Brain.Screen.clearLine();
            Brain.Screen.print("Back Red Sniper -- First Cap, Snipe High Flags");
        }
        else if(SelectValueTwo > 50){
            //BckRedSniperPrk();
            Brain.Screen.clearLine(1, vex::color::red);
            Brain.Screen.clearLine();
            Brain.Screen.print("Back Red Parking Sniper -- First Cap, Snipe High Flags, Park");
        }
        else if(SelectValueTwo > 30){
            //none
            Brain.Screen.clearLine(1, vex::color::red);
            Brain.Screen.clearLine();
            Brain.Screen.print("N/A");
        }
        else if(SelectValueTwo >= 0){
            //none
            Brain.Screen.clearLine(1, vex::color::red);
            Brain.Screen.clearLine();
            Brain.Screen.print("N/A");
        }
    }

    else if(SelectValueOne > 20){
        if(SelectValueTwo > 80){
            //BckBlueSniper
            Brain.Screen.clearLine(1, vex::color::blue);
            Brain.Screen.clearLine();
            Brain.Screen.print("Back Blue Sniper -- First Cap, Snipe High Flags");
        }
        else if(SelectValueTwo > 50){
            //BackBlueSnipePrk
            Brain.Screen.clearLine(1, vex::color::blue);
            Brain.Screen.clearLine();
            Brain.Screen.print("Back Blue Parking Sniper -- First Cap, Snipe High Flags");
        }
        else if(SelectValueTwo > 30){
            //none
            Brain.Screen.clearLine(1, vex::color::blue);
            Brain.Screen.clearLine();
            Brain.Screen.print("N/A");
        }
        else if(SelectValueTwo >= 0){
            //none
            Brain.Screen.clearLine(1, vex::color::blue);
            Brain.Screen.clearLine();
            Brain.Screen.print("N/A");
        }
    }
    else if(SelectValueOne >= 0){
        if(SelectValueTwo > 80){
            //FrntBlueFlag
            Brain.Screen.clearLine(1, vex::color::blue);
            Brain.Screen.clearLine();
            Brain.Screen.print("Front Blue Flag -- First Cap, First Row Flags, One Middle Row Flag, Second Cap");
        }
        else if(SelectValueTwo > 50){
            //FrntBluePrk
            Brain.Screen.clearLine(1, vex::color::blue);
            Brain.Screen.clearLine();
            Brain.Screen.print("Front Blue Park -- First Cap, First Row Flags, Park");
        }
        else if(SelectValueTwo > 30){
            //none
            Brain.Screen.clearLine(1, vex::color::blue);
            Brain.Screen.clearLine();
            Brain.Screen.print("N/A");
        }
        else if(SelectValueTwo >= 0){
            //none
            Brain.Screen.clearLine(1, vex::color::blue);
            Brain.Screen.clearLine();
            Brain.Screen.print("N/A");
        }
      }
    }
    vex::task::sleep(100);
  }
}
