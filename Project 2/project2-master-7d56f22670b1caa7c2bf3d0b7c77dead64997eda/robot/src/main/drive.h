/*
  Drive.h - Library for using the servo's on the Parallax
  Created by Jort Stuyt, January 12, 2018.
  Released into the public domain.
*/

#ifndef drive_h
#define drive_h

#include "Arduino.h"
#include <Servo.h>

class Drive
{
  public:
    Drive(int leftPin, int rightPin, int upPin, int downPin);
    void setup();
  
    enum Wheel{
      leftWheel, rightWheel, all 
    };

    enum Direction{
      north, east, south, west
    };
    
    void drive(Direction direction, int speedLevel);
    void stopDriving();
    void rotateWheel(Wheel wheel, boolean moveClockwise, int speedLevel);
    void disableWheel(Wheel wheel);
    void disableWheels();
    void calibrateLeftServo();
    void calibrateRightServo();
    void calibrateServos();
    boolean upButton();
    boolean downButton();
    boolean bothButtons();
    
  private:
    int leftZeroValue = 90;
    int rightZeroValue = 90;
    int leftPin = 2;
    int rightPin = 3;
    int upPin = 4;
    int downPin = 5;

};

#endif
