// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#include "RedScene.h"
#include "TFT_eSPI.h"

extern TFT_eSPI tft; 

void RedScene::setBlueScene(Scene* scene){
  blueScene = scene;
}
void RedScene::onExit() {}

void RedScene::onEnter() {
  tft.fillScreen(TFT_RED);
}

void RedScene::update() {
  if (context.buttons.isClicked()) {
    nextScene = blueScene;
  }
} 