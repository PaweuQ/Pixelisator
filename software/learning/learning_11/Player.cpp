// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT
#include "Player.h"

Player::Player(Context& ctx, TileMap& map)
  : context(ctx), tileMap(map)
{} 

void Player::update() {

  int newX = x;
  int newY = y;

  if (context.wasPressed(ButtonID::Up)) {
    newY++;
  }
  if (context.wasPressed(ButtonID::Down)) {
    newY--;
  }
  if (context.wasPressed(ButtonID::Right)) {
    newX++;
  }
  if (context.wasPressed(ButtonID::Left)) {
    newX--;
  }

  if (!tileMap.isWall(newX, newY)) {
    x = newX;
    y = newY;
  }
}

void Player::draw() {
  auto& gph = context.renderer;

  int screenX = x * TILE_SIZE;
  int screenY = y * TILE_SIZE;

  gph.fillRect(screenX, screenY, TILE_SIZE, TILE_SIZE, TFT_GREEN);
}