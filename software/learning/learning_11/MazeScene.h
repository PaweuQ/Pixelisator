// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once 
#include <Arduino.h>
#include "Scene.h"
#include "TileMap.h"
#include "Player.h"

class MazeScene : public Scene {
public:
  MazeScene(Context& ctx);

  void setBlueScene(Scene* scene);
  void setGreenScene(Scene* scene);
  void onEnter();
  void onExit();
  void update();

private:
  Player player;
  TileMap map;
  Scene* blueScene = nullptr;
  Scene* greenScene = nullptr;
};