//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn ==chg to 4
 pin 11 is connected to the CLK ==chg to 2
 pin 10 is connected to LOAD ==chg to 3
 We have only a single MAX72XX. - if only 1 matrix is selected, will still control 2, but will be the same (OK?)
 */
LedControl lc=LedControl(4,2,3,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime=500;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,2);
  /* and clear the display */
  lc.clearDisplay(0);
}


void rows() {
  for(int row=0;row<8;row++) {
    delay(delaytime);
    lc.setRow(0,row,B10100000);
    delay(delaytime);
    lc.setRow(0,row,(byte)0);
    for(int i=0;i<row;i++) {
      delay(delaytime);
      lc.setRow(0,row,B10100000);
      delay(delaytime);
      lc.setRow(0,row,(byte)0);
    }
  }
}

/*
  This function lights up a some Leds in a column.
 The pattern will be repeated on every column.
 The pattern will blink along with the column-number.
 column number 4 (index==3) will blink 4 times etc.
 */
void columns() {
  for(int col=0;col<8;col++) {
    delay(delaytime);
    lc.setColumn(0,col,B10100000);
    delay(delaytime);
    lc.setColumn(0,col,(byte)0);
    for(int i=0;i<col;i++) {
      delay(delaytime);
      lc.setColumn(0,col,B10100000);
      delay(delaytime);
      lc.setColumn(0,col,(byte)0);
    }
  }
}

/* 
 This function will light up every Led on the matrix.
 The led will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void single() {
  for(int row=0;row<8;row++) {
    for(int col=0;col<8;col++) {
      delay(delaytime);
      lc.setLed(0,row,col,true);
      lc.setLed(1,row,col,true);
      delay(delaytime);
      for(int i=0;i<col;i++) {
        lc.setLed(0,row,col,false);
        lc.setLed(1,row,col,false);
        delay(delaytime);
        lc.setLed(0,row,col,true);
        lc.setLed(1,row,col,true);
        delay(delaytime);
      }
    }
  }
}
  
  void lookCenter(){
  //look center
  lc.clearDisplay(0);
  lc.setColumn(0,2,B00111100);
  lc.setColumn(0,3,B00111100);
  lc.setColumn(0,4,B00110100);  
  lc.setColumn(0,5,B00111100);
  }

  void lookLeft(){
  //look left
  lc.clearDisplay(0);
  lc.setColumn(0,2,B00011110);
  lc.setColumn(0,3,B00011110);
  lc.setColumn(0,4,B00011010);  
  lc.setColumn(0,5,B00011110);
  delay(delaytime);
  }
  void lookUpLeft(){
  //look up left
  lc.clearDisplay(0);
  lc.setColumn(0,3,B00011110);
  lc.setColumn(0,4,B00011110);
  lc.setColumn(0,5,B00011010);  
  lc.setColumn(0,6,B00011110);
  delay(delaytime);
  }
  void lookUpCenter(){
  //look up center
  lc.clearDisplay(0);
  lc.setColumn(0,3,B00111100);
  lc.setColumn(0,4,B00111100);
  lc.setColumn(0,5,B00110100);  
  lc.setColumn(0,6,B00111100);
  delay(delaytime);
  }
  void lookUpRight(){
  lc.clearDisplay(0);
  lc.setColumn(0,3,B01111000);
  lc.setColumn(0,4,B01111000);
  lc.setColumn(0,5,B01101000);  
  lc.setColumn(0,6,B01111000);
  delay(delaytime); 
  }
  void lookRight(){
  //look right
  lc.clearDisplay(0);
  lc.setColumn(0,2,B01111000);
  lc.setColumn(0,3,B01111000);
  lc.setColumn(0,4,B01101000);  
  lc.setColumn(0,5,B01111000);
  delay(delaytime);
  }
void loop(){ 
lookCenter();
lookLeft();
lookRight();
lookCenter();
lookLeft();
lookUpLeft();
lookUpCenter();
lookUpRight();
lookRight();

}
