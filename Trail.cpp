#ifndef Trail_h
#define Trail_h
#include <FastLED.h>
#include "Animation.cpp"
class Trail : public Animation {
  public:
    Trail(CRGB *leds, int num_leds) : Animation(leds, num_leds, false, 5) {};
    void effect(Animation::Palette palette) {
      for (int c = 0; c < palette.size; c++) {
        for (int i = 0; i < num_leds; i++) {
          fadeToBlackBy(leds, num_leds, 8);
          leds[i] = palette.colors[c];
          show(wait);
        }
      }
    };
};
#endif