#include "WriteToScreen.h"

    const unsigned char WriteToScreen::frame0[] PROGMEM =  {0x01, 0x00, 0x01, 0x00, 0x02, 0x40, 0x02, 0x80, 0x04, 0x80, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x08, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame1[] PROGMEM =  {0x01, 0x00, 0x01, 0x00, 0x02, 0x40, 0x02, 0x80, 0x04, 0x80, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x08, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame2[] PROGMEM =  {0x01, 0x00, 0x01, 0x00, 0x02, 0x40, 0x02, 0x80, 0x04, 0x80, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x08, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame3[] PROGMEM = {0x01, 0x00, 0x01, 0x00, 0x02, 0x40, 0x02, 0x80, 0x04, 0x80, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x08, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame4[] PROGMEM = {0x01, 0x00, 0x01, 0x00, 0x02, 0x40, 0x02, 0x80, 0x04, 0x80, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x08, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame5[] PROGMEM = {0x01, 0x00, 0x01, 0x00, 0x02, 0x40, 0x02, 0x80, 0x00, 0x80, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x08, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame6[] PROGMEM = {0x01, 0x00, 0x01, 0x00, 0x03, 0x40, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x10, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame7[] PROGMEM = {0x01, 0x00, 0x01, 0x00, 0x00, 0x40, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x10, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame8[] PROGMEM = {0x01, 0x00, 0x01, 0x00, 0x00, 0x40, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x10, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame9[] PROGMEM =  {0x01, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x10, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame10[] PROGMEM = {0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x10, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame11[] PROGMEM = {0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x10, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame12[] PROGMEM = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x10, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame13[] PROGMEM =  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x10, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame14[] PROGMEM = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x10, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame15[] PROGMEM = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x10, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame16[] PROGMEM =  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x10, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame17[] PROGMEM = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x10, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame18[] PROGMEM = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x10, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame19[] PROGMEM = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x04, 0x00, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x10, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame20[] PROGMEM = {0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x06, 0x00, 0x04, 0x00, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x10, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame21[] PROGMEM = {0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x02, 0x00, 0x04, 0x80, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x08, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame22[] PROGMEM = {0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x02, 0x80, 0x04, 0x80, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x08, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame23[] PROGMEM = {0x01, 0x00, 0x01, 0x00, 0x02, 0x00, 0x02, 0x80, 0x04, 0x80, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x08, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame24[] PROGMEM = {0x01, 0x00, 0x01, 0x00, 0x02, 0x40, 0x02, 0x80, 0x04, 0x80, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x08, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame25[] PROGMEM = {0x01, 0x00, 0x01, 0x00, 0x02, 0x40, 0x02, 0x80, 0x04, 0x80, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x08, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame26[] PROGMEM = {0x01, 0x00, 0x01, 0x00, 0x02, 0x40, 0x02, 0x80, 0x04, 0x80, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x08, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};

    const unsigned char WriteToScreen::frame27[] PROGMEM = {0x01, 0x00, 0x01, 0x00, 0x02, 0x40, 0x02, 0x80, 0x04, 0x80, 0x00, 0x00, 0x1F, 0xF0, 0x10, 0x10, 0x10, 0x3C, 0x08, 0x24, 0x08, 0x24, 0x08, 0x3C, 0x08, 0x30, 0x08, 0x20, 0x08, 0x20, 0x0F, 0xE0};


WriteToScreen::WriteToScreen()
{
  m_DisplayPtr = new Adafruit_SSD1306( SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESETBTN);
}

WriteToScreen::~WriteToScreen()
{
  delete m_DisplayPtr;
  m_DisplayPtr = NULL;
}


void WriteToScreen::SetupScreen()const
{
  if( !m_DisplayPtr->begin( SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS ) )
  {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  m_DisplayPtr->display();
  delay(2000);

  m_DisplayPtr->clearDisplay();
  return;
}

void WriteToScreen::SendToScreen( const String message, const uint8_t xPos, const uint8_t yPos, const uint8_t textSize )const
{
  m_DisplayPtr->setTextSize(textSize);             // Normal 1:1 pixel scale
  m_DisplayPtr->setTextColor(SSD1306_WHITE);        // Draw white text
  m_DisplayPtr->setCursor(xPos, yPos);             // Start at top-left corner
  m_DisplayPtr->println(message);

  m_DisplayPtr->display();
  delay(2000);
  return;
}

void WriteToScreen::DrawCoffeeAnimation( const uint8_t xx, const uint8_t yy, const uint8_t tt )
{
    for( uint8_t i = 0; i < 28; ++i )
    {
        m_DisplayPtr->clearDisplay();
        m_DisplayPtr->drawBitmap(xx, yy, frameNames[i], 16, 16, 1);
        m_DisplayPtr->display();
        delay(tt);
    }
}

void WriteToScreen::ClearScreen() const
{
  m_DisplayPtr->clearDisplay();
  return;
}
