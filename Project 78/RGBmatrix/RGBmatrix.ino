#include <RGBmatrixPanel.h>

#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

const int SW_pin = 4; // digital pin connected to switch output
const int X_pin = A4; // analog pin connected to X output
const int Y_pin = A5; // analog pin connected to Y output

long currentMillis;
long prevMillis;

int x = 0;
int y = 0;

int xDotOld = 0;
int yDotOld = 0;

int xDotNew;
int yDotNew;

int dotWidth = 3;
int dotHeight = 3;

String joystickDirection;
int movementSpeedY;
int movementSpeedX;

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

void setup() {
  // put your setup code here, to run once:
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  matrix.begin();
    matrix.drawRect(0, 0, 64, 32, matrix.Color333(0, 0, 7));
  matrix.drawRect(1, 1, 62, 30, matrix.Color333(0, 0, 7));
  matrix.fillRect(xDotOld, yDotOld, dotWidth, dotHeight, matrix.Color333(5, 0, 0));
  millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(X_pin);
  int y = analogRead(Y_pin);


  if (y > 550) {
    Serial.println("up");
    if (yDotNew > 0) {
      yDotNew = yDotOld - 2;
      matrix.fillRect(xDotNew, yDotNew, dotWidth, dotHeight, matrix.Color333(5, 0, 0));
      matrix.fillRect(xDotOld, yDotOld, dotWidth, dotHeight, matrix.Color333(0, 0, 0));
      xDotOld = xDotNew;
      yDotOld = yDotNew;
      delay(100);
    }
  }

  else if (y < 450) {
    Serial.println("down");
    if (yDotNew < (32 - dotHeight)) {
      yDotNew = yDotOld + 2;
      matrix.fillRect(xDotNew, yDotNew, dotWidth, dotHeight, matrix.Color333(5, 0, 0));
      matrix.fillRect(xDotOld, yDotOld, dotWidth, dotHeight, matrix.Color333(0, 0, 0));
      xDotOld = xDotNew;
      yDotOld = yDotNew;
      delay(100);
    }
  }

  if (x > 550) {
    Serial.println("right");
    if (xDotNew < (64 - dotWidth)) {
      xDotNew = xDotOld + 1;
      matrix.fillRect(xDotNew, yDotNew, dotWidth, dotHeight, matrix.Color333(5, 0, 0));
      matrix.fillRect(xDotOld yDotOld, dotWidth, dotHeight, matrix.Color333(0, 0, 0));
      xDotOld = xDotNew;
      yDotOld = yDotNew;
      delay(100);
    }
  }

  else if (x < 450) {
    Serial.println("left");
    if (xDotNew > 0) {
      xDotNew = xDotOld - 1;
      matrix.fillRect(xDotNew, yDotNew, dotWidth, dotHeight, matrix.Color333(5, 0, 0));
      matrix.fillRect(xDotOld, yDotOld, dotWidth, dotHeight, matrix.Color333(0, 0, 0));
      xDotOld = xDotNew;
      yDotOld = yDotNew;
      delay(100);
    }
  }

  if (digitalRead(SW_pin) == LOW) {
    Serial.println("click");
    if (dotHeight < 5) {
      dotHeight++;
      dotWidth++;
    }

    else {
      dotHeight = 2;
      dotWidth = 2;
      matrix.fillRect((xDotNew+dotWidth), yDotNew, 3, 5, matrix.Color333(0, 0, 0));
      matrix.fillRect(xDotNew, (yDotNew+dotHeight), 5, 3, matrix.Color333(0, 0, 0));
    }

    matrix.fillRect(xDotNew, yDotNew, dotWidth, dotHeight, matrix.Color333(5, 0, 0));
    delay(500);
  }
}
