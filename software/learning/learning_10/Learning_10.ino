// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

// 1 adding all buttons predicted for the project
// 2 adding all crucial button states - pressed, held, released
// 3 switching between all scenes are controlled by buttons now 

// 4 taking important project decision - managing buttons with multiple objects
// instead of creating InputManager to rule them all 
// this version of buttons management keeps the code more readable, clean and easier to develop

#include "Buttons.h"
#include "BlinkScene.h"
#include "BlueScene.h"
#include "RedScene.h"
#include "YellowScene.h"
#include "GreenScene.h"
#include "SceneManager.h"
#include <TFT_eSPI.h>
#include <SPI.h>
#include "Context.h"

TFT_eSPI tft = TFT_eSPI();
Context context (tft);

Buttons okButton(21, ButtonID::A);
Buttons backButton(12, ButtonID::B);
Buttons upButton(22, ButtonID::Up);
Buttons downButton(33, ButtonID::Down);
Buttons leftButton(26, ButtonID::Left);
Buttons rightButton(25, ButtonID::Right);

BlinkScene blinkScene(context);
BlueScene blueScene(context);
RedScene redScene(context);
YellowScene yellowScene(context);
GreenScene greenScene(context);

SceneManager manager(&blinkScene, &blueScene, &redScene, &yellowScene, &greenScene);

void setup() {
  Serial.begin(9600);
  okButton.begin();
  backButton.begin();
  upButton.begin();
  downButton.begin();
  leftButton.begin();
  rightButton.begin();
  tft.init();
  tft.setRotation(0);
  tft.invertDisplay(false);

  blinkScene.setBlueScene(&blueScene);
  blueScene.setBlinkScene(&blinkScene);
  blueScene.setRedScene(&redScene);
  blueScene.setYellowScene(&yellowScene);
  blueScene.setGreenScene(&greenScene);
  redScene.setBlueScene(&blueScene);
  yellowScene.setBlueScene(&blueScene);
  greenScene.setBlueScene(&blueScene);
  
  manager.setScene(&blinkScene);

}

void loop() {
  
  okButton.update(context);
  backButton.update(context);
  upButton.update(context);
  downButton.update(context);
  leftButton.update(context);
  rightButton.update(context);
  manager.update();
  context.clearEvents();
}
