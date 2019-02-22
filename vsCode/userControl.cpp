vex::brain Brain;
vex::controller Controller1 = vex::controller();

// Drive
vex::motor leftFront = vex::motor(vex::PORT1,vex::gearSetting::ratio18_1,false);
vex::motor leftBack = vex::motor(vex::PORT2,vex::gearSetting::ratio18_1,false);
vex::motor rightFront = vex::motor(vex::PORT9,vex::gearSetting::ratio18_1,true); // True = reversed
vex::motor rightBack = vex::motor(vex::PORT10,vex::gearSetting::ratio18_1,true);
// Intake
vex::motor intakeLeft = vex::motor(vex::PORT3,vex::gearSetting::ratio18_1,false);
vex::motor intakeRight = vex::motor(vex::PORT4,vex::gearSetting::ratio18_1,true);
// Puncher
vex::motor puncherLeft = vex::motor(vex::PORT5,vex::gearSetting::ratio36_1,true);
vex::motor puncherRight = vex::motor(vex::PORT6,vex::gearSetting::ratio36_1,false);

#include <cmath>

// Motivational quote
void littleCeasars(){
    Controller1.Screen.print("lEtS gEt tHiS bReAd");
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           User Control Functions                          */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// Drive
void drive(){
    leftFront.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
    leftBack.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
    rightFront.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
    rightBack.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
}
void driveLock(){
    if(Controller1.ButtonX.pressing()){
        leftFront.stop(vex::brakeType::hold);
        leftBack.stop(vex::brakeType::hold);
        rightFront.stop(vex::brakeType::hold);
        rightBack.stop(vex::brakeType::hold);
    }
    else if(Controller1.ButtonY.pressing()){
        leftFront.stop(vex::brakeType::coast);
        leftBack.stop(vex::brakeType::coast);
        rightFront.stop(vex::brakeType::coast);
        rightBack.stop(vex::brakeType::coast);
    }
}

// Intake
void intake(){
    if(Controller1.ButtonR2.pressing()){ // Intake ball
        intakeLeft.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
        intakeRight.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }
    else if (Controller1.ButtonL1.pressing()){ // Run reversed top roller only
        intakeLeft.spin(vex::directionType::fwd, -100, vex::velocityUnits::pct);
    }
    else if (Controller1.Button.L2.pressing()){ // Run reversed bottom roller only
        intakeRight.spin(vex::directionType::fwd, -100, vex::velocityUnits::pct);
    }
    else {
        intakeLeft.stop(vex::brakeType::coast);
        intakeRight.stop(vex::brakeType::coast);
    }
}

// Puncher
void punch(){
    if(Controller1.ButtonR1.pressing()){
        puncherLeft.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
        puncherRight.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }
    else {
        puncherLeft.stop(vex::brakeType::hold);
        puncherRight.stop(vex::brakeType::hold);
    }
}