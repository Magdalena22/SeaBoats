#include "pinout.h"
#include "definitions.h"
#include "motorcontrol.h"
#include "CytronMotorDriver.h"
#include <ST_HW_HC_SR04.h>

volatile ST_HW_HC_SR04 ultr_L(ULTR_L_TRIG, ULTR_L_ECHO);

volatile unsigned long previousMilis = 0;
volatile int speed = 100;
volatile int incomingByte = 0; // for incoming serial data 
int echo = 0;

void setup() {
    noInterrupts();
  
    Serial.begin(9600); //Communication start

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
    
    // check sensor at INTERVAL
    unsigned long currentMilis = millis();
    if(currentMilis - previousMilis > CHECK_INTERVAL)
    {
        previousMilis = currentMilis;
        echo = ultr_L.getHitTime();      
        if(echo)
        {
            Serial.print("*L:\t" + String(echo) + "\t*");
        }      
    }
}
