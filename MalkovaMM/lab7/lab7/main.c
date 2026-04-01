#include <stdio.h>
#include <stdlib.h>
#include "pol.h"
#include <locale.h>

int main(int argc, char** argv) {
	char* fname;
	int deg1, deg2, resdeg, res, i, choice, num, x;
	polinom p1, p2, pres;
	setlocale(LC_ALL, "Rus");
	if (argc < 2) {
		printf("Incorrect parametres");
		return 1;
	}
	fname = argv[1];
	deg1 = degpol(fname, 1);
	deg2 = degpol(fname, 2);
	p1 = pcreate(fname, deg1, 1);
	p2 = pcreate(fname, deg2, 2);
	printf("Полиномы:\n1)");
	pprint(&p1);
	printf("\n2)");
	pprint(&p2);
	printf("\nвыберите какую операцию вы хотите проделать с ними:\nсложить: 1\nвычесть: 2\nумножить: 3\nдифференцировать: 4\nвычислить значение в точке: 5\n");
	scanf_s("%d", &choice);
	if (choice == 1) pres = pplus(&p1, &p2);
	if (choice == 2) pres = pminus(&p1, &p2);
	if (choice == 3) pres = pumn(&p1, &p2);
	if (choice == 4){
		printf("введите 1 или 2 - номер полинома: ");
		scanf_s("%d", &num);
		if (num == 1) pres = pdif(&p1);
		else if (num == 2) pres = pdif(&p2);
	}
	if (choice == 5){
		printf("введите 1 или 2 - номер полинома: ");
		scanf_s("%d", &num);
		printf("введите число, от которого будем считать значение: ");
		scanf_s("%d", &x);
		if (num==1) res = pznach(&p1, x);
		else if (num==2) res = pznach(&p2, x);
		printf("значение полинома в этой точке: %d", res);
	}
	if ((choice >= 1) && (choice <= 4)){
		resdeg = pres.deg;
		printf("Получившийся полином: \n");
		pprint(&pres);
	}
	return 0;
}
