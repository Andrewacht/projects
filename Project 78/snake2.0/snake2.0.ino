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

int screenWidth = 32;
int screenHeight = 32;

int x;
int y;

int xHeadStart = screenWidth/2;
int yHeadStart = screenHeight/2;

int snakeOldX = xHeadStart;
int snakeOldY = yHeadStart;

int xHeadNew = xHeadStart;
int yHeadNew = yHeadStart;

int snakeWidth = 2;
int snakeHeight = 2;

int headSpeed = 150;

String headDirection = "right";

String joystickDirection;

//fruit
int fruitX;
int fruitY;
int fruitActive = 0;

// Snake
const int MAX_SNAKE_LENGTH = 20;

// Variables
int snakeX[MAX_SNAKE_LENGTH];                      // X-coordinates of snake
int snakeY[MAX_SNAKE_LENGTH];                      // Y-coordinates of snake
int snakeLength = 2;                               // nr of parts of snake





RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

void setup() {
  // put your setup code here, to run once:
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  matrix.begin();
  matrix.drawRect(0, 0, screenWidth, screenHeight, matrix.Color333(0, 0, 7));
  matrix.drawRect(1, 1, screenWidth-2, screenHeight-2, matrix.Color333(0, 0, 7));
  matrix.fillRect(xHeadStart, yHeadStart, snakeWidth, snakeHeight, matrix.Color333(5, 0, 0));
  millis();
  snakeX[0] = xHeadStart;
  snakeY[0] = yHeadStart;
  for (int i = 1; i < MAX_SNAKE_LENGTH; i++) {
    snakeX[i] = snakeY[i] = -1;
  }
}

void loop() {
  Serial.println(snakeX[0]);
  currentMillis = millis();
  x = analogRead(X_pin);
  y = analogRead(Y_pin);
  //Serial.println(y);

  if (fruitActive == 0) {
    makeFruit();
  }

  if (currentMillis - prevMillis >= headSpeed) {
    headDirectionCheck();
    headMovement();
    draw();
    prevMillis = currentMillis;
  }

  if (digitalRead(SW_pin) == LOW) {
  }
}

void draw() {
  drawSnake();
  if (fruitActive == 0) {
    drawFruit();
  }
}

void makeFruit() {
  fruitX = 1;
  fruitY = 1;
  while (fruitX % 2 != 0) {
    fruitX = random(2, screenWidth-2);
  }
  while (fruitY % 2 != 0) {
    fruitY = random(2, screenHeight-2);
  }
}

void drawFruit() {
  makeFruit();
  matrix.fillRect(fruitX, fruitY, snakeWidth, snakeHeight, matrix.Color333(0, 0, 5));
  fruitActive++;
}

void headDirectionCheck() {
  if (headDirection.equals("left") || headDirection.equals("right")) {
  if (y < 200) {
      headDirection = "up";
    }

    if (y > 800) {
      headDirection = "down";
    }
  }

  else if (headDirection.equals("up") || headDirection.equals("down")) {
  if (x > 800) {
      headDirection = "right";
    }

    if (x < 200) {
      headDirection = "left";
    }
  }
}

void headMovement() {
  for (int i = snakeLength - 1; i > 0; i--) {
    snakeX[i] = snakeX[i - 1];
    snakeY[i] = snakeY[i - 1];
  }

  if (headDirection.equals("left")) {
    if (xHeadNew > snakeWidth) {
      xHeadNew -= 2;
      snakeX[0] -= 2;
    }
    else {
      gameOver();
    }
  }

  if (headDirection.equals("right")) {
    if (xHeadNew < (screenWidth-2 - snakeWidth)) {
      xHeadNew += 2;
      snakeX[0] += 2;
    }
    else {
      gameOver();
    }
  }

  if (headDirection.equals("up")) {
    if (yHeadNew > snakeHeight) {
      yHeadNew -= 2;
      snakeY[0] -= 2;
    }
    else {
      gameOver();
    }
  }

  if (headDirection.equals("down")) {
    if (yHeadNew < (screenHeight-2 - snakeHeight)) {
      yHeadNew += 2;
      snakeY[0] += 2;
    }
    else {
      gameOver();
    }
  }

  if (xHeadNew == fruitX && yHeadNew == fruitY) {
    if (snakeLength < MAX_SNAKE_LENGTH) {
      snakeLength++;
    }
    fruitActive--;
  }
  for (int i = snakeLength; i > 1; i--) {
    if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
      gameOver();
    }
  }
}

void gameOver() {
  matrix.fillRect(0, 0, screenWidth, screenHeight, matrix.Color333(0, 0, 0));
  matrix.setTextColor(matrix.Color333(5, 0, 0));
  if (screenWidth == 64){
  matrix.setTextSize(2);
  matrix.setCursor(9, 1);
  matrix.print("Game");
  matrix.setCursor(9, 17);
  matrix.print("Over");
  }
  else if (screenWidth == 32){
    matrix.setTextSize(1);
  matrix.setCursor(3, 7);
  matrix.print("Game");
  matrix.setCursor(3, 17);
  matrix.print("Over");
  }

  while (digitalRead(SW_pin) == HIGH) {
  }
  restart();
}

void restart() {
  snakeX[0] = xHeadStart;
  snakeY[0] = yHeadStart;
  xHeadNew = xHeadStart;
  yHeadNew = yHeadStart;
  for (int i = 1; i < MAX_SNAKE_LENGTH; i++) {
    snakeX[i] = snakeY[i] = -1;
  }
  snakeLength = 2;
  fruitActive = 0;
  headDirection = "right";
  matrix.fillRect(0, 0, 64, 32, matrix.Color333(0, 0, 0));
  matrix.drawRect(0, 0, screenWidth, screenHeight, matrix.Color333(0, 0, 7));
  matrix.drawRect(1, 1, screenWidth-2, screenHeight-2, matrix.Color333(0, 0, 7));
  drawSnake();
}

void drawSnake() {
  for (int i = 0; i < snakeLength; i++) {
    matrix.drawRect(snakeX[i], snakeY[i], snakeWidth, snakeHeight, matrix.Color333(5, 0, 0));
  }
  matrix.fillRect(snakeX[snakeLength - 1], snakeY[snakeLength - 1], 2, 2, matrix.Color333(0, 0, 0));
}
