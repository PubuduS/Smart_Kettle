#include <WriteToScreen.h>
#include <TempSensor.h>
#include <SendToFirebase.h>

// Pins
const uint8_t btn_Pin = 3;
const uint8_t led_Pin = 9;
const uint8_t buzzer_Pin = 8;

// Globals
volatile bool heater_State = true;
float temperature = 0.0;

WriteToScreen m_Screen;
TempSensor m_Sensor;
SendToFirebase m_Firebase;

void setup() 
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode( btn_Pin, INPUT_PULLUP );
  pinMode( led_Pin, OUTPUT );
  pinMode( buzzer_Pin, OUTPUT );

  digitalWrite( led_Pin, LOW );
  attachInterrupt( digitalPinToInterrupt( btn_Pin ), ToggleState, RISING );
  
  m_Screen.SetupScreen();  
  m_Sensor.SensorState( false );
  m_Firebase.SetupFirebase();

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
    HandleTemp();
    m_Firebase.FirebaseUpdateTemp( temperature );
  }

  m_Firebase.FirebaseUpdateSystemState( heater_State );
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
