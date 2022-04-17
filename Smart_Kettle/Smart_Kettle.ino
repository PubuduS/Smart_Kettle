#include <WriteToScreen.h>

WriteToScreen m_Screen;

void setup() {
  // put your setup code here, to run once:
  m_Screen.SetupScreen();
  m_Screen.SendToScreen("hello", (uint8_t)40, (uint8_t)30);  
  m_Screen.SendToScreen("World", (uint8_t)40, (uint8_t)40);

}

void loop() {
  // put your main code here, to run repeatedly:
  m_Screen.DrawCoffeeAnimation( 0, 0, 0);
}
