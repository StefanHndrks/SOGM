//delete naar regel 81 verschoven om memory leak te fixen
//delete stont na return, wat nergen op slaat

#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

static int SAMPLERATE = 48000

float* sinewave(int freq) {
	int tableSize = rate / freq;
	float *temp = new float[tableSize];
	for (int i = 0; i < tableSize; i++) {
		temp[i] = sin((i * M_PI * 2) / tableSize);
	}
	return temp;
}

float* squarewave(int tableSize) {
	float *temp = new float[tableSize];
	for (int i = 0; i < tableSize; i++) {
		temp[i] = 0 <= sin((i * M_PI * 2) / tableSize) ? 1 : -1;
	}
	return temp;
}

float* trianglewave(int tableSize) {
	float *temp = new float[tableSize];
	for (int i = 0; i < tableSize; i++) {
		int iMod = (i + (tableSize / 4)) % tableSize;
		float incr = (iMod * 2) / (tableSize * 0.5);
		temp[i] = iMod < (tableSize / 2) ? incr - 1 : 3 - incr;
	}
	return temp;
}

float* sawtoothwave(int tableSize) {
	float *temp = new float[tableSize];
	for (int i = 0; i < tableSize; i++) {
		temp[i] = (i / (tableSize * 0.5)) - 1;
	}
	return temp;
}

int main(int argc, char *argv[]) {
	if (argc != (3 || 4)) {
		cout << "function: plot the chosen soundwave" << endl;
		cout << "syntax: ./opdr1 sine 440" << endl;
		cout << "        ./opdr1 saw 1240 24000" << endl;
		cout << "give a soundwave name, frequentie and a optinal samplerate" << endl;
	} else {
		float freq = atof(argv[2]);
		int tableSize = rate / freq;
		float* output;
		if (argc == 4) {
			SAMPLERATE = atoi(argv[3]);
		}

		if (strncmp(argv[1], "sin", 3) == 0) {
			output = sinewave(tableSize);
			for (int i = 0; i < tableSize; i++) {
				cout << output[i] << endl;
			}
		} else if (strncmp(argv[1], "squ", 3) == 0) {
			output = squarewave(tableSize);
			for (int i = 0; i < tableSize; i++) {
				cout << output[i] << endl;
			}
		} else if (strncmp(argv[1], "tri", 3) == 0) {
			output = trianglewave(tableSize);
			for (int i = 0; i < tableSize; i++) {
				cout << output[i] << endl;
			}
		} else if (strncmp(argv[1], "saw", 3) == 0) {
			output = sawtoothwave(tableSize);
			for (int i = 0; i < tableSize; i++) {
				cout << output[i] << endl;
			}
		} else {
			cout << "avelible waves:" << endl;
			cout << "sine, square, triangle, sawtooth" << endl;
			cout << "only the first 3 letters are needed" << endl;
		}
		delete[] output;
	}
	return 0;
}
