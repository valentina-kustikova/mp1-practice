#include "operations.h"
#include <stdlib.h> 

pnom_info sum(pnom_info* fpnom, pnom_info* spnom, pnom_info* res_pnom) {
	int i;
	res_pnom->power = max(fpnom->power, spnom->power);
	res_pnom->coefs = (int*)calloc((res_pnom->power + 1), sizeof(int));
	for (i = 0; i < res_pnom->power + 1; i++) {
		int c1 = (i <= fpnom->power) ? fpnom->coefs[i] : 0;
		int c2 = (i <= spnom->power) ? spnom->coefs[i] : 0;
		res_pnom->coefs[i] = c1 + c2;
	}
	while (res_pnom->power > 0 && res_pnom->coefs[res_pnom->power] == 0) {
		res_pnom->power--;
	}
	return *res_pnom;
}

pnom_info multiply(pnom_info* fpnom, pnom_info* spnom, pnom_info* res_pnom) {
	int i, j;
	res_pnom->power = fpnom->power + spnom->power;
	res_pnom->coefs = (int*)calloc((res_pnom->power + 1), sizeof(int));
	for (i = 0; i <= fpnom->power; i++) {
		for (j = 0; j <= spnom->power; j++) {
			res_pnom->coefs[i + j] += fpnom->coefs[i] * spnom->coefs[j];
		}
	}
	return *res_pnom;
}

pnom_info subtract(pnom_info* fpnom, pnom_info* spnom, pnom_info* res_pnom) { // p1 + (-p2)
	int i;

	res_pnom->power = max(fpnom->power, spnom->power);
	res_pnom->coefs = (int*)calloc((res_pnom->power + 1), sizeof(int));

	pnom_info copied_pnom;
	copied_pnom.power = spnom->power;
	copied_pnom.coefs = (int*)calloc((spnom->power + 1), sizeof(int));

	for (i = 0; i < copied_pnom.power + 1; i++) {
		copied_pnom.coefs[i] = spnom->coefs[i] * -1;
	}

	sum(fpnom, &copied_pnom, res_pnom);
	free_polynomial(&copied_pnom);
	return *res_pnom;
}

pnom_info diff_pnom(pnom_info* pnom, pnom_info* res_pnom) {
	int i;

	if (pnom->power == 0) {
		printf("Diff:\n0\n");
		res_pnom->power = 0;
		res_pnom->coefs = (int*)calloc(1, sizeof(int));
		res_pnom->coefs[0] = 0;
		return *res_pnom;
	}
	res_pnom->power = pnom->power - 1;
	res_pnom->coefs = (int*)calloc((res_pnom->power + 1), sizeof(int));

	for (i = 0; i <= res_pnom->power; i++) {
		if (!pnom->coefs[i + 1]) continue;
		res_pnom->coefs[i] = pnom->coefs[i + 1] * (i + 1);
	}

	return *res_pnom;
}

double calculate(pnom_info* pnom, double x) {
	int i;
	double pow_x;
	long double result;
	result = pnom->coefs[0];
	pow_x = x;
	for (i = 1; i <= pnom->power; i++) {
		result += pnom->coefs[i] * pow_x;
		pow_x *= x;
	}
	printf("\nRESULT: %.3Lf\n", result);
	return result;
}