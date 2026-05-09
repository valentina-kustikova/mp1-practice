#include <iostream>
#include <locale.h>
#include "pol.h"

using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Rus");
	if (argc < 2) {
		printf("Incorrect parametres");
		return 1;
	}
	string fname = std::string(argv[1]);
	polinom p1(fname, 1), p2(fname, 2);
	cout << "Полиномы:\n1)" << p1 << "\n2)" << p2 << 
		"\nвыберите какую операцию вы хотите проделать с ними:" <<
		"\nсложить: 1\nвычесть: 2\nумножить: 3\nдифференцировать: 4\n" <<
		"вычислить значение в точке: 5\n";
	int choice;
	cin >> choice;
	int num;
	if ((choice >= 1) && (choice <= 4)) {
		polinom pres;
		if (choice == 1) pres = p1 + p2;
		if (choice == 2) pres = p1 - p2;
		if (choice == 3) pres = p1 * p2;
		if (choice == 4) {
			cout << "введите 1 или 2 - номер полинома: ";
			cin >> num;
			if (num == 1) pres = p1.pdif();
			else if (num == 2) pres = p2.pdif();
		}
		cout << "Получившийся полином: \n" << pres;
	}
	if (choice == 5) {
		cout << "введите 1 или 2 - номер полинома: ";
		cin >> num;
		cout << "введите число, от которого будем считать значение: ";
		int x;
		cin >> x;
		double res;
		if (num == 1) res = p1(x);
		else if (num == 2) res = p2(x);
		cout << "значение полинома в этой точке: " << res << endl;
	}
	
	return 0;
}
