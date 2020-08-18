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
long prevMillis = 0;

int x;
int y;

int xHeadStart = 30;
int yHeadStart = 14;

int xHeadOld = xHeadStart;
int yHeadOld = yHeadStart;

int xHeadNew = xHeadOld;
int yHeadNew = yHeadOld;

int dotWidth = 2;
int dotHeight = 2;

int headSpeed = 2000;

String headDirection = "";

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
  matrix.fillRect(xHeadOld, yHeadOld, dotWidth, dotHeight, matrix.Color333(5, 0, 5));
  millis();
}

void loop() {
  currentMillis = millis();
  x = analogRead(X_pin);
  y = analogRead(Y_pin);
  Serial.println(y);

  headDirectionCheck();
  Serial.println(headDirection);

  if (currentMillis - prevMillis >= headSpeed) {
    headMovement();
  }
  // put your main code here, to run repeatedly:

  if (digitalRead(SW_pin) == LOW) {
    Serial.println("click");
  }
  delay(100);
}

void moveHead() {
  matrix.fillRect(xHeadNew, yHeadNew, dotWidth, dotHeight, matrix.Color333(5, 0, 5));
  matrix.fillRect(xHeadOld, yHeadOld, dotWidth, dotHeight, matrix.Color333(0, 0, 0));
  xHeadOld = xHeadNew;
  yHeadOld = yHeadNew;
}

void headDirectionCheck() {
  if (y < 200) {
    headDirection = "up";
    Serial.println("up");
  }

  if (y > 800) {
    headDirection = "down";
    Serial.println("down");
  }

  if (x > 800) {
    headDirection = "right";
    Serial.println("right");
  }

  if (x < 200) {
    headDirection = "left";
    Serial.println("left");
  }
}

void headMovement() {
  if (headDirection.equals("left")) {
    if (xHeadNew > dotWidth) {
      xHeadNew = xHeadOld - 2;
      moveHead();
    }
    else {
      gameOver();
    }
  }

  if (headDirection.equals("right")) {
    if (xHeadNew < (62 - dotWidth)) {
      xHeadNew = xHeadOld + 2;
      moveHead();
    }
    else {
      gameOver();
    }
  }

  if (headDirection.equals("up")) {
    if (yHeadNew > dotHeight) {
      yHeadNew = yHeadOld - 2;
      moveHead();
    }
    else {
      gameOver();
    }
  }

  if (headDirection.equals("down")) {
    if (yHeadNew < (30 - dotHeight)) {
      yHeadNew = yHeadOld + 2;
      moveHead();
    }
    else {
      gameOver();
    }
  }
}

void gameOver() {
  matrix.fillRect(0, 0, 64, 32, matrix.Color333(0, 0, 0));
  matrix.setTextColor(matrix.Color333(5, 0, 5));
  matrix.setTextSize(2);
  matrix.setCursor(9, 1);
  matrix.print("Game");
  matrix.setCursor(9, 17);
  matrix.print("Over");

  while (digitalRead(SW_pin) == HIGH) {
    Serial.println(".");
  }
  restart();
}

void restart() {
  xHeadOld = xHeadStart;
  yHeadOld = yHeadStart;
  xHeadNew = xHeadOld;
  yHeadNew = yHeadOld;
  headDirection = "";
  matrix.fillRect(0, 0, 64, 32, matrix.Color333(0, 0, 0));
  matrix.drawRect(0, 0, 64, 32, matrix.Color333(0, 0, 7));
  matrix.drawRect(1, 1, 62, 30, matrix.Color333(0, 0, 7));
  matrix.fillRect(xHeadOld, yHeadOld, dotWidth, dotHeight, matrix.Color333(5, 0, 0));
}
