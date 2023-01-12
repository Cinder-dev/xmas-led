#ifndef Fade_h
#define Fade_h
#include <FastLED.h>
#include "Animation.cpp"
class Fade : public Animation {
  public:
    Fade(CRGB *leds, int num_leds) : Animation(leds, num_leds, false, 15) {};
    void effect(Animation::Palette palette) {
      // Fade Out
      for(int i = 100; i >=0; i--) {
        FastLED.setBrightness(i);
        show(wait);
      }
      for(int c = 0; c < palette.size; c++) {
        fill_solid(leds, num_leds, palette.colors[c]);
        // Fade In
        for(int i = 0; i <= 100; i++) {
          FastLED.setBrightness(i);
          show(wait);
        }
        delay(1000);
        // Fade Out
        for(int i = 100; i >=0; i--) {
          FastLED.setBrightness(i);
          show(wait);
        }
      }
      fill_solid(leds, num_leds, palette.colors[0]);
      // Fade In
      for(int i = 0; i <= 100; i++) {
        FastLED.setBrightness(i);
        show(wait);
      }
      delay(1000);
    };
};
#endif