//instantiate RFIDReader object
/*
PINOUT:
RC522 MODULE    Uno/Nano     MEGA
SDA             D10          D9
SCK             D13          D52
MOSI            D11          D51
MISO            D12          D50
IRQ             N/A          N/A
GND             GND          GND
RST             D9           D8
3.3V            3.3V         3.3V
*/
//RFID library: https://github.com/miguelbalboa/rfid
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 49
#define RST_PIN 48
MFRC522 mfrc522(SS_PIN, RST_PIN);


//instantiate Keypad object
//Keypad library: https://playground.arduino.cc/Code/Keypad
#include <Keypad.h>
#define ROWS 4
#define COLS 4
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {26, 27, 28, 29};
byte colPins[COLS] = {22, 23, 24, 25};
Keypad keypad = Keypad(makeKeymap(keys), colPins, rowPins, ROWS, COLS);


void setup() {
  Serial.begin(2000000);
  keypad.addEventListener(keypadEvent);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.print("Started");
}


void loop() {
  //without this event won't work
  keypad.getKey();

  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    delay(1);
    return;
  }
  Serial.print("RFID ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
}


void keypadEvent(KeypadEvent key) {
  if (keypad.getState() == RELEASED) {
    Serial.print("KEY "); Serial.print(key);
  }
}
