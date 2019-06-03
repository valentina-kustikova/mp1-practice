#include "Matrix.h"
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

void main() 
{
	srand(static_cast<unsigned int>(time(0)));
	Matrix m1(3, 3), m2(3, 3), m3(0, 0), mRes(0, 0), mDiffDim(4,4);
	m1.Gen();
	m2.Gen();
	m3.Gen();
	mDiffDim.Gen();
	cout << "Matrix 1: " << endl;
	m1.Print();
	cout << "Matrix 2: " << endl;
	m2.Print();
	cout << "Matrix 3: " << endl;
	m3.Print();
	cout << "Matrix DiffDim: " << endl;
	mDiffDim.Print();

	try {
		mRes = m1 + m2;
		cout << "Matrix 1 + Matrix 2" << endl;
		mRes.Print();
	}
	catch(string k) {
		cout << k << endl;
	}

	try {
		mRes = m1 + mDiffDim;
		cout << "Matrix 1 + Matrix DiffDim" << endl;
		mRes.Print();
	}
	catch (string k) {
		cout << k << endl;
	}

	try {
		mRes = m1 + 5.0;
		cout << "Matrix 1 + 5.0" << endl;
		mRes.Print();
	}
	catch (string k) {
		cout << k << endl;
	}

	try {
		mRes = m1 + 0.0;
		cout << "Matrix 1 + 0.0" << endl;
		mRes.Print();
	}
	catch (string k) {
		cout << k << endl;
	}

	try {
		mRes = m1 + m3;
		cout << "Matrix 1 + Matrix 3" << endl;
		mRes.Print();
	}
	catch (string k) {
		cout << k << endl;
	}

	try {
		mRes = m1 * m2;
		cout << "Matrix 1 * Matrix 2" << endl;
		mRes.Print();
	}
	catch (string k) {
		cout << k << endl;
	}

	try {
		mRes = m1 * mDiffDim;
		cout << "Matrix 1 * Matrix DiffDim" << endl;
		mRes.Print();
	}
	catch (string k) {
		cout << k << endl;
	}

	try {
		mRes = m1 * 2.0;
		cout << "Matrix 1 * 2.0" << endl;
		mRes.Print();
	}
	catch (string k) {
		cout << k << endl;
	}

	try {
		cout << "[1][0] element of Matrix 1: " << (int)m1[1][0] << endl;
	}
	catch (string k) {
		cout << k << endl;
	}


	int t;
	cin >> t;
}