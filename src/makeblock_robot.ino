#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <MeMegaPi.h>

uint8_t motorSpeed = 255;
long count = 0;
char command;

int startXCoord = 0;
int startYCoord = 0;

// {x, y} there x = 1-8, y = A-H
int coords[8][8] = {
  {1, 0, 1, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 0, 1},
};

MeMegaPiDCMotor m1(PORT1B);
MeMegaPiDCMotor m2(PORT2B);
MeMegaPiDCMotor m3(PORT3B);

String motorControl(char mNum){
  switch(mNum){
    // Motor 1 instructions
    case 'q':
      Serial.println("M1 forward");
      m1.run(motorSpeed);
      delay(50);
      m1.stop();
      break;

    case 'e':
      Serial.println("M1 backward");
      m1.run(-motorSpeed);
      delay(50);
      m1.stop();
      break;

    // Motor 2 instructions
    case 'w':
      Serial.println("M2 forward");
      m2.run(motorSpeed);
      delay(50);
      m2.stop();
      break;

    case 's':
      Serial.println("M2 backward");
      m2.run(-motorSpeed);
      delay(50);
      m2.stop();
      break;
      
    // Motor 3 instructions
    case 'd':
      Serial.println("M3 forward");
      m3.run(motorSpeed);
      delay(50);
      m3.stop();
      break;

    case 'a':
      Serial.println("M3 backward");
      m3.run(-motorSpeed);
      delay(50);
      m3.stop();
      break;

    default:
      Serial.println("Motor " + (String)mNum + " not found");
      break;
  }
  return (String)mNum;

}

void setup(){
    Serial.begin(9600);
    Serial.println(":: Motor M1 initialized");
    Serial.println(":: Motor M2 initialized");
    Serial.println(":: Motor M3 initialized");   
    Serial.println(":: Serial initialized!");
}

void loop(){
  if(Serial.available() > 0){
    command = Serial.read();

    Serial.print("# ");
    motorControl(command);
  }
}
