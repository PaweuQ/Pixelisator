// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

//#include "esp32-hal-gpio.h"
#include "Buttons.h"
#include "Context.h"

Buttons::Buttons(int buttonPin) 
  : pin(buttonPin)
{}

void Buttons::begin() {
  pinMode(pin, INPUT_PULLUP);
}

void Buttons::update(Context& context) {

  currentState = digitalRead(pin);

  if (previousState == HIGH && currentState == LOW) {

    Event e;
    e.type = EventType::ButtonPressed;
    e.button = ButtonID::A;
    context.pushEvent(e);
  }
  previousState = currentState;
}
