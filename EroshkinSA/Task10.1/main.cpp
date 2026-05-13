#include <iostream>
#include "box.h"

using namespace std;

int main() {
	int step;
	cin >> step;
	Box<int> b(5, step);
	cout << b << endl;
	b.push(2);
	cout << b << endl;
	b.remove(b[0]);
	cout << b << endl;
	return 0;
}