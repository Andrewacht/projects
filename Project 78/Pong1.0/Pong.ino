#include <RGBmatrixPanel.h>

#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

const int SW_pin = 4; // digital pin connected to switch output
const int playerOneX_pin = A4; // analog pin connected to X output
const int playerOneY_pin = A5; // analog pin connected to playerOneY
const int playerTwoX_pin = A4;
const int playerTwoY_pin = A5;

long currentMillis;
long prevMillisBall = 0;
long prevMillisPaddle = 0;

bool pause = false;

int playerOneX = 0;
int playerOneY = 0;

int playerTwoX = 0;
int playerTwoY = 0;

int ballOldX = 32;
int ballOldY = 14;

int ballNewX;
int ballNewY;

int newPaddleOneY;
int newPaddleTwoY;

int ballWidth = 2;
int ballHeight = 2;

int paddleHeight = 8;
int paddleWidth = 2;

String ballDirectionX;
String ballDirectionY;
String winnerSide;

int paddleOneX = 2;
int paddleOneY = 12;
int paddleTwoX = 60;
int paddleTwoY = 12;

int ballYspeed[] = {2, 4, 6};
int currentBallYSpeed;

String joystickDirection;
int ballSpeed = 50;
int paddleSpeed = 50;

int ballTouches;

int scoreOne = 0;
int scoreTwo = 0;


RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

void setup() {

  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  matrix.begin();

  matrix.drawRect(0, 0, 64, 32, matrix.Color333(0, 0, 7));
  matrix.drawRect(1, 1, 62, 30, matrix.Color333(0, 0, 7));
  matrix.fillRect(paddleOneX, paddleOneY, paddleWidth, paddleHeight, matrix.Color333(7, 0, 0));
  matrix.fillRect(paddleTwoX, paddleTwoY, paddleWidth, paddleHeight, matrix.Color333(7, 0, 0));

  matrix.fillRect(ballOldX, ballOldY, ballWidth, ballHeight, matrix.Color333(0, 5, 0));

  ballDirectionX = "right";
  ballDirectionY = "down";
  // matrix.fillRect(ballOldX, ballOldY, ballWidth, ballHeight, matrix.Color333(0, 5, 0));

  millis();
}

void loop() {
  // put playerOneYour main code here, to run repeatedlplayerOneY:
  playerOneX = analogRead(playerOneX_pin);
  playerOneY = analogRead(playerOneY_pin);

  playerTwoX = analogRead(playerTwoX_pin);
  playerTwoY = analogRead(playerTwoY_pin);

  currentMillis = millis();
  if (currentMillis - prevMillisBall >= ballSpeed) {
    ballMovement();
    prevMillisBall = currentMillis;
  }
  if (currentMillis - prevMillisPaddle >= paddleSpeed) {
    paddleMovement();
    prevMillisPaddle = currentMillis;
  }
}

void ballMovement() {

  if (ballDirectionX.equals("left")) {

    if (ballNewX <= (paddleOneX + paddleWidth) && (ballNewY >= paddleOneY - 2) && (ballNewY < (paddleOneY + paddleHeight))) {
      ballDirectionX = "right";
      if (ballNewY == paddleOneY || ballNewY == paddleOneY+6){
        currentBallYSpeed = 1;
      }
      else if (ballNewY == paddleOneY + 2 || ballNewY == paddleOneY+6){
        currentBallYSpeed = 0;
      }
      ballTouches++;
      if (ballTouches % 3 == 0) {
        ballSpeed -= 5;
      }
    }
    else if (ballNewX < paddleOneX + paddleWidth) {
      scoreTwo++;
      ballNewX = 32;
      ballDirectionX = "center";
      winnerSide = "right";
      ballTouches = 0;
      ballSpeed = 50;
      pointScored();
    }
    else {
      if (ballNewY < 28 && ballDirectionY.equals("down")) {
        ballNewX = ballOldX - ballYspeed[currentBallYSpeed];
        ballNewY = ballOldY + ballYspeed[currentBallYSpeed];
        matrix.fillRect(ballNewX, ballNewY, ballWidth, ballHeight, matrix.Color333(0, 7, 0));
        matrix.fillRect(ballOldX, ballOldY, ballWidth, ballHeight, matrix.Color333(0, 0, 0));
        ballOldX = ballNewX;
        ballOldY = ballNewY;
      }
      else {
        ballDirectionY = "up";
      }

      if (ballNewY > 2 && ballDirectionY.equals("up")) {
        ballNewX = ballOldX - ballYspeed[currentBallYSpeed];
        ballNewY = ballOldY - ballYspeed[currentBallYSpeed];
        matrix.fillRect(ballNewX, ballNewY, ballWidth, ballHeight, matrix.Color333(0, 7, 0));
        matrix.fillRect(ballOldX, ballOldY, ballWidth, ballHeight, matrix.Color333(0, 0, 0));
        ballOldX = ballNewX;
        ballOldY = ballNewY;

      }
      else {
        ballDirectionY = "down";
      }
    }
  }

  else if (ballDirectionX.equals("right")) {

    if (ballNewX >= paddleTwoX - ballWidth && (ballNewY > paddleTwoY) && (ballNewY < (paddleTwoY + paddleHeight))) {
      ballDirectionX = "left";
      ballTouches++;
      if (ballNewY == paddleOneY || ballNewY == paddleOneY+6){
        currentBallYSpeed = 1;
      }
      else if (ballNewY == paddleOneY + 2 || ballNewY == paddleOneY+6){
        currentBallYSpeed = 0;
      }
      if (ballTouches % 3 == 0) {
        ballSpeed -= 5;
      }
    }
    else if (ballNewX > paddleTwoX - ballWidth) {
      scoreOne++;
      ballNewX = 32;
      ballDirectionX = "center";
      winnerSide = "left";
      ballTouches = 0;
      ballSpeed = 50;
      pointScored();
    }

    else {
      if (ballNewY < 28 && ballDirectionY.equals("down")) {
        ballNewX = ballOldX + ballYspeed[currentBallYSpeed];
        ballNewY = ballOldY + ballYspeed[currentBallYSpeed];
        matrix.fillRect(ballNewX, ballNewY, ballWidth, ballHeight, matrix.Color333(0, 7, 0));
        matrix.fillRect(ballOldX, ballOldY, ballWidth, ballHeight, matrix.Color333(0, 0, 0));
        ballOldX = ballNewX;
        ballOldY = ballNewY;
      }
      else {
        ballDirectionY = "up";
      }

      if (ballNewY > 2 && ballDirectionY.equals("up")) {
        ballNewX = ballOldX + ballYspeed[currentBallYSpeed];
        ballNewY = ballOldY - ballYspeed[currentBallYSpeed];
        matrix.fillRect(ballNewX, ballNewY, ballWidth, ballHeight, matrix.Color333(0, 7, 0));
        matrix.fillRect(ballOldX, ballOldY, ballWidth, ballHeight, matrix.Color333(0, 0, 0));
        ballOldX = ballNewX;
        ballOldY = ballNewY;
      }
      else {
        ballDirectionY = "down";
      }

    }
  }
  delay(ballSpeed);
}

void paddleMovement() {
  //  Serial.println(playerOneY);
  if (playerOneY < 200) {
    Serial.println("up");
    newPaddleOneY = paddleOneY - 1;
    if (newPaddleOneY > 0) {
      matrix.fillRect(paddleOneX, newPaddleOneY, paddleWidth, paddleHeight, matrix.Color333(7, 0, 0));
      matrix.fillRect(paddleOneX, (newPaddleOneY + paddleHeight), paddleWidth, (paddleOneY - newPaddleOneY), matrix.Color333(0, 0, 0));

      paddleOneY = newPaddleOneY;
    }
  }

  if (playerOneY > 800) {
    Serial.println("down");
    if (newPaddleOneY < (30 - paddleHeight)) {
      newPaddleOneY = paddleOneY + 1;
      matrix.fillRect(paddleOneX, newPaddleOneY, paddleWidth, paddleHeight, matrix.Color333(7, 0, 0));
      matrix.fillRect(paddleOneX, paddleOneY, paddleWidth, (newPaddleOneY - paddleOneY), matrix.Color333(0, 0, 0));
      paddleOneY = newPaddleOneY;
    }
  }

  if (playerTwoY < 200) {
    Serial.println("up");
    newPaddleTwoY = paddleTwoY - 1;
    if (newPaddleTwoY > 0) {
      matrix.fillRect(paddleTwoX, newPaddleTwoY, paddleWidth, paddleHeight, matrix.Color333(7, 0, 0));
      matrix.fillRect(paddleTwoX, (newPaddleTwoY + paddleHeight), paddleWidth, (paddleTwoY - newPaddleTwoY), matrix.Color333(0, 0, 0));

      paddleTwoY = newPaddleTwoY;
    }
  }

  if (playerTwoY > 800) {
    Serial.println("down");
    if (newPaddleTwoY < (30 - paddleHeight)) {
      newPaddleTwoY = paddleTwoY + 1;
      matrix.fillRect(paddleTwoX, newPaddleTwoY, paddleWidth, paddleHeight, matrix.Color333(7, 0, 0));
      matrix.fillRect(paddleTwoX, paddleTwoY, paddleWidth, (newPaddleTwoY - paddleTwoY), matrix.Color333(0, 0, 0));
      paddleTwoY = newPaddleTwoY;
    }
  }
}

void pointScored() {
  if (scoreOne == 5 || scoreTwo == 5){
    
  }
  matrix.fillRect(0, 0, 64, 32, matrix.Color333(0, 0, 0));
  matrix.setTextSize(2);
  matrix.setCursor(3, 1);
  matrix.print("Score");
  if (scoreOne >= 10 && scoreTwo >= 10){
    matrix.setCursor(4, 17);
  }
  else if (scoreOne >= 10 || scoreTwo >=10){
    matrix.setCursor(9, 17);
  }
  else{
  matrix.setCursor(15, 17);
  }
  matrix.print(scoreOne);
  matrix.print("-");
  matrix.print(scoreTwo);

  while (digitalRead(SW_pin) == HIGH) {
  }
  matrix.fillRect(0, 0, 64, 32, matrix.Color333(0, 0, 0));
  matrix.drawRect(0, 0, 64, 32, matrix.Color333(0, 0, 7));
  matrix.drawRect(1, 1, 62, 30, matrix.Color333(0, 0, 7));
  matrix.fillRect(paddleOneX, paddleOneY, paddleWidth, paddleHeight, matrix.Color333(7, 0, 0));
  matrix.fillRect(paddleTwoX, paddleTwoY, paddleWidth, paddleHeight, matrix.Color333(7, 0, 0));
  int r = 1;
  while (r % 2 != 0) {
    r = random(4, 26);
    Serial.println(r);
  }
  ballNewY = r;
  matrix.fillRect(ballNewX, ballNewY, ballWidth, ballHeight, matrix.Color333(0, 7, 0));
  matrix.fillRect(ballOldX, ballOldY, ballWidth, ballHeight, matrix.Color333(0, 0, 0));
  ballOldX = ballNewX;
  ballOldY = ballNewY;
  Serial.println("go");
  if (ballDirectionX.equals("center")) {
    ballDirectionX = winnerSide;
    winnerSide = "";
  }
}
