#include "Container.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	Container<int, 3> c1;
	Container<int*, 5> c3;
	int r;
	cout << "Working with Containers 1 and 2 (int)" << endl;
	do {
		cout << "Type: " << endl << "1 to add var" << endl << "2 to remove var" << endl << "3 to get N var" << endl << "4 to print container" << endl << "5 to copy container" << endl;
		cin >> r;
		switch (r) {
		case 1: {
					int k;
					cout << "Type the var: ";
					cin >> k;
					try {
						c1.Add(k);
					}
					catch (string k) {
						cout << k << endl;
					}
					break;
		}
		case 2: {
					int k;
					cout << "Type the var: ";
					cin >> k;
					try {
						c1.Delete(k);
					}
					catch (string k) {
						cout << k << endl;
					}
					break;
		}
		case 3: {
					int k;
					cout << "Type the var: ";
					cin >> k;
					try {
						cout << endl << c1[k] << endl;
					}
					catch (string k) {
						cout << k << endl;
					}
					break;
		}
		case 4: {
					try {
						c1.Print();
					}
					catch (string k) {
						cout << k << endl;
					}
					break;
		}
		case 5: {
					Container<int, 3> *c = new Container<int, 3>(c1);
					cout << "Container: " << endl;
					try {
						c1.Print();
					}
					catch (string k) {
						cout << k << endl;
					}
					cout << "Copied Container: " << endl;
					try {
						c->Print();
					}
					catch (string k) {
						cout << k << endl;
					}
					break;
		}
		case 0: {
					break;
		}
		default: {
					 cout << "Wrong number" << endl;
					 continue;
		}
		}
	} while (r != 0);

	cout << "Working with Containers 3 and 4 (char)" << endl;
	do {
		cout << "Type: " << endl << "1 to add var" << endl << "2 to remove var" << endl << "3 to get N var" << endl << "4 to print container" << endl << "5 to copy container" << endl;
		cin >> r;
		switch (r) {
		case 1: {
					int k;
					cout << "Type the var: ";
					cin >> k;
					try {
						c3.Add(k);
					}
					catch (string k) {
						cout << k << endl;
					}
					break;
		}
		case 2: {
					int k;
					cout << "Type the var: ";
					cin >> k;
					try {
						c3.Delete(k);
					}
					catch (string k) {
						cout << k << endl;
					}
					break;
		}
		case 3: {
					int k;
					cout << "Type the var: ";
					cin >> k;
					try {
						cout << endl << c3[k] << endl;
					}
					catch (string k) {
						cout << k << endl;
					}
					break;
		}
		case 4: {
					try {
						c3.Print();
					}
					catch (string k) {
						cout << k << endl;
					}
					break;
		}
		case 5: {
					Container<int*, 5> *c = new Container<int*, 5>(c3);
					cout << "Container: " << endl;
					try {
						c3.Print();
					}
					catch (string k) {
						cout << k << endl;
					}
					cout << "Copied Container: " << endl;
					try {
						c->Print();
					}
					catch (string k) {
						cout << k << endl;
					}
					break;
		}
		case 0: {
					break;
		}
		default: {
					 cout << "Wrong number" << endl;
					 continue;
		}
		}
	} while (r != 0);
	return 0;
}