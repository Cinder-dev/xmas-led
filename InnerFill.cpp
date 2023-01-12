#ifndef InnerFill_h
#define InnerFill_h
#include <FastLED.h>
#include "Animation.cpp"
class InnerFill : public Animation {
  public:
    InnerFill(CRGB *leds, int num_leds) : Animation(leds, num_leds, false, 5) {};
    void effect(Animation::Palette palette) {
      for (int c = 0; c < palette.size; c++) {
        for (int i = num_leds / 2 - 1; i >= 0; i--) {
          leds[i] = leds[num_leds - 1 - i] = palette.colors[c];
          show(wait);
        }
      }
    };
};
#endif