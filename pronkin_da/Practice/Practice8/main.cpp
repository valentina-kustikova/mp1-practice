#include "Vector.h"
#include <iostream>

void main() {
	double a[] = {3, 6, 7, 10};
	double b[] = {4, 3, 1, 13};
	Vector V1 = Vector(4, a);
	Vector V2 = Vector(4, b);
	Vector V3 = Vector(4);
	try {
		V3 = V1 + V2;
	}
	catch (char* str) {
		cout << str << endl;
	}
	try {
		cout << "Square bracket overload " << V3[2] << endl;
	}
	catch (char* str) {
		cout << str << endl;
	}

	try {
		cout << " Vector length" << V3.Vlength() << endl;
	}
	catch (char* str) {
		cout << str << endl;
	}
	try {
		V3 = V2 - V1;
	}
	catch (char* str) {
		cout << str << endl;
	}
	try {
		cout << " Vector length" << V3.Vlength() << endl;
	}
	catch (char* str) {
		cout << str << endl;
	}
	try {
		cout << "Scalar product" << V1 * V2 << endl;
	}
	catch (char* str) {
		cout << str << endl;
	}
	try {
		V3 = V1 * 2.0;
	}
	catch (char* str) {
		cout << str << endl;
	}
	try {
		cout << "Square bracket overload " << V3[2] << endl;
	}
	catch (char* str) {
		cout << str << endl;
	}
	try {
		V3 += V1;
	}
	catch (char* str) {
		cout << str << endl;
	}
	try {
		cout << "Square bracket overload " << V3[2] << endl;
	}
	catch (char* str) {
		cout << str << endl;
	}
	Vector *V4 = new Vector(4);
	*V4 = V1;
	cout << (*V4)[2] << endl;
}