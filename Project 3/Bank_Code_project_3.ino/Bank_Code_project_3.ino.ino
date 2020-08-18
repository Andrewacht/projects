#include <Keypad.h>
#define password_length 5 // 4 cijfers en een NULL
#define LOCK_PIN 12

#include <SPI.h>
#include <MFRC522.h>

int pas = 0;

#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

const byte ROWS = 4; //vier rijen
const byte COLS = 4; //vier kolommen

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};                  //layout van keypad

byte rowPins[ROWS] = {5, 4, 3, 2}; //digitale inputs voor de rijen
byte colPins[COLS] = {A0, A1, A2, A3}; //digitale inputs voor de kolommen

char pass[password_length] = "8809"; //geheime code
char passdata[password_length]; //de array waar de invoer in weggezet wordt
byte data_index = 0, pass_index = 0; //bijhouders voor de invoer

//instantie maken van keypad object
Keypad keypad = Keypad(makeKeymap(keys), colPins, rowPins, ROWS, COLS);


//codefragment of main function loop()
void setup() {
  pinMode(LOCK_PIN, OUTPUT);

  Serial.begin(2000000);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522

  digitalWrite(LOCK_PIN, LOW);
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    Serial.print("Keypad ");
    Serial.println(key);
    delay(100);
  }
  
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  //print RFID + UID code
  String content;
  byte letter;
  
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {

    //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    //Serial.print(mfrc522.uid.uidByte[i], HEX);
    
    
    
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
    
  }
 if (content != 0){
  content.toUpperCase(); 

  Serial.println("RFID " + content);
 // Serial.println();
delay(500);
 }
}
