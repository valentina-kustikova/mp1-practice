#include "Matrix.h"
#include <iostream>

using namespace std;

void main() {
	double a[] = { 2.0, 4.5, 5.0, 10.0, 2.4, 3.7, 1.3, 1.2 };
	double b[] = { 2.4, 7.2, 6.0, 13.3, 7.4, 3.3, 10.7, 12.3 };
	double c[] = { 22.1, 4.5, 5.0, 10.0, 2.4, 3.7};
	Matrix MA(a, 2, 4);
	Matrix MB(b, 2, 4);
	Matrix MC(c, 2, 3);
	Matrix MTB(b, 4, 2);
	Matrix R(2, 4);
	try {
		R = MA + MB;
	}
	catch (char *str) {
		cout << str << endl;
	}
	cout << R << endl;
	try {
		R = MA + 13.13;
	}
	catch (char *str) {
		cout << str << endl;
	}
	cout << R << endl;
	try {
		R = MA - MC;
	}
	catch (char *str) {
		cout << str << endl;
	}
	cout << R << endl;
	try {
		R = MC - 13.13;
	}
	catch (char *str) {
		cout << str << endl;
	}
	cout << R << endl;
	try {
		R = MA * MTB;
	}
	catch (char *str) {
		cout << str << endl;
	}
	cout << R << endl;
	try {
		R = MA * 13.13;
	}
	catch (char *str) {
		cout << str << endl;
	}
	cout << R << endl;
	try {
		cout << MA[3] << endl;
	}
	catch (char *str) {
		cout << str << endl;
	}
}