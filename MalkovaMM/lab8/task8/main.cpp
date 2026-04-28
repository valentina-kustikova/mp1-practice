#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "pol.h"
#include <locale.h>
using namespace std;

int main(int argc, char** argv) {
	string fname;
	int deg1, deg2, resdeg, res, i, choice, num, x;
	setlocale(LC_ALL, "Rus");
	if (argc < 2) {
		printf("Incorrect parametres");
		return 1;
	}
	fname = argv[1];
	polinom p1(fname, 1);
	polinom p2(fname, 2);
	cout << "Полиномы:\n1)" << p1 << "\n2)" << p2 << "\nвыберите какую операцию вы хотите проделать с ними:\nсложить: 1\nвычесть: 2\nумножить: 3\nдифференцировать: 4\nвычислить значение в точке: 5\n";
	cin >> choice;
	polinom pres(p1.deg + p2.deg);
	if (choice == 1) pres = p1 + p2;
	if (choice == 2) pres = p1 - p2;
	if (choice == 3) pres = p1 * p2;
	if (choice == 4) {
		cout << "введите 1 или 2 - номер полинома: ";
		cin >> num;
		if (num == 1) pres = p1.pdif();
		else if (num == 2) pres = p2.pdif();
	}
	if (choice == 5) {
		cout << "введите 1 или 2 - номер полинома: ";
		cin >> num;
		cout << "введите число, от которого будем считать значение: ";
		cin >> x;
		if (num == 1) res = p1.pznach(x);
		else if (num == 2) res = p2.pznach(x);
		cout << "значение полинома в этой точке: %d" << res << endl;
	}
	if ((choice >= 1) && (choice <= 4)) {
		resdeg = pres.deg;
		cout << "Получившийся полином: \n" << pres;
	}
	return 0;
}
