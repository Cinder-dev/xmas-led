#ifndef RotateRainbow_h
#define RotateRainbow_h
#include <FastLED.h>
#include "Animation.cpp"
class RotateRainbow : public Animation {
  public:
    RotateRainbow(CRGB *leds, int num_leds) : Animation(leds, num_leds, false, 10) {};
    void effect(Animation::Palette palette) {
      // iterate through all 8-bit hues, using 16-bit values for granularity
      for (unsigned int firstPixelHue = 0; firstPixelHue < 255; firstPixelHue++) {
        for (unsigned int i = 0; i < num_leds; i++) {
          unsigned int pixelHue = firstPixelHue + (i * 256U / num_leds); // vary LED hue based on position
          leds[i] = CHSV(pixelHue, 187, 255); // assign color, using gamma curve for a more natural look
        }
        show(wait);
      }
    };
};
#endif