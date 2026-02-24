// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#include "YellowScene.h"
#include <TFT_eSPI.h>

extern TFT_eSPI tft; 

void YellowScene::setBlueScene(Scene* scene) {
  blueScene = scene;
}
void YellowScene::onExit() {}

void YellowScene::onEnter() {
  tft.fillScreen(TFT_YELLOW);
}

void YellowScene::update() {
  if(context.buttons.isClicked()) {
    nextScene = blueScene;
  }
}