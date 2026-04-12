// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#include "TileMap.h"

TileMap::TileMap(Context& ctx)
  : context(ctx)
{}

void TileMap::draw() {
  auto& gph = context.renderer;

  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++ ) {

      int tile = themap[x][y];

      int screenX = x * TILE_SIZE;
      int screenY = y * TILE_SIZE;

      if (tile == 1) {
        gph.fillRect(screenX, screenY, TILE_SIZE, TILE_SIZE, TFT_PINK);
      } else {
        gph.fillRect(screenX, screenY, TILE_SIZE, TILE_SIZE, TFT_BLACK);  
      }
    }
  }
}