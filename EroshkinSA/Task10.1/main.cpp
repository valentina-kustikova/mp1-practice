#include <iostream>
#include "box.h"

using namespace std;

int main() {
	int step;
	cin >> step;
	Box<int> b(5, step, 1);
	cout << b << endl;
	b.remove(1);
	cout << b << endl;
	b.remove(b[0]);
	cout << b << endl;
	return 0;
}