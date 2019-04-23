#include<iostream>
#include<fstream>
#include "util.h"

using namespace std;

int nextcommand(int *i, int *v, int *f) {
	char c;
	while (1) {
		scanf("%c", &c);
		if (c == ' ' || c == '\t' || c == '\n') {
			continue;
		}
		if (c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'W' || c == 'w') {
			cout << "COMMAND " << c << "." << endl;
			break;
		}
		if (c == 'C' || c == 'c') {
			scanf("%d", i); scanf("%d", v); scanf("%d", f);
			cout << "COMMAND " << c << " " << *i << " " << *v << " " << *f << "." << endl;
			break;
		}
		else {
			cout << "invalid command.\n";
		}
	}
	return c;
}