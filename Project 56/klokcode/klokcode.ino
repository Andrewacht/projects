#include <RGBmatrixPanel.h>

long currentMillis;
long prevMillis;
int minutes = 46;
int hours = 20;

String day[] = {"Ma", "Di", "Wo", "Do", "Vr", "Za", "Zo"};
int currentDay = 0;
String month[] = {"jan", "feb", "mar", "apr", "mei", "jun", "jul", "aug", "sep", "okt", "nov", "dec"};
int currentMonth = 0;
int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int currentMonthDay = 27;

#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

void setup() {
  matrix.setTextColor(matrix.Color333(5, 0, 0));

  show(31, 4, 2, 2, 5, 0, 0);
  show(31, 12, 2, 2, 5, 0, 0);
  timeSetup();

  Serial.begin(9600);
  prevMillis = millis();
}

void loop() {
  currentMillis = millis();
  if (currentMillis - prevMillis >= 59425) { //59425
    if (minutes < 59) {
      minutes++;
    }
    else {
      minutes = 0;
      if (hours < 23) {
        hours++;
      }
      else {
        hours = 0;
        if (currentDay < 6) {
          currentDay++;
        }
        else {
          currentDay = 0;
        }
        if (currentMonthDay < monthDays[currentMonth]) {
          currentMonthDay++;
        }
        else {
          currentMonthDay = 1;
          if (currentMonth < 11) {
            currentMonth++;
          }
          else {
            currentMonth = 0;
          }
          printMonth();
        }
        printWeekDay();
        printMonthDay();
      }
      printHours();
    }
    printMinutes();
    prevMillis = currentMillis;
  }
}

void show(int xStart, int yStart, int xLength, int yLength, int red, int green, int blue) {
  matrix.fillRect(xStart, yStart, xLength, yLength, matrix.Color333(red, green, blue));
}

void clearHour() {
  matrix.fillRect(7, 2, 24, 14, matrix.Color333(0, 0, 0));
}

void clearMinute() {
  matrix.fillRect(35, 2, 25, 16, matrix.Color333(0, 0, 0));
}

void clearWeekDay() {
  matrix.fillRect(5, 20, 12, 12, matrix.Color333(0, 0, 0));
}

void clearMonthDay() {
  matrix.fillRect(18, 20, 18, 12, matrix.Color333(0, 0, 0));
}

void clearMonth() {
  matrix.fillRect(39, 20, 30, 12, matrix.Color333(0, 0, 0));
}

void printMinutes() {

  matrix.setTextSize(2);    // size 1 == 8 pixels high
  clearMinute();
  matrix.setCursor(35, 2);

  if (minutes < 10) {
    matrix.print('0');
    matrix.setCursor(47, 2);   // start at top left, with one pixel of spacing
    matrix.print(minutes);
  }

  else {
    matrix.print(minutes);
  }
}

void printHours() {

  matrix.setTextSize(2);    // size 1 == 8 pixels high
  clearHour();
  matrix.setCursor(7, 2);

  if (hours < 10) {
    matrix.print('0');
    matrix.setCursor(19, 2);   // start at top left, with one pixel of spacing
    matrix.print(hours);
  }

  else {
    matrix.print(hours);
  }
}

void printWeekDay() {

  matrix.setCursor(6, 20);   // start at top left, with one pixel of spacing
  matrix.setTextSize(1);    // size 1 == 8 pixels high
  clearWeekDay();

  matrix.print(day[currentDay]);
}

void printMonthDay() {
  matrix.setCursor(24, 20);   // start at top left, with one pixel of spacing
  matrix.setTextSize(1);    // size 1 == 8 pixels high
  clearMonthDay();

  if (currentMonthDay < 10) {

    matrix.print('0');
    matrix.print(currentMonthDay);
  }

  else {

    matrix.print(currentMonthDay);
  }
}

void printMonth() {

  matrix.setCursor(41, 20);   // start at top left, with one pixel of spacing
  matrix.setTextSize(1);    // size 1 == 8 pixels high
  // print each letter with a rainbow color
  clearMonth();
  matrix.print(month[currentMonth]);
}

void timeSetup() {
  matrix.begin();
  matrix.setCursor(6, 20);   // start at top left, with one pixel of spacing
  matrix.setTextSize(1);    // size 1 == 8 pixels high
  matrix.setTextColor(matrix.Color333(5, 0, 0));

  matrix.print(day[currentDay]);
  matrix.setCursor(24, 20);   // start at top left, with one pixel of spacing
  if (currentMonthDay < 10) {
    matrix.print('0');
    matrix.print(currentMonthDay);
  }

  else {
    matrix.print(currentMonthDay);
  }

  matrix.setCursor(41, 20);
  matrix.print(month[currentMonth]);

  matrix.setTextSize(2);    // size 1 == 8 pixels high
  clearHour();
  matrix.setCursor(7, 2);

  if (hours < 10) {
    matrix.print('0');
    matrix.setCursor(19, 2);
    matrix.print(hours);
  }

  else {
    matrix.print(hours);
  }

  if (minutes <= 59) {
    matrix.setTextSize(2);    // size 1 == 8 pixels high
    clearMinute();
    matrix.setCursor(35, 2);

    if (minutes < 10) {
      matrix.print('0');
      matrix.setCursor(47, 2);   // start at top left, with one pixel of spacing
      matrix.print(minutes);
    }

    else {
      matrix.print(minutes);
    }
  }
}

void printAll() {
  clearMinute();
  clearHour();
  clearWeekDay();
  clearMonthDay();
  clearMonth();
  timeSetup();
}
