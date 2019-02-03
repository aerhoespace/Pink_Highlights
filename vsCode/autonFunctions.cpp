/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           Autonomous Functions                            */
/*                                                                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                       Autonomous Drive Functions                          */
/*---------------------------------------------------------------------------*/
double sgn(double number){
    if (number > 0) number = 1;
    else number = -1;
    return number;
}

void setLeftFrontPower (int power){
    if(power==0) leftFront.stop(vex::brakeType::brake);
    else{
        leftFront.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}
void setLeftBackPower (int power){
    if(power==0) leftBack.stop(vex::brakeType::brake);
    else{
        leftBack.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}
void setRightFrontPower (int power){
    if(power==0) rightFront.stop(vex::brakeType::brake);
    else{
        rightFront.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}
void setRightBackPower (int power){
    if(power==0) rightBack.stop(vex::brakeType::brake);
    else{
        rightBack.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}

void setDrivePower (int left, int right){
    setLeftFrontPower(left);
    setLeftBackPower(left);
    setRightFrontPower(right);
    setRightBackPower(right);
}

void autoDrive(int distance, int power = 60){
    int direction = sgn(distance);
        
    leftFront.resetRotation();
    leftBack.resetRotation();
    rightFront.resetRotation();
    rightBack.resetRotation();
    
    while(std::abs(leftFront.rotation(vex::rotationUnits::deg))<std::abs(distance)){
        setDrivePower(power*direction, power*direction);
    }
    setDrivePower(0,0);
}

void autoTurn(int distance, int power = 60){
    int direction = sgn(distance);
        
    leftFront.resetRotation();
    leftBack.resetRotation();
    rightFront.resetRotation();
    rightBack.resetRotation();
    
    while(std::abs(leftFront.rotation(vex::rotationUnits::deg))<std::abs(distance)){
        setDrivePower(-power*direction, power*direction);
    }
    setDrivePower(0,0);
}

/*---------------------------------------------------------------------------*/
/*                       Autonomous Intake Functions                         */
/*---------------------------------------------------------------------------*/
void setIntakeLeftPower (int power){
    if(power==0) intakeLeft.stop(vex::brakeType::coast);
    else{
        intakeLeft.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}
void setIntakeRightPower (int power){
    if(power==0) intakeRight.stop(vex::brakeType::coast);
    else{
        intakeRight.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}
void setIntakePower (int left, int right){
    setIntakeLeftPower(left);
    setIntakeRightPower(right);
}

void autoIn(int rotations, int power = 100){
    int direction = sgn(rotations);
        
    intakeLeft.resetRotation();
    intakeRight.resetRotation();
    
    while(std::abs(intakeLeft.rotation(vex::rotationUnits::deg))<std::abs(rotations)){
        setIntakePower(power*direction, power*direction);
    }
    setIntakePower(0,0);
}

/*---------------------------------------------------------------------------*/
/*                      Autonomous Puncher Functions                         */
/*---------------------------------------------------------------------------*/
void setPuncherLeftPower (int power){
    if(power==0) puncherLeft.stop(vex::brakeType::coast);
    else{
        puncherLeft.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}
void setPuncherRightPower (int power){
    if(power==0) puncherRight.stop(vex::brakeType::coast);
    else{
        puncherRight.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}
void setPuncherPower (int left, int right){
    setPuncherLeftPower(left);
    setPuncherRightPower(right);
}

void autoShoot(int rotations = 360, int power = 100){
    int direction = sgn(rotations);
        
    puncherLeft.resetRotation();
    puncherRight.resetRotation();
    
    while(std::abs(puncherLeft.rotation(vex::rotationUnits::deg))<std::abs(rotations)){
        setPuncherPower(power*direction, power*direction);
    }
    setPuncherPower(0,0);
}