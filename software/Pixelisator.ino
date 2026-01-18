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

float p = 3.1415926;

// ================= Setup =============================
void setup()
{
    Serial.begin(9600);
    delay(200);

    // --- TFT ---
    tft.init(240, 320);
    tft.setRotation(2);
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
}

// ================= Loop ==========================
void loop()
{
    testdrawtext("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", WHITE);
    delay(1000);

    // line draw test
    testlines(YELLOW);
    delay(500);

    testtriangles();
    delay(500);
    tft.fillScreen(BLACK);
    testfillcircles(10, BLUE);
    testdrawcircles(10, WHITE);
    delay(500);
    tft.fillScreen(BLACK);
    TJpgDec.drawSdJpg(0, 0, "/test3.jpg");
    delay(50000);
}

void testlines(uint16_t color)
{
    tft.fillScreen(BLACK);
    for (int16_t x = 0; x < tft.width(); x += 6) {
        tft.drawLine(0, 0, x, tft.height() - 1, color);
    }
    for (int16_t y = 0; y < tft.height(); y += 6) {
        tft.drawLine(0, 0, tft.width() - 1, y, color);
    }
}

void testdrawtext(char *text, uint16_t color)
{
    tft.setCursor(0, 0);
    tft.setTextColor(color);
    tft.setTextWrap(true);
    tft.print(text);
}

void testfastlines(uint16_t color1, uint16_t color2)
{
    tft.fillScreen(BLACK);
    for (int16_t y = 0; y < tft.height(); y += 5) {
        tft.drawFastHLine(0, y, tft.width(), color1);
    }
    for (int16_t x = 0; x < tft.width(); x += 5) {
        tft.drawFastVLine(x, 0, tft.height(), color2);
    }
}

void testdrawrects(uint16_t color)
{
    tft.fillScreen(BLACK);
    for (int16_t x = 0; x < tft.width(); x += 6) {
        tft.drawRect(tft.width() / 2 - x / 2, tft.height() / 2 - x / 2, x, x, color);
    }
}

void testfillrects(uint16_t color1, uint16_t color2)
{
    tft.fillScreen(BLACK);
    for (int16_t x = tft.width() - 1; x > 6; x -= 6) {
        tft.fillRect(tft.width() / 2 - x / 2, tft.height() / 2 - x / 2, x, x, color1);
        tft.drawRect(tft.width() / 2 - x / 2, tft.height() / 2 - x / 2, x, x, color2);
    }
}

void testfillcircles(uint8_t radius, uint16_t color)
{
    for (int16_t x = radius; x < tft.width(); x += radius * 2) {
        for (int16_t y = radius; y < tft.height(); y += radius * 2) {
            tft.fillCircle(x, y, radius, color);
        }
    }
}

void testdrawcircles(uint8_t radius, uint16_t color)
{
    for (int16_t x = 0; x < tft.width() + radius; x += radius * 2) {
        for (int16_t y = 0; y < tft.height() + radius; y += radius * 2) {
            tft.drawCircle(x, y, radius, color);
        }
    }
}

void testtriangles()
{
    tft.fillScreen(BLACK);
    int color = 0xF800;
    int t;
    int w = tft.width() / 2;
    int x = tft.height() - 1;
    int y = 0;
    int z = tft.width();
    for (t = 0 ; t <= 15; t++) {
        tft.drawTriangle(w, y, y, x, z, x, color);
        x -= 4;
        y += 4;
        z -= 4;
        color += 100;
    }
}

void testroundrects()
{
    tft.fillScreen(BLACK);
    int color = 100;
    int i;
    int t;
    for (t = 0 ; t <= 4; t += 1) {
        int x = 0;
        int y = 0;
        int w = tft.width() - 2;
        int h = tft.height() - 2;
        for (i = 0 ; i <= 16; i += 1) {
            tft.drawRoundRect(x, y, w, h, 5, color);
            x += 2;
            y += 3;
            w -= 4;
            h -= 6;
            color += 1100;
        }
        color += 100;
    }
}

void tftPrintTest()
{
    tft.setTextWrap(false);
    tft.fillScreen(BLACK);
    tft.setCursor(0, 30);
    tft.setTextColor(RED);
    tft.setTextSize(1);
    tft.println("Hello World!");
    tft.setTextColor(YELLOW);
    tft.setTextSize(2);
    tft.println("Hello World!");
    tft.setTextColor(GREEN);
    tft.setTextSize(3);
    tft.println("Hello World!");
    tft.setTextColor(BLUE);
    tft.setTextSize(4);
    tft.print(1234.567);
    delay(1500);
    tft.setCursor(0, 0);
    tft.fillScreen(BLACK);
    tft.setTextColor(WHITE);
    tft.setTextSize(0);
    tft.println("Hello World!");
    tft.setTextSize(1);
    tft.setTextColor(GREEN);
    tft.print(p, 6);
    tft.println(" Want pi?");
    tft.println(" ");
    tft.print(8675309, HEX); // print 8,675,309 out in HEX
    tft.println(" Print HEX!");
    tft.println(" ");
    tft.setTextColor(WHITE);
    tft.println("Sketch has been");
    tft.println("running for: ");
    tft.setTextColor(MAGENTA);
    tft.print(millis() / 1000);
    tft.setTextColor(WHITE);
    tft.print(" seconds.");
}