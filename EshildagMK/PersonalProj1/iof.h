#ifndef IOF_H
#define IOF_H

typedef struct {
	int power;
	int* coefs;
} pnom_info;

void get_info(pnom_info* fpnom, pnom_info* spnom, const char* filename);
void printer(pnom_info* pnom);
void free_polynomial(pnom_info* pnom);

#endif
