#ifndef EveryOther_h
#define EveryOther_h
#include <FastLED.h>
#include "Animation.cpp"
class EveryOther : public Animation {
public:
  EveryOther(CRGB *leds, int num_leds) : Animation(leds, num_leds, false, 30) {};
  void effect(Animation::Palette palette) {
    for (int j = 0; j < palette.size; j++) {
      unsigned long counter = j;
      for (int i = 0; i < num_leds; i++) {
        // leds[i] = i % 2 == j ? colors[0] : colors[1];
        leds[i] = palette.colors[counter++ % palette.size];
      }
      show(wait);
    }
  };
};
#endif