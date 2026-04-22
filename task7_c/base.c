#include "base.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

box getbase() {
	box ans;
	FILE* file = fopen("base.txt", "r");
	//обьявления
	int i;
	char c[1000];
	magaz **mag;
	ans.len = 0;
	//код

	if (file == NULL) {
		printf("FILE ERROR");
		return ans;
	}
	while (fgets(c, 1000, file) != NULL) {
		ans.len++;
	}
	rewind(file);

	mag = (magaz**)malloc(ans.len * sizeof(magaz*));
	if (mag == NULL) {
		printf("MEMORY ERROR 1");
		fclose(file);
		return ans;
	}

	for (i = 0; i < ans.len; i++) {
		mag[i] = (magaz*)malloc(sizeof(magaz));
		if (mag[i] == NULL) {
			printf("MEMORY ERROR 2 [%d]", i);
			for (int j = 0; j < i; j++) {
				free(mag[j]);
			}
			free(mag);
			fclose(file);
			ans.len = 0;
			return ans;
		}
	}

	for (i = 0; i < ans.len; i++) {
		char *tmp, *mpt;
		char* token;
		int u;
		int topens[7], tcloses[7];
		if (fgets(c, 1000, file) == NULL) {
			printf("READ ERROR [%d]", i);
			ans.len = 0;
			return ans;
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
	ans.base = mag;
	return ans;
}

box findstores(box base) {
	int i;
	box ans;
	int* tmp = (int*)malloc(sizeof(int) * base.len);
	for (i = 0; i < base.len; i++) {
		if (strcmp(base.base[i]->special, "food") == 0 && timesum(base.base[i]->opens, base.base[i]->closes) == 10080) {
			ans.len++;
		}
	}
	ans.base = (magaz**)malloc(ans.len * sizeof(magaz*));
	for (i = 0; i < ans.len; i++) {
		ans.base[i] = (magaz*)malloc(sizeof(magaz));
	}
	return ans;
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

void delit(magaz** base, int len) {
	int i = 0;
	for (i = 0; i < len; i++) {
		free(base[i]);
	}
	free(base);
}