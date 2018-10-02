#include <SoftwareSerial.h>
//#include "ver_led.h"

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
