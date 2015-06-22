#include <math.h>
#include <iostream>
using namespace std;

#ifndef __guitarFX__amplifier__
#define __guitarFX__amplifier__

class amplifier //Base class
{
public:
  amplifier();
  amplifier(float level);

  float getLevel();
  void setLevel(float level);

  virtual void process(float **buffer, int frames, int channels);
protected:
  int samplerate;
private:
  float level;
};

#endif
