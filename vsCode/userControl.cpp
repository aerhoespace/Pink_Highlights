/*---------------------------------------------------------------------------*/
/*                           User Control Functions                          */
/*---------------------------------------------------------------------------*/

// Drive
void drive(){
    leftFront.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
    leftBack.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
    rightFront.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
    rightBack.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
}

// Intake
void intake(){
    if(Controller1.ButtonR2.pressing()){
        intakeLeft.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
        intakeRight.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }
    else if (Controller1.ButtonL1.pressing()){
        intakeLeft.spin(vex::directionType::fwd, -100, vex::velocityUnits::pct);
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
        puncherLeft.stop(vex::brakeType::brake);
        puncherRight.stop(vex::brakeType::brake);
    }
}