// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

// 1 BlueScene update() optimisation
//   removed blocking Serial.readString()
//   replaced with non-blocking char reading

// 2 Passing hardware objects through Context
//   Context stores shared system objects (tft, buttons)
//   scenes receive them through reference
//   this removes global variables and keeps dependencies explicit

// 3 Implementing events for buttons instead of polling
//   

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
Buttons buttons(21);
Context context (buttons, tft);

BlinkScene blinkScene(context);
BlueScene blueScene(context);
RedScene redScene(context);
YellowScene yellowScene(context);
GreenScene greenScene(context);

SceneManager manager(&blinkScene, &blueScene, &redScene, &yellowScene, &greenScene);

void setup() {
  Serial.begin(9600);
  buttons.begin();

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
  buttons.update(context);
  manager.update();
  context.clearEvents();
}
