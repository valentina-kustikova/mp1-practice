#ifndef OPERATIONS_H
#define OPERATIONS_H
#include"iof.h"


pnom_info sum(pnom_info* fpnom, pnom_info* spnom, pnom_info* res_pnom);
pnom_info multiply(pnom_info* fpnom, pnom_info* spnom, pnom_info* res_pnom);
pnom_info subtract(pnom_info* fpnom, pnom_info* spnom, pnom_info* res_pnom);
pnom_info diff_pnom(pnom_info* pnom, pnom_info* res_pnom);
double calculate(pnom_info* pnom, double x);

#endif
