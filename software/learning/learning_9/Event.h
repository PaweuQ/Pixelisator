// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once 

enum class EventType {
  ButtonPressed,
  ButtonReleased
};

enum class ButtonID {
  A,
  B,
  Left,
  Right,
  Up,
  Down
};

struct Event {
  EventType type;
  ButtonID button;
};