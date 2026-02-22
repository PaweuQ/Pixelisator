// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once 
#include "Scene.h"

class SceneManager {
  public:
    void setScene(Scene* next);
    void update();

  private:
    Scene* current = nullptr;
};
