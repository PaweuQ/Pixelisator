// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once
#include <Arduino.h>
#include "Event.h"
//#include "Context.h"
struct Context; // <-- forward declaration

class Buttons {
public:
  Buttons(int buttonPin);

  void begin();
  void update(Context& context);

private:
  int pin;
  bool previousState = HIGH;
  bool currentState = false;
};