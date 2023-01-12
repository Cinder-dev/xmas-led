#ifndef Fan_h
#define Fan_h
#include <FastLED.h>
#include "Animation.cpp"
class Fan : public Animation {
  public:
    Fan(CRGB *leds, int num_leds) : Animation(leds, num_leds, false, 15) {};
    void effect(Animation::Palette palette) {
      for (int c = 0; c < palette.size; c++) {
        unsigned int position = 0;
        while (position < num_leds - width) {
          for (int i = 0; i < num_leds; i++) {
            if (i >= position && i < position + width) {
              leds[i] = palette.colors[c];
            } else {
              leds[i] = palette.colors[(c + 1) % palette.size];
            }
          }
          show(wait);
          position++;
        }
        while (position > 0) {
          for (int i = 0; i < num_leds; i++) {
            if (i > position && i < position + width) {
              leds[i] = palette.colors[c];
            } else {
              leds[i] = palette.colors[(c + 1) % palette.size];
            }
          }
          show(wait);
          position--;
        }
      }
    };

    void set_width(unsigned int width) { this->width = width; };
  private:
    unsigned int width = 3;
};
#endif