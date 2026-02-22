// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#include "BlinkScene.h"
#include <TFT_eSPI.h>
#include "Buttons.h"

extern TFT_eSPI tft;
extern Buttons buttons;

void BlinkScene::onEnter() {
  tft.fillScreen(TFT_BLACK);
}

void BlinkScene::onExit() {}

void BlinkScene::update() {
  Serial.println("BlinkScene update");

  if (millis() - lastToggle > 1000) {
    lastToggle = millis();
    state = !state;

    tft.fillScreen (state ? TFT_WHITE : TFT_BLACK); //if state then white else black
  }
  if (buttons.isClicked()) {
    Serial.println("Change");
    nextScene = SceneID::Blue;
  }
}
