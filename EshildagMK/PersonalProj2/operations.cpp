#include"operations.h"
#include <algorithm>
#include<iostream>
#include <iomanip>

void sum(polynom& fpnom, polynom& spnom, polynom& res_pnom) {
	res_pnom.power = std::max(fpnom.power, spnom.power);
	res_pnom.coefs = new int[res_pnom.power + 1]();
	for (int i = 0; i < res_pnom.power + 1; i++) {
		int c1 = (i <= fpnom.power) ? fpnom.coefs[i] : 0;
		int c2 = (i <= spnom.power) ? spnom.coefs[i] : 0;
		res_pnom.coefs[i] = c1 + c2;
	}
	while (res_pnom.power > 0 && res_pnom.coefs[res_pnom.power] == 0) {
		res_pnom.power--;
	}
}

void multiply(polynom& fpnom, polynom& spnom, polynom& res_pnom) {
	res_pnom.power = fpnom.power + spnom.power;
	res_pnom.coefs = new int[res_pnom.power + 1]();
	for (int i = 0; i <= fpnom.power; i++) {
		for (int j = 0; j <= spnom.power; j++) {
			res_pnom.coefs[i + j] += fpnom.coefs[i] * spnom.coefs[j];
		}
	}
}

void subtract(polynom& fpnom, polynom& spnom, polynom& res_pnom) {

	res_pnom.power = std::max(fpnom.power, spnom.power);
	res_pnom.coefs = new int[res_pnom.power + 1]();

	polynom copied_pnom;
	copied_pnom.power = spnom.power;
	copied_pnom.coefs = new int[copied_pnom.power + 1]();

	for (int i = 0; i < copied_pnom.power + 1; i++) {
		copied_pnom.coefs[i] = spnom.coefs[i] * -1;
	}

	sum(fpnom, copied_pnom, res_pnom);
	free_polynomial(copied_pnom);
}

void diff_pnom(polynom& pnom, polynom& res_pnom) {

	if (pnom.power == 0) {
		std::cout << "Diff: 0" << std::endl;
		res_pnom.power = 0;
		res_pnom.coefs = new int[res_pnom.power + 1]();
		res_pnom.coefs[0] = 0;
		return;
	}
	res_pnom.power = pnom.power - 1;
	res_pnom.coefs = new int[res_pnom.power + 1]();

	for (int i = 0; i <= res_pnom.power; i++) {
		res_pnom.coefs[i] = pnom.coefs[i + 1] * (i + 1);
	}
}

double calculate(polynom& pnom, double x) {
	double pow_x;
	long double result;
	result = pnom.coefs[0];
	pow_x = x;
	for (int i = 1; i <= pnom.power; i++) {
		result += pnom.coefs[i] * pow_x;
		pow_x *= x;
	}
	// printf("\nRESULT: %.3Lf\n", result);
	std::cout << std::endl << "RESULT: " << std::fixed << std::setprecision(3) << result << std::endl;
	return result;
}