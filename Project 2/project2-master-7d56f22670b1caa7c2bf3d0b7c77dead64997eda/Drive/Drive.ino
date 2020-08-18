#include "Drive.h"

Drive drive(3, 4, 5, 6); 

void setup(){
  Serial.begin(9600);
  Serial.println("Started Drive");
  drive.setup();
  drive.calibrateServos();
}

void loop(){
  drive.stopDriving();
  drive.drive(Drive::north, 2);
  delay(5000);
  drive.stopDriving();
  drive.drive(Drive::south, 4);
  delay(5000);
  drive.stopDriving();
  drive.drive(Drive::north, 4);
  delay(5000);
  drive.stopDriving();
  drive.drive(Drive::south, 2);
  delay(5000);
}



