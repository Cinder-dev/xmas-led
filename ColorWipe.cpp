#ifndef ColorWipe_h
#define ColorWipe_h
#include <FastLED.h>
#include "Animation.cpp"
class ColorWipe : public Animation {
public:
  ColorWipe(CRGB *leds, int num_leds) : Animation(leds, num_leds, false, 30) {};
  void effect(Animation::Palette palette) {
    for(int c = 0; c < palette.size; c++) {
      for (int i = 0; i < num_leds; i++) {
        leds[i] = palette.colors[c];
        show(wait);
      }
    }
    // Primary Color Wipe
    // for (int i = 0; i < num_leds; i++) {
    //   leds[i] = colors[0];
    //   show(wait);
    // }
    // Secondary Color Wipe
    // for (int i = 0; i < num_leds; i++) {
    //   leds[i] = colors[1];
    //   show(wait);
    // }
  };
};
#endif