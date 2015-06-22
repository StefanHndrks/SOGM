#include "distortion.h"

distortion::distortion() {
  this->amount = 16;
  samplerate = 48000;
} // distortion()

distortion::distortion(int amount) {
  this->amount = amount;
  samplerate = 48000;
} // distortion()

int distortion::getAmount() {
  cout << "distortion.amount = " << amount << endl;

  return amount;
} // getAmount()

void distortion::setAmount(int amount) {
  this->amount = amount;
} // setAmount()

void distortion::process(float** buffer, int frames, int channels) {
  for (int chn = 0; chn < channels; chn++) {
    for (int frm = 0; frm < frames; frm++) {
      buffer[chn][frm] = round(buffer[chn][frm] * amount) / amount;
    } // for
  } // for
} // process()
