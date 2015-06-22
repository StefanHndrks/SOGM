#include "amplifier.h"
#include "tremolo.h"
#include "distortion.h"
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
  int channels = 2;
  int frames = 512;
  float** buffer = new float*[channels];

  for (int chn = 0; chn < channels; chn++) {
    buffer[chn] = new float[frames];
    for (int frm = 0; frm < frames; frm++) {
      buffer[chn][frm] = sin(float(frm) / 20);
    } // for
  } // for

  amplifier* effect[3];

  effect[0] = new amplifier(0.5);
  effect[1] = new tremolo(5);
  effect[2] = new distortion(8);

  cout << "level = " << buffer[0][20] << endl;
  effect[0]->process(buffer, frames, channels);

  cout << "level = " << buffer[0][20] << endl;
  effect[1]->process(buffer, frames, channels);

  cout << "level = " << buffer[0][20] << endl;
  effect[2]->process(buffer, frames, channels);

  cout << "level = " << buffer[0][20] << endl;
} // main()
