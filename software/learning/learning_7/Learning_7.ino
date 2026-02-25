// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

// changing the scene switiching system. It was based on class enum SceneID in previous version. Now it operates on pointers.
// I resigned from creating scenes with setScene(new BlueScene()) when it must be activated. 
// Now I make objects in main so they are alive for eternity and use pointers to show precisely their addresses. That's better memory management

#include "Buttons.h"
#include "BlinkScene.h"
#include "BlueScene.h"
#include "SceneManager.h"
#include <TFT_eSPI.h>
#include <SPI.h>
#include "Context.h"

TFT_eSPI tft = TFT_eSPI();

Buttons buttons(21);
Context context { buttons };

BlinkScene blinkScene(context);
BlueScene blueScene(context);

SceneManager manager(&blinkScene, &blueScene);



void setup() {
  Serial.begin(9600);
  buttons.begin();

  tft.init();
  tft.setRotation(0);
  tft.invertDisplay(false);

  blinkScene.setBlueScene(&blueScene);
  blueScene.setBlinkScene(&blinkScene);
  
  manager.setScene(&blinkScene);

}

void loop() {
/*
  Serial.print("Button state: ");
  Serial.print(btnClick);
  Serial.println("");
*/
  buttons.update();
  manager.update();
}
