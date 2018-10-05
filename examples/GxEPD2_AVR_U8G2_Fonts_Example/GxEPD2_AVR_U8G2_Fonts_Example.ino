// Display Library example for SPI e-paper panels from Dalian Good Display and boards from Waveshare.
// Requires HW SPI and Adafruit_GFX. Caution: these e-papers require 3.3V supply AND data lines!
//
// based on Demo Example from Good Display: http://www.good-display.com/download_list/downloadcategoryid=34&isMode=false.html
//
// Author: Jean-Marc Zingg
//
// Version: see library.properties
//
// Library: https://github.com/ZinggJM/GxEPD2_AVR
//
// GxEPD2_AVR_U8G2_Fonts_Example : show use of U8G2_FOR_ADAFRUIT_GFX with GxEPD2
//
// Library: https://github.com/olikraus/U8g2_for_Adafruit_GFX
// see: https://github.com/olikraus/U8g2_for_Adafruit_GFX/blob/master/README.md
//
// This version uses the U8G2_FONTS_GFX addition for newline support (issue #5)
//
// NOTE: you need to SAVE the modified example to a saveable location for UTF-8 characters to work
//       e.g. for Umlauts

// Supporting Arduino Forum Topics:
// Waveshare e-paper displays with SPI: http://forum.arduino.cc/index.php?topic=487007.0
// Good Dispay ePaper for Arduino : https://forum.arduino.cc/index.php?topic=436411.0

// mapping suggestion from Waveshare SPI e-Paper to Wemos D1 mini
// BUSY -> D2, RST -> D4, DC -> D3, CS -> D8, CLK -> D5, DIN -> D7, GND -> GND, 3.3V -> 3.3V

// mapping suggestion from Waveshare SPI e-Paper to generic ESP8266
// BUSY -> GPIO4, RST -> GPIO2, DC -> GPIO0, CS -> GPIO15, CLK -> GPIO14, DIN -> GPIO13, GND -> GND, 3.3V -> 3.3V

// mapping suggestion for ESP32, e.g. LOLIN32, see .../variants/.../pins_arduino.h for your board
// NOTE: there are variants with different pins for SPI ! CHECK SPI PINS OF YOUR BOARD
// BUSY -> 4, RST -> 16, DC -> 17, CS -> SS(5), CLK -> SCK(18), DIN -> MOSI(23), GND -> GND, 3.3V -> 3.3V

// new mapping suggestion for STM32F1, e.g. STM32F103C8T6 "BluePill"
// BUSY -> A1, RST -> A2, DC -> A3, CS-> A4, CLK -> A5, DIN -> A7

#include <GxEPD2_AVR_BW.h>
#include <GxEPD2_AVR_3C.h>
//#include <U8g2_for_Adafruit_GFX.h>
#include "additions/U8G2_FONTS_GFX.h"

#if defined(__AVR)
// select one and adapt to your mapping
//GxEPD2_AVR_BW display(GxEPD2::GDEP015OC1, /*CS=*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7);
//GxEPD2_AVR_BW display(GxEPD2::GDE0213B1, /*CS=*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7);
//GxEPD2_AVR_BW display(GxEPD2::GDEH029A1, /*CS=*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7);
//GxEPD2_AVR_BW display(GxEPD2::GDEW027W3, /*CS=*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7);
GxEPD2_AVR_BW display(GxEPD2::GDEW042T2, /*CS=*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7);
//GxEPD2_AVR_BW display(GxEPD2::GDEW075T8, /*CS=*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7);
// 3-color e-papers
//GxEPD2_AVR_3C display(GxEPD2::GDEW0154Z04, /*CS=*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7);
//GxEPD2_AVR_3C display(GxEPD2::GDEW0213Z16, /*CS=*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7);
//GxEPD2_AVR_3C display(GxEPD2::GDEW029Z10, /*CS=*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7);
//GxEPD2_AVR_3C display(GxEPD2::GDEW027C44, /*CS=*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7);
//GxEPD2_AVR_3C display(GxEPD2::GDEW042Z15, /*CS=*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7);
#endif

// for test on ESP8266
#if defined (ESP8266)
// select one and adapt to your mapping
//GxEPD2_AVR_BW display(GxEPD2::GDEP015OC1, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
//GxEPD2_AVR_BW display(GxEPD2::GDE0213B1, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
//GxEPD2_AVR_BW display(GxEPD2::GDEH029A1, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
//GxEPD2_AVR_BW display(GxEPD2::GDEW027W3, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
GxEPD2_AVR_BW display(GxEPD2::GDEW042T2, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
//GxEPD2_AVR_BW display(GxEPD2::GDEW075T8,  /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
// 3-color e-papers
//GxEPD2_AVR_3C display(GxEPD2::GDEW0154Z04,  /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
//GxEPD2_AVR_3C display(GxEPD2::GDEW0213Z16,  /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
//GxEPD2_AVR_3C display(GxEPD2::GDEW029Z10,  /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
//GxEPD2_AVR_3C display(GxEPD2::GDEW027C44,  /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
//GxEPD2_AVR_3C display(GxEPD2::GDEW042Z15,  /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4);
#endif

//U8G2_FOR_ADAFRUIT_GFX u8g2_for_adafruit_gfx;

U8G2_FONTS_GFX u8g2Fonts(display);

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println(F("setup"));
  display.init();
  //u8g2_for_adafruit_gfx.begin(display); // connect u8g2 procedures to Adafruit GFX
  helloWorld();
  delay(1000);
  helloArduino();
  delay(1000);
  helloEpaper();
  delay(1000);
  showFont(F("u8g2_font_helvR14_tf"), u8g2_font_helvR14_tf); // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  delay(2000);
  showFont(F("u8g2_font_profont22_mr"), u8g2_font_profont22_mr); // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  delay(1000);
  Serial.println(F("setup done"));
}

void loop()
{
}

void helloWorld()
{
  //Serial.println(F("helloWorld"));
  uint16_t bg = GxEPD_WHITE;
  uint16_t fg = GxEPD_BLACK;
  u8g2Fonts.setFontMode(1);                 // use u8g2 transparent mode (this is default)
  u8g2Fonts.setFontDirection(0);            // left to right (this is default)
  u8g2Fonts.setForegroundColor(fg);         // apply Adafruit GFX color
  u8g2Fonts.setBackgroundColor(bg);         // apply Adafruit GFX color
  u8g2Fonts.setFont(u8g2_font_helvR14_tf);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  uint16_t x = (display.width() - 160) / 2;
  uint16_t y = display.height() / 2;
  display.firstPage();
  do
  {
    display.fillScreen(bg);
    u8g2Fonts.setCursor(x, y); // start writing at this position
    u8g2Fonts.print(F("Hello World!"));
  }
  while (display.nextPage());
  //Serial.println(F("helloWorld done"));
}

void helloArduino()
{
  //Serial.println(F("helloArduino"));
  uint16_t bg = GxEPD_WHITE;
  uint16_t fg = (display.hasColor() ? GxEPD_RED : GxEPD_BLACK);
  u8g2Fonts.setFontMode(1);                 // use u8g2 transparent mode (this is default)
  u8g2Fonts.setFontDirection(0);            // left to right (this is default)
  u8g2Fonts.setForegroundColor(fg);         // apply Adafruit GFX color
  u8g2Fonts.setBackgroundColor(bg);         // apply Adafruit GFX color
  u8g2Fonts.setFont(u8g2_font_helvR14_tf);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  uint16_t x = (display.width() - 160) / 2;
  uint16_t y = display.height() / 4;
  display.setPartialWindow(0, y - 14, display.width(), 20);
  display.firstPage();
  do
  {
    display.fillScreen(bg);
    u8g2Fonts.setCursor(x, y);
    u8g2Fonts.println(F("Hello Arduino!"));
  }
  while (display.nextPage());
  //Serial.println(F("helloArduino done"));
}

void helloEpaper()
{
  //Serial.println(F("helloEpaper"));
  uint16_t bg = GxEPD_WHITE;
  uint16_t fg = (display.hasColor() ? GxEPD_RED : GxEPD_BLACK);
  u8g2Fonts.setFontMode(1);                 // use u8g2 transparent mode (this is default)
  u8g2Fonts.setFontDirection(0);            // left to right (this is default)
  u8g2Fonts.setForegroundColor(fg);         // apply Adafruit GFX color
  u8g2Fonts.setBackgroundColor(bg);         // apply Adafruit GFX color
  u8g2Fonts.setFont(u8g2_font_helvR14_tf);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  uint16_t x = (display.width() - 160) / 2;
  uint16_t y = display.height() * 3 / 4;
  display.setPartialWindow(0, y - 14, display.width(), 20);
  display.firstPage();
  do
  {
    display.fillScreen(bg);
    u8g2Fonts.setCursor(x, y);
    u8g2Fonts.println(F("Hello E-Paper!"));
  }
  while (display.nextPage());
  //Serial.println("F(helloEpaper done"));
}

void showFont(const __FlashStringHelper* name, const uint8_t *font)
{
  display.setFullWindow();
  display.setRotation(0);
  u8g2Fonts.setFontMode(1);                   // use u8g2 transparent mode (this is default)
  u8g2Fonts.setFontDirection(0);              // left to right (this is default)
  u8g2Fonts.setForegroundColor(GxEPD_BLACK);  // apply Adafruit GFX color
  u8g2Fonts.setBackgroundColor(GxEPD_WHITE);  // apply Adafruit GFX color
  u8g2Fonts.setFont(font); // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  display.firstPage();
  do
  {
    drawFont(name);
  }
  while (display.nextPage());
}

void drawFont(const __FlashStringHelper* name)
{
  //display.setRotation(0);
  display.fillScreen(GxEPD_WHITE);
  u8g2Fonts.setCursor(0, 0);
  u8g2Fonts.println();
  u8g2Fonts.println(name);
  u8g2Fonts.println(F(" !\"#$%&'()*+,-./"));
  u8g2Fonts.println(F("0123456789:;<=>?"));
  u8g2Fonts.println(F("@ABCDEFGHIJKLMNO"));
  u8g2Fonts.println(F("PQRSTUVWXYZ[\\]^_"));
  if (display.hasColor())
  {
    u8g2Fonts.setForegroundColor(GxEPD_RED);
  }
  u8g2Fonts.println(F("`abcdefghijklmno"));
  u8g2Fonts.println(F("pqrstuvwxyz{|}~ "));
  u8g2Fonts.println(F("Umlaut ÄÖÜäéöü"));
}


