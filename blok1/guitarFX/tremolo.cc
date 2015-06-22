#include "tremolo.h"

tremolo::tremolo() {
  this->freq = 7;
  offset = 0;
  samplerate = 48000;
} // tremolo()

tremolo::tremolo(float freq) {
  this->freq = freq;
  offset = 0;
  samplerate = 48000;
} // tremolo()

float tremolo::getFreq() {
  cout << "tremolo.freq = " << freq << endl;

  return freq;
} // getFreq()

void tremolo::setFreq(float freq) {
  this->freq = freq;
} // setFreq()

void tremolo::process(float** buffer, int frames, int channels) {
  for (int chn = 0; chn < channels; chn++) {
    for (int frm = 0; frm < frames; frm++) {
      buffer[chn][frm] *= (sin(offset * freq/samplerate * 2 * M_PI) + 1) / 2;
      offset++;
    } // for
  } // for
} // process()
