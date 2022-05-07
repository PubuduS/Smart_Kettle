#include "SendToFirebase.h"

SendToFirebase::SendToFirebase()
{
   Serial.begin(9600);
   delay(1000);

   Serial.print(F("Connecting to WiFi…"));
   int status = WL_IDLE_STATUS;

   while( status != WL_CONNECTED )
   {
      status = WiFi.begin( WIFI_SSID, WIFI_PASSWORD );
      delay(300);
   }

   Serial.print(F(" IP: "));
   Serial.println(WiFi.localIP());


}

void SendToFirebase::SetupFirebase()
{
   Firebase.begin( FIREBASE_HOST, FIREBASE_AUTH, WIFI_SSID, WIFI_PASSWORD );
   Firebase.reconnectWiFi( true );
}

void SendToFirebase::FirebaseUpdateTemp( const float temp )
{
   if( Firebase.setFloat( m_FirebaseData, m_Path + "Temp/", temp ) )
   {
        // We don't have to do anything here
   }
   else
   {
      Serial.println( m_FirebaseData.errorReason() );
   }
}

void SendToFirebase::FirebaseUpdateSystemState( const bool state )
{
   if( Firebase.setBool( m_FirebaseData, m_Path + "State/", state ) )
   {
        // We don't have to do anything here
   }
   else
   {
      Serial.println( m_FirebaseData.errorReason() );
   }
}
