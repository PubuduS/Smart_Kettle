/**@file Smart_Kettle.ino */
#include <WriteToScreen.h>
#include <TempSensor.h>
#include <LedPanel.h>
#include "arduino_secrets.h"
#include <Firebase_Arduino_WiFiNINA.h>

// Pins
const uint8_t btn_Pin = 3;
const uint8_t led_Pin = 9;
const uint8_t buzzer_Pin = 8;

// Globals
volatile bool heater_State = true;
float temperature = 0.0;
bool m_KeepWarmFlag = false;

WriteToScreen m_Screen;
TempSensor m_Sensor;
LedPanel m_LedPanel;
FirebaseData firebaseData;

String m_Path = "/ThermoBot/";

void setup() 
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode( btn_Pin, INPUT_PULLUP );
  pinMode( led_Pin, OUTPUT );
  pinMode( buzzer_Pin, OUTPUT );

  // Serial.print("Connecting to WiFi…");
  uint8_t status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED) {
    status = WiFi.begin( WIFI_SSID, WIFI_PASSWORD );
    // Serial.print(".");
    delay(300);
  }
  //Serial.print(" IP: ");
  Serial.println( WiFi.localIP() );
  // Serial.println();

  Firebase.begin( FIREBASE_HOST, FIREBASE_AUTH, WIFI_SSID, WIFI_PASSWORD );
  Firebase.reconnectWiFi(true);

  digitalWrite( led_Pin, LOW );
  attachInterrupt( digitalPinToInterrupt( btn_Pin ), ToggleState, RISING );
  attachInterrupt( digitalPinToInterrupt( led_Pin ), ToggleState, RISING );
  
  m_Screen.SetupScreen();  
  m_Sensor.SensorState( false );  

}

void loop() {
  // put your main code here, to run repeatedly:

  if( Firebase.getBool( firebaseData, m_Path + "WarmFlag/" ) ) 
  {
    //Success, then read the payload value

    //Make sure payload value returned from server is integer
    //This prevent you to get garbage data
    if( firebaseData.dataType() == "boolean" ) 
    {
      m_KeepWarmFlag = firebaseData.boolData();
      m_LedPanel.ControlKeepWarmLED( m_KeepWarmFlag );
      // Serial.println( m_KeepWarmFlag );
    }

  } 
  else 
  {
    //Failed, then print out the error detail
    Serial.println( firebaseData.errorReason() );
  }
  
  if( heater_State == false )
  {
    m_Sensor.SensorState( true );
    m_Screen.ClearScreen();
    m_Screen.SendToScreen( "Heater OFF", (uint8_t)40, (uint8_t)30, 2 );
    temperature = m_Sensor.GetTemperature();
    FirebaseUpdateTemp( temperature );
    digitalWrite( led_Pin, LOW );
    
    noTone( buzzer_Pin );
  }
  else
  {   
    m_Sensor.SensorState( false );
    m_Screen.ClearScreen();   
    temperature = m_Sensor.GetTemperature();
    FirebaseUpdateTemp( temperature ); 
    m_LedPanel.ControlTempLED( temperature );
    HandleTemp();
    
  }
  
  m_LedPanel.ControlPowerLED( heater_State );
  FirebaseUpdateState( heater_State );
 
}

//! Change the state upon interrup.
void ToggleState()
{
  heater_State = !heater_State;  
}

//! Change the state based on temperature changes.
void HandleTemp()
{
  if( temperature >= 95.0 )
  {
    digitalWrite( led_Pin, HIGH );
    tone( buzzer_Pin, 1000 );
    m_Sensor.SensorState( true );
    m_Screen.DrawCoffeeAnimation( 50, 32, 0);
  }
  else if( m_KeepWarmFlag == true && temperature <= 88.0 && temperature >= 80.0 )
  {
    TurnHeaterOn();
  }
  else if( heater_State == true )
  {    
    TurnHeaterOn();
  }
}

//! Turn on the heater.
void TurnHeaterOn()
{
    String temp = String(temperature, 2);
    String msg = temp +"C\n";

    m_Screen.ClearScreen();
    m_Screen.SendToScreen( msg, (uint8_t)40, (uint8_t)30, 2 ); 
    digitalWrite( led_Pin, LOW );
    noTone( buzzer_Pin );
    m_Sensor.SensorState( false ); 
}

//! Send the temperature data to database
void FirebaseUpdateTemp( float temp )
{
   if( Firebase.setFloat( firebaseData, m_Path + "Temp/", temp ) )
   {
        // We don't have to do anything here
   }
   else
   {
      Serial.println( firebaseData.errorReason() );
   }
}

//! Send the state data to database
void FirebaseUpdateState( bool state )
{
   if( Firebase.setBool( firebaseData, m_Path + "State/", state ) )
   {
        // We don't have to do anything here
   }
   else
   {
      Serial.println( firebaseData.errorReason() );
   }
}
