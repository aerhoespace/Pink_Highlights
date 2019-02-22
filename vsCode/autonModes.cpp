/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Modes                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                          11 Point Skills Autonomous                       */
/*---------------------------------------------------------------------------*/
void auton11(){ // Old but works
// Start on back tile
    // Pull puncher back halfway
    pullBack();
    // Drive forward to hit cap (+1)
    autoDrive(1230);
    // Intake ball partly
    autoIn(100);
    // Drive back
    autoDrive(-1080);
    vex::task::sleep(20);
    // Drive back more
    autoDrive(-130,20);
    // Forward slightly
    autoDrive(150,40);
    // Turn left to face flags
    autoTurn(187);
    vex::task::sleep(200);
    // Drive forward
    autoDrive(1340,90);
    vex::task::sleep(100);
    // More forward
    autoDrive(170,25);
    // Shoot top flag (+2)
    autoShoot();
    // Drive forward slightly
    autoDrive(425);
    vex::task::sleep(100);
    // Intake ball
    autoIn(400);
    vex::task::sleep(100);
    // Shoot middle flag (+2)
    autoShoot();
    vex::task::sleep(20);
    // Back up
    autoDrive(-1255);
    vex::task::sleep(200);
    // Turn right
    autoTurn (-280);
    vex::task::sleep(200);
    // Back up
    autoDrive(-250,35);
    vex::task::sleep(200);
    // Drive onto alliance platform
    autoDrive(2000,100); 
    // Intake ball
    autoIn(100);
    // Drive onto center platform
    autoDrive(1060);
}

/*---------------------------------------------------------------------------*/
/*                            23 Point Autonomous                            */
/*---------------------------------------------------------------------------*/
void auton23(){
// Back tile
    // Back cap + ball (+1) //good
    /*pullBack();
    driveRamp(950,100);
    autoIn(200);
    driveRamp(-1190,60,300);
    vex::task::sleep(200);
    driveRamp(65,70,70);
    rampTurn(-7.5);
    vex::task::sleep(100);
    driveRamp(-390);
    vex::task::sleep(100);
    // High + middle flags (first row) (+4) //good
    driveRamp(1520,100,500);
    rampTurn(1); //keeps straight
    autoShoot();
    driveRamp(220);
    autoIn(500);
    rampTurn(-0.5);
    vex::task::sleep(100);
    autoShoot();
    // Front cap + ball (+1) //good
    driveRamp(-350);
    rampTurn(9.3);
    vex::task::sleep(100);
    driveRamp(-250,50);
    driveRamp(950,100);
    autoIn(600);
    vex::task::sleep(200);
    // Top + bottom flag (sometimes middle flag) (second row) (+3(5)) //good
    driveRamp(-30);
    rampTurn(-10.4);
    driveRamp(40);
    autoIn(500);
    vex::task::sleep(200);
    autoShoot();
    rampTurn(-0.75);
    autoIntake(true,true);
    driveRamp(910);
    driveRamp(-300,50);
    autoIntake(false,false);
    vex::task::sleep(100);
    rampTurn(1.37);
    autoShoot();
    // Cap + front cap + ball (+2) 
    driveRamp(-30,50);
    rampTurn(8.6);
    autoIntake(true,false);
    driveRamp(1100,100);
    autoIntake(false,false);
    vex::task::sleep(100);
    driveRamp(-200,50);
    rampTurn(9.50);
    driveRamp(400);
    rampTurn(13);
    vex::task::sleep(100);
    driveRamp(200,100);
    autoIn(200);
    autoIntake(true,true);
    driveRamp(-1250,60,300);
    autoIntake(false,false);
    vex::task::sleep(100);*/
    // Back cap + ball (+1)
    driveRamp(60);
    rampTurn(-8.6);
    /*driveRamp(1600,100);
    vex::task::sleep(200);
    driveRamp(-330);
    vex::task::sleep(200);*/
    driveRamp(1100);
    rampTurn(12);
    driveRamp(-150);
    driveRamp(950,100);
    autoIn(200);
    driveRamp(-1300,60,300);
    //vex::task::sleep(200);
    // High + middle + bottom flags (third row) (+5)
    driveRamp(60);
    rampTurn(12);
    //driveRamp(-450);
    //vex::task::sleep(100);
    driveRamp(1000);
    vex::task::sleep(100);
    rampTurn(-8.18);
    driveRamp(-200,50);
    driveRamp(400);
    rampTurn(13.25);
    driveRamp(40);
    autoShoot();
    autoIntake(true,true);
    driveRamp(220);
    autoIntake(false,false);
    autoShoot();
    rampTurn(-1);
    driveRamp(600);
    // Center park (+6)
    // Total score (if perfect) = 23 (with a small chance of 25)
}

/*---------------------------------------------------------------------------*/
/*                        6 Point Front Red Autonomous                       */
/*---------------------------------------------------------------------------*/
void auton6(){ // Old
// Start facing cap
    // Pull puncher back halfway
    pullBack();
    // Drive forward to hit cap (+1)
    autoDrive(1070,100);
    // Intake ball
    autoIn(100);
    // Drive back to starting position
    autoDrive(-1125);
    // Pause for a short amount of time
    vex::task::sleep(500);
    // Come forward slightly
    autoDrive(100);
    // Pause for a short amount of time
    vex::task::sleep(200);
    // Turn left to face flags (under 90deg)
    autoTurn(253);
    // Pause for a short amount of time
    vex::task::sleep(200);
    // Drive forward slightly
    autoDrive(58);
    // Shoot top flag (+2)
    autoShoot();
    // Drive forward slightly
    autoDrive(570);
    // Intake ball
    autoIn(400);
    vex::task::sleep(100);
    // Shoot middle flag (+2)
    autoShoot();
    // Turn left slightly
    autoTurn(1,30);
    // Drive forward to hit bottom flag (+1)
    autoDrive(800);
    // Intake ball
    autoIn(500);
}

/*---------------------------------------------------------------------------*/
/*                       6 Point Front Blue Autonomous                       */
/*---------------------------------------------------------------------------*/
void auton6(){ // Old
// Start facing cap
    // Pull puncher back halfway
    pullBack();
    // Drive forward to hit cap (+1)
    autoDrive(1045,100);
    // Intake ball
    autoIn(100);
    // Drive back to starting position
    autoDrive(-1125);
    // Pause for a short amount of time
    vex::task::sleep(500);
    // Come forward slightly
    autoDrive(100);
    // Pause for a short amount of time
    vex::task::sleep(200);
    // Turn right to face flags (under 90deg)
    autoTurn(-270);
    // Pause for a short amount of time
    vex::task::sleep(200);
    // Drive forward slightly
    autoDrive(58);
    // Shoot top flag (+2)
    autoShoot();
    // Drive forward slightly
    autoDrive(570);
    // Intake ball
    autoIn(400);
    vex::task::sleep(100);
    // Shoot middle flag (+2)
    autoShoot();
    // Turn right slightly
    autoTurn(-7,30);
    // Drive forward to hit bottom flag (+1)
    autoDrive(800);
    // Intake ball
    autoIn(500);
}

/*---------------------------------------------------------------------------*/
/*                        4 Point Back Red Autonomous                        */
/*---------------------------------------------------------------------------*/
void autonR(){
    // Back cap + ball (+1)
    autoIntake(true,true);
    driveRamp(1100);
    autoIntake(false,false);
    // Platform (+3)
    driveRamp(-40;
    rampTurn(-12);
    autoDrive(1150,100);
    autonLock();
}

/*---------------------------------------------------------------------------*/
/*                        4 Point Back Red Autonomous                        */
/*---------------------------------------------------------------------------*/
void auton4(){ // Old but works
// Start facing cap
    // Pull puncher back halfway
    pullBack();
    // Drive forward to hit cap (+1)
    autoDrive(1065,100);
    vex::task::sleep(100);
    // Intake ball
    autoIn(110);
    // Turn left to face platform
    autoTurn(250);
    // Drive forward onto platform (+3)
    autoDrive(1100,100);
}

/*---------------------------------------------------------------------------*/
/*                        4 Point Back Blue Autonomous                       */
/*---------------------------------------------------------------------------*/
void autonR(){
    // Back cap + ball (+1)
    autoIntake(true,true);
    driveRamp(1100);
    autoIntake(false,false);
    // Platform (+3)
    driveRamp(-40);
    rampTurn(13);
    autoDrive(1150,100);
    autonLock();
}

/*---------------------------------------------------------------------------*/
/*                        4 Point Back Blue Autonomous                       */
/*---------------------------------------------------------------------------*/
void auton4(){ // Old but works
// Start facing cap
    // Pull puncher back halfway
    pullBack();
    // Drive forward to hit cap (+1)
    autoDrive(1070,100);
    vex::task::sleep(100);
    // Intake ball
    autoIn(120);
    // Turn right to face platform
    autoTurn(-265);
    // Drive forward onto platform (+3)
    autoDrive(1200,100);
}

/*---------------------------------------------------------------------------*/
/*                         9 Point Epic Red Autonomous                       */
/*---------------------------------------------------------------------------*/
void auton9(){ // Old
// Start facing cap
    // Pull puncher back halfway
    pullBack();
    // Drive forward to hit cap (+1)
    autoDrive(1055,100);
    // Intake ball
    autoIn(100);
    // Drive back to starting position
    autoDrive(-1125);
    vex::task::sleep(200);
    // Back more
    autoDrive(30,30);
    // Pause for a short amount of time
    vex::task::sleep(500);
    // Come forward slightly
    autoDrive(90);
    // Pause for a short amount of time
    vex::task::sleep(200);
    // Turn left to face flags (under 90deg)
    autoTurn(245);
    // Pause for a short amount of time
    vex::task::sleep(200);
    // Drive forward slightly
    autoDrive(70);
    // Shoot top flag (+2)
    autoShoot();
    // Drive forward slightly
    autoDrive(580);
    // Intake ball
    autoIn(400);
    vex::task::sleep(100);
    // Shoot middle flag (+2)
    autoShoot();
    // Turn left slightly
    autoTurn(4,30);
    // Drive forward to hit bottom flag (+1)
    autoDrive(800);
    // Intake ball
    autoIn(500);
    // Drive Back
    autoDrive(-1970);
    vex::task::sleep(100);
    // Turn right to face platform
    autoTurn(-250);
    vex::task::sleep(100);
    // Drive back
    autoDrive(-70,40);
    vex::task::sleep(100);
    // Park on platform (+3)
    autoDrive(1200);
}

/*---------------------------------------------------------------------------*/
/*                            Epic Blue Autonomous                           */
/*---------------------------------------------------------------------------*/
void auton9(){ // Old
// Start facing cap
    // Pull puncher back halfway
    pullBack();
    // Drive forward to hit cap (+1)
    autoDrive(1053,100);
    // Intake ball
    autoIn(100);
    // Drive back to starting position
    autoDrive(-1125);
    // Pause for a short amount of time
    vex::task::sleep(500);
    // Come forward slightly
    autoDrive(90);
    // Pause for a short amount of time
    vex::task::sleep(200);
    // Turn right to face flags (under 90deg)
    autoTurn(-275);
    // Pause for a short amount of time
    vex::task::sleep(200);
    // Drive forward slightly
    autoDrive(58);
    // Shoot top flag (+2)
    autoShoot();
    // Drive forward slightly
    autoDrive(570);
    // Intake ball
    autoIn(400);
    vex::task::sleep(100);
    // Forward against wall to straighten out
    autoDrive(50);
    // Shoot middle flag (+2)
    autoShoot();
    // Turn right slightly
    autoTurn(-7,30);
    // Drive forward to hit bottom flag (+1)
    autoDrive(800);
    // Intake ball
    autoIn(500);
    // Drive Back
    autoDrive(-1900);
    // Turn left to face platform
    autoTurn(315);
    // Drive back
    autoDrive(-50);
    // Park on platform (+3)
    autoDrive(2000);
}