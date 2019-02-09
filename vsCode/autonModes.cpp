/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Modes                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                          11 Point Skills Autonomous                       */
/*---------------------------------------------------------------------------*/
void auton11(){ // Perfected
// Start on back tile (use auton aligner against right side of bot and post holder)
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
/*                        15 Point Skills Autonomous                         */
/*---------------------------------------------------------------------------*/
void auton15(){ // Needs more testing
// Start on back tile (use auton aligner against right side of bot and post holder)
    // Pull puncher back halfway
    pullBack();
    // Drive forward to hit cap (+1)
    autoDrive(1230);
    // Intake ball partly
    autoIn(60);
    // Drive back
    autoDrive(-1080);
    vex::task::sleep(20);
    // Drive back more
    autoDrive(-130,20);
    // Forward slightly
    autoDrive(150,40);
    // Turn left to face flags
    autoTurn(186);
    vex::task::sleep(200);
    // Drive forward
    autoDrive(1325,90);
    vex::task::sleep(100);
    // More forward
    autoDrive(100,25);
    // Shoot top flag (+2)
    autoShoot();
    // Drive forward slightly
    autoDrive(530);
    vex::task::sleep(10);
    // Intake ball
    autoIn(400);
    vex::task::sleep(10);
    // Shoot middle flag (+2)
    autoShoot();
    vex::task::sleep(20);
    // Back up
    autoDrive(-650);
    vex::task::sleep(200);
    // Turn right
    autoTurn (-285);
    vex::task::sleep(200);
    // Back up
    autoDrive(-250,35);
    vex::task::sleep(200);
    // Drive forward to hit cap (+1)
    autoDrive(1400);
    // Intake ball
    autoIn(200);
    // Back slightly
    autoDrive(-2);
    // Intake ball
    autoIn(500);
    // Turn left to face flags
    autoTurn(160);
    // Drive forward
    autoDrive(60);
    // Shoot top flag
    autoShoot();
    vex::task::sleep(100);
    // Turn left to straighten out
    autoTurn(1,50);
    // Drive forward to hit bottom flag
    autoDrive(1300);
    // Intake ball
    autoIn(200);
    // Forward slightly
    autoDrive(10,30);
    vex::task::sleep(100);
    // Drive back
    autoDrive(-1250);
    vex::task::sleep(100);
    // Trun right
    //autoTurn(-270);
    //vex::task::sleep(100);
}

/*---------------------------------------------------------------------------*/
/*                        21 Point Skills Autonomous                         */
/*---------------------------------------------------------------------------*/
void auton21(){ // Incomplete
    // Start on back tile (use auton aligner against right side of bot and post holder)
    // Pull puncher back halfway
    pullBack();
    // Drive forward to hit cap (+1)
    autoDrive(1240);
    // Intake ball partly
    autoIn(60);
    // Drive back
    autoDrive(-1090);
    vex::task::sleep(20);
    // Drive back more
    autoDrive(-110,15);
    // Forward slightly
    autoDrive(125,40);
    vex::task::sleep(200);
    // Turn left to face flags
    autoTurn(270,55);
    vex::task::sleep(200);
    // Drive forward
    autoDrive(1300,80);
    vex::task::sleep(100);
    // More forward
    autoDrive(130,25);
    vex::task::sleep(100);
    // Right slightly
    autoTurn(-1);
    // Shoot top flag (+2)
    autoShoot();
    // Drive forward slightly
    autoDrive(490);
    vex::task::sleep(100);
    // Intake ball
    autoIn(500);
    vex::task::sleep(100);
    // Shoot middle flag (+2)
    autoShoot();
    vex::task::sleep(20);
    // Left slightly
    autoTurn(2,55);
    vex::task::sleep(500);
    // Forward slightly
    autoDrive(200);
    vex::task::sleep(100);
    // Right slighty
    autoTurn(-5);
    // More forward to hit bottom flag (+1)
    autoDrive(450,50);
    // Intake ball
    autoIn(1000);
    // Forward to straighten out
    autoDrive(20,30);
    // Back up
    autoDrive(-1300);
    vex::task::sleep(200);
    // Turn right
    autoTurn (-285);
    vex::task::sleep(200);
    // Back up
    autoDrive(-280,35);
    vex::task::sleep(200);
    // Drive forward to hit cap (+1)
    autoDrive(1400);
    // Intake ball
    autoIn(200);
    // Back slightly
    autoDrive(-2);
    // Turn left to face flags
    autoTurn(248);
    // Drive forward
    autoDrive(60);
    // Shoot top flag (+2)
    autoShoot();
    // Drive forward
    autoDrive(450);
    // Intake ball
    autoIn(400);
    vex::task::sleep(100);
    // Shoot middle flag (+2)
    autoShoot();
    // Turn left to straighten out
    autoTurn(7);
    // Drive forward to hit bottom flag (+1);
    autoDrive(525);
    // Intake ball
    autoIn(1000);
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