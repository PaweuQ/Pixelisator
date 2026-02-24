// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once 
#include "Scene.h"
#include "Context.h"

class SceneManager {
  public:
    SceneManager(Scene* blink, Scene* blue, Scene* red, Scene* yellow, Scene* green)
      : blinkScene(blink), blueScene(blue), redScene(red), yellowScene(yellow), greenScene(green) {}

    void setScene(Scene* next);
    void update();

  private:
    Scene* current = nullptr;
    Scene* blinkScene;
    Scene* blueScene;
    Scene* redScene;
    Scene* yellowScene;
    Scene* greenScene;
};
