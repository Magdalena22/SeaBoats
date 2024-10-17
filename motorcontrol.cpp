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

void goforward(int speed){
    front_right.setSpeed(speed);
    // front_left.setSpeed(speed);
    // rear_right.setSpeed(speed);
    // rear_left.setSpeed(speed);
    Serial.println("going forward");
}

void gobackward(int speed){
    // front_right.setSpeed(-speed);
    front_left.setSpeed(speed);
    // rear_right.setSpeed(-speed);
   1 // rear_left.setSpeed(-speed);
    Serial.println("going backward");
}

void goright(int speed){
    // front_right.setSpeed(speed);
    // front_left.setSpeed(-speed);
    rear_right.setSpeed(speed);
    // rear_left.setSpeed(-speed);
    Serial.println("going right");
}

void goleft(int speed){
    // front_right.setSpeed(-speed);
    // front_left.setSpeed(speed);
    // rear_right.setSpeed(-speed);
    rear_left.setSpeed(speed);
    Serial.println("going left");
}
