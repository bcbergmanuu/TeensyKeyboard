#include <Arduino.h>
// https://github.com/thomasfredericks/Bounce2
#include <Bounce2.h>

// INSTANTIATE A Bounce OBJECT.
Bounce bounce = Bounce();

void setup()
{
  // make pin 2 an input and turn on the
  // pullup resistor so it goes high unless
  // connected to ground:
  bounce.attach(2, INPUT_PULLUP);
  bounce.interval(5); // interval in ms

  Keyboard.begin();
}

void loop()
{
  // if the button is pressed
  //  Update the Bounce instance (YOU MUST DO THIS EVERY LOOP)
  bounce.update();

  // <Bounce>.changed() RETURNS true IF THE STATE CHANGED (FROM HIGH TO LOW OR LOW TO HIGH)
  if (bounce.changed())
  {
    // THE STATE OF THE INPUT CHANGED
    // GET THE STATE
    int deboucedInput = bounce.read();
    // IF THE CHANGED VALUE IS HIGH
    if (deboucedInput == LOW)
    {
      // Send the message
      Keyboard.write('p');      
    }
  }
}