#include <iostream>
#include <locale.h>

#include "pol.h"

using namespace std;

int main(int argc, char** argv) {
	string fname;
	int deg1, deg2, res, i, choice, num, x;
	setlocale(LC_ALL, "Rus");
	if (argc < 2) {
		printf("Incorrect parametres");
		return 1;
	}
	fname = std::string(argv[1]);
	polinom p1(fname, 1);
	polinom p2(fname, 2);
	cout << "Полиномы:\n1)" << p1 << "\n2)" << p2 << "\nвыберите какую операцию вы хотите проделать с ними:\nсложить: 1\nвычесть: 2\nумножить: 3\nдифференцировать: 4\nвычислить значение в точке: 5\n";
	cin >> choice;
	if ((choice >= 1) && (choice <= 4)) {
		int presdeg;
		if (choice == 1) presdeg = (p1 + p2).deg;
		if (choice == 2) presdeg = (p1 - p2).deg;
		if (choice == 3) presdeg = (p1 * p2).deg;
		if (choice == 4) {
			cout << "введите 1 или 2 - номер полинома: ";
			cin >> num;
			if (num == 1) presdeg = (p1.pdif()).deg;
			else if (num == 2) presdeg = (p2.pdif()).deg;
		}
		polinom pres(presdeg);
		if (choice == 1) pres = p1 + p2;
		if (choice == 2) pres = p1 - p2;
		if (choice == 3) pres = p1 * p2;
		if (choice == 4) {
			if (num == 1) pres = p1.pdif();
			else if (num == 2) pres = p2.pdif();
		}
		cout << "Получившийся полином: \n" << pres;
	}
	if (choice == 5) {
		cout << "введите 1 или 2 - номер полинома: ";
		cin >> num;
		cout << "введите число, от которого будем считать значение: ";
		cin >> x;
		if (num == 1) res = p1.pznach(x);
		else if (num == 2) res = p2.pznach(x);
		cout << "значение полинома в этой точке: " << res << endl;
	}
	
	return 0;
}
