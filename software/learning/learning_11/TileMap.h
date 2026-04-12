// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once 
#include "context.h"

class TileMap {
public:
  TileMap(Context& ctx);

  //nazwa do zmiany
  void draw();

private:
  Context& context;

  static const int WIDTH = 10;
  static const int HEIGHT = 8;
  static const int TILE_SIZE = 32;

  uint8_t themap[HEIGHT][WIDTH] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,0,0,0,1,0,0,1,0,1},
    {1,1,1,0,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
  };
};