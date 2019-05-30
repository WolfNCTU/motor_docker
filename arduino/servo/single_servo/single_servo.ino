/*
single_servo.ino

Author     : Wolf Chen
Date       : 2019/05/25
Description: This code can control a single servo with serial port.

What you need to prepare:
1. Arduino board
2. Servo motor
3. External power supply (if needed)

Tested material:
1. Arduino UNO
2. Servo MG996R

Input:
Angle/Angular velocity

Output:
None
*/

#include <Servo.h>
#include <math.h>

// define your servo name here
Servo servo1;

// set the initial state for the servo
int state      = 90;
// set the pin for your servo *please set it to the pin witch is PWM enable
int servo1_pin = 3;
// set the mininum and maxinum bandwidth
int min_band   = 500;
int max_band   = 2500;
//set the baud rate for serial port
int baud_rate  = 9600;

// setup both servo and serial port
void setup(){
  // setup serial port
  Serial.begin(baud_rate);

  // setup servo
  // Servo.attach(pin, min_bandwidth = 544, max_bandwidth = 2400)
  servo1.attach(servo1_pin, min_band, max_band);
  // initialize the velocity of the motor
  servo1.write(state);

  Serial.print("Initializing...\n");
}

void loop(){
  // request a value for servo
  Serial.print("Please import a number between 0~180\n");
  Serial.print("Import 90 to halt the servo\n\n");
  while (Serial.available() <= 0);
  if (Serial.available() > 0){
    // read data from serial port
    int value = Serial.parseInt();

    if (value >= 0 && value <= 180){
      Serial.println("Your imoprted number is:\t");
      Serial.println(value);
      Serial.println("\n");
      int diff = value - state;
        if (diff > 0){
          for (int i = 0; i < diff; i++){
            servo1.write(state + i);
            delay(15);
          }
        }
        if (diff < 0){
          for (int i = 0; i > diff; i--){
            servo1.write(state + i);
            delay(15);
          }
        }
      state = value;
    }
    else {
      Serial.print("The number is not between 1~180/n");
    }
  }  
}
