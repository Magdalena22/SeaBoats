// motor control functions

#include "motorcontrol.h"
#include "pinout.h"
#include "CytronMotorDriver.h"

// Configure the motor driver.

CytronMD front_right(PWM_DIR, PWM_PIN_FR, DIR_PIN_FR);
CytronMD front_left(PWM_DIR, PWM_PIN_FL, DIR_PIN_FL);
CytronMD rear_right(PWM_DIR, PWM_PIN_RR, DIR_PIN_RR);
CytronMD rear_left(PWM_DIR, PWM_PIN_RL, DIR_PIN_RL);

void stop(){
    front_right.setSpeed(0);
    front_left.setSpeed(0);
    rear_right.setSpeed(0);
    rear_left.setSpeed(0);
    Serial.println("stopped");
}

void goforward(int speedToSet){
    front_right.setSpeed(speedToSet);
    front_left.setSpeed(speedToSet);
    rear_right.setSpeed(speedToSet);
    rear_left.setSpeed(speedToSet);
    Serial.println("going forward");
}

void gobackward(int speedToSet){
    speedToSet = speedToSet*2;
    front_right.setSpeed(-speedToSet);
    front_left.setSpeed(-speedToSet);
    rear_right.setSpeed(-speedToSet);
    rear_left.setSpeed(-speedToSet);
    Serial.println("going backward");
}

void goright(int speedToSet){
    front_right.setSpeed(-speedToSet);
    front_left.setSpeed(speedToSet);
    rear_right.setSpeed(speedToSet);
    rear_left.setSpeed(-speedToSet);
    Serial.println("going right");
}

void goleft(int speedToSet){
    front_right.setSpeed(speedToSet);
    front_left.setSpeed(-speedToSet);
    rear_right.setSpeed(-speedToSet);
    rear_left.setSpeed(speedToSet);
    Serial.println("going left");
}

void godiagonalright(int speedToSet){
    front_right.setSpeed(0);
    front_left.setSpeed(speedToSet);
    rear_right.setSpeed(speedToSet);
    rear_left.setSpeed(0);
    Serial.println("going diagonal right");
}

void godiagonalleft(int speedToSet){
    front_right.setSpeed(speedToSet);
    front_left.setSpeed(0);
    rear_right.setSpeed(0);
    rear_left.setSpeed(speedToSet);
    Serial.println("going diagonal left");
}

void godiagonalbackright(int speedToSet){
    front_right.setSpeed(-speedToSet);
    front_left.setSpeed(0);
    rear_right.setSpeed(0);
    rear_left.setSpeed(-speedToSet);
    Serial.println("going diagonal backright");
}

void godiagonalbackleft(int speedToSet){
    front_right.setSpeed(0);
    front_left.setSpeed(-speedToSet);
    rear_right.setSpeed(-speedToSet);
    rear_left.setSpeed(0);
    Serial.println("going diagonal backleft");
}

void turnright(int speedToSet){
    front_right.setSpeed(speedToSet);
    front_left.setSpeed(-speedToSet);
    rear_right.setSpeed(speedToSet);
    rear_left.setSpeed(-speedToSet);
    Serial.println("turn right");
}

void turnleft(int speedToSet){
    front_right.setSpeed(-speedToSet);
    front_left.setSpeed(speedToSet);
    rear_right.setSpeed(-speedToSet);
    rear_left.setSpeed(speedToSet);
    Serial.println("turn left");
}


