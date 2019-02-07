/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Modes                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                              11 Point Autonomous                          */
/*---------------------------------------------------------------------------*/
void auton11(){ // Perfected
// Start on back tile (use auton aligner against right side of bot and post holder)
    // Pull puncher back halfway
    pullBack();
    // Drive forward to hit cap (+1)
    autoDrive(1200);
    // Intake ball partly
    autoIn(60);
    // Drive back
    autoDrive(-1050);
    vex::task::sleep(20);
    // Drive back more
    autoDrive(-130,20);
    // Forward slightly
    autoDrive(150,40);
    // Turn left to face flags
    autoTurn(187);
    vex::task::sleep(200);
    // Drive forward
    autoDrive(1370,90);
    vex::task::sleep(100);
    // More forward
    autoDrive(140,25);
    // Shoot top flag (+2)
    autoShoot();
    // Drive forward slightly
    autoDrive(420);
    // Intake ball
    autoIn(400);
    // Shoot middle flag (+2)
    autoShoot();
    vex::task::sleep(20);
    // Drive forward to hit bottom flag (+1)
    //autoDrive(600);
    // Back up
    autoDrive(-1265); // Add 600 in case of bottom flag (or whatever distance)
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
    autoDrive(1100);
}

/*---------------------------------------------------------------------------*/
/*                        14 Point Skills Autonomous                         */
/*---------------------------------------------------------------------------*/
void auton14(){ // Needs a lot of testing
// Start on back tile (use auton aligner against right side of bot and post holder)
    // Drive forward to hit cap (+1)
    autoDrive(1200);
    // Intake ball partly
    autoIn(60);
    // Drive back
    autoDrive(-1205);
    vex::task::sleep(20);
    // Forward slightly
    autoDrive(150,40);
    vex::task::sleep(20);
    // Turn left to face flags
    autoTurn(187);
    vex::task::sleep(200);
    // Drive forward
    autoDrive(1500);
    // Shoot top flag (+2)
    autoShoot();
    // Drive forward slightly
    autoDrive(400);
    // Intake ball
    autoIn(400);
    // Shoot middle flag (+2)
    autoShoot();
    vex::task::sleep(20);
    // Back up
    autoDrive(-625);
    vex::task::sleep(20);
    // Turn right to face cap
    autoTurn (-280);
    vex::task::sleep(20);
    // Drive forward to hit cap (+1)
    autoDrive(1400);
    // Intake ball partly
    autoIn(60);
    // Back slightly
    autoDrive(-100);
    // Turn left to face flags
    autoTurn(190);
    // Forward slightly
    autoDrive(70);
    // Shoot top flag
    autoShoot();
    // Back slightly
    //autoDrive(50);
    // Turn right
    autoTurn(-190);
    // Drive back
    autoDrive(-1205);
    vex::task::sleep(20);
    // Forward slightly
    autoDrive(150,40);
    vex::task::sleep(20);
    // Turn right
    autoTurn(-187);
    // Turn left to face platform
    autoTurn(187);
    // Back up
    autoDrive(-250,30);
    vex::task::sleep(20);
    // Drive onto center platform (+6)
    autoDrive(3100,100);
}

/*---------------------------------------------------------------------------*/
/*                        6 Point Front Red Autonomous                       */
/*---------------------------------------------------------------------------*/
void auton6(){ // Perfected
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
void auton6(){ // Perfected
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
void auton4(){ // Perfected
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
void auton4(){ // Perfected
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
void auton9(){ // Needs work
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
void auton9(){ // Perfected
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