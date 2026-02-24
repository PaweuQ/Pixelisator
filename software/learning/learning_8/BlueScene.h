// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once
#include <Arduino.h>
#include "Scene.h"

class BlueScene : public Scene {
public:
  BlueScene(Context& ctx) : Scene(ctx) {}
  
  void setRedScene(Scene* scene);
  void setYellowScene(Scene* scene);
  void setGreenScene(Scene* scene);
  void setBlinkScene(Scene* scene);
  
  void onEnter() override;
  void onExit() override;
  void update() override;
private: 
  String message = ""; 
  Scene* redScene = nullptr;
  Scene* yellowScene = nullptr;
  Scene* greenScene = nullptr;
  Scene* blinkScene = nullptr;
};



