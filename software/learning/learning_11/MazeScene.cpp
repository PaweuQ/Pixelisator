// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#include "MazeScene.h"

MazeScene::MazeScene(Context& ctx)
  : Scene(ctx), map(ctx), player(ctx, map)
{}

void MazeScene::setBlueScene(Scene* scene) {
  blueScene = scene;
}
void MazeScene::setGreenScene(Scene* scene) {
  greenScene = scene;
}

void MazeScene::onExit() {}

void MazeScene::onEnter() {
  context.renderer.clear(TFT_BLACK);
  map.draw();
}

void MazeScene::update() {

  player.update();
  //context.renderer.clear(TFT_BLACK);
  //map.draw();
  player.draw();
/*
  if (context.wasPressed(ButtonID::Up)) {
    nextScene = blueScene;
  }
  if (context.wasPressed(ButtonID::Right)) {
    nextScene = greenScene;
  }
  */
} 