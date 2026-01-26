// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

// files ordering 
#include "BlinkScene.h"
#include "SceneManager.h"
#include <TFT_eSPI.h>
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();

const int BTN_OK = 21;
bool btnPressed = false;
bool btnLast = false;
bool btnClick = false; 

SceneManager manager;

void setup() {
  Serial.begin(9600);
  pinMode(BTN_OK, INPUT_PULLUP);

  tft.init();
  tft.setRotation(0);
  tft.invertDisplay(false);
  
  manager.setScene(new BlinkScene());

}

void loop() {
  btnLast = btnPressed;
  btnPressed = digitalRead(BTN_OK) == LOW;
  btnClick = btnPressed && !btnLast;
  Serial.print("Button state: ");
  Serial.print(btnClick);
  Serial.println("");
  manager.update();
}
