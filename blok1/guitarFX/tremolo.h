#include "amplifier.h"
#include <iostream>
using namespace std;

#ifndef __guitarFX__tremolo__
#define __guitarFX__tremolo__

class tremolo : public amplifier
{
public:
  tremolo();
  tremolo(float freq);

  float getFreq();
  void setFreq(float freq);

  virtual void process(float **buffer, int frames, int channels);
protected:

private:
  float freq;
  int offset;
};

#endif
