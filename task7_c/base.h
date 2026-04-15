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

typedef struct {
	int len;
	magaz** ans;
} Fmagaz;

magaz** getbase(int *len);

Fmagaz findstores(magaz **base,int len);

void printer(magaz** base, int* ans);