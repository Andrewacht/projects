const int SW_pin = 4; // digital pin connected to switch output
const int X_pin = A4; // analog pin connected to X output
const int Y_pin = A5; // analog pin connected to Y output

long currentMillis;
long prevMillis;

int x = 0;
int y = 0;

String joystickDirection;
int movementSpeedY;
int movementSpeedX;

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(115200);
  millis();
}

void loop() {
  int x = analogRead(X_pin);
  int y = analogRead(Y_pin);

  Serial.print("X: ");
  Serial.println(x);
  Serial.print("Y: ");
  Serial.println(y);

  if (y > 525) {
    Serial.println("up");
    speedY();
  }

  else if (y < 475) {
    Serial.println("down");
    speedY();
  }

  else {
    movementSpeedY = 0;
  }

  Serial.print("speedY: ");
  Serial.println(movementSpeedY);

  if (x > 500) {
    Serial.println("right");
    speedX();
  }

  else if (x < 475) {
    Serial.println("left");
    speedX();
  }

  else {
    movementSpeedX = 0;
  }

  Serial.print("speedX: ");
  Serial.println(movementSpeedX);


  if (digitalRead(SW_pin) == LOW) {
    Serial.println("click");
  }
}

void speedY() {
  if (movementSpeedY == 0) {
    prevMillis = millis();
    movementSpeedY++;
  }
  currentMillis = millis();
  if (movementSpeedY < 5) {
    if (currentMillis - prevMillis >= 500) {
      movementSpeedY++;
      prevMillis = millis();
    }
  }
}

void speedX() {
  if (movementSpeedX == 0) {
    prevMillis = millis();
    movementSpeedX++;
  }
  currentMillis = millis();
  if (movementSpeedX < 5) {
    if (currentMillis - prevMillis >= 500) {
      movementSpeedX++;
      prevMillis = millis();
    }
  }
}
