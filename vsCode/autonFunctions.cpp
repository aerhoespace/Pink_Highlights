/*---------------------------------------------------------------------------*/
/*                           Autonomous Functions                            */
/*---------------------------------------------------------------------------*/

double sgn(double number){
    if (number > 0) number = 1;
    else number = -1;
    return number;
}

void setLeftFrontPower (int power){
    if(power==0) leftFront.stop(vex::brakeType::coast);
    else{
        leftFront.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}
void setLeftBackPower (int power){
    if(power==0) leftBack.stop(vex::brakeType::coast);
    else{
        leftBack.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}
void setRightFrontPower (int power){
    if(power==0) rightFront.stop(vex::brakeType::coast);
    else{
        rightFront.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}
void setRightBackPower (int power){
    if(power==0) rightBack.stop(vex::brakeType::coast);
    else{
        rightBack.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}

void setDrivePower (int left, int right){
    setRightBackPower(right);
    setRightFrontPower(right);
    setLeftBackPower(left);
    setLeftFrontPower(left);
}

void autoDrive(int distance, int power = 100){
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

void autoTurn(int distance, int power = 100){
    int direction = sgn(distance);
        
    leftFront.resetRotation();
    leftBack.resetRotation();
    rightFront.resetRotation();
    rightBack.resetRotation();
    
    while(std::abs(leftFront.rotation(vex::rotationUnits::deg))<std::abs(distance)){
        setDrivePower(power*direction, -power*direction);
    }
    setDrivePower(0,0);
}