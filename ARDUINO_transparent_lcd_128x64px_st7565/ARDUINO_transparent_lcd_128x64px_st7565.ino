// transparent LCD from Crystalfontz 128x64px ST7565 with Arduino UNO
// created by upir, 2026
// youtube channel: https://www.youtube.com/upir_upir

// Youtube Video: https://youtu.be/ZfIvxvHziRA
// Source Files: https://github.com/upiir/transparent_lcd_display

// Links related to this project:
// Do you like this video? You can buy me a coffee ☕: https://www.buymeacoffee.com/upir
// Transparent LCD: https://www.crystalfontz.com/product/cfag12864u4nfi-128x64-transparent-graphic-lcd-display
// Mini transparent clock: https://s.click.aliexpress.com/e/_c3Cr0hBl
// Seeduino // 3.3V Arduino UNO: https://s.click.aliexpress.com/e/_c3eea2fl
// Getting started blog post: https://www.crystalfontz.com/blog/graphic-lcd-board-cfa10110-getting-started/
// Arduino DEMO source: https://github.com/crystalfontz/CFAG12864Tx_and_Ux_ST7565P
// Image2cpp converting images to c-style arrays: https://javl.github.io/image2cpp/
// Arduino UNO pinout: https://docs.arduino.cc/resources/pinouts/A000066-full-pinout.pdf
// u8g2 documentation: https://github.com/olikraus/u8g2/wiki/u8g2reference#drawxbmp

// Related videos:
// Transparent 128x128px OLED: https://youtu.be/HFeO1TjBkfM
// Transparent PCB: https://youtu.be/jDI_Xw7IoPI
// Transparent edgelit display: https://youtu.be/Cg9MDF1VE2g
// Transparent OLED menu: https://youtu.be/uEkksez7qvE
// Transparent OLED clock: https://youtu.be/OqqPvb8FEHs
// Transparent 3D cube: https://youtu.be/kBAcaA7NAlA
// Transparent OLED and Xiao: https://youtu.be/4GfPQoIRqW8


#include <Arduino.h>
#include <U8g2lib.h> // u8g2 library is used for drawing graphics on the display
#include <SPI.h> 

#include "images.h" // this file includes generated c-style arrays for all the screenshots


// ARD    | LCD  | Color
// ---------+--------+-------
// 3v3    | 3v3  |  Red
// GND    | GND  |  Black - ground
// D8     | DC   |  Green - data/command
// D9     | RES  |  Blue - reset
// D10    | CS   |  Purple - chip select
// D11    | D7   |  Gray - SPI data 
// D13    | D6   |  Orange - SPI clock

// display initilization
U8G2_ST7565_64128N_F_4W_HW_SPI u8g2(U8G2_R2, /*cs*/ 10, /*dc*/ 8 , /*reset*/ 9);


void setup(void) {
  u8g2.begin(); // begin function is required for u8g2
}

int counter;

void loop(void) {
  u8g2.clearBuffer();					// clear the internal memory
  u8g2.drawXBMP( 0, 0, 128, 64, epd_bitmap_allArray[counter]); // draw fullscreen image from images.h file
  u8g2.sendBuffer();					// transfer internal memory to the display
  delay(1000);  

  // increase the counter, we have 16 screenshots
  counter++;
  if (counter >= 16) {counter = 0;}
}
