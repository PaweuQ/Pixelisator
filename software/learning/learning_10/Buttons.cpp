// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

//#include "esp32-hal-gpio.h"
#include "Buttons.h"
#include "Context.h"

Buttons::Buttons(int buttonPin, ButtonID ButtonIdentifier) 
  : pin(buttonPin), id(ButtonIdentifier) 
{}

void Buttons::begin() {
  pinMode(pin, INPUT_PULLUP);
}

void Buttons::update(Context& context) {

  const unsigned long debounceTime = 25;
  unsigned long lastChangeTime = 0;
  
  currentState = digitalRead(pin);
  unsigned long now = millis();

  // debounce 
  if (currentState != previousState) {
    if (now - lastChangeTime < debounceTime) {
      previousState = currentState;
      return;
    }
    lastChangeTime = now;
  }


  if (previousState == HIGH && currentState == LOW) {

    // we can also: Event e{EventType::ButtonPressed, id}
    Event e;
    e.type = EventType::ButtonPressed;
    e.button = id;
    context.pushEvent(e);

    pressStart = now;
    holdSent = false;
  }

  if (previousState == LOW && currentState == HIGH) {

    Event e;
    e.type = EventType::ButtonReleased;
    e.button = id;

    context.pushEvent(e);
  }

  if (currentState == LOW && !holdSent) {

    if (now - pressStart > 500) {

      Event e;
      e.type = EventType::ButtonHeld;
      e.button = id;

      context.pushEvent(e);

      holdSent = true;
    }
  }

  previousState = currentState;
}
