#ifndef WRITETOSCREEN_H
#define WRITETOSCREEN_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <avr/pgmspace.h>

class WriteToScreen
{
  public:

    //! Each of these holds bytes of a frame of coffee animation.
    static const unsigned char frame0[] PROGMEM;

    static const unsigned char frame1[] PROGMEM;

    static const unsigned char frame2[] PROGMEM;

    static const unsigned char frame3[] PROGMEM;

    static const unsigned char frame4[] PROGMEM;

    static const unsigned char frame5[] PROGMEM;

    static const unsigned char frame6[] PROGMEM;

    static const unsigned char frame7[] PROGMEM;

    static const unsigned char frame8[] PROGMEM;

    static const unsigned char frame9[] PROGMEM;

    static const unsigned char frame10[] PROGMEM;

    static const unsigned char frame11[] PROGMEM;

    static const unsigned char frame12[] PROGMEM;

    static const unsigned char frame13[] PROGMEM;

    static const unsigned char frame14[] PROGMEM;

    static const unsigned char frame15[] PROGMEM;

    static const unsigned char frame16[] PROGMEM;

    static const unsigned char frame17[] PROGMEM;

    static const unsigned char frame18[] PROGMEM;

    static const unsigned char frame19[] PROGMEM;

    static const unsigned char frame20[] PROGMEM;

    static const unsigned char frame21[] PROGMEM;

    static const unsigned char frame22[] PROGMEM;

    static const unsigned char frame23[] PROGMEM;

    static const unsigned char frame24[] PROGMEM;

    static const unsigned char frame25[] PROGMEM;

    static const unsigned char frame26[] PROGMEM;

    static const unsigned char frame27[] PROGMEM;

    //! Define the constructor.
    //! Allocate pointer m_DisplayPtr
    WriteToScreen();

    //! Define the destructor.
    //! Deallocate pointer m_DisplayPtr
    ~WriteToScreen();

    //! Handles SSD1306 Memory Allocation Error
    //! SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    void SetupScreen() const;

    //! Accept incoming message and display the message in screen.
    void SendToScreen( const String message, const uint8_t xPos, const uint8_t yPos, const uint8_t textSize = 1) const;

    //! Draw a hot coffee mug animation on the screen.
    void DrawCoffeeAnimation( const uint8_t xx = 40, const uint8_t yy = 0, const uint8_t tt = 0 );

    //! Clear the content buffer to clear the screen.
    void ClearScreen() const;

  private:
    const uint8_t SCREEN_WIDTH = 128;
    const uint8_t SCREEN_HEIGHT = 64;

    //! Share the Arduino Reset pin
    const int8_t OLED_RESETBTN = -1;
    const uint8_t SCREEN_ADDRESS = 0x3C;

    //! Pointer to Adafruit_SSD1306 Drivers
    Adafruit_SSD1306* m_DisplayPtr = NULL;

    //! Holds pointers to byte arrays that contains animation frames.
    const unsigned char* frameNames[29] = { frame0, frame1, frame2, frame3, frame4, frame5, frame6, frame7, frame8, frame9, frame10,
                                            frame11, frame12, frame13, frame14, frame15, frame16, frame17, frame18, frame19, frame20,
                                            frame21, frame22, frame23, frame24, frame25, frame26, frame27 };

};
#endif
