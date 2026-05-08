#ifndef OPERATIONS_H
#define OPERATIONS_H
#include"iof.h"

void sum(polynom& fpnom, polynom& spnom, polynom& res_pnom);
void multiply(polynom& fpnom, polynom& spnom, polynom& res_pnom);
void subtract(polynom& fpnom, polynom& spnom, polynom& res_pnom);
void diff_pnom(polynom& pnom, polynom& res_pnom);
double calculate(polynom& pnom, double x);

#endif