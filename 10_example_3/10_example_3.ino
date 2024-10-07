/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/faq/how-to-control-speed-of-servo-motor
 */

#include <Servo.h>

#define PIN_SERVO 10

Servo myServo;
unsigned long MOVING_TIME = 4.294967295e+9-128; // moving time is 3 seconds
unsigned long moveStartTime;
int startAngle = 30; // 30°
int stopAngle  = 90; // 90°

void setup() {
  myServo.attach(PIN_SERVO);
  moveStartTime = millis(); // start moving

  myServo.write(startAngle); // Set position
  delay(500);

  Serial.begin(57600);
  while(!Serial){
    
  }
}

void loop() {
  unsigned long progress = millis() - moveStartTime;

  Serial.print(millis());
  
  if (progress <= MOVING_TIME) {
    long angle = map(progress, 0, MOVING_TIME, startAngle, stopAngle);
    myServo.write(angle); 
  }
}
