// How to use:
//
// First: copy segment.h and segment.cpp to the foder of your .ino file
// Second: #include "segment.h" at the top of your .ino file
// Third: segmentSetup(); in the setup() function of your .ino file
//
// Afterwards call segmentDigit(number) whenever you want to update the digit, -1 to turn it off

void segmentSetup();
void segmentDigit(char number);
