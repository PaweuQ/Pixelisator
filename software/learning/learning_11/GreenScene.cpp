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
void GreenScene::setMazeScene(Scene* scene) {
  mazeScene = scene;
}
void GreenScene::onExit() {}

void GreenScene::onEnter() {
  context.renderer.clear(TFT_GREEN);
  context.renderer.fillRect(100, 100, 100, 100, TFT_RED);
}

void GreenScene::update() {
  if(context.wasHeld(ButtonID::B)) {
    nextScene = mazeScene;
  }
}

