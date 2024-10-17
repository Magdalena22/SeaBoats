// motor control functions

#include "motorcontrol.h"
#include "pinout.h"
#include "CytronMotorDriver.h"

// Configure the motor driver.
CytronMD motor1(PWM_DIR, PWM_PIN_M1, DIR_PIN_M1);
CytronMD motor2(PWM_DIR, PWM_PIN_M2, DIR_PIN_M2);

void stop(){
    motor1.setSpeed(0);     // Motor 1 stops.
    motor2.setSpeed(0);     // Motor 2 stops.
    Serial.println("stopped");
}

void goforward(int speed){
    motor1.setSpeed(speed);
    motor2.setSpeed(speed);
    Serial.println("going forward");
}

void gobackward(int speed){
    motor1.setSpeed(-speed);
    motor2.setSpeed(-speed);
    Serial.println("going backward");
}

void goright(int speed){
    motor1.setSpeed(speed);
    motor2.setSpeed(-speed);
    Serial.println("going right");
}

void goleft(int speed){
    motor1.setSpeed(-speed);
    motor2.setSpeed(speed);
    Serial.println("going left");
}
