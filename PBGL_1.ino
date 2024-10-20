#include "pinout.h"
#include "definitions.h"
#include "motorcontrol.h"
#include "ultrasoniccontrol.h"
#include <CytronMotorDriver.h>

void speedChange(int speed, bool mode);

const UltrasonicSensor ultr_L{ULTR_L_TRIG, ULTR_L_ECHO};
const UltrasonicSensor ultr_R{ULTR_R_TRIG, ULTR_R_ECHO};

volatile unsigned long previousMilis = 0;
volatile int speed = FAST_SPEED;
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
            // speedChange(true);
            speed = FAST_SPEED;
            break;
            case CHANGE_SPEED_SLOWER:
            // speedChange(false);
            speed = SLOW_SPEED;
            break;
            case AUTONOMIC_MODE:
            gobackward(speed);
            operationMode = GOING_BACKWARD;
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
                case TURNING_L:
                case TURNING_R:
                case GOING_FORWARD:
                break;
                case GOING_BACKWARD:
                if (obstacleL)
                {
                    turnleft(speed);
                    operationMode = TURNING_R;
                }
                else
                {
                    turnright(speed);
                    operationMode = TURNING_L;
                }
                break;
            }

            // reset flags
            obstacleL = false;
            obstacleR = false;
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
                gobackward(speed);
                operationMode = GOING_BACKWARD;
                break;
                case TURNING_R:
                gobackward(speed);
                operationMode = GOING_BACKWARD;
                break;
            }
        }
    }
}

void speedChange(bool mode)
{
    if (mode)
    {
        // mode = true - increase
        speed += SPEED_INCREMENT;
        if (speed > MAX_SPEED)
        {
            speed = MAX_SPEED;
        }
    }
    else
    {
        // mode = false - decrease speed
        speed -= SPEED_INCREMENT;
        if (speed < MIN_SPEED)
        {
            speed = MIN_SPEED;
        }
    }

    switch (operationMode)
    {
        case GOING_BACKWARD:
        gobackward(speed);
        break;
        case TURNING_L:
        turnleft(speed);
        break;
        case TURNING_R:
        turnright(speed);
        break;
        default:
        stop();
    }
}
