// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once 
#include <Arduino.h>
#include "Scene.h"

class RedScene : public Scene {
public:
  RedScene(Context& ctx) : Scene(ctx) {}

  void setBlueScene(Scene* scene);
  void onEnter();
  void onExit();
  void update();

private:
  Scene* blueScene = nullptr;
};