/*
  Drive.cpp - Library for using the servo's on the Parallax
  Created by Jort Stuyt, January 12, 2018.
  Released into the public domain.
*/

#include "drive.h"

Servo leftServo;
Servo rightServo;

Drive::Drive(int leftPin, int rightPin, int upPin, int downPin){
  this->leftPin = leftPin;
  this->rightPin = rightPin;
  this->upPin = upPin;
  this->downPin = downPin;
}

void Drive::setup(){
  Serial.println("Setting up Drive...");
  Serial.print("Attaching rightServo result: "); Serial.println(rightServo.attach(rightPin));
  Serial.print("Attaching leftServo result: "); Serial.println(leftServo.attach(leftPin));
  pinMode(upPin, INPUT_PULLUP);
  pinMode(downPin, INPUT_PULLUP);
}

void Drive::drive(Direction direction, int speedLevel){
  Serial.println("Driving...");
  if(direction == north){
    rotateWheel(leftWheel, true, speedLevel);
    rotateWheel(rightWheel, true, speedLevel);
  }
  else if(direction == south){
    rotateWheel(leftWheel, false, speedLevel);
    rotateWheel(rightWheel, false, speedLevel);
  }
  else if(direction == east){
    rotateWheel(leftWheel, true, speedLevel);
    rotateWheel(rightWheel, false, speedLevel);
  }
  else if(direction == west){
    rotateWheel(leftWheel, false, speedLevel);
    rotateWheel(rightWheel, true, speedLevel);
  }
}

void Drive::stopDriving(){
  disableWheel(all);
}

void Drive::rotateWheel(Wheel wheel, boolean moveClockwise, int speedLevel){
  if(wheel == leftWheel){
    if(!leftServo.attached()){
      leftServo.attach(leftPin);
    }
    
    if(moveClockwise){
      leftServo.write(leftZeroValue + speedLevel);
    }
    else{
      leftServo.write(leftZeroValue - speedLevel);
    }    
    Serial.print("Rotating leftServo with value "); Serial.print(leftZeroValue); Serial.print(" with speedLevel "); Serial.println(speedLevel);
  }
  else if(wheel == rightWheel){
    rightServo.attach(rightPin);
    if(moveClockwise){
      rightServo.write(rightZeroValue - speedLevel);
    }
    else{
      rightServo.write(rightZeroValue + speedLevel);
    }
    Serial.print("Rotating rightServo with value "); Serial.print(rightZeroValue); Serial.print(" with speedLevel "); Serial.println(speedLevel);
  }
  else if(wheel == all){
    rotateWheel(leftWheel, moveClockwise, speedLevel);
    rotateWheel(rightWheel, moveClockwise, speedLevel);
  }
}

void Drive::calibrateServos(){
  Serial.println();
  calibrateLeftServo();
  Serial.println();
  delay(500);
  calibrateRightServo();
  Serial.println("Both servo's have been calibrated.");
  Serial.println();
}


void Drive::disableWheel(Wheel wheel){
  if(wheel == leftWheel){
    leftServo.detach();
  }
  else if(wheel == rightWheel){
    rightServo.detach();
  }
  else if(wheel == all){
    disableWheel(leftWheel);
    disableWheel(rightWheel);
  }
}

void Drive::calibrateLeftServo(){
  leftServo.write(leftZeroValue);
  
  Serial.println("Calibrate left servo.");
  Serial.print("Starting value: "); Serial.println(leftZeroValue);
  
  while(true){    
    if(upButton()){
      leftServo.write(++leftZeroValue);
      Serial.println(leftZeroValue);
      delay(200);
      if(bothButtons()){
        leftServo.write(--leftZeroValue);
        break;
      }
    }
    else if(downButton()){
      leftServo.write(--leftZeroValue);
      Serial.println(leftZeroValue);
      delay(200);
      if(bothButtons()){
        leftServo.write(++leftZeroValue);
        break;
      }
    }   
  }

  Serial.print("Calibrated left servo with value: "); Serial.println(leftZeroValue);
}

void Drive::calibrateRightServo(){
  leftServo.write(rightZeroValue);
  
  Serial.println("Calibrate right servo.");
  Serial.print("Starting value: "); Serial.println(rightZeroValue);
  
  while(true){    
    if(upButton()){
      rightServo.write(++rightZeroValue);
      Serial.println(rightZeroValue);
      delay(200);
      if(bothButtons()){
        rightServo.write(--rightZeroValue);
        break;
      }
    }
    else if(downButton()){
      rightServo.write(--rightZeroValue);
      Serial.println(rightZeroValue);
      delay(200);
      if(bothButtons()){
        rightServo.write(++rightZeroValue);
        break;
      }
    }   
  }

  Serial.print("Calibrated right servo with value: "); Serial.println(rightZeroValue);
}

boolean Drive::upButton(){
  return digitalRead(upPin) == LOW;
}

boolean Drive::downButton(){
  return digitalRead(downPin) == LOW;
}

boolean Drive::bothButtons(){
  return downButton() && upButton();
}

