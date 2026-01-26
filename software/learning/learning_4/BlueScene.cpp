// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#include "BlueScene.h"
#include <TFT_eSPI.h>

extern TFT_eSPI tft;
extern bool btnClick;

void BlueScene::onEnter() {
  Serial.println("BlueScene");
  tft.fillScreen(TFT_BLUE);
}

void BlueScene::onExit() {}

void BlueScene::update() {
  Serial.println("BLUE update");
  if (btnClick) {
    nextScene = SceneID::Blink;
  }
}