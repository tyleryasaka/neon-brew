#include <Adafruit_NeoPixel.h>
#define LED_PIN 6
#define LED_COUNT 1

Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
int analogPin = 9;
int cR = 0;
int cG = 0;
int cB = 0;

void setup() {
  Serial.begin(9600);
  pixels.begin();
  lightOff();
  pixels.setBrightness(255);
}

void loop() {
  setColor(255, 0, 0);
  setColor(255, 89, 0);
  setColor(255, 255, 0);
  setColor(0, 255, 0);
  setColor(0, 0, 255);
  setColor(221, 0, 255);
  setColor(0, 0, 255);
  setColor(0, 255, 0);
  setColor(255, 255, 0);
  setColor(255, 89, 0);
}

void setColor(int r, int g, int b) {
  while(cR != r || cG != g || cB != b) {
    cR = adjustColor(cR, r);
    cG = adjustColor(cG, g);
    cB = adjustColor(cB, b);
    pixels.setPixelColor(0, pixels.Color(cR, cG, cB));
    pixels.show();
    delay(100);
  }
}

int adjustColor(int current, int dest) {
  if (current == dest) {
    return dest;
  }
  int delta = dest - current;
  int adjustment = (delta / 10);
  if (adjustment == 0) {
    if (delta > 0) {
      adjustment = 5;
    } else {
      adjustment = -5;
    }
  }

  int newVal = current + adjustment;
  if (delta == 0) {
    return dest;
  } else if ((delta > 0 && newVal < dest) || (delta < 0 && newVal > dest)) {
    return newVal;
  } else {
    return dest;
  }
}

void lightOff() {
  setColor(0, 0, 0);
  pixels.clear();
  pixels.show();
}
