#ifndef Animation_h
#define Animation_h
#include <FastLED.h>
class Animation {
public:
  // Constructor
  Animation(
    CRGB *leds,
    int num_leds,
    bool clear, 
    fract8 glitter_chance
  ) {
    this->leds = leds;
    this->num_leds = num_leds;
    _clear = clear;
    _glitter_chance = glitter_chance;
  };

  struct Palette {
    unsigned int size;
    CRGB colors[8];
  };

  // Public Fields
  CRGB *leds;
  int num_leds;
  unsigned long wait;
  unsigned int loop;

  // Public Methods
  void run(Animation::Palette palette) {
    if (_clear) { blank(0); }
    for (loop = 0; loop < loops; loop++) {
      effect(palette);
    }
  };
  virtual void effect(Animation::Palette palette) {};
  void set_wait(unsigned long new_wait) { wait = new_wait; };
  void set_loops(unsigned int new_loops) { loops = new_loops; };
  void blank(unsigned long wait) {
    fill_solid(leds, num_leds, CRGB::Black);
    FastLED.show();
    delay(wait);
  };
  void show(unsigned long wait) {
    addGlitter();
    FastLED.show();
    delay(wait);
  };

private:
  // Private Fields
  bool _clear;
  fract8 _glitter_chance;
  unsigned int loops = 1;

  // Private Methods
  void addGlitter() {
    if(random8() < _glitter_chance) {
      leds[random16(num_leds)] += CRGB::White;
    }
  };
};
#endif