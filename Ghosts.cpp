#ifndef Ghosts_h
#define Ghosts_h
#include <FastLED.h>
#include "Animation.cpp"
class Ghosts : public Animation {
  public:
    Ghosts(CRGB *leds, int num_leds) : Animation(leds, num_leds, false, 0) {};
    void effect(Animation::Palette palette) {
      unsigned int state[num_leds];

      for (int i = 0; i < num_leds; i++) { state[i] = 0; }

      unsigned int current = 0;
      while(current < runs) {
        if (random8() > 200) {
          int selected = random16(num_leds);
          state[selected] = (state[selected] + 1) % palette.size;
        }

        for (int i = 0; i < num_leds; i++) {
          leds[i] = blend(leds[i], palette.colors[state[i]], 8);
        }
        show(wait);
        current++;
      }
    };

    void set_runs(unsigned int runs) { this->runs = runs; };
  private:
    unsigned int runs = 1000;
};
#endif