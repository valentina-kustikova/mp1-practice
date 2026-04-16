#include"iof.h"
#include<stdio.h>
#include<stdlib.h>

void get_info(pnom_info* fpnom, pnom_info* spnom, const char* filename) {
	int i;
	FILE* filep = fopen(filename, "r");
	if (filep == NULL) {
		printf("Openning error.\n");
	}
	//first scan
	fscanf(filep, "%d", &fpnom->power);
	fpnom->coefs = (int*)malloc((fpnom->power + 1) * sizeof(int));
	for (i = 0; i <= fpnom->power; i++) {
		fscanf(filep, "%d", &fpnom->coefs[i]);
	}
	//second scan
	fscanf(filep, "%d", &spnom->power);
	spnom->coefs = (int*)malloc((spnom->power + 1) * sizeof(int));
	for (i = 0; i <= spnom->power; i++) {
		fscanf(filep, "%d", &spnom->coefs[i]);
	}

	fclose(filep);
}

void printer(pnom_info* pnom) {
	int i;
	int first = 1;
	for (i = pnom->power; i > 0; i--) {
		if (!pnom->coefs[i]) continue;
		if (first) {
			printf("%d*x^%d", pnom->coefs[i], i);
			first = 0;
		}
		else {
			printf(" %+d*x^%d", pnom->coefs[i], i);
		}
	}
	if (first) {
		printf(" %d\n", pnom->coefs[0]);
	}
	else {
		printf(" %+d\n", pnom->coefs[0]);
	}
}

void free_polynomial(pnom_info* pnom) {
	free(pnom->coefs);
	pnom->coefs = NULL;
	pnom->power = 0;
}