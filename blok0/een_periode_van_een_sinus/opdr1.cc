//verschillende dingen nu gebruikt.
//als eerst vectoren, tweede keer lees ik deze uit met iterator,
//probeerde die ook te vullen via iterator, maar kwam er al snel achter dat in dit geval niet kon.
//daarna via new zoals eerst

//functies aangepast zodat ze een freq willen, en samplerate is nu optioneel
//ook geeft de square functie nu geen pulse meer

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>

using namespace std;

static int SAMPLERATE = 48000;

vector<float> sinewave(int freq) {
	int vectorSize = SAMPLERATE / freq;
	vector<float> temp(vectorSize);
	for (int i = 0; i < temp.size(); i++) {
		temp[i] = sin((i * M_PI * 2) / vectorSize);
	}
	return temp;
}

vector<float> squarewave(int freq) {
	int vectorSize = SAMPLERATE / freq;
	vector<float> temp(vectorSize);
	for (int i = 0; i < vectorSize; i++) {
		temp[i] = i < (vectorSize / 2) ? 1 : -1;
	}
	return temp;
}

float* trianglewave(int freq) {
	int tableSize = SAMPLERATE / freq;
	float *temp = new float[tableSize];
	for (int i = 0; i < tableSize; i++) {
		int iMod = (i + (tableSize / 4) + 1) % tableSize;
		float incr = (iMod * 2) / (tableSize * 0.5);
		temp[i] = iMod < (tableSize / 2) ? incr - 1 : 3 - incr;
	}
	return temp;
}

float* sawtoothwave(int freq) {
	int tableSize = SAMPLERATE / freq;
	float *temp = new float[tableSize];
	for (int i = 0; i < tableSize; i++) {
		temp[i] = (i / (tableSize * 0.5)) - 1;
	}
	return temp;
}

int main(int argc, char *argv[]) {
	if ((argc != 3) && (argc != 4)) {
		cout << "function: plot the chosen soundwave" << endl;
		cout << "syntax: ./opdr1 sine 440" << endl;
		cout << "        ./opdr1 saw 1240 24000" << endl;
		cout << "give a soundwave name, frequentie and a optional samplerate" << endl;
		cout << "the default samplerate is 48000" << endl;
	} else {
		float freq = atof(argv[2]);
		if (argc == 4) {
			SAMPLERATE = atoi(argv[3]);
		}
		int tableSize = SAMPLERATE / freq;
		float *output;

		if (strncmp(argv[1], "sin", 3) == 0) {
			vector<float> vOutput = sinewave(freq);
			for (int i = 0; i < vOutput.size(); i++) {
				cout << vOutput[i] << endl;
			}
		} else if (strncmp(argv[1], "squ", 3) == 0) {
			vector<float> vOutput = squarewave(freq);
			for (vector<float>::iterator i = vOutput.begin(); i != vOutput.end(); i++) {
				cout << *i << endl;
			}
		} else if (strncmp(argv[1], "tri", 3) == 0) {
			output = trianglewave(freq);
			for (int i = 0; i < tableSize; i++) {
				cout << output[i] << endl;
			}
		} else if (strncmp(argv[1], "saw", 3) == 0) {
			output = sawtoothwave(freq);
			for (int i = 0; i < tableSize; i++) {
				cout << output[i] << endl;
			}
		} else {
			cout << "available soundwaves:" << endl;
			cout << "sine, square, triangle, sawtooth" << endl;
			cout << "only the first 3 letters are needed" << endl;
		}
		delete[] output;
	}
	return 0;
}
