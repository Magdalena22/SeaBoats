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
            operationMode = MANUAL;
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
            case AUTONOMIC_MODE:
            goforward(speed);
            operationMode = GOING_FORWARD;
        }
    }
    
    // check sensor at INTERVAL
    unsigned long currentMilis = millis();
    if(currentMilis - previousMilis > CHECK_INTERVAL)
    {
        previousMilis = currentMilis;
        
        // detect obstacles
        echo = getDistance(ultr_L);
        if (echo)
        {
            obstacleL = true;
            Serial.print("*L:\t" + String(echo) + "\n");
        }
        echo = getDistance(ultr_R);
        if (echo)
        {
            obstacleR = true;
            Serial.print("*R:\t" + String(echo) + "\n");   
        }

        if (obstacleL || obstacleR)
        {
            // turn to avoid obstacle
            switch(operationMode)
            {
                case MANUAL:
                case STOPPED:
                case GOING_BACKWARD:
                case TURNING_L:
                case TURNING_R:
                break;
                case GOING_FORWARD:
                if (obstacleL)
                {
                    goright(speed);
                    operationMode = TURNING_R;
                }
                else
                {
                    goleft(speed);
                    operationMode = TURNING_L;
                }
                break;
            }
        }
        else
        {
            // no obstacles - go forward
            switch(operationMode)
            {
                case MANUAL:
                case STOPPED:
                case GOING_FORWARD:
                case GOING_BACKWARD:
                break;
                case TURNING_L:
                goforward(speed);
                operationMode = GOING_FORWARD;
                break;
                case TURNING_R:
                goforward(speed);
                operationMode = GOING_FORWARD;
                break;
            }
        }
    }
}
