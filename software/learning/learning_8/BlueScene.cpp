// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#include "BlueScene.h"
#include <TFT_eSPI.h>

extern TFT_eSPI tft;
//extern Buttons buttons;

void BlueScene::setRedScene(Scene* scene) {
  redScene = scene;
}
void BlueScene::setYellowScene(Scene* scene) {
  yellowScene = scene;
}
void BlueScene::setGreenScene(Scene* scene) {
  greenScene = scene;
}
void BlueScene::setBlinkScene(Scene* scene) {
  blinkScene = scene;
}
void BlueScene::onEnter() {
  Serial.println("BlueScene");
  tft.fillScreen(TFT_BLUE);
}

void BlueScene::onExit() {}

void BlueScene::update() {
  //message = ""; 
  message = Serial.readString();
  Serial.println("BLUE update");
  if (context.buttons.isClicked()) {
    nextScene = blinkScene;
  }
  //if (Serial.available() > 0) {

  
    Serial.println("Serial available");
    if (message.startsWith("red")) {
      Serial.println("red");
      nextScene = redScene;
    }
    if (message.startsWith("yellow")) {
      nextScene = yellowScene;
    }
    if (message.startsWith("green")) {
      nextScene = greenScene;
    }
  //}
}