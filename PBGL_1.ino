/*******************************************************************************
 * THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTY AND SUPPORT
 * IS APPLICABLE TO THIS SOFTWARE IN ANY FORM. CYTRON TECHNOLOGIES SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR CONSEQUENTIAL
 * DAMAGES, FOR ANY REASON WHATSOEVER.
 ********************************************************************************
 * DESCRIPTION:
 *
 * This example shows how to drive 2 motors using 4 PWM pins (2 for each motor)
 * with 2-channel motor driver.
 * 
 * 
 * CONNECTIONS:
 * 
 * Arduino D3  - Motor Driver PWM 1A Input
 * Arduino D9  - Motor Driver PWM 1B Input
 * Arduino D10 - Motor Driver PWM 2A Input
 * Arduino D11 - Motor Driver PWM 2B Input
 * Arduino GND - Motor Driver GND
 *
 *
 * AUTHOR   : Kong Wai Weng
 * COMPANY  : Cytron Technologies Sdn Bhd
 * WEBSITE  : www.cytron.io
 * EMAIL    : support@cytron.io
 *
 *******************************************************************************/

 #include "CytronMotorDriver.h"


// Configure the motor driver.
CytronMD front_right(PWM_PWM, 7, 6);   // PWM 1A = Pin 7, PWM 1B = Pin 6.
CytronMD front_left(PWM_PWM, 12, 11); // PWM 2A = Pin 12, PWM 2B = Pin 11.
CytronMD rear_right(PWM_PWM, 8, 9);   // PWM 1A = Pin 8, PWM 1B = Pin 9.
CytronMD rear_left(PWM_PWM, 4, 5); // PWM 2A = Pin 4, PWM 2B = Pin 5.

char key;


// The setup routine runs once when you press reset.
void setup() {
  Serial.begin( 9600 ); 
}

void loop() {
  char key;
  if(Serial.available() > 0){
    
    key = Serial.read();
    Serial.print(key);
    
  }

  if(key == 'w'){
    forward();
  }else if( key == 's'){
    backward();
  }else if( key == 'd'){
    turn_right();
  }else if( key == 'a'){
    turn_left();
  }else if( key == 'c'){
    stop();
  }
}



void forward() {
  front_right.setSpeed(128);   // front_right runs forward at 50% speed.
  front_left.setSpeed(128);  // front_left runs backward at 50% speed.
  rear_right.setSpeed(128);   // rear_right runs forward at 50% speed.
  rear_left.setSpeed(128);  // rear_left runs backward at 50% speed.
  Serial.print("forward");
}

void backward(){
  front_right.setSpeed(-128);   // front_right runs forward at 50% speed.
  front_left.setSpeed(-128);  // front_left runs backward at 50% speed.
  rear_right.setSpeed(-128);   // rear_right runs forward at 50% speed.
  rear_left.setSpeed(-128);  // rear_left runs backward at 50% speed.
  Serial.print("backward");
}

void turn_right(){
  front_right.setSpeed(128);   // front_right runs forward at 50% speed.
  front_left.setSpeed(-128);  // front_left runs backward at 50% speed.
  rear_right.setSpeed(128);   // rear_right runs forward at 50% speed.
  rear_left.setSpeed(-128);  // rear_left runs backward at 50% speed.
  Serial.print("turn_right");
}

void turn_left(){
  front_right.setSpeed(-128);   // front_right runs forward at 50% speed.
  front_left.setSpeed(128);  // front_left runs backward at 50% speed.
  rear_right.setSpeed(-128);   // rear_right runs forward at 50% speed.
  rear_left.setSpeed(128);  // rear_left runs backward at 50% speed.
  Serial.print("turn_left");
}

void stop(){
  front_right.setSpeed(0);   // front_right runs forward at 0% speed.
  front_left.setSpeed(0);  // front_left runs backward at 0% speed.
  rear_right.setSpeed(0);   // rear_right runs forward at 0% speed.
  rear_left.setSpeed(0);  // rear_left runs backward at 0% speed.
  Serial.print("stop");
}
