// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

// adding access layers with Context struct 
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
Context context { buttons };

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
  buttons.update();
  manager.update();
}
