#include <Adafruit_GFX.h>
#include <Arduino_ST7789.h>
#include <SPI.h>
#include <SD.h>
#include <TJpg_Decoder.h> // Bodmer

// ================= TFT (software SPI) =================
#define TFT_MISO -1
#define TFT_MOSI 13
#define TFT_SCLK 14
#define TFT_CS   27
#define TFT_DC   32
#define TFT_RST  15

Arduino_ST7789 tft(
    TFT_DC,
    TFT_RST,
    TFT_MOSI,
    TFT_SCLK,
    TFT_CS
);

// ================= SD (hardware SPI - VSPI) ===========
#define SD_MOSI 23
#define SD_MISO 19
#define SD_SCLK 18
#define SD_CS   5

// ================= BUTTON =============================
#define BTN_PIN 22

// ================= JPG state ==========================
uint8_t currentImage = 1;   // test1.jpg ... test8.jpg
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

// ================= Callback rysujący JPG na TFT =======
bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t *bitmap)
{
    if (y >= tft.height() || x >= tft.width()) return false;

    tft.setAddrWindow(x, y, x + w - 1, y + h - 1);

    for (uint32_t i = 0; i < (uint32_t)w * h; i++) {
        tft.pushColor(bitmap[i]);
    }

    return true;
}

// ================= Funkcja rysująca JPG ================
void drawCurrentImage()
{
    char filename[20];
    sprintf(filename, "/test%d.jpg", currentImage);

    Serial.print("Displaying: ");
    Serial.println(filename);

    tft.fillScreen(BLACK);

    if (!TJpgDec.drawSdJpg(0, 0, filename)) {
        Serial.println("JPG draw FAILED");
    }
}

// ================= Setup ===============================
void setup()
{
    Serial.begin(9600);
    delay(200);

    // --- Button ---
    pinMode(BTN_PIN, INPUT_PULLUP);

    // --- TFT ---
    tft.init(240, 320);
    tft.setRotation(2);
    tft.fillScreen(BLACK);
    Serial.println("TFT OK");

    // --- SD ---
    SPI.begin(SD_SCLK, SD_MISO, SD_MOSI, SD_CS);
    if (!SD.begin(SD_CS)) {
        Serial.println("SD init FAILED");
        while (1);
    }
    Serial.println("SD OK");

    // --- JPG decoder ---
    TJpgDec.setCallback(tft_output);
    TJpgDec.setJpgScale(1);      // pełny rozmiar
    TJpgDec.setSwapBytes(false);

    drawCurrentImage(); // pokaż test1.jpg na start
}

// ================= Loop ================================
void loop()
{
    static bool lastState = HIGH;
    bool currentState = digitalRead(BTN_PIN);

    // wykrycie zbocza HIGH -> LOW (przycisk wciśnięty)
    if (lastState == HIGH && currentState == LOW) {
        Serial.println("BUTTON PRESSED");

        currentImage++;
        if (currentImage > 8) currentImage = 1;

        drawCurrentImage();

        delay(200); // twardy debounce (wystarczy)
    }

    lastState = currentState;
}

