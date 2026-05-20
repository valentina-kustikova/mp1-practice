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
		Box<int*> b1(20, step);
		b1.push(a2);
		b1.push(a1);
		cout << b1 << endl;
		cout << b1.find(a1) << "\n"; b1.remove(a1);
		cout << b1 << endl;





		Box<int> d(20, step);
		d.push(42); d.push(45); d.push(78);
		cout << d << endl;

	}
	catch (...) {}
	return 0;
}