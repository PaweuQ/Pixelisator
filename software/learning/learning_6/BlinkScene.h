// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once
#include <Arduino.h>
#include "Scene.h"

class BlinkScene : public Scene {
public:
  BlinkScene(Context& ctx) : Scene(ctx) {}
  void onEnter() override;
  void onExit() override;
  void update() override;

private:
  uint32_t lastToggle = 0;
  bool state = false;
};
