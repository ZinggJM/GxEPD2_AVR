# GxEPD2_AVR
Simplified Version of GxEPD for AVR Arduino

## for SPI e-paper displays from Dalian Good Display 
## and SPI e-paper boards from Waveshare

### important note :
### - these displays are for 3.3V supply and 3.3V data lines
### - never connect data lines directly to 5V Arduino data pins, you may use e.g. 4k7 series resistor


### Paged Drawing, Picture Loop
#### - This library uses paged drawing to cope with RAM restriction and missing single pixel update support
#### - Paged drawing is implemented as picture loop, like in U8G2 (Oliver Kraus)
#### - see https://github.com/olikraus/u8glib/wiki/tpictureloop

### Supporting Arduino Forum Topics:

- Waveshare e-paper displays with SPI: http://forum.arduino.cc/index.php?topic=487007.0
- Good Dispay ePaper for Arduino : https://forum.arduino.cc/index.php?topic=436411.0

### Version 1.0.1
- Example Bitmaps & 4.2" b/w fast partial update
