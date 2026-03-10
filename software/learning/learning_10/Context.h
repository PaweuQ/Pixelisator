// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once
//#include "Buttons.h"
#include "TFT_eSPI.h"
#include "Event.h"

#define EVENT_QUEUE_SIZE 10

struct Context {

  TFT_eSPI& tft;
  //Buttons& buttons;

  Context(TFT_eSPI& display) : tft(display) {}

  Event eventQueue[EVENT_QUEUE_SIZE];
  int eventCount = 0;

  void pushEvent(Event e) {
    if (eventCount < EVENT_QUEUE_SIZE) {
      eventQueue[eventCount++] = e;
    }
  }
  void clearEvents() {
    eventCount = 0;
  }

  bool wasPressed (ButtonID button) {
    
    for (int i=0; i<eventCount; i++) {
      
      if (eventQueue[i].type == EventType::ButtonPressed && eventQueue[i].button == button) {
        return true;
      } 
    }
    return false;
  }

  bool wasReleased (ButtonID button) {
    
    for (int i=0; i<eventCount; i++) {

      if (eventQueue[i].type == EventType::ButtonReleased && eventQueue[i].button == button) {
        
        return true;
      }
    }
    return false;
  }

  bool wasHeld(ButtonID button) {

    for (int i=0; i<eventCount; i++) {

      if (eventQueue[i].type == EventType::ButtonHeld && eventQueue[i].button == button) {

        return true;
      }
    }
    return false;
  }
};
