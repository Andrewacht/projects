#include "Arduino.h"

#include "segment.h"

//   F
//  ---
// |   |
// | G | E
// |   |
//  ---  H
// |   |
// | D | B
// |   |
//  --- . A
//   C

#define SEGMENT_A 2
#define SEGMENT_B 3
#define SEGMENT_C 4
#define SEGMENT_D 5
#define SEGMENT_E 6
#define SEGMENT_F 7
#define SEGMENT_G 8
#define SEGMENT_H 9

void segmentSetup() {
    pinMode(SEGMENT_A, OUTPUT);
    pinMode(SEGMENT_B, OUTPUT);
    pinMode(SEGMENT_C, OUTPUT);
    pinMode(SEGMENT_D, OUTPUT);
    pinMode(SEGMENT_E, OUTPUT);
    pinMode(SEGMENT_F, OUTPUT);
    pinMode(SEGMENT_G, OUTPUT);
    pinMode(SEGMENT_H, OUTPUT);
}

void segmentDigit(char number) {
    digitalWrite(SEGMENT_A, LOW);
    digitalWrite(SEGMENT_B, LOW);
    digitalWrite(SEGMENT_C, LOW);
    digitalWrite(SEGMENT_D, LOW);
    digitalWrite(SEGMENT_E, LOW);
    digitalWrite(SEGMENT_F, LOW);
    digitalWrite(SEGMENT_G, LOW);
    digitalWrite(SEGMENT_H, LOW);

    switch (number) {
        case -1:
            break;
        case 0:
            digitalWrite(SEGMENT_B, HIGH);
            digitalWrite(SEGMENT_C, HIGH);
            digitalWrite(SEGMENT_D, HIGH);
            digitalWrite(SEGMENT_E, HIGH);
            digitalWrite(SEGMENT_F, HIGH);
            digitalWrite(SEGMENT_G, HIGH);
            break;
        case 1:
            digitalWrite(SEGMENT_B, HIGH);
            digitalWrite(SEGMENT_E, HIGH);
            break;
        case 2:
            digitalWrite(SEGMENT_C, HIGH);
            digitalWrite(SEGMENT_D, HIGH);
            digitalWrite(SEGMENT_E, HIGH);
            digitalWrite(SEGMENT_F, HIGH);
            digitalWrite(SEGMENT_H, HIGH);
            break;
        case 3:
            digitalWrite(SEGMENT_B, HIGH);
            digitalWrite(SEGMENT_C, HIGH);
            digitalWrite(SEGMENT_E, HIGH);
            digitalWrite(SEGMENT_F, HIGH);
            digitalWrite(SEGMENT_H, HIGH);
            break;
        case 4:
            digitalWrite(SEGMENT_B, HIGH);
            digitalWrite(SEGMENT_E, HIGH);
            digitalWrite(SEGMENT_G, HIGH);
            digitalWrite(SEGMENT_H, HIGH);
            break;
        case 5:
            digitalWrite(SEGMENT_B, HIGH);
            digitalWrite(SEGMENT_C, HIGH);
            digitalWrite(SEGMENT_F, HIGH);
            digitalWrite(SEGMENT_G, HIGH);
            digitalWrite(SEGMENT_H, HIGH);
            break;
        case 6:
            digitalWrite(SEGMENT_B, HIGH);
            digitalWrite(SEGMENT_C, HIGH);
            digitalWrite(SEGMENT_D, HIGH);
            digitalWrite(SEGMENT_F, HIGH);
            digitalWrite(SEGMENT_G, HIGH);
            digitalWrite(SEGMENT_H, HIGH);
            break;
        case 7:
            digitalWrite(SEGMENT_B, HIGH);
            digitalWrite(SEGMENT_E, HIGH);
            digitalWrite(SEGMENT_F, HIGH);
            break;
        case 8:
            digitalWrite(SEGMENT_B, HIGH);
            digitalWrite(SEGMENT_C, HIGH);
            digitalWrite(SEGMENT_D, HIGH);
            digitalWrite(SEGMENT_E, HIGH);
            digitalWrite(SEGMENT_F, HIGH);
            digitalWrite(SEGMENT_G, HIGH);
            digitalWrite(SEGMENT_H, HIGH);
            break;
        case 9:
            digitalWrite(SEGMENT_B, HIGH);
            digitalWrite(SEGMENT_C, HIGH);
            digitalWrite(SEGMENT_E, HIGH);
            digitalWrite(SEGMENT_F, HIGH);
            digitalWrite(SEGMENT_G, HIGH);
            digitalWrite(SEGMENT_H, HIGH);
            break;
    }
}
