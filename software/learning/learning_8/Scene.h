// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once 
#include "Context.h"

class Scene {
public:
  Scene(Context& ctx) : context(ctx)  {}
  Scene* nextScene = nullptr;
  virtual void onEnter()  = 0;
  virtual void onExit()   = 0;
  virtual void update()   = 0;
  virtual ~Scene() {}
protected:
  Context& context;
};