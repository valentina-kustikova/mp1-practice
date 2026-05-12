#include "base.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void generate(box* base) {
	int i = 0;
	base->base = (Shop**)malloc(base->len * sizeof(Shop*));
	if (base->base == NULL) {
		printf("MEMORY ERROR 1");
		base->len = 0;
		free(base->base);
	}

	for (i = 0; i < base->len; i++) {
		base->base[i] = (Shop*)malloc(sizeof(Shop));
		if (base->base[i] == NULL) {
			printf("MEMORY ERROR 2 [%d]", i);
			for (int j = 0; j < i; j++) {
				free(base->base[j]);
			}
			free(base->base);
			base->len = 0;
		}
	}
}

void setstring(char *string, char *data ) {
	int len = strlen(*data);
	string = (char*)malloc(sizeof(char) * len);
	if (string == NULL) {
		printf("string copy error");
	}
	else {
		strcpy(string, data);
	}
}

void setadres(Shop* base, char* data) {
	char* token = NULL;
	setstring(base->address.street, strtok_s(data, ",", &token));
	setstring(base->address.hnum, strtok_s(data, ",", &token));

}

void getdaystatus(timing* day) {
	if (day->start.hours == 0 && day->start.hours == 0 && day->finish.hours == 24 && day->finish.minutes == 00) {
		day->status = alldayopen;
	}
	else {
		day->status = open;
	}
}
void timegetter(timing* timings, char* data) {
	char* token = NULL, *daytimes;
	timings = (timing*)malloc(sizeof(timing) * dayscount);
	if (timings == NULL) {
		printf("time memory error");
	} else {
		int i = 0;
		for (i = 0; i < dayscount; i++) {
			timings[i].day = i;
			daytimes = strtok_r(data, ",", token);
			if (*daytimes == "c") {
				timings[i].status = close;
			}
			else {
				sscanf(daytimes, "%d.%d-%d.%d", timings[i].start.hours, timings[i].start.minutes, timings[i].finish.hours, timings[i].finish.minutes);
				getdaystatus(&timings[i]);
			}
		}
	}
}

void getter(box* ans, FILE* file) {
	int i = 0;
	for (i = 0; i < ans->len; i++) {
		char* c;
		char *token = NULL;
		int u;
		if (fgets(c, 1000, file) == NULL) {
			printf("READ ERROR [%d]", i);
			ans->len = 0;
			return ans;
		}
		setstring(((ans->base[i])->name), strtok_s(c, ":", &token));
		setadres(ans->base[i], strtok_r(NULL, ":", &token));
		setstring(((ans->base[i])->phones, strtok_s(c, ":", &token)));
		setstring(((ans->base[i])->special, strtok_s(c, ":", &token)));
		setstring(((ans->base[i])->form, strtok_s(c, ":", &token)));

		timegetter((ans->base[i])->timings, strtok_s(c, ":", &token));
	}
}

box getbase(char *filename) {
	//обьявления
	box ans;
	FILE* file = fopen(filename, "r");
	char c[1000];
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

	generate(&ans);
	if (ans.len == 0)return ans;

	getter(&ans, file);
	fclose(file);
	return ans;
}

box findstores(box *base) {
	int i;
	box ans;
	ans.len = 0;
	int* tmp = (int*)malloc(sizeof(int) * base->len);
	for (i = 0; i < base->len; i++) {
		if (strcmp(base->base[i]->special, "food") == 0 && timesum(base->base[i]->opens, base->base[i]->closes) == 10080) {
			tmp[ans.len] = i;
			ans.len++;
		}
	}
	generate(&ans);
	for (i = 0; i < ans.len; i++) {
		*(ans.base[i]) = *(base->base[tmp[i]]);
	}
	free(tmp);
	return ans;
}

int timesum(int* opens, int* closes) {
	int i, sum = 0;
	for (i = 0; i < 7; i++) {
		sum += closes[i] - opens[i];
	}
	return sum;
}

void printer(box *base) {
	int i;
	if (base->len == 0) {
		printf("no stores found");
	}
	else {
		for (i = 0; i < base->len; i++) {
			printf("%s \n", base->base[i]->name);
			printf("	adress: %s \n", base->base[i]->adres);
			printf("	phones: %s \n", base->base[i]->phones);
			printf("	form:   %s \n", base->base[i]->form);
		}
		printf(" \ntotal stores founded: %d", base->len);
	}
}

void delit(box* base) {
	int i;
	for (i = 0; i < base->len; i++) {
		free(base->base[i]);
	}
	free(base->base);
}
