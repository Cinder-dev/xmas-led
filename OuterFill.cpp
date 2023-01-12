#ifndef OuterFill_h
#define OuterFill_h
#include <FastLED.h>
#include "Animation.cpp"
class OuterFill : public Animation {
  public:
    OuterFill(CRGB *leds, int num_leds) : Animation(leds, num_leds, false, 5) {};
    void effect(Animation::Palette palette) {
      for (int c = 0; c < palette.size; c++) {
        for (int i = 0; i < num_leds / 2; i++) {
          leds[i] = leds[num_leds - 1 - i] = palette.colors[c];
          show(wait);
        }
      }
    };
};
#endif