#include "Event.h"
// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#include "BlinkScene.h"
//#include <TFT_eSPI.h>
//#include "Buttons.h"

//extern TFT_eSPI tft;
//extern Buttons buttons;

void BlinkScene::setBlueScene(Scene* scene) {
  blueScene = scene;
}

void BlinkScene::onEnter() {
  context.tft.fillScreen(TFT_BLACK);
}

void BlinkScene::onExit() {}

void BlinkScene::update() {
  Serial.println("BlinkScene update");

  if (millis() - lastToggle > 1000) {
    lastToggle = millis();
    state = !state;

    context.tft.fillScreen (state ? TFT_WHITE : TFT_BLACK); //if state then white else black
  }

  for(int i=0; i<context.eventCount; i++) {

    Event e = context.eventQueue[i];

    if(e.type == EventType::ButtonPressed && e.button == ButtonID::A) {
      Serial.println("Button OK pressed. I'm out of Blink");
      nextScene = blueScene;
    }
  }
}
