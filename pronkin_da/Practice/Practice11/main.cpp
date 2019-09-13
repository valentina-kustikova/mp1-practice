#include "Container.h"
#include "Containers.h"
#include <iostream>

using namespace std;

void main() {
	Container<int, 6> C;
	for (int i = 0; i < 4; i++) {
		int a;
		cin >> a;
		try {
			C.Add(a);
		}
		catch (char* str) {
			cout << str << endl;
		}
	}
	int b;
	cin >> b;
	try {
		cout << C.Find(b) << endl;
	}
	catch(char* str){
		cout << str << endl;
	}
	try {
		C.Delete(b);
	}
	catch (char* str) {
		cout << str << endl;
	}
	cout << C[2] << endl;
	Container<int*, 6> CS;
	for (int i = 0; i < 4; i++) {
		int a;
		cin >> a;
		try {
			CS.Add(&a);
		}
		catch (char* str) {
			cout << str << endl;
		}
	}
	Container<int*, 6> CG(CS);
	cin >> b;
	try {
		cout << CS.Find(&b) << endl;
	}
	catch (char* str) {
		cout << str << endl;
	}
	try {
		cout << CG.Find(&b) << endl;
	}
	catch (char* str) {
		cout << str << endl;
	}
	try {
		CS.Delete(&b);
	}
	catch (char* str) {
		cout << str << endl;
	}
	cout << CS[2] << endl;
}