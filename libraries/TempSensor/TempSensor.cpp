#include "TempSensor.h"

TempSensor::TempSensor(): m_OneWire( OneWire(ONE_WIRE_BUS)), m_SensorsPtr( new DallasTemperature(&m_OneWire) ), m_OffFlag( false )
{
    Serial.begin(9600);
    pinMode( RELAYPIN, OUTPUT );
    m_SensorsPtr->begin();
}

TempSensor::~TempSensor()
{
    delete m_SensorsPtr;
    m_SensorsPtr = NULL;
}

void TempSensor::SensorState( const bool OffFlag )
{
    m_OffFlag = OffFlag;

    if( OffFlag )
    {
        digitalWrite( RELAYPIN, LOW );
        return;
    }

    digitalWrite( RELAYPIN, HIGH );
}

float TempSensor::GetTemperature()
{
    float temp = ( m_SensorsPtr->getTempCByIndex(0) );
    /*
    if( m_OffFlag )
    {
        Serial.print(F("Heater is off "));
        return temp;
    }
    */

    delay( 500 );
    m_SensorsPtr->requestTemperatures();

    return temp;
}
