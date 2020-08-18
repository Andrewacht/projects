#include <Wire.h>

#define A 3   // For displaying segment "A"
#define B 2   // For displaying segment "B"
#define C 7   // For displaying segment "C"
#define D 8   // For displaying segment "D"
#define E 9   // For displaying segment "E"
#define F 4   // For displaying segment "F"
#define G 5   // For displaying segment "G"
#define DP 6  // For displaying segment "."

// Set debug mode with Serial
const boolean DEBUG_MODE = true;

// For buttons to request the lift
const int BUTTON_UP_PIN = 11;
const int BUTTON_DOWN_PIN = 12;
const int BUTTON_UP_LED_PIN = A2;
const int BUTTON_DOWN_LED_PIN = A1;
int goingUpButtonPressed = 0;
int goingDownButtonPressed = 0;

// For LED to simulate door opening/closing
const int DOOR_LED_PIN = 10;

// For ir detect lift arrived
// http://henrysbench.capnfatz.com/henrys-bench/arduino-sensors-and-input/arduino-ir-obstacle-sensor-tutorial-and-manual/
const int IR_PIN = 13;
int liftArrived = 0;      // false

// For displaying lift position on LED display
int liftPosition = 0;

// For receiving command for save to open door
int openDoor = 0;

// For data to send to master
byte sendingData[3];

void setup() {
  if (DEBUG_MODE) {
    Serial.begin(9600);                     // Begin serial communication
  }

  // For led display segments
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);

  // For get lift
  pinMode(BUTTON_UP_PIN, INPUT);
  pinMode(BUTTON_DOWN_PIN, INPUT);

  // For led buttons
  pinMode(BUTTON_UP_LED_PIN, OUTPUT);
  pinMode(BUTTON_DOWN_LED_PIN, OUTPUT);

  // For LED to simulate door opening/closing
  pinMode(DOOR_LED_PIN, OUTPUT);

  // For ir detect lift arrived
  pinMode(liftArrived, INPUT);

  // For initialization
  int address = determineAddress();         // Run initialization to determine the location of the segment
  Serial.print("address: ");
  Serial.println(address);

  // For communication
  Wire.begin(address + 8);                  // Start I2C communication // https://www.arduino.cc/en/Reference/Wire inside NOTE: addresses should start from 8 
  Wire.onReceive(getLiftRelatedData);       // Set the event handler to handle data incoming from the master
  Wire.onRequest(sendDataToMaster);         // Set the event handler to hande data sending to the master
}

void loop() {
}

/*********************** I2C CODE ***********************/

// NOTE: Dont add Serial.prints or complex code in I2C functions.
void getLiftRelatedData(int numBytes) {
  // Get liftPosition and show it on LED display
  liftPosition = Wire.read();           // Receive byte containing current lift position
  openDoor = Wire.read();               // Receive byte containing whether the door should open
}

void sendDataToMaster() {
  // Send goingUpButton, goingDownButton and liftArrived (ir data)
  Wire.write(sendingData, 3);
}

/*********************** INITIALIZE FLOOR CODE ***********************/

int determineAddress() {
  // Initializes the segment by determinging the location of the segment
  int selectingFloor = 0;                                            // Set current selected location on 0
  // Show the currenly selected location on the led display by 
  // passing the selected floor to the (self written) methode called for example
  // ledDisplayHandler(selectingFloor);                                 
  digitalWrite(DP, HIGH);                                            // Show a dot on the led display to indicate initialization
  while (true) {
    if (DEBUG_MODE) {
      Serial.print("selectedFloor: ");
      Serial.println(selectingFloor);
    }
    keepReadingButtonUpAndDownUntilPressed();                        // Read the buttons on the segment
    if (goingUpButtonPressed) {                                      // If the floor up button is pressed
      if (DEBUG_MODE) {
        Serial.println("goingUpButtonPressed");
      }
      selectingFloor++;                                              // Increase the currently selected floor by one
      goingUpButtonPressed = 0;                                      // Reset the floor up button
      if (selectingFloor > 9) {                                      // If the currently selected floor is more then 9
        selectingFloor = 0;                                          // Reset the currently selected floor to 0
      }
      // Show the currenly selected location on the led display by 
      // passing the selected floor to the (self written) methode called for example
      // ledDisplayHandler(selectingFloor);                            // Show the currently selected location
      digitalWrite(DP, HIGH);                                        // Show a dot on the led display to indicate initialization
    } 
    else if (goingDownButtonPressed) {                               // If the floor down button is pressed
      if (DEBUG_MODE) {
        Serial.println("Floor selected (goingDownButtonPressed)");
      }
      // Turn off led display to show successful initialization 
      // by calling the (self written) methode called for example
      // turnOff();                                                     
      delay(2000);                                                   // Wait 2 seconds
      goingDownButtonPressed = 0;                                    // Reset the floor down button
      digitalWrite(DP, LOW);                                         // Disable the dot to indicate normal function
      return selectingFloor;                                         // Return the selected floor
    }
    delay(1000);
  }
}

void keepReadingButtonUpAndDownUntilPressed() {
  // Reads the buttons until the are pressed
  if (!goingUpButtonPressed) {                              // If button up is not pressed
    goingUpButtonPressed = digitalRead(BUTTON_UP_PIN);      // Read button up
  }
  if (!goingDownButtonPressed) {                            // If button down is not pressed
    goingDownButtonPressed = digitalRead(BUTTON_DOWN_PIN);  // Read button down
  }
}

