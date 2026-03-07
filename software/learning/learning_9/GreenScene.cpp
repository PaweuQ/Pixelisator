// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#include "GreenScene.h"
//#include <TFT_eSPI.h>

//extern TFT_eSPI tft;

void GreenScene::setBlueScene(Scene* scene) {
  blueScene = scene;
}
void GreenScene::onExit() {}

void GreenScene::onEnter() {
  context.tft.fillScreen(TFT_GREEN);
}

void GreenScene::update() {
  /*if(context.buttons.isClicked()) {
    nextScene = blueScene;
  }*/
}

