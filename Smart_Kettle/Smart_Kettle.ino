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

  Serial.print("Connecting to WiFi…");
  uint8_t status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED) {
    status = WiFi.begin( WIFI_SSID, WIFI_PASSWORD );
    Serial.print(".");
    delay(300);
  }
  Serial.print(" IP: ");
  Serial.println( WiFi.localIP() );
  Serial.println();

  Firebase.begin( FIREBASE_HOST, FIREBASE_AUTH, WIFI_SSID, WIFI_PASSWORD );
  Firebase.reconnectWiFi(true);

  digitalWrite( led_Pin, LOW );
  attachInterrupt( digitalPinToInterrupt( btn_Pin ), ToggleState, RISING );
  
  m_Screen.SetupScreen();  
  m_Sensor.SensorState( false );  

}

void loop() {
  // put your main code here, to run repeatedly:


  if( heater_State == false )
  {
    m_Sensor.SensorState( true );
    m_Screen.ClearScreen();
    m_Screen.SendToScreen( "Heater OFF", (uint8_t)40, (uint8_t)30, 2 );
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

  FirebaseUpdateState( heater_State );
 
}


void ToggleState()
{
  heater_State = !heater_State;  
}

void HandleTemp()
{
  if( temperature >= 70.0 )
  {
    digitalWrite( led_Pin, HIGH );
    tone( buzzer_Pin, 1000 );
    m_Sensor.SensorState( true );
    m_Screen.DrawCoffeeAnimation( 50, 32, 0);
  }
  else
  {    
    String temp = String(temperature, 2);
    String msg = temp +"C\n";

    m_Screen.ClearScreen();
    m_Screen.SendToScreen( msg, (uint8_t)40, (uint8_t)30, 2 ); 
    digitalWrite( led_Pin, LOW );
    noTone( buzzer_Pin );
    m_Sensor.SensorState( false ); 
  }
}

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
