#include <RGBmatrixPanel.h>

long currentMillis;
long prevMillis;
int minutes = 06;
int hours = 11;

String day[] = {"Ma", "Di", "Wo", "Do", "Vr", "Za", "Zo"};
int currentDay = 5;
String month[] = {"jan", "feb", "mar", "apr", "mei", "jun", "jul", "aug", "sep", "okt", "nov", "dec"};
int currentMonth = 11;
int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int currentMonthDay = 8;

#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

void setup() {
  matrix.begin();
  // draw some text!
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
  matrix.setTextColor(matrix.Color333(3, 0, 3));
  matrix.print(month[currentMonth]);

  show(31, 4, 2, 2, 5, 0, 0);
  show(31, 12, 2, 2, 5, 0, 0);

  matrix.setTextColor(matrix.Color333(3, 0, 3));
  matrix.setTextSize(2);    // size 1 == 8 pixels high
  clearHour();
  matrix.setCursor(7, 2);

  if (hours < 10) {
    matrix.print('0');
    matrix.setCursor(19, 2);   // start at top left, with one pixel of spacing
    matrix.setTextColor(matrix.Color333(3, 0, 3));
    matrix.print(hours);
  }

  else {
    matrix.print(hours);
  }
  
  if (minutes <= 59) {
    matrix.setTextColor(matrix.Color333(3, 0, 3));
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

  Serial.begin(9600);
  prevMillis = millis();
}

void loop() {
  currentMillis = millis();
 
  if (currentMillis - prevMillis >= 59425) {
    Serial.print(currentMillis - prevMillis);
    if (minutes < 59) {
      minutes++;
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

    else {
      minutes = 0;
      matrix.setTextSize(2);    // size 1 == 8 pixels high
      clearMinute();
      matrix.setCursor(35, 2);
      matrix.print('0');
      matrix.print(minutes);

      if (hours < 23) {
        hours++;
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
      
      else {
        hours = 0;
        matrix.setTextSize(2);    // size 1 == 8 pixels high
        clearHour();
        clearMonthDay();
        matrix.setCursor(7, 2);

        if (hours < 10) {
          matrix.print('0');
          matrix.setCursor(19, 2);   // start at top left, with one pixel of spacing
          matrix.print(hours);
        }

        else {
          matrix.print(hours);
        }

        if (currentDay < 6) {
          currentDay++;
        }

        else {
          currentDay = 0;
        }
        matrix.setCursor(6, 20);   // start at top left, with one pixel of spacing
          matrix.setTextSize(1);    // size 1 == 8 pixels high
          // print each letter with a rainbow color
          matrix.print(day[currentDay]);

        if (currentMonthDay < monthDays[currentMonth]) {
          currentMonthDay++;

          if (currentMonthDay < 10) {
            matrix.setCursor(24, 20);   // start at top left, with one pixel of spacing
            matrix.setTextSize(1);    // size 1 == 8 pixels high
            matrix.print('0');
            matrix.print(currentMonthDay);
          }
          
          else {
            matrix.setCursor(24, 20);   // start at top left, with one pixel of spacing
            matrix.setTextSize(1);
            matrix.print(currentMonthDay);
          }
        }
        
        else {
          currentMonthDay = 1;
          clearMonth();
          matrix.setCursor(24, 20);   // start at top left, with one pixel of spacing
          matrix.setTextSize(1);    // size 1 == 8 pixels high
          // print each letter with a rainbow color
          matrix.print('0');
          matrix.print(currentMonthDay);

          if (currentMonth < 11) {
            currentMonth++;
          }
          
          else {
            currentMonth = 0;
          }
          
          matrix.setCursor(41, 20);   // start at top left, with one pixel of spacing
          matrix.setTextSize(1);    // size 1 == 8 pixels high
          // print each letter with a rainbow color
          
          matrix.print(month[currentMonth]);
        }
      }

      Serial.print("hours: ");
      Serial.println(hours);
    }
    Serial.print("minutes: ");
    Serial.println(minutes);
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

void clearMonthDay() {
  matrix.fillRect(5, 20, 30, 12, matrix.Color333(0, 0, 0));
}

void clearMonth() {
  matrix.fillRect(39, 20, 30, 12, matrix.Color333(0, 0, 0));
}
