#include <iostream>

using namespace std;

void hallo(char **x, int length) {
	for (int i = 1; i < length; i++) {
		cout << i << ": " << x[i] <<endl;
	}
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		cout << "functie: print de input" << endl;
		cout << "syntax: ./opdr2 hoi hey 64" << endl;
		cout << "geef zoveel argumenten als u wilt" << endl;
	} else {
		hallo(argv, argc);
	}
	return 0;
}
