// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#include "SceneManager.h"
#include "BlinkScene.h"
#include "BlueScene.h"

void SceneManager::setScene(Scene* next) {
    if (current) {   //shortcut of if (current != nullptr)
      current->onExit();
      delete current;
    }
    current = next;
    current->onEnter(); 
}

void SceneManager::update() {
  if (!current) return;

  current->update();

  if (current->nextScene != SceneID::None) {
    SceneID next = current->nextScene;
    current->nextScene = SceneID::None;

    switch(next){
      case SceneID::Blink:
        setScene(new BlinkScene(context));
        break;
      case SceneID::Blue:
        setScene(new BlueScene(context));
        break;
      default:
        break;
    }
  }
}