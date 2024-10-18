#include "pinout.h"
#include "definitions.h"
#include "motorcontrol.h"
#include "ultrasoniccontrol.h"
#include <CytronMotorDriver.h>

const UltrasonicSensor ultr_L{ULTR_L_TRIG, ULTR_L_ECHO};
const UltrasonicSensor ultr_R{ULTR_R_TRIG, ULTR_R_ECHO};

volatile unsigned long previousMilis = 0;
volatile int speed = 100;
volatile int incomingByte = 0; // for incoming serial data 
int echo = 0; // for obstacle detection

// flags
volatile bool obstacleL = false;
volatile bool obstacleR = false;
volatile Mode operationMode = MANUAL;

void setup() {
    noInterrupts();

    Serial.begin(9600); //Communication start
    interrupts();
}


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
            case CHANGE_SPEED_FASTER:
            speed += SPEED_INCREMENT;
            if (speed > MAX_SPEED)
            {
                speed = MAX_SPEED;
            }
            break;
            case CHANGE_SPEED_SLOWER:
            speed -= SPEED_INCREMENT;
            if (speed < MIN_SPEED)
            {
                speed = MIN_SPEED;
            }
            break;
        }
    }
    
    // check sensor at INTERVAL
    unsigned long currentMilis = millis();
    if(currentMilis - previousMilis > CHECK_INTERVAL)
    {
        previousMilis = currentMilis;
        
        echo = getDistance(ultr_L);
        Serial.print("*L:\t" + String(echo) + "\n");
        echo = getDistance(ultr_R);
        Serial.print("*R:\t" + String(echo) + "\n");   
    }
}
