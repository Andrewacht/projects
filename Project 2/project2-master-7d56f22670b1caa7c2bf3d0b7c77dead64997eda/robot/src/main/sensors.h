#ifndef sensors_h
#define sensors_h

#include "Arduino.h"

#define PIN_0 16
#define PIN_1 5
#define PIN_2 4
#define PIN_3 0
#define PIN_4 2
#define PIN_5 14
#define PIN_6 12
#define PIN_7 13
#define PIN_8 15

class Sensors {
public:
    Sensors();
    void setup();

    void colorUpdate();
    void ultraSonicUpdate();
    void lineTrackerUpdate();
    void printColors(int colors[3]);
    void printColors(float colors[3]);
    
    int getColor();
    long getDistance();
    char * getIR();
	
private:
	int cBlack[2] = {0, 0};
	int cRed[2] = {0, 0};
	int cFloor[2] = {0, 0};
    int color;

	long duration;
	long distance;

	char irSensor[4];
};

#endif
