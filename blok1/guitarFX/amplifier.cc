#include "amplifier.h"

amplifier::amplifier() {
  this->level = 1;
  samplerate = 48000;
} // amplifier()

amplifier::amplifier(float level) {
  this->level = level;
  samplerate = 48000;
} // amplifier()

float amplifier::getLevel() {
  cout << "amplifier.level = " << level << endl;

  return level;
} // getLevel()

void amplifier::setLevel(float level) {
  this->level = level;
} // setLevel()

void amplifier::process(float** buffer, int frames, int channels) {
  for (int chn = 0; chn < channels; chn++) {
    for (int frm = 0; frm < frames; frm++) {
      buffer[chn][frm] *= level;
    } // for
  } // for
} // process()
