//Not my work, based off of an example from adafruit neomatrix, name=matrixtest
//I have added comments for simplification

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define PIN 6 //pin on arduino that you will use
int repeat1=random(0, 255);
int repeat2=random(0, 255);
int repeat3=random(0, 255);
// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_GRBW    Pixels are wired for GRBW bitstream (RGB+W NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)


// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(43, 7, PIN, //Matrix must be 7 tall for it to work, legnth doesn't matter
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT + //change depending on orientation, if arduino at top left, these are the settings, scrolling will be from right to left
  NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_RGB);

const uint16_t colors[] = {
   matrix.Color(200, 0, 0), matrix.Color(0, 200, 0), matrix.Color(0, 0, 200), matrix.Color(200, 0, 200), matrix.Color(0, 200, 200), matrix.Color(200, 200, 0), matrix.Color(repeat1, repeat2, repeat3) };
//above line is colors, edit as you like between 0 and 255, if you add or delete matrix.Color in above function, change the pass number below
void setup() {
  delay(5000); //for your sanity, else it starts up right when it gets power: leave it so that you can go hide before it turns on
  matrix.begin();
  matrix.setTextWrap(true);
  matrix.setBrightness(10); //brightness, works best between 1 and 10, anything above stays the same as 10
  matrix.setTextColor(colors[0]);
}

int x    = matrix.width();
int pass = 0;

void loop() {
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print(F("Wash Your Hands!  Stay Home!  Front Line Workers, Thank You!")); //Change the words here if you want to
  if(--x < -330) { //change the x number depending on above line, each letter approx. 6 pixels wide
    x = matrix.width();
    if(++pass >= 7) pass = 0; //change number of greater than to number of colors in above function
    matrix.setTextColor(colors[pass]);
  }
  matrix.show();
  delay(25); //adjust this number for scroll speed (aka rerfresh rate)
  repeat1=random(0, 255);
  repeat2=random(0, 255);
  repeat3=random(0, 255);
}
