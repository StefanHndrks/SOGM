#include "amplifier.h"
#include <iostream>
using namespace std;

#ifndef __guitarFX__distortion__
#define __guitarFX__distortion__

class distortion : public amplifier
{
public:
  distortion();
  distortion(int amount);

  int getAmount();
  void setAmount(int amount);

  virtual void process(float **buffer, int frames, int channels);
protected:

private:
  int amount;
};

#endif
