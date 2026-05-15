#include <iostream>
#include "box.h"

using namespace std;

int main() {
	try {
		int step; cin >> step;

		int* a1 = new int[2];
		a1[0] = 1; a1[1] = 2;
		int* a2 = new int[3];
		a2[0] = 2; a2[1] = 3; a2[2] = 4;
		Box<int*> b1(1, step);
		b1.push(a2, 3);
		b1.push(a1, 2);
		cout << b1.find(a1, 2);
	}
	catch (...) {}
	return 0;
}