// /*******************************************************************************
//  * THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTY AND SUPPORT
//  * IS APPLICABLE TO THIS SOFTWARE IN ANY FORM. CYTRON TECHNOLOGIES SHALL NOT,
//  * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR CONSEQUENTIAL
//  * DAMAGES, FOR ANY REASON WHATSOEVER.
//  ********************************************************************************
//  * DESCRIPTION:
//  *
//  * This example shows how to drive 2 motors using 4 PWM pins (2 for each motor)
//  * with 2-channel motor driver.
//  * 
//  * 
//  * CONNECTIONS:
//  * 
//  * Arduino D3  - Motor Driver PWM 1A Input
//  * Arduino D9  - Motor Driver PWM 1B Input
//  * Arduino D10 - Motor Driver PWM 2A Input
//  * Arduino D11 - Motor Driver PWM 2B Input
//  * Arduino GND - Motor Driver GND
//  *
//  *
//  * AUTHOR   : Kong Wai Weng
//  * COMPANY  : Cytron Technologies Sdn Bhd
//  * WEBSITE  : www.cytron.io
//  * EMAIL    : support@cytron.io
//  *
//  *******************************************************************************/

//  #include "CytronMotorDriver.h"


// // Configure the motor driver.
// CytronMD motor1(PWM_PWM, 3, 9);   // PWM 1A = Pin 3, PWM 1B = Pin 9.
// CytronMD motor2(PWM_PWM, 10, 11); // PWM 2A = Pin 10, PWM 2B = Pin 11.

// char key;


// // The setup routine runs once when you press reset.
// void setup() {
//   Serial.begin( 9600 ); 
// }

// void loop() {
//   char key;
//   if(Serial.available() > 0){
    
//     key = Serial.read();
//     Serial.print(key);
    
//   }

//   if(key == 'w'){
//     forward();
//   }else if( key == 's'){
//     backward();
//   }else if( key == 'd'){
//     turn_right();
//   }else if( key == 'a'){
//     turn_left();
//   }else if( key == 'c'){
//     stop();
//   }
// }



// void forward() {
//   motor1.setSpeed(128);   // Motor 1 runs forward at 50% speed.
//   motor2.setSpeed(128);  // Motor 2 runs backward at 50% speed.
//   Serial.print("forward");
// }

// void backward(){
//   motor1.setSpeed(-128);   // Motor 1 runs forward at 50% speed.
//   motor2.setSpeed(-128);  // Motor 2 runs backward at 50% speed.
//   Serial.print("backward");
// }

// void turn_right(){
//   motor1.setSpeed(128);   // Motor 1 runs forward at 50% speed.
//   motor2.setSpeed(-128);  // Motor 2 runs backward at 50% speed.
//   Serial.print("turn_right");
// }

// void turn_left(){
//   motor1.setSpeed(-128);   // Motor 1 runs forward at 50% speed.
//   motor2.setSpeed(128);  // Motor 2 runs backward at 50% speed.
//   Serial.print("turn_left");
// }

// void stop(){
//   motor1.setSpeed(0);   // Motor 1 runs forward at 50% speed.
//   motor2.setSpeed(0);  // Motor 2 runs backward at 50% speed.
//   Serial.print("stop");
// }
