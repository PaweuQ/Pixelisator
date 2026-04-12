#include "Event.h"
// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#include "BlueScene.h"
//#include <TFT_eSPI.h>

//extern TFT_eSPI tft;
//extern Buttons buttons;

void BlueScene::setMazeScene(Scene* scene) {
  mazeScene = scene;
}
void BlueScene::setGreenScene(Scene* scene) {
  greenScene = scene;
}
void BlueScene::onEnter() {
  Serial.println("BlueScene onEnter()");
  context.renderer.clear(TFT_BLUE);
}

void BlueScene::onExit() {
  Serial.println("BlueScene onExit()");
}

void BlueScene::update() {

  unsigned long blueTime = millis();
  //message = ""; 
  //message = Serial.readString();
  while(Serial.available() > 0) {
    char c = Serial.read();
    if (c =='\r' || c == '\n') {
      message.trim();
      Serial.println("Received: " + message);
      message = "";
    } else {
      message += c;
    }
  }
  
  if (context.wasPressed(ButtonID::A)) {
    Serial.println("Go to GreenScene");
    nextScene = greenScene;
  }

  if (context.wasPressed(ButtonID::Down)) {
    Serial.println("Go to MazeScene");
    nextScene = mazeScene;
  }
  //if (Serial.available() > 0) {

  
    //Serial.println("Serial available");
    if (message.startsWith("maze")) {
      Serial.println("maze");
      nextScene = mazeScene;
    }
    if (message.startsWith("green")) {
      nextScene = greenScene;
    }

  if (context.wasPressed(ButtonID::Up)) {
    //Serial.print("UP ");
    //Serial.println(blueTime);
  }
  if (context.wasPressed(ButtonID::A)) {
    Serial.println("OK");
  }
  //}
  //Serial.println("BLUE update");
}