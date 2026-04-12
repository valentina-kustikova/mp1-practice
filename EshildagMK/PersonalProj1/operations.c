#include "operations.h"
#include <stdlib.h> 

void sum(pnom_info* fpnom, pnom_info* spnom) {
	int i;
	pnom_info res_pnom;
	res_pnom.power = max(fpnom->power, spnom->power);
	res_pnom.coefs = (int*)calloc((res_pnom.power + 1), sizeof(int));
	for (i = 0; i < res_pnom.power + 1; i++) {
		int c1 = (i <= fpnom->power) ? fpnom->coefs[i] : 0;
		int c2 = (i <= spnom->power) ? spnom->coefs[i] : 0;
		res_pnom.coefs[i] = c1 + c2;
	}
	printf("\nSum:\n");
	printer(&res_pnom);
	free_polynomial(&res_pnom);
}

void multiply(pnom_info* fpnom, pnom_info* spnom) {
	int i, j;
	pnom_info res_pnom;
	res_pnom.power = fpnom->power + spnom->power;
	res_pnom.coefs = (int*)calloc((res_pnom.power + 1), sizeof(int));
	for (i = 0; i <= fpnom->power; i++) {
		for (j = 0; j <= spnom->power; j++) {
			res_pnom.coefs[i + j] += fpnom->coefs[i] * spnom->coefs[j];
		}
	}
	printf("\nMultiply:\n");
	printer(&res_pnom);
	free_polynomial(&res_pnom);
}

void subtract(pnom_info* fpnom, pnom_info* spnom) {
	int i;
	pnom_info res_pnom;
	res_pnom.power = max(fpnom->power, spnom->power);
	res_pnom.coefs = (int*)calloc((res_pnom.power + 1), sizeof(int));
	for (i = 0; i < res_pnom.power + 1; i++) {
		int c1 = (i <= fpnom->power) ? fpnom->coefs[i] : 0;
		int c2 = (i <= spnom->power) ? spnom->coefs[i] : 0;
		res_pnom.coefs[i] = c1 - c2;
	}
	printf("\nSubtraction:\n");
	printer(&res_pnom);
	free_polynomial(&res_pnom);
}

void diff_pnom(pnom_info* pnom) {
	int i;
	pnom_info res_pnom;
	if (pnom->power == 0) {
		printf("Diff:\n0\n");
		return;
	}
	res_pnom.power = pnom->power - 1;
	res_pnom.coefs = (int*)calloc((res_pnom.power + 1), sizeof(int));

	for (i = 0; i <= res_pnom.power; i++) {
		if (!pnom->coefs[i + 1]) continue;
		res_pnom.coefs[i] = pnom->coefs[i + 1] * (i + 1);
	}
	printf("Diff:\n");
	printer(&res_pnom);
	free_polynomial(&res_pnom);
}

void calculate(pnom_info* pnom, int x) {
	int i, pow_x;
	long long int result;
	result = pnom->coefs[0];
	pow_x = x;
	for (i = 1; i <= pnom->power; i++) {
		result += pnom->coefs[i] * pow_x;
		pow_x *= x;
	}
	printf("\nRESULT: %dll\n", result);
}