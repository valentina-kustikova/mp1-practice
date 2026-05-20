#include <iostream>
#include "box.h"

using namespace std;

int main() {
	try {
		int step; cin >> step;
		int* a1 = new int(1);
		int* a2 = new int(2);
		int* a3 = new int(3);
		Box<int*> b1(1, step);
		b1.push(a2);
		b1.push(a1);
		cout << b1 << endl;
		cout << b1.find(a3) << "\n"; b1.remove(a1);
		cout << b1 << endl;

		Box<int> d(20, step);
		d.push(42); d.push(45); d.push(78);
		cout << d << endl;

		Box<int> e(4, step + 8);
		e.push(1); e.push(2);

		Box<Box<int>*> B(5, step - 3);
		B.push(&d); B.push(&e);
		cout << B << endl;
	}
	catch (const std::exception& ex) {
		cout << ex.what() << endl;
	}
	return 0;
}