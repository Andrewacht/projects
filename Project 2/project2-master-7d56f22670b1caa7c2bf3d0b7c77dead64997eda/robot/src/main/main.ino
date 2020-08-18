#include "drive.h"
#include "sensors.h"

#define PIN_0 16
#define PIN_1 5
#define PIN_2 4
#define PIN_3 0
#define PIN_4 2
#define PIN_5 14
#define PIN_6 12
#define PIN_7 13
#define PIN_8 15

Drive drive(3, 4, 5, 6);
Sensors sensors;

void setup() {
    Serial.begin(9600);

    pinMode(PIN_0, OUTPUT);
    pinMode(PIN_1, INPUT);

    pinMode(PIN_3, INPUT);
    pinMode(PIN_4, INPUT);
    pinMode(PIN_5, INPUT);
    pinMode(PIN_6, INPUT);

    drive.setup();
    drive.calibrateServos();

    sensors.setup();
}

void loop() {
    sensors.colorUpdate();
    sensors.ultraSonicUpdate();
    sensors.lineTrackerUpdate();
}
