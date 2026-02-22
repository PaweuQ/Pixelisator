// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once 

enum class SceneID {
  None,
  Blink,
  Blue
};

class Scene {
public:
  SceneID nextScene = SceneID::None;
  virtual void onEnter()  = 0;
  virtual void onExit()   = 0;
  virtual void update()   = 0;
  virtual ~Scene() {}
};