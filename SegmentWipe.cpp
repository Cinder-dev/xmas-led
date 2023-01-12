#ifndef SegmentWipe_h
#define SegmentWipe_h
#include <FastLED.h>
#include "Animation.cpp"
class SegmentWipe : public Animation {
public:
  SegmentWipe(CRGB *leds, int num_leds) : Animation(leds, num_leds, false, 30) {};
  void effect(Animation::Palette palette) {
    int group_size = num_leds / groups;
    for (int c = 0; c < palette.size; c++) {
      for (unsigned int pos = 0; pos < group_size; pos++) {
        for (unsigned int i = pos; i < num_leds; i += group_size) {
          leds[i] = palette.colors[c];  // turn on the current group
        }
        show(wait);
      }
    }
  };

  void set_groups(unsigned int groups) { this->groups = groups; };
private:
  unsigned int groups = 1;
};
#endif