// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#include "SceneManager.h"

void SceneManager::setScene(Scene* next) {
    if (current) {   //shortcut of if (current != nullptr)
      current->onExit();
    }
    current = next;
    current->onEnter(); 
}

void SceneManager::update() {
  if (!current) return;

  current->update();

  if (current->nextScene != nullptr) {
    Scene* next = current->nextScene;
    current->nextScene = nullptr;
    setScene(next);
  }
}