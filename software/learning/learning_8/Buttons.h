// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once
#include <Arduino.h>

class Buttons {
public:
  Buttons(int okPin);

  void begin();
  void update();

  bool isPressed() const;
  bool isClicked() const;

private:
  int _okPin;

  bool _currentState = false;
  bool _lastState    = false; 
  bool _clicked      = false; 
};