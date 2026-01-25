// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

// first working scene with simple logic, changing tft screen color

#include <TFT_eSPI.h>
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();

class Scene {
public:
  virtual void onEnter()  = 0;
  virtual void onExit()   = 0;
  virtual void update()   = 0;
  virtual ~Scene() {}
};

class SceneManager {
private:
  Scene* current = nullptr; //doesnt point at any address

public: 
  void setScene(Scene* next){
    if (current) {   //shortcut of if (current != nullptr)
      current->onExit();
      delete current;
    }
    current = next;
    current->onEnter(); 
  }
  void update() {
    if(current){
      current->update();
    }
  }
};

class BlinkScene : public Scene{
private:
  uint32_t lastToggle = 0;
  bool state = false;

public:
  void onEnter() override {
    tft.fillScreen(TFT_BLACK);
  }

  void onExit() override {

  }

  void update() override {
    if (millis() - lastToggle > 1000) {
      lastToggle = millis();
      state = !state;

      tft.fillScreen (state ? TFT_WHITE : TFT_BLACK); //if state then white else black
    }
  }
};

SceneManager manager;

void setup() {
  Serial.begin(9600);

  tft.init();
  tft.setRotation(2);
  
  manager.setScene(new BlinkScene());

}

void loop() {
  manager.update();
}
