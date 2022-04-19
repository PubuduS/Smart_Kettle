#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

#include <OneWire.h>
#include <DallasTemperature.h>

class TempSensor
{

    public:

        //! Data wire is plugged into digital pin 2 on the Arduino
        uint8_t ONE_WIRE_BUS = 2;

        //! Allocate variables
        TempSensor();

        //! Deallocate m_SensorsPtr pointer
        ~TempSensor();

        //! Determine whether relay should be on or off
        void SensorState( const bool OffFlag = false );

        //! Periodically polls for temperature
        //! Convert it to Celsius and return it.
        float GetTemperature();

    private:

        //! Defines the pin of the Relay
        const uint8_t RELAYPIN = 7;

        //! Describes Relay On or Off
        bool m_OffFlag;

        //! Setup a oneWire instance to communicate with any OneWire device
        OneWire m_OneWire;

        //! Pointer for sensor
        DallasTemperature* m_SensorsPtr = NULL;

};
#endif // TEMPSENSOR_H
