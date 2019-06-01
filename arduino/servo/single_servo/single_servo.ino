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

int motor_type = 0;
int time = 0;

// setup both servo and serial port
void setup(){
  // setup serial port
  Serial.begin(baud_rate);

  Serial.print("Initializing...\nPlease set your baud rate to ");
  Serial.print(baud_rate);
  Serial.print("\n");

  // setup servo
  // Servo.attach(pin, min_bandwidth = 544, max_bandwidth = 2400)
  servo1.attach(servo1_pin);
  // initialize the velocity of the motor
  servo1.write(state);
/*
  Serial.print("Please define your servo type\nIf you use an angle-controllable servo, enter 0\nIf you use a velocity-controllable servo, enter1");
  motor_type = Serial.read();
  Serial.println(motor_type);
*/
  Serial.print("Done\n\n");
}

void loop(){
  // request a value for servo
  Serial.print("Please import a number between 0~180\n");
  Serial.print("Import 90 to halt the servo\n\n");
  while (Serial.available() <= 0);

  if (motor_type == 1){
    // request a valeu for time
    Serial.print("Please enter your rotating time\n");
    time = Serial.parseInt();
  }
  
  if (Serial.available()){
    // read data from serial port
    int value = Serial.parseInt();

    if (value >= 0 && value <= 180){
      Serial.println("Your imoprted number is:\t");
      Serial.println(value);
      Serial.println("\n");
      int diff = value - state;
        if (diff > 0){
          for (int i = 0; i < (diff + 1); i++){
            servo1.write(state + i);
            delay(15);
          }
        }
        if (diff < 0){
          for (int i = 0; i > (diff - 1); i--){
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
