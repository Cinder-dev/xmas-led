#include <FastLED.h>
#include "Animation.cpp"
#include "ColorWipe.cpp"
#include "EveryOther.cpp"
#include "SegmentWipe.cpp"
#include "Fade.cpp"
#include "Trail.cpp"
#include "OuterFill.cpp"
#include "InnerFill.cpp"
#include "Fan.cpp"
#include "SolidRainbow.cpp"
#include "RotateRainbow.cpp"
#include "Ghosts.cpp"

 // Which pin on the Arduino is connected to the LEDs?
#define DATA_PIN 3

// How many LEDs are attached to the Arduino?
#define NUM_LEDS 30

CRGB leds[NUM_LEDS+1];

Animation::Palette p1 = { 2, CRGB::Red, CRGB::Green, };
Animation::Palette p2 = { 2, CRGB::Silver, CRGB::Gold, };
Animation::Palette p3 = { 4, CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Yellow };
Animation::Palette p4 = { 2, CRGB::White, CRGB::Blue, };
Animation::Palette p5 = { 3, CRGB::Red, CRGB::White, CRGB::Blue };
Animation::Palette p6 = { 7, CRGB::White, CRGB::Aqua, CRGB::DarkCyan, CRGB::Blue, CRGB::DarkCyan, CRGB::Aqua, CRGB::White, };

Animation::Palette palettes[] = {
  p1,
  p2,
  p3,
  p4,
  p5,
  p6,
};
unsigned int palettes_size = 6;

static ColorWipe color_wipe(leds, NUM_LEDS);
static EveryOther every_other(leds, NUM_LEDS);
static SegmentWipe segment_wipe(leds, NUM_LEDS);
static Fade fade(leds, NUM_LEDS);
static Trail trail(leds, NUM_LEDS);
static OuterFill outer_fill(leds, NUM_LEDS);
static InnerFill inner_fill(leds, NUM_LEDS);
static Fan fan(leds, NUM_LEDS);
static SolidRainbow solid_rainbow(leds, NUM_LEDS);
static RotateRainbow rotate_rainbow(leds, NUM_LEDS);
static Ghosts ghosts(leds, NUM_LEDS);

Animation *animations[] = {
  &ghosts,
  &color_wipe,
  &every_other,
  &segment_wipe,
  &fade,
  &trail,
  &outer_fill,
  &inner_fill,
  &fan,
  // &solid_rainbow,
  // &rotate_rainbow,
};
unsigned int animations_size = 8;

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS+1);
  FastLED.setBrightness(100);

  randomSeed(analogRead(0));

  // Animation Settings
  color_wipe.set_wait(32);

  every_other.set_wait(500);
  every_other.set_loops(10);

  segment_wipe.set_wait(64);
  segment_wipe.set_loops(2);
  segment_wipe.set_groups(3);

  fade.set_wait(32);
  fade.set_loops(1);

  trail.set_wait(32);
  trail.set_loops(2);

  outer_fill.set_wait(64);
  outer_fill.set_loops(2);

  inner_fill.set_wait(64);
  inner_fill.set_loops(2);

  fan.set_wait(32);
  fan.set_loops(2);
  fan.set_width(6);

  solid_rainbow.set_wait(32);
  solid_rainbow.set_loops(2);

  rotate_rainbow.set_wait(16);
  rotate_rainbow.set_loops(2);

  ghosts.set_wait(16);
  ghosts.set_loops(1);
  ghosts.set_runs(500);

  leds[30] = CRGB::FairyLight;
}

int next_palette_in = 0;
Animation::Palette current_palette;

void loop() {
  if (next_palette_in-- <= 0) {
    next_palette_in = 5;
    current_palette = palettes[random8(palettes_size)];
  }

  Animation *animation = animations[random8(animations_size)];
  animation->run(current_palette);
}

// ============================================================================
// ===================== Utilities ============================================
// ============================================================================

/*
* Blanks the LEDs and waits for a short time.
*/
void blank(unsigned long wait) {
	fill_solid(leds, NUM_LEDS, CRGB::Black);
	FastLED.show();
	delay(wait);
}