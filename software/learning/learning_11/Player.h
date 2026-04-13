// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once 
#include "Context.h"
#include "TileMap.h"

class Player {
public:
  Player(Context& ctx, TileMap& map);

  void update();
  void draw();

private:
  Context& context; 
  TileMap& tileMap;

  int x = 1;
  int y = 1;

  static const int TILE_SIZE = 32;
};