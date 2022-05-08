#include "LedPanel.h"

LedPanel::LedPanel()
{
    pinMode( GREEN_LED_PIN, OUTPUT );
    pinMode( YELLOW_LED_PIN, OUTPUT );
    pinMode( RED_LED_PIN, OUTPUT );

    pinMode( POWER_LED_PIN, OUTPUT );
    pinMode( KEEP_WARM_LED_PIN, OUTPUT );

    digitalWrite( GREEN_LED_PIN, LOW );
    digitalWrite( YELLOW_LED_PIN, LOW );
    digitalWrite( RED_LED_PIN, LOW );

    digitalWrite( POWER_LED_PIN, LOW );
    digitalWrite( KEEP_WARM_LED_PIN, LOW );
}

void LedPanel::ControlTempLED( const float temp )
{
    if( ( temp >= 0 ) && ( temp <= 40.0 ) )
    {
        digitalWrite( YELLOW_LED_PIN, LOW );
        digitalWrite( GREEN_LED_PIN, LOW );
        digitalWrite( RED_LED_PIN, HIGH );
    }
    else if( ( temp > 40.0 ) && ( temp <= 80.0 ) )
    {
        digitalWrite( RED_LED_PIN, LOW );
        digitalWrite( GREEN_LED_PIN, LOW );
        digitalWrite( YELLOW_LED_PIN, HIGH );
    }
    else if( ( temp > 80.0 ) && ( temp <= 100.0 ) )
    {
        digitalWrite( RED_LED_PIN, LOW );
        digitalWrite( YELLOW_LED_PIN, LOW );
        digitalWrite( GREEN_LED_PIN, HIGH );
    }
    else
    {
        digitalWrite( RED_LED_PIN, HIGH );
        digitalWrite( YELLOW_LED_PIN, HIGH );
        digitalWrite( GREEN_LED_PIN, HIGH );
        delay( 1000 );

        digitalWrite( RED_LED_PIN, LOW );
        digitalWrite( YELLOW_LED_PIN, LOW );
        digitalWrite( GREEN_LED_PIN, LOW );
        delay(1000);
    }
}

void LedPanel::ControlPowerLED( const bool stateFlag )
{
    switch( stateFlag )
    {
        case true:
            digitalWrite( POWER_LED_PIN, HIGH );
            break;
        case false:
            digitalWrite( POWER_LED_PIN, LOW );
            break;
    }
}

void LedPanel::ControlKeepWarmLED( const bool warmFlag )
{
    switch( warmFlag )
    {
        case true:
            digitalWrite( KEEP_WARM_LED_PIN, HIGH );
            break;
        case false:
            digitalWrite( KEEP_WARM_LED_PIN, LOW );
            break;
    }
}
