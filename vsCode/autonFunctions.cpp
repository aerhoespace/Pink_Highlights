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

// Drive ramping
bool DriveRampingEnabled;

class Ramping{
    public:
    int ChangePct=1; // The amout of Pct change per loop
    int ChangeMsec=1; // The amount of time inbetween loops

    int RequestedPct=0; // Used to request Pct value change
    int Pct=0; // Pct output
    int MinUpPct=0; // Used as moveing up StillSpeed
    int MinDownPct=0; // Used as moving down StillSpeed
    int MaxPct=100; // the max pct value

    Ramping(); // Object specifer

    Ramping(int CP,int CM,int MaxP=100,int MinDP=0,int MinUP=0){
        // ChangePct,ChangeMsec,MaxPct
        ChangePct=CP;
        ChangeMsec=CM;
        MaxPct=MaxP;
        MinUpPct=MinUP;
        MinDownPct=MinDP;
    }

    void TaskRun(){
        if(RequestedPct>Pct){ // Ramp up
            Pct=Pct+ChangePct;
        }
        else if(RequestedPct<Pct){ // Ramp down
            Pct=Pct-ChangePct;
        }
        // Limit Pct
        if(Pct>MaxPct)  Pct=MaxPct;
        if(Pct<-MaxPct) Pct=-MaxPct;
        if(Pct>0 && Pct<MinUpPct) Pct=MinUpPct;
        if(Pct<0 && Pct>MinDownPct)    Pct=MinDownPct;
    }
}; // End of task

Ramping leftRamp(1,6); // First value = pct of pwr change after each interval passed
Ramping rightRamp(1,6); // Second value = number of Msec between each pct change

    int Drive_Ramping(){
        DriveRampingEnabled=true;
        while(DriveRampingEnabled){
            leftRamp.TaskRun();
            rightRamp.TaskRun();
            setDrivePower(leftRamp.Pct,rightRamp.Pct);
            vex::task::sleep(leftRamp.ChangeMsec);
        }
        return 1;
    }

void SetDRpower(int Lpower,int Rpower){ // DMR
    leftRamp.RequestedPct = Lpower;
    rightRamp.RequestedPct = Rpower;
}
void DI(int Lpower,int Rpower){
    leftRamp.RequestedPct=Lpower; // Tells ramping to run at inputed power
    rightRamp.RequestedPct=Rpower; // Use for turning
    
    leftRamp.Pct=Lpower; // Instantly changes the ramping pct to desired power instead of ramping up
    rightRamp.Pct=Rpower; // Use for turning
    setDrivePower(leftRamp.Pct,rightRamp.Pct);
}

// Drive ramping with auto straightening
void autonDriveRamp(double Distance,int Pct=100,int EndWait=250,int Correction=2){
        // Update ramping speed
        leftRamp.ChangeMsec = 6;
        rightRamp.ChangeMsec = 6;

        double Direction=sgn(Distance);
        int LPower=0;
        int RPower=0;
    
        // Clear encoder
        leftFront.resetRotation();
        leftBack.resetRotation();
        rightFront.resetRotation();
        rightBack.resetRotation();
    
        // Is it there yet?
        while(std::abs(leftFront.rotation(vex::rotationUnits::deg))<std::abs(Distance)){
            double LEncValue=leftFront.rotation(vex::rotationUnits::deg);
            double REncValue=rightBack.rotation(vex::rotationUnits::deg);
            // Straighten
            if(std::abs(LEncValue)>std::abs(REncValue)){
                LPower=Pct-Correction;
                RPower=Pct;
            }
            else if(std::abs(LEncValue)<std::abs(REncValue)){
                LPower=Pct;
                RPower=Pct-Correction;
            }
            else if(std::abs(LEncValue)==std::abs(REncValue)){
                LPower=Pct;
                RPower=Pct;
            }
            // Correct direction
            LPower=LPower*Direction;
            RPower=RPower*Direction;
            // Send to SetDRpower
            SetDRpower(LPower,RPower);
            vex::task::sleep(1);
        }
        SetDRpower(0,0);
        vex::task::sleep(EndWait);
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
void autoIntakeHalf(int rotations, int power = 100){
    int direction = sgn(rotations);
    
    intakeRight.resetRotation();
    
    while(std::abs(intakeLeft.rotation(vex::rotationUnits::deg))<std::abs(rotations)){
        setIntakePower(power*direction, power*direction);
    }
    setIntakeRightPower(0);
}

// Auto intake
void autoIntake(bool ON, bool In){
    if(ON){
        if(In){
            setIntakePower(-100);
        } 
        if(!In){
            setIntakePower(100);
        } 
    }
    if(!ON){
        intakeLeft.stop();
        intakeRight.stop();
    }
}

/*---------------------------------------------------------------------------*/
/*                      Autonomous Puncher Functions                         */
/*---------------------------------------------------------------------------*/
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

void autoShoot(int rotations = 360, int power = 100){
    int direction = sgn(rotations);
        
    puncherLeft.resetRotation();
    puncherRight.resetRotation();
    
    while(std::abs(puncherLeft.rotation(vex::rotationUnits::deg))<std::abs(rotations)){
        setPuncherPower(power*direction, power*direction);
    }
    setPuncherPower(0,0);
}
void pullBack(int rotations = 180, int power = 100){
    int direction = sgn(rotations);
        
    puncherLeft.resetRotation();
    puncherRight.resetRotation();
    
    while(std::abs(puncherLeft.rotation(vex::rotationUnits::deg))<std::abs(rotations)){
        setPuncherPower(power*direction, power*direction);
    }
    setPuncherPower(0,0);
}