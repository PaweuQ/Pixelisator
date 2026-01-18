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

// ================= Callback rysujący JPG na TFT =======
bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t *bitmap)
{
    if (y >= tft.height() || x >= tft.width()) return false;

    // ustaw okno do rysowania
    tft.setAddrWindow(x, y, x + w - 1, y + h - 1);

    // rysowanie piksel po pikselu
    for (uint32_t i = 0; i < (uint32_t)w * h; i++) {
        tft.pushColor(bitmap[i]);
    }

    return true;
}



// ================= Setup =============================
void setup()
{
    Serial.begin(115200);
    delay(200);

    // --- TFT ---
    tft.init(240, 320);
    tft.setRotation(0);
    tft.fillScreen(BLACK);
    Serial.println("TFT OK");

    // --- SD ---
    SPI.begin(SD_SCLK, SD_MISO, SD_MOSI, SD_CS); // hardware SPI
    if (!SD.begin(SD_CS)) {
        Serial.println("SD init FAILED");
        while (1);
    }
    Serial.println("SD OK");

    // --- TJpg_Decoder ---
    TJpgDec.setCallback(tft_output);  // ustawia funkcję rysującą
    TJpgDec.setJpgScale(1);           // 1 = pełny rozmiar
    TJpgDec.setSwapBytes(false);       // RGB565 MSB/LSB
    

    tft.fillScreen(BLACK);

    // --- Rysowanie JPG ---
    if (TJpgDec.drawSdJpg(0, 0, "/test3.jpg") == false) {
        Serial.println("JPG draw FAILED");
    } else {
        Serial.println("JPG draw OK");
    }
}

// ================= Loop ==========================
void loop()
{
    /*
    TJpgDec.drawSdJpg(0, 0, "/test.jpg");
    delay(500);
    TJpgDec.drawSdJpg(0, 0, "/test3.jpg");
    delay(5000);
    TJpgDec.drawSdJpg(0, 0, "/test.jpg");
    TJpgDec.drawSdJpg(0, 0, "/test2.jpg"); 
    */
}
