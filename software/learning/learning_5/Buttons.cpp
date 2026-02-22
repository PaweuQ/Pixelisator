// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#include "Buttons.h"

Buttons::Buttons(int okPin)
  : _okPin(okPin)
{}

void Buttons::begin() {
  pinMode(_okPin, INPUT_PULLUP);
}

void Buttons::update() {
  _lastState = _currentState;
  _currentState = (digitalRead(_okPin) == LOW);

  _clicked = (_currentState && !_lastState);
}

bool Buttons::isPressed() const {
  return _currentState;
}

bool Buttons::isClicked() const {
  return _clicked;
}