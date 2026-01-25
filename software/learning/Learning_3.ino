// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

// bypassing class declaration order problems with introducing change request

#include <TFT_eSPI.h>
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();

const int BTN_OK = 21;
bool btnPressed = false;
bool btnLast = false;
bool btnClick = false; 

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



class BlueScene : public Scene {
public:
  void onEnter() override {
    Serial.println("BlueScene");
    tft.fillScreen(TFT_BLUE);
  }
  void onExit() override {}

  void update() override {
    extern bool btnClick;
    //extern SceneManager manager;

    Serial.println("BLUE update");
    if (btnClick) {
      nextScene = SceneID::Blink;
    }
  }
};

class BlinkScene : public Scene {
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
    Serial.println("BlinkScene update");
    extern bool btnClick;
    //extern SceneManager manager;

    if (millis() - lastToggle > 1000) {
      lastToggle = millis();
      state = !state;

      tft.fillScreen (state ? TFT_WHITE : TFT_BLACK); //if state then white else black
    }
    if (btnClick) {
      Serial.println("Change");
      nextScene = SceneID::Blue;
    }
  }
};

class SceneManager {
private:
  Scene* current = nullptr; //doesnt point at any address

public: 
  void setScene(Scene* next) {
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

      if (current->nextScene != SceneID::None) {
        switch(current->nextScene){
          case SceneID::Blink:
            setScene(new BlinkScene());
            break;
          case SceneID::Blue:
            setScene(new BlueScene());
            break;
        }
      }
    }
  }
};

SceneManager manager;

void setup() {
  Serial.begin(9600);
  pinMode(BTN_OK, INPUT_PULLUP);

  tft.init();
  tft.setRotation(0);
  tft.invertDisplay(false);
  
  manager.setScene(new BlinkScene());

}

void loop() {
  btnLast = btnPressed;
  btnPressed = digitalRead(BTN_OK) == LOW;
  btnClick = btnPressed && !btnLast;
  Serial.print("Button state: ");
  Serial.print(btnClick);
  Serial.println("");
  manager.update();
}
