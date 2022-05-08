#ifndef LEDPANEL_H
#define LEDPANEL_H

#include <Arduino.h>

class LedPanel
{
  private:
      const uint8_t GREEN_LED_PIN = 10;
      const uint8_t YELLOW_LED_PIN = 11;
      const uint8_t RED_LED_PIN = 12;

      const uint8_t POWER_LED_PIN = 4;
      const uint8_t KEEP_WARM_LED_PIN = 5;

  public:

    //! Allocate variables and set everything off
    LedPanel();

    //! Display Led according to the temperature
    void ControlTempLED( const float temp = 0.0 );

    //! Indicate power is on or off
    void ControlPowerLED( const bool state = true );

    //! Indicate the keep warm function is on or off
    void ControlKeepWarmLED( const bool state = false );
};
#endif // LEDPANEL_H
