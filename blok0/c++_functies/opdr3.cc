#include <iostream>
#include <stdlib.h>

using namespace std;

int hallo(char **x, int length) {
	int max = 0;
	for (int i = 0; i < length; i++) {
		int xi = atoi(x[i]);
		if (xi > max) {
			max = xi;
		}
	}
	return max;
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		cout << "functie: geeft de max van de input" << endl;
		cout << "syntax: ./opdr3 6 2 8" << endl;
		cout << "geef zoveel getallen als u wilt, symbolen woorden genegeerd" << endl;
	} else {
		cout << "max: " << hallo(argv, argc) << endl;
	}
	return 0;
}
