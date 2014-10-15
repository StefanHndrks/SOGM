#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

float* sinewave(int tableSize) {
	float *temp = new float[tableSize];
	for (int i = 0; i < tableSize; i++) {
		temp[i] = sin((i * M_PI * 2) / tableSize);
	}
	return temp;
	delete[] temp;
}

float* squarewave(int tableSize) {
	float *temp = new float[tableSize];
	for (int i = 0; i < tableSize; i++) {
		temp[i] = 0 <= sin((i * M_PI * 2) / tableSize) ? 1 : -1;
	}
	return temp;
	delete[] temp;
}

float* trianglewave(int tableSize) {
	float *temp = new float[tableSize];
	for (int i = 0; i < tableSize; i++) {
		int iMod = (i + (tableSize / 4)) % tableSize;
		float incr = (iMod * 2) / (tableSize * 0.5);
		temp[i] = iMod < (tableSize / 2) ? incr - 1 : 3 - incr;
	}
	return temp;
	delete[] temp;
}

float* sawtoothwave(int tableSize) {
	float *temp = new float[tableSize];
	for (int i = 0; i < tableSize; i++) {
		temp[i] = (i / (tableSize * 0.5)) - 1;
	}
	return temp;
	delete[] temp;
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
		cout << "functie: plot de uitgekozen geluidsgolf" << endl;
		cout << "syntax: ./opdr1 sine 440 48000" << endl;
		cout << "geef een golfvorm, frequentie en dan een samplerate" << endl;
	} else {
		float freq = atof(argv[2]);
		float rate = atof(argv[3]);
		int tableSize = rate / freq;
		float *output;

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
			cout << "beschikbare golfen:" << endl;
			cout << "sine, square, triangle, sawtooth" << endl;
			cout << "alleen de eerste 3 letters zijn nodig" << endl;
		}
	}
	return 0;
}
