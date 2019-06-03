#include "Vector.h"
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

void main()
{
	srand(static_cast<unsigned int>(time(0)));
	Vector *v1 = new Vector(5);
	Vector *v2 = new Vector(5);
	Vector *v3 = new Vector(5);
	v1->Gen();
	v2->Gen();
	v1->PrintVector(1);
	v2->PrintVector(2);
	try{
		*v3 = *v2;
		cout << "Vector 3 = Vector 2" << endl;
	}
	catch (string k) { cout << k << endl; }
	try {
		*v2 = *v2 + *v1;
		cout << "Vector 2 = Vector 2 + Vector 1" << endl;
		v2->PrintVector(2);
	}
	catch (string k) { cout << k << endl; }
	try { cout << "Length of Vector 3" << v3->Length() << endl; }
	catch (string k) { cout << k << endl; }
	try {
		*v3 += *v1;
		cout << "Vector 3 += Vector 1" << endl;
		v3->PrintVector(3);
	}
	catch (string k) { cout << k << endl; }
	try {
		*v3 = *v3 * 5.0;
		cout << "Vector 3 = Vector 3 * 5.0" << endl;
		v3->PrintVector(3);
	}
	catch (string k) { cout << k << endl; }
	try { cout << "Vector 1 * Vector 2 = " << (*v1 * *v2) << endl; }
	catch (string k) { cout << k << endl; }
	int t;
	cin >> t;
}