#include "sensors.h"

Sensors::Sensors() {
}

void Sensors::setup() {
    pinMode(PIN_0, OUTPUT);
    pinMode(PIN_1, INPUT);

    pinMode(PIN_3, INPUT);
    pinMode(PIN_4, INPUT);
    pinMode(PIN_5, INPUT);
    pinMode(PIN_6, INPUT);
}

void Sensors::colorUpdate() {
    int tmp = analogRead(A0);

    if (tmp > this->cBlack[0] && tmp < this->cBlack[1]) {
        this->color = 0; // Black
    }
    else if (tmp > this->cRed[0] && tmp < this->cRed[1]) {
        this->color = 1; // Red
    }
    else if (tmp > this->cFloor[0] && tmp < this->cFloor[1]) {
        this->color = 2; // Floor
    }
}

void Sensors::ultraSonicUpdate() {
    // Clears the Trig pin
    digitalWrite(PIN_0, LOW);
    delayMicroseconds(2);

    // Sets the Trig pin on HIGH state for 10 microseconds
    digitalWrite(PIN_0, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_0, LOW);

    // Reads the Echo pin, return the sound wave travel time in microseconds
    duration = pulseIn(PIN_1, HIGH);

    // Calculate the distance in cm
    distance = duration / 29 * 0.5;
}

void Sensors::lineTrackerUpdate() {
    irSensor[0] = digitalRead(PIN_3);
    irSensor[1] = digitalRead(PIN_4);
    irSensor[2] = digitalRead(PIN_5);
    irSensor[3] = digitalRead(PIN_6);
}

void Sensors::printColors(int colors[3]) {
    Serial.println("red: " + String(colors[0]) + ", green: " + String(colors[1]) + ", blue: " + String((int)colors[2]));
}

void Sensors::printColors(float colors[3]) {
    int tmp[3] = {(int)colors[0], (int)colors[1], (int)colors[2]};
    printColors(tmp);
}

int Sensors::getColor() {
    return this->color;
}

long Sensors::getDistance() {
    return this->distance;
}

char * Sensors::getIR() {
    return this->irSensor;
}
