/** @file init.c
 * @brief File for initialization code
 *
 * This file should contain the user initialize() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs pre-initialization code. This function will be started in kernel mode one time while the
 * VEX Cortex is starting up. As the scheduler is still paused, most API functions will fail.
 *
 * The purpose of this function is solely to set the default pin modes (pinMode()) and port
 * states (digitalWrite()) of limit switches, push buttons, and solenoids. It can also safely
 * configure a UART port (usartOpen()) but cannot set up an LCD (lcdInit()).
 */
void initializeIO() {
}

/*
 * Runs user initialization code. This function will be started in its own task with the default
 * priority and stack size once when the robot is starting up. It is possible that the VEXnet
 * communication link may not be fully established at this time, so reading from the VEX
 * Joystick may fail.
 *
 * This function should initialize most sensors (gyro, encoders, ultrasonics), LCDs, global
 * variables, and IMEs.
 *
 * This function must exit relatively promptly, or the operatorControl() and autonomous() tasks
 * will not start. An autonomous mode selection menu like the pre_auton() in other environments
 * can be implemented in this task if desired.
 */
void initialize() {
    //initialization function code
    pros::lcd::initialize();

      //setup controller
    pros::Controller master (E_CONTROLLER_MASTER);

    //setup motors
    pros::Motor leftFront  (11, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES); //for conditions check: https://pros.cs.purdue.edu/v5/tutorials/topical/motors.html
    pros::Motor leftBack   (12, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);  //E_MOTOR_GEARSET_36 = red(100RPM),	E_MOTOR_GEARSET_18 == green(200 RPM), E_MOTOR_GEARSET_06 = blue(600 RPM) for more see: https://pros.cs.purdue.edu/v5/api/c/motors.html#motor-gearset-e-t
    pros::Motor rightFront (13, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
    pros::Motor rightBack  (14, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
    pros::Motor puncher    (15, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
    pros::Motor intake     (16, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);

}
