#include <iostream>
#include <cstdlib>
#include <clocale>
#include <fstream> 
#include "polynom.h"
#include "display.h"
using namespace std;

/*
Чтение происходит из файла "data.txt"
-В первой строке - количество полиномов
-В второй строке перечисленны степени каждого полинома
-В последующих строках перечисленны коэффициенты полиномов

!!!Предполагается, что введенные данные верны!!!
*/

int main() {
	setlocale(LC_ALL, "rus");

	int n, ans = 1;
	float x;
	int ind_1;
	int ind[2];

	TPolynom* p;
	TPolynom res;

	

	try {
		read_file(p, n);

		while (ans) {
			system("cls");
			print_p(p, n);
			choose();
			answer(ans);

			switch (ans) {
			case 0:
				break;

			case 1:
				system("cls");
				print_p(p, n);

				index(ind, n);
				system("cls");
				print_2p(p[ind[0]], p[ind[1]], ind);
				res = p[ind[0]] + p[ind[1]];

				cout << "f" << ind[0] << " + f" << ind[1] << " = ";
				cout << res;

				retry(ans);
				break;

			case 2:
				system("cls");
				print_p(p, n);

				index(ind, n);
				system("cls");
				print_2p(p[ind[0]], p[ind[1]], ind);
				res = p[ind[0]] - p[ind[1]];

				cout << "f" << ind[0] << " - f" << ind[1] << " = ";
				cout << res;

				retry(ans);
				break;

			case 3:
				system("cls");
				print_p(p, n);

				index(ind, n);
				system("cls");
				print_2p(p[ind[0]], p[ind[1]], ind);
				res = p[ind[0]] * p[ind[1]];

				cout << "f" << ind[0] << " * f" << ind[1] << " = ";
				cout << res;

				retry(ans);
				break;

			case 4:
				system("cls");
				print_p(p, n);

				cout << "Выберите полином: ";
				do { cin >> ind_1; } while (ind_1 < 0 || ind_1 > n);
				cout << "Введите значение x: ";
				cin >> x;

				system("cls");
				cout << "f" << ind_1 << " = ";
				cout << p[ind_1];

				cout << "\nf" << ind_1 << "(" << x << ") = " << p[ind_1](x) << endl;

				retry(ans);
				break;

			case 5:
				system("cls");
				print_p(p, n);

				cout << "Выберите полином: ";
				do { cin >> ind_1; } while (ind_1 < 0 || ind_1 > n);

				system("cls");
				cout << "f" << ind_1 << " = ";
				cout << p[ind_1];

				res.Diff(p[ind_1]);
				cout << "f'" << ind_1 << " = ";
				cout << res;

				retry(ans);
				break;
			default:
				cout << "ERROR" << endl;
			}
		}
	}
	catch (const char& exc) {
		cout << exc << endl;
		delete[] p;
		return 1337;
	}

	delete[] p;
	return 0;
}