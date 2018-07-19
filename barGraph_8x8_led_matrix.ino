/*
  LED bar graph

  Turns on an LED matrix based on the value of an analog sensor.
 
  The circuit:
   * 3 pin 7219 LED interface as defined under constants
   * Potentiometer or analog source on Pin A0

 created 9 July 2018
 by Reuben Burton

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/BarGraph
 */
#include <MaxMatrix.h>
#include <avr/pgmspace.h>

// these constants won't change:
const int analogPin = A0;   // the pin that the potentiometer is attached to
const int ledCount = 9;    // the height of the bar graph inc 0
const int buffer1 = 9;    //buffer for input signal

int DIN = 2;   // DIN pin of MAX7219 module
int CLK = 4;   // CLK pin of MAX7219 module
int CS = 3;    // CS pin of MAX7219 module
int maxInUse = 1; //number of MAX7219 modules in daisy chain
int shift_speed = 50; //This value can be changed to slow down or speed up LED scroll
int ledarray[] = {0, 1, 3, 7, 15, 31, 63, 127, 255}; //array for led matrix (unsigned byte-dec)
int ledarray2[] = {0, 128, 192, 224, 240, 248, 252, 254, 255}; //array for matrix opposite side
MaxMatrix m(DIN, CS, CLK, maxInUse);
//To flip the bar graph 180 degrees, simply change ledarray2 to ledarray in line 44

void setup() {
   m.init(); // module initialize
  m.setIntensity(15); // dot matix intensity 0-15
  }

void loop() {
  // read the analog source:
  int sensorReading = analogRead(analogPin);
  // map the result to a range from 0 to the number of LEDs:
  byte ledLevel = map(sensorReading, 0, 1023, 0, ledCount);
  int(ledLevel2) = ledarray2[ledLevel]; //converts input signal from unsigned byte to dec
m.setColumn(buffer1, ledLevel2);
delay(shift_speed);
m.shiftLeft(false, false);
    }




