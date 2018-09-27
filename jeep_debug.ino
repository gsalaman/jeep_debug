#include <SoftwareSerial.h>
#include "ver_led.h"

SoftwareSerial XBee(2,3);

//#define DEBUG_SERIAL
#define DEBUG_XBEE

#if defined(DEBUG_SERIAL) && defined(DEBUG_XBEE)
  #define DEBUG_PRINT(x) Serial.print(x); XBee.print(x)
#elif defined(DEBUG_SERIAL)
  #define DEBUG_PRINT(x) Serial.print(x)
  #define DEBUG_PRINTLN(x) Serial.println(x)
#elif defined (DEBUG_XBEE)
  #define DEBUG_PRINT(x) XBee.print(x)
  #define DEBUG_PRINTLN(x) XBee.println(x)
#endif


void setup() 
{
 Serial.begin(9600);
 XBee.begin(9600);

 ver_led_setup(1);
  
 DEBUG_PRINTLN("Setup finished");
 
}





void loop() 
{
  static int i=0;

  DEBUG_PRINTLN(i++);
  ver_led_run();
  
  delay(300);
}
