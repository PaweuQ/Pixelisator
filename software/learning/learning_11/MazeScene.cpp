// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#include "MazeScene.h"

MazeScene::MazeScene(Context& ctx)
  : Scene(ctx), map(ctx)
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
}

void MazeScene::update() {

  map.draw();

  if (context.wasPressed(ButtonID::Up)) {
    nextScene = blueScene;
  }
  if (context.wasPressed(ButtonID::Right)) {
    nextScene = greenScene;
  }
} 