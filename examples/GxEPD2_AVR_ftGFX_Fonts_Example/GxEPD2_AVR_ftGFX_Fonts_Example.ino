// Display Library example for SPI e-paper panels from Dalian Good Display and boards from Waveshare.
// Requires HW SPI and Adafruit_GFX. Caution: these e-papers require 3.3V supply AND data lines!
//
// based on Demo Example from Good Display: http://www.good-display.com/download_list/downloadcategoryid=34&isMode=false.html
//
// Author: Jean-Marc Zingg
//
// Version: see library.properties
//
// Library: https://github.com/ZinggJM/GxEPD2_32
//
// GxEPD2_AVR_ftGFX_Fonts_Example : show use of ftGFX_for_Adafruit_GFX with GxEPD2
//
// ftGFX_for_Adafruit_GFX uses Adafruit_ftGFX from https://github.com/ZinggJM/Adafruit_ftGFX
//
// Initial, experimental version GxEPD2_32_ftGFX_Fonts_Example! for test use only

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
#include <additions/ftGFX_for_Adafruit_GFX.h>

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

ftGFX_for_Adafruit_GFX ftGFX(display);

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println(F("setup"));
  display.init();
  helloWorld();
  delay(1000);
  helloArduino();
  delay(1000);
  helloEpaper();
  delay(1000);
  showFont(F("Open_Sans_Bold_12pt"), OPENSANSBOLD_12);
  delay(2000);
  //showFont(F("Open_Sans_Bold_14pt"), OPENSANSBOLD_14);
  //delay(2000);
  showCharacterSet(OPENSANSBOLD_12);
  //delay(2000);
  //showCharacterSet(OPENSANSBOLD_14);
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
  ftGFX.setFont(OPENSANSBOLD_12);
  ftGFX.setTextColor(fg, bg);
  uint16_t x = (display.width() - 160) / 2;
  uint16_t y = display.height() / 2;
  display.firstPage();
  do
  {
    display.fillScreen(bg);
    ftGFX.setCursor(x, y); // start writing at this position
    ftGFX.print(F("Hello World!"));
  }
  while (display.nextPage());
  //Serial.println(F("helloWorld done"));
}

void helloArduino()
{
  //Serial.println(F("helloArduino"));
  uint16_t bg = GxEPD_WHITE;
  uint16_t fg = (display.hasColor() ? GxEPD_RED : GxEPD_BLACK);
  ftGFX.setFont(OPENSANSBOLD_12);
  ftGFX.setTextColor(fg, bg);
  uint16_t x = (display.width() - 160) / 2;
  uint16_t y = display.height() / 4;
  display.setPartialWindow(0, y, display.width(), 20);
  display.firstPage();
  do
  {
    display.fillScreen(bg);
    ftGFX.setCursor(x, y);
    ftGFX.println(F("Hello Arduino!"));
  }
  while (display.nextPage());
  //Serial.println(F("helloArduino done"));
}

void helloEpaper()
{
  //Serial.println(F("helloEpaper"));
  uint16_t bg = GxEPD_WHITE;
  uint16_t fg = (display.hasColor() ? GxEPD_RED : GxEPD_BLACK);
  ftGFX.setFont(OPENSANSBOLD_12);
  ftGFX.setTextColor(fg, bg);
  uint16_t x = (display.width() - 160) / 2;
  uint16_t y = display.height() * 3 / 4;
  display.setPartialWindow(0, y, display.width(), 20);
  display.firstPage();
  do
  {
    display.fillScreen(bg);
    ftGFX.setCursor(x, y);
    ftGFX.println(F("Hello E-Paper!"));
  }
  while (display.nextPage());
  //Serial.println("F(helloEpaper done"));
}

void showFont(const __FlashStringHelper* name, uint8_t font)
{
  display.setFullWindow();
  display.setRotation(0);
  ftGFX.setFont(font);
  ftGFX.setTextColor(GxEPD_BLACK, GxEPD_WHITE);
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
  ftGFX.setCursor(0, 0);
  //ftGFX.println();
  ftGFX.println(name);
  ftGFX.println(F(" !\"#$%&'()*+,-./"));
  ftGFX.println(F("0123456789:;<=>?"));
  ftGFX.println(F("@ABCDEFGHIJKLMNO"));
  ftGFX.println(F("PQRSTUVWXYZ[\\]^_"));
  if (display.hasColor())
  {
    ftGFX.setTextColor(GxEPD_RED, GxEPD_WHITE);
  }
  ftGFX.println(F("`abcdefghijklmno"));
  ftGFX.println(F("pqrstuvwxyz{|}~ "));
  delay(1);
  ftGFX.println(F("Umlaut ÄÖÜäéöü"));
}

void showCharacterSet(uint8_t font)
{
  ftGFX.setFont(font);
  ftGFX.setTextColor(GxEPD_BLACK, GxEPD_WHITE);
  uint16_t perLine = ftGFX.width() / ftGFX.getStringWidth(F("A"));
  uint16_t perColumn = ftGFX.height() / ftGFX.getCharHeight();
  uint16_t lines = (255 - 0x20) / perLine;
  uint16_t pages = lines / perColumn;
  uint16_t chr = 0x20;
  for (uint16_t page = 0; page <= pages; page++)
  {
    display.firstPage();
    do
    {
      uint16_t pchr = chr;
      ftGFX.setCursor(0, 0);
      display.fillScreen(GxEPD_WHITE);
      for (uint16_t l = 0; (l <= lines) && (pchr < 255); l++)
      {
        for (uint16_t c = 0; (c < perLine) && (pchr < 255); c++, pchr++)
        {
          ftGFX.write(pchr);
        }
        ftGFX.write('\n');
      }
    }
    while (display.nextPage());
    chr += perLine * perColumn;
    delay(2000);
  }
}


