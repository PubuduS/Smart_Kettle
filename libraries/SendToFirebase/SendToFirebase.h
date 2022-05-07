#ifndef SENDTOFIREBASE_H
#define SENDTOFIREBASE_H

#include <Firebase_Arduino_WiFiNINA.h>
#include "arduino_secrets.h"

class SendToFirebase
{
  private:
      FirebaseData m_FirebaseData;
      String m_Path = "/ThermoBot/";

  public:
    SendToFirebase();
    void SetupFirebase();
    void FirebaseUpdateTemp( const float temp = 0.0 );
    void FirebaseUpdateSystemState( const bool state = true );

};
#endif // SENDTOFIREBASE_H
