#ifndef IOF_H
#define IOF_H
#include<string>

struct polynom {
	int power;
	int* coefs;
};

void get_info(polynom& fpnom, polynom& spnom, std::string filename);
void printer(polynom& pnom);
void free_polynomial(polynom& pnom);

#endif
