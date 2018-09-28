#include <SoftwareSerial.h>
//#include "ver_led.h"

SoftwareSerial XBee(2,3);

#define DEBUG_SERIAL

//quick and dirty remove the #defines...
#if 0
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
#endif  // 0

void debug_print(char *string)
{

  #ifdef DEBUG_SERIAL
  Serial.println(string);
  #endif
  
  XBee.println(string);
}

void setup() 
{
 Serial.begin(9600);
 XBee.begin(9600);

 //ver_led_setup(1);
  
 debug_print("Setup finished");
 
}





void loop() 
{
  static int i=0;
  char my_string[40];

  sprintf(my_string, "Number: %d", i);
  debug_print(my_string);
  if (i<50)
  i++;
  else 
  i=0;
  
  //ver_led_run();
  
  delay(100);
}
