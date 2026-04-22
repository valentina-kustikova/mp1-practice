#pragma once

typedef struct {
	char name[30];
	char adres[70];
	char phones[50];
	char special[50];
	char form[30];
	int opens[7];
	int closes[7];
} magaz;


magaz** getbase(int *len);

int* findstores(magaz **base,int len);

void printer(magaz** base, int* ans);

void delit(magaz** base, int len);