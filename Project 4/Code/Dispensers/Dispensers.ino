#define motorVijfEuro 2
#define motorTienEuro 3
#define motorTwintigEuro 4
#define motorVijftigEuro 5

#define biljetSensorVijfEuro 8
#define biljetSensorTienEuro 9
#define biljetSensorTwintigEuro 10
#define biljetSensorVijftigEuro 11

String input;

int biljettenNodigVijfEuro = 3;

void setup() {
  pinMode(motorVijfEuro, OUTPUT);
  pinMode(motorTienEuro, OUTPUT);
  pinMode(motorTwintigEuro, OUTPUT);
  pinMode(motorVijftigEuro, OUTPUT);
  pinMode(biljetSensorVijfEuro, INPUT_PULLUP);
  pinMode(biljetSensorTienEuro, INPUT_PULLUP);
  pinMode(biljetSensorTwintigEuro, INPUT_PULLUP);
  pinMode(biljetSensorVijftigEuro, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  while (!Serial.available()) {
  }
  if (Serial.available()) {
    input = Serial.readString();
  }

  if (input == "dispense 5") {
    dropVijfEuro(1);
  }

  if (input == "dispense 10") {
    dropTienEuro(1);
  }

  if (input == "dispense 20") {
    dropTwintigEuro(1);
  }

  if (input == "dispense 50") {
    dropVijftigEuro(1);
  }
}

void dropVijfEuro(int biljettenNodigVijfEuro) {

  for (int i = 1; i <= biljettenNodigVijfEuro; i++) {
    digitalWrite(motorVijfEuro, HIGH);
    while (digitalRead(biljetSensorVijfEuro) == HIGH) {
    }
    Serial.println(i);
    digitalWrite(motorVijfEuro, LOW);
    delay(1000);

  }
  Serial.println("uitgave briefje van vijf compleet");
  return;
}

void dropTienEuro(int biljettenNodigTienEuro) {

  for (int i = 1; i <= biljettenNodigTienEuro; i++) {
    digitalWrite(motorTienEuro, HIGH);
    while (digitalRead(biljetSensorTienEuro) == HIGH) {
    }
    Serial.println(i);
    digitalWrite(motorTienEuro, LOW);
    delay(1000);

  }
  Serial.println("uitgave briefje van tien compleet");
  return;
}

void dropTwintigEuro(int biljettenNodigTwintigEuro) {
  for (int i = 1; i <= biljettenNodigTwintigEuro; i++) {
    digitalWrite(motorTwintigEuro, HIGH);
    while (digitalRead(biljetSensorTwintigEuro) == HIGH) {
    }
    Serial.println(i);
    digitalWrite(motorTwintigEuro, LOW);
    delay(1000);

  }
  Serial.println("uitgave briefje van twintig compleet");
  return;
}

void dropVijftigEuro(int biljettenNodigVijftigEuro) {
  for (int i = 1; i <= biljettenNodigVijftigEuro; i++) {
    digitalWrite(motorVijftigEuro, HIGH);
    while (digitalRead(biljetSensorVijftigEuro) == HIGH) {
    }
    Serial.println(i);
    digitalWrite(motorVijftigEuro, LOW);
    delay(1000);

  }
  Serial.println("uitgave briefje van vijftig compleet");
  return;
}

