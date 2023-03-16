#include <iostream>
#include <clocale>
#include <cstdlib>
#include "display.h"
#include "polynom.h"
using namespace std;

void choose() {
	cout << "1. Сложить полиномы." << endl;
	cout << "2. Вычесть из одного полинома второй полином." << endl;
	cout << "3. Умножение полиномов." << endl;
	cout << "4. Вычислить значение по заданному аргументу." << endl;
	cout << "5. Найти производную полинома." << endl;
	cout << "0. Выход\n" << endl;
}

void answer(int& ans) {
	do {
		cin >> ans;
	} while (ans > 5 || ans < 0);
}

void retry(int& ans) {
	cout << "\nПродолжить? (1/0)" << endl;
	answer(ans);
}


void print_p(TPolynom*& p, const int n) {
	for (int i = 0; i < n; i++) {
		cout << "f" << i << " = ";
		cout << p[i];
	}
	cout << endl;
}
void index(int* ind, int n) {
	cout << "Выберите 2 полинома:\n";
	cout << "Полином 1: ";
	do {
		cin >> ind[0];
	} while (ind[0] < 0 || ind[0] >= n);

	cout << "Полином 2: ";
	do {
		cin >> ind[1];
	} while (ind[1] < 0 || ind[1] >= n);
	cout << endl;
}

void print_2p(TPolynom& p1, TPolynom& p2, int* ind) {
	cout << "f" << ind[0] << " = ";
	cout << p1;
	cout << "f" << ind[1] << " = ";
	cout << p2;
	cout << endl;
}