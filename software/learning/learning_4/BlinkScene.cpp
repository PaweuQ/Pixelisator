// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#include "BlinkScene.h"
#include <TFT_eSPI.h>

extern TFT_eSPI tft;
extern bool btnClick;

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
  if (btnClick) {
    Serial.println("Change");
    nextScene = SceneID::Blue;
  }
}
