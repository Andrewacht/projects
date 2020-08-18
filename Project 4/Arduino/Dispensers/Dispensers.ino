#define servo5 2
#define servo10 3
#define servo20 4
#define servo50 5

#define sensor5 8
#define sensor10 9
#define sensor20 10
#define sensor50 11

String input;
int maxDispenseTime = 8000;

void setup() {
  pinMode(servo5, OUTPUT);
  pinMode(servo10, OUTPUT);
  pinMode(servo20, OUTPUT);
  pinMode(servo50, OUTPUT);
  pinMode(sensor5, INPUT_PULLUP);
  pinMode(sensor10, INPUT_PULLUP);
  pinMode(sensor20, INPUT_PULLUP);
  pinMode(sensor50, INPUT_PULLUP);

  Serial.begin(2000000);
}

void loop() {
  while (!Serial.available()) {
    delay(1);
  }
  input = Serial.readString();
  if (dropNote(input)) {
    Serial.print("Success");
  }
  else {
    Serial.print("Failed");
  }

}

boolean dropNote(String command) {
  boolean result = false;
  Serial.print(command);
  Serial.print(millis());
  if (command == "dispense 5") {
    result = drop5Note();
  }
  else if (command == "dispense 10") {
    result = drop10Note();
  }
  else if (command == "dispense 20") {
    result = drop20Note();
  }
  else if (command == "dispense 50") {
    result = drop50Note();
  }
  else{
    Serial.print("Command not recognized");
  }

  return result;
}


boolean drop5Note() {
  digitalWrite(servo5, HIGH);
  long startTime = millis();
  while (digitalRead(sensor5) == HIGH) {
    if (millis() - startTime > maxDispenseTime) {
      digitalWrite(servo5, LOW);
      Serial.print("Timed out");
      return false;
    }
    delay(1);
  }
  digitalWrite(servo5, LOW);
  return true;
}


boolean drop10Note() {
  digitalWrite(servo10, HIGH);
  long startTime = millis();
  while (digitalRead(sensor10) == HIGH) {
    if (millis() - startTime > maxDispenseTime) {
      digitalWrite(servo10, LOW);
      Serial.print("Timed out");
      return false;
    }
    delay(1);
  }
  digitalWrite(servo10, LOW);
  return true;
}


boolean drop20Note() {
  digitalWrite(servo20, HIGH);
  long startTime = millis();
  while (digitalRead(sensor20) == HIGH) {
    if (millis() - startTime > maxDispenseTime) {
      digitalWrite(servo20, LOW);
      Serial.print("Timed out");
      return false;
    }
    delay(1);
  }
  digitalWrite(servo20, LOW);
  return true;
}


boolean drop50Note() {
  digitalWrite(servo50, HIGH);
  long startTime = millis();
  while (digitalRead(sensor50) == HIGH) {
    if (millis() - startTime > maxDispenseTime) {
      digitalWrite(servo50, LOW);
      Serial.print("Timed out");
      return false;
    }
    delay(1);
  }
  digitalWrite(servo50, LOW);
  return true;
}

