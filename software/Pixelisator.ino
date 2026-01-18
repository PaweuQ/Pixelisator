#include <Adafruit_GFX.h>
#include <Arduino_ST7789.h>
#include <SPI.h>
#include <pgmspace.h>

#include "image.h"

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

void drawImageDiagnostic(int16_t x0, int16_t y0)
{
    uint32_t index = 0;

    for (int16_t y = 0; y < IM19_HEIGHT; y++)
    {
        for (int16_t x = 0; x < IM19_WIDTH; x++)
        {
            uint16_t raw = pgm_read_word(&im19[index++]);
            uint16_t color = (raw << 8) | (raw >> 8);   // SWAP BAJTÓW
            tft.drawPixel(x0 + x, y0 + y, color);
        }
    }
}

void setup()
{
    Serial.begin(9600);

    tft.init(240, 320);
    tft.setRotation(0);
    tft.fillScreen(BLACK);

    tft.fillRect(0, 0, 40, 40, RED);
    tft.fillRect(40, 0, 40, 40, GREEN);
    tft.fillRect(80, 0, 40, 40, BLUE);

    delay(1000);

    drawImageDiagnostic(10, 60);
}

void loop()
{
}
