#include "base.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

magaz** getbase(int *len) {
	FILE* file = fopen("base.txt", "r");
	//обьявления
	int i;
	char c[1000];
	magaz **mag;
	//код

	if (file == NULL) {
		printf("FILE ERROR");
		return NULL;
	}
	while (fgets(c, 1000, file) != NULL) {
		(*len)++;
	}
	rewind(file);

	mag = (magaz**)malloc((*len) * sizeof(magaz*));
	if (mag == NULL) {
		printf("MEMORY ERROR 1");
		fclose(file);
		return NULL;
	}

	for (i = 0; i < (*len); i++) {
		mag[i] = (magaz*)malloc(sizeof(magaz));
		if (mag[i] == NULL) {
			printf("MEMORY ERROR 2 [%d]", i);
			for (int j = 0; j < i; j++) {
				free(mag[j]);
			}
			free(mag);
			fclose(file);
			return NULL;
		}
	}

	for (i = 0; i < *len; i++) {
		char *tmp, *mpt;
		char* token;
		int u;
		int topens[7], tcloses[7];
		if (fgets(c, 1000, file) == NULL) {
			printf("READ ERROR [%d]", i);
			return NULL;
		}
		tmp = strtok(c, ":");
		strcpy(mag[i]->name, tmp);
		tmp = strtok(NULL, ":");
		strcpy(mag[i]->adres, tmp);
		tmp = strtok(NULL, ":");
		strcpy(mag[i]->phones, tmp);
		tmp = strtok(NULL, ":");
		strcpy(mag[i]->special, tmp);
		tmp = strtok(NULL, ":");
		strcpy(mag[i]->form, tmp);

		tmp = strtok(NULL, ":");

		for (u = 0; u < 7; u++) {
			int oh = 0, om = 0, kh = 0, km = 0;
			char* itok;
			if (strcmp(tmp, "c") == 0) {
				topens[u] = -1;
				tcloses[u] = -1;
			}
			else {
				mpt = strtok_s(tmp, ",", &token);
				sscanf(mpt, "%d.%d-%d.%d", &oh, &om, &kh, &km);
				topens[u] = oh * 60 + om;
				tcloses[u] = kh * 60 + km;
			}
		}
		memcpy(mag[i]->opens, topens, sizeof(topens));
		memcpy(mag[i]->closes, tcloses, sizeof(tcloses));
	}
	fclose(file);
	return mag;
}

int* findstores(magaz** base, int len) {
	int i, new = 0;
	int* ans2;
	int* ans = (int*)malloc(sizeof(int) * len);
	for (i = 0; i < len; i++) {
		if (strcmp(base[i]->special, "food") == 0 && timesum(base[i]->opens, base[i]->closes) == 10080) {
			ans[new+1] = i;
			new++;
		}
	}
	ans2 = (int*)realloc(ans, sizeof(int) * (new+1));
	ans2[0] = new;
	return ans2;
}

int timesum(int* opens, int* closes) {
	int i, sum = 0;
	for (i = 0; i < 7; i++) {
		sum += closes[i] - opens[i];
	}
	return sum;
}

void printer(magaz** base, int* ans) {
	int n = ans[0] + 1, i;
	if (n == 0) {
		printf("no stores found");
	}
	for (i = 1; i < n; i++) {
		int k = ans[i];
		printf("%s \n", base[k]->name);
		printf("	adress: %s \n", base[k]->adres);
		printf("	phones: %s \n", base[k]->phones);
		printf("	form:   %s \n", base[k]->form);
	}
}