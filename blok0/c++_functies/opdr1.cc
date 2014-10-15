#include <iostream>
#include <stdlib.h>

using namespace std;

int hello(char **x, int length) {
	int out = 0;
	for (int i = 1; i < length; i++) {
		out += atoi(x[i]);
	}
	return out;
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		cout << "functie: telt alle getallen bij elkaar op" << endl;
		cout << "syntax: ./opdr1 4 9 8" << endl;
		cout << "geef zoveel elementen als u wilt, symbolen woorden genegeerd" << endl;
	} else {
		cout << "uitkomst: " << hello(argv, argc) << endl;
	}
	return 0;
}
