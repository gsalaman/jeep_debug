#include <SoftwareSerial.h>
#include "ver_led.h"

#define DEBUG_SERIAL

SoftwareSerial XBee(2,3);

// Simple version of debug print only takes strings.  Use sprintf if you
// want to embed paramenters.  Currently sending newline to determine when the string
// is done....no newline needed in the string itself.
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

 ver_led_setup(2);
  
 debug_print("Setup finished");
 
}





void loop() 
{
  static int i=0;
  char debug_string[40];
  
  ver_led_run();
  
  sprintf(debug_string, "Number %d", i++);
  debug_print(debug_string);
  
  delay(300);
}
