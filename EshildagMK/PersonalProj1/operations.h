#ifndef OPERATIONS_H
#define OPERATIONS_H
#include"iof.h"


void sum(pnom_info* fpnom, pnom_info* spnom, pnom_info* res_pnom);
void multiply(pnom_info* fpnom, pnom_info* spnom, pnom_info* res_pnom);
void subtract(pnom_info* fpnom, pnom_info* spnom, pnom_info* res_pnom);
void diff_pnom(pnom_info* pnom, pnom_info* res_pnom);
double calculate(pnom_info* pnom, double x);

#endif
