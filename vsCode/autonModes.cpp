/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Modes                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                       11 Point Skills Autonomous                          */
/*---------------------------------------------------------------------------*/

void auton11(){
// Start on back tile (use auton aligner against right side of bot and post holder)
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
    autoDrive(150,25);
    // Back slightly
    autoDrive(-10);
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
    autoDrive(-1245);
    vex::task::sleep(200);
    // Turn right
    autoTurn (-280);
    vex::task::sleep(200);
    // Back up
    autoDrive(-250,30);
    vex::task::sleep(200);
    // Drive onto center platform (+6)
    autoDrive(3100,100); 
}

/*---------------------------------------------------------------------------*/
/*                           Front Red Autonomous                            */
/*---------------------------------------------------------------------------*/

// Start facing cap
    // Drive forward to hit cap (+1)
    autoDrive(1050);
    // Intake ball
    autoIn(100);
    // Drive back to starting position
    autoDrive(-1200);
    // Pause for a short amount of time
    vex::task::sleep(500);
    // Come forward slightly
    autoDrive(70);
    // Pause for a short amount of time
    vex::task::sleep(200);
    // Turn left to face flags (under 90deg)
    autoTurn(181);
    // Pause for a short amount of time
    vex::task::sleep(200);
    // Drive forward slightly
    autoDrive(58);
    // Shoot top flag (+2)
    autoShoot();
    // Drive forward slightly
    autoDrive(355);
    // Intake ball
    autoIn(400);
    // Shoot middle flag (+2)
    autoShoot();
    // Turn left slightly
    autoTurn(1,30);
    // Drive forward to hit bottom flag (+1)
    autoDrive(650);

/*---------------------------------------------------------------------------*/
/*                           Front Blue Autonomous                           */
/*---------------------------------------------------------------------------*/

// Start facing cap
    // Drive forward to hit cap (+1)
    autoDrive(1050);
    // Intake ball
    autoIn(100);
    // Drive back to starting position
    autoDrive(-1200);
    // Pause for a short amount of time
    vex::task::sleep(500);
    // Come forward slightly
    autoDrive(70);
    // Pause for a short amount of time
    vex::task::sleep(200);
    // Turn right to face flags (under 90deg)
    autoTurn(-181);
    // Pause for a short amount of time
    vex::task::sleep(200);
    // Drive forward slightly
    autoDrive(58);
    // Shoot top flag (+2)
    autoShoot();
    // Drive forward slightly
    autoDrive(355);
    // Intake ball
    autoIn(400);
    // Shoot middle flag (+2)
    autoShoot();
    // Turn right slightly
    autoTurn(-1,30);
    // Drive forward to hit bottom flag (+1)
    autoDrive(650);

/*---------------------------------------------------------------------------*/
/*                             Back Red Autonomous                           */
/*---------------------------------------------------------------------------*/

// Start facing cap
    // Drive forward to hit cap (+1)
    autoDrive(1050);
    // Intake ball partly
    autoIn(100);
    // Drive back slightly
    autoDrive(-100);
    // Turn left to face platform
    autoTurn(181);
    // Drive forward onto platform (+3)
    autoDrive(300,100);

/*---------------------------------------------------------------------------*/
/*                            Back Blue Autonomous                           */
/*---------------------------------------------------------------------------*/

// Start facing cap
    // Drive forward to hit cap (+1)
    autoDrive(1050);
    // Intake ball partly
    autoIn(100);
    // Drive back slightly
    autoDrive(-100);
    // Turn right to face platform
    autoTurn(-181);
    // Drive forward onto platform (+3)
    autoDrive(300,100);

/*---------------------------------------------------------------------------*/
/*                             Epic Red Autonomous                           */
/*---------------------------------------------------------------------------*/

// Start facing cap
    // Drive forward to hit cap (+1)
    autoDrive(1050);
    // Intake ball
    autoIn(100);
    // Drive back to starting position
    autoDrive(-950);
    // Turn left to face flags (under 90deg)
    autoTurn(181);
    // Drive forward slightly
    autoDrive(58);
    // Shoot top flag (+2)
    autoShoot();
    // Drive forward slightly
    autoDrive(355);
    // Intake ball
    autoIn(400);
    // Shoot middle flag (+2)
    autoShoot();
    // Turn left slightly
    autoTurn(5);
    // Drive forward to hit bottom flag (+1)
    autoDrive(400);
    // Turn right to straighten out
    autoTurn(-10);
    // Drive backwards to platform
    autoDrive(-1200);
    // Turn right
    autoTurn(-200);
    // Drive forward onto platform (+3)
    autoDrive(400,100);

/*---------------------------------------------------------------------------*/
/*                            Epic Blue Autonomous                           */
/*---------------------------------------------------------------------------*/

// Start facing cap
    // Drive forward to hit cap (+1)
    autoDrive(1050);
    // Intake ball
    autoIn(100);
    // Drive back to starting position
    autoDrive(-950);
    // Turn right to face flags (under 90deg)
    autoTurn(-181);
    // Drive forward slightly
    autoDrive(58);
    // Shoot top flag (+2)
    autoShoot();
    // Drive forward slightly
    autoDrive(355);
    // Intake ball
    autoIn(400);
    // Shoot middle flag (+2)
    autoShoot();
    // Turn right slightly
    autoTurn(-5);
    // Drive forward to hit bottom flag (+1)
    autoDrive(400);
    // Turn left to straighten out
    autoTurn(10);
    // Drive backwards to platform
    autoDrive(-1200);
    // Turn left
    autoTurn(200);
    // Drive forward onto platform (+3)
    autoDrive(400,100);