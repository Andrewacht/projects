#include <RGBmatrixPanel.h>
#include <arcade64_menu.h>
#include <arcade64_letters.h>
/****************Fields****************/

/**Matrix board setup**/
//#define CLK  8   // USE THIS ON ARDUINO UNO
#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

Arcade64Menu main_menu;
Arcade64Letters letters;


/*Button define for the example*/
#define button A4                                                 //Button for example
bool buttonState = false;                                         //Button for example
unsigned long buttonPrevious = 0;                                           //Button for example
  
void setup() {
  Serial.begin(9600);
  matrix.begin();
  pinMode (button, INPUT_PULLUP);                                 //Button for example
                                  
  main_menu.initMenu( 3,        //Amount of options
                      0, 3, 7,  //Other menu option colors
                      0, 7, 0,  //Selector color
                      matrix);  //the matrix object
                      
 letters.matrixWrite("abcdef",      //The word or letter
                      middle , start,   //X and Y coordinates ('middle', 'start' and 'end' are also valid)
                      7, 0, 0,      //The RGB values
                      matrix);      //The matrix object
  letters.matrixWrite("options",
                      end , middle,
                      7, 0, 0,
                      matrix);                                                        

  letters.matrixWrite("Credits",
                      middle , end,
                      7, 0, 0,
                      matrix);                                        


}
void loop(){
  main_menu.Menu(matrix); //Makes the menu blink
  
  listenMenu();                                                    //Button for example

}
 
/*Button code for this example*/
  
  void listenMenu(){
    buttonState = !digitalRead(button);
    unsigned long buttonMillis = millis();
    int buttonInterval = 500;
    
    if (buttonState == true) {
       if (buttonMillis - buttonPrevious >= buttonInterval) {
            main_menu.setSelector(1, matrix);    //move 1 option up
            buttonPrevious = buttonMillis;
       }
    }
  }
