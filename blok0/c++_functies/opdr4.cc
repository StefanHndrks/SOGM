#include <iostream>
#include <stdlib.h>

using namespace std;

void hallo(char **x, int length) {
	char *temp[length];
	for (int i = 0; i < length; i++) {
		temp[(i + length - 1) % length] = x[i];
	}
	for (int i = 0; i < length; i++) {
		x[i] = temp[i];
	}
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		cout << "functie: roteert de lijst naar links" << endl;
		cout << "syntax: ./opdr4 hoi hey 8" << endl;
		cout << "geef zoveel elementen als u wilt" << endl;
	} else {
		int length = argc - 1;
		char *temp [length];
		for (int i = 1; i < argc; i++) {
			temp[i - 1] = argv[i];
		}
		hallo(temp, length);
		for (int i = 0; i < length; i++) {
			cout << temp[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
