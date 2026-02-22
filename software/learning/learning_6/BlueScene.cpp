// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#include "BlueScene.h"
#include <TFT_eSPI.h>
#include "Buttons.h"

extern TFT_eSPI tft;
//extern Buttons buttons;

void BlueScene::onEnter() {
  Serial.println("BlueScene");
  tft.fillScreen(TFT_BLUE);
}

void BlueScene::onExit() {}

void BlueScene::update() {
  Serial.println("BLUE update");
  if (context.buttons.isClicked()) {
    nextScene = SceneID::Blink;
  }
}