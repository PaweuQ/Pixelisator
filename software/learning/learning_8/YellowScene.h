// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once
#include <Arduino.h>
#include "Scene.h"

class YellowScene : public Scene {
public:
  YellowScene(Context& ctx) : Scene(ctx) {}
  
  void setBlueScene(Scene* scene);
  void onExit();
  void onEnter();
  void update();

private:
Scene* blueScene = nullptr;
};