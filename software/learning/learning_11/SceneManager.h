// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once 
#include "Scene.h"
#include "Context.h"

class SceneManager {
  public:
    SceneManager(Scene* blue, Scene* maze, Scene* green)
      : blueScene(blue), mazeScene(maze), greenScene(green) {}

    void setScene(Scene* next);
    void update();

  private:
    Scene* current = nullptr;
    Scene* blueScene;
    Scene* greenScene;
    Scene* mazeScene;
};
