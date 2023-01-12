#ifndef SolidRainbow_h
#define SolidRainbow_h
#include <FastLED.h>
#include "Animation.cpp"
class SolidRainbow : public Animation {
  public:
    SolidRainbow(CRGB *leds, int num_leds) : Animation(leds, num_leds, false, 10) {};
    void effect(Animation::Palette palette) {
      for (unsigned long pixelHue = 0; pixelHue < 255; pixelHue ++) {
        fill_solid(leds, num_leds, CHSV(pixelHue, 187, 255));
        show(wait);
      }
    };
};
#endif