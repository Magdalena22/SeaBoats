#include "pinout.h"
#include "definitions.h"
#include "motorcontrol.h"
#include "CytronMotorDriver.h"

volatile int speed = 100;
volatile int incomingByte = 0; // for incoming serial data 

void setup() {
    noInterrupts();
  
    Serial.begin(9600); //Communication start

    // // Configure the motor driver.
    // CytronMD motor1(PWM_DIR, PWM_PIN_M1, DIR_PIN_M1);
    // CytronMD motor2(PWM_DIR, PWM_PIN_M2, DIR_PIN_M2);
    
    // timer configuration
  
    interrupts();
}

// interrupt communication - set proper timer -check what's in lib
// ISR(TIMER5_COMPA_vect) {
void loop() {

    if(Serial.available() > 0) {
        incomingByte = Serial.read();
        //Serial.println(incomingByte);
        switch(incomingByte) {
            case STOP:
            stop();
            break;
            case GOFORWARD:
            goforward(speed);
            break;
            case GOBACK:
            gobackward(speed);
            break;
            case GOLEFT:
            goleft(speed);
            break;
            case GORIGHT:
            goright(speed);
            break;
            case GODIAGONALRIGHT:
            godiagonalright(speed);
            break;
            case GODIAGONALLEFT:
            godiagonalleft(speed);
            break;
            case GODIAGONALBACKRIGHT:
            godiagonalbackright(speed);
            break;
            case GODIAGONALBACKLEFT:
            godiagonalbackleft(speed);
            break;
            case TURNRIGHT:
            turnright(speed);
            break;
            case TURNLEFT:
            turnleft(speed);
            break;
            
        }
    }
}
