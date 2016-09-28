/*
  VB Button Presser 

  for 5V Adafruit Trinket

  Two Momentary Switches (Jodi and Krystal) wired to Pin 0
  Servo wired to Pin 1
*/
 
#include <Adafruit_SoftServo.h>  // SoftwareServo (works on non PWM pins)

#define SERVOPIN 1   // Servo control line (white) on Trinket Pin #1
#define BUTTON 0  // Momentary buttons wired to Trinket Pin #0
 
Adafruit_SoftServo drive;  //create a servo object
 
// the setup routine runs once when you press reset:
void setup() 
{
  // setup an interrupt timer
  OCR0A = 0xAF;            // DEC = 175, this sets the number of cycles before the interrupt is triggered
  TIMSK |= _BV(OCIE0A);    // Turn on the compare interrupt (below!)

  //setup servo
  drive.attach(SERVOPIN);   // Attach the servo to pin 1 on Trinket
  drive.write(110);           // Tell servo to go to position per quirk
  delay(15);                    // Wait 15ms for the servo to reach the position
  
  // setup momentary switched, pulled up to 5V (digital 1) by default
  pinMode(BUTTON, INPUT_PULLUP);
  
}
 
// the loop routine runs over and over again forever:
void loop() 
{
  if(digitalRead(BUTTON) == 0)
  {
      drive.write(60);
  } 
  else
  {    
      drive.write(130);
  }
  
  delay(15);
}


volatile uint8_t counter = 0;
SIGNAL(TIMER0_COMPA_vect) {
  // this gets called every 2 milliseconds
  counter += 2;
  // every 20 milliseconds, refresh the servos!
  if (counter >= 20) {
    counter = 0;
    drive.refresh();
  }
}
