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

void setstring(char *string, char *data) {
	int len = strlen(data);
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
	setstring(base->address.hnum, strtok_s(NULL, ",", &token));

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
			daytimes = strtok_s(data, ",", &token);
			data = token;
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
		char c[1000];
		char *token = NULL;
		int u;
		if (fgets(c, 1000, file) == NULL) {
			printf("READ ERROR [%d]", i);
			ans->len = 0;
			return ans;
		}
		setstring(((ans->base[i])->name), strtok_s(c, ":", &token));
		setadres(ans->base[i], strtok_s(NULL, ":", &token));
		setstring(((ans->base[i])->phones), strtok_s(NULL, ":", &token));
		setstring(((ans->base[i])->special), strtok_s(NULL, ":", &token));
		setstring(((ans->base[i])->form), strtok_s(NULL, ":", &token));

		timegetter((ans->base[i])->timings, strtok_s(NULL, ":", &token));
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
int canallday(timing* timings) {
	int i, flag = 0;
	for (i = 0; i < dayscount; i++) {
		if(timings[i].status != 0){
			flag = 1;
			break;
		}
	}
	return flag;
}

box findstores(box *base) {
	int i;
	box ans;
	ans.len = 0;
	int* tmp = (int*)malloc(sizeof(int) * base->len);
	for (i = 0; i < base->len; i++) {
		if (strcmp(base->base[i]->special, "food") == 0 && canallday(base->base[i]->timings) == 0) {
			tmp[ans.len] = i;
			ans.len++;
		}
	}
	generate(&ans);
	for (i = 0; i < ans.len; i++) {
		int u;
		setstring(ans.base[i]->name, base->base[tmp[i]]->name);
		setstring(ans.base[i]->phones, base->base[tmp[i]]->phones);
		setstring(ans.base[i]->special, base->base[tmp[i]]->special);
		setstring(ans.base[i]->form, base->base[tmp[i]]->form);
		setstring(ans.base[i]->address.street, base->base[tmp[i]]->address.street);
		setstring(ans.base[i]->address.hnum, base->base[tmp[i]]->address.hnum);
		for (u = 0; u < dayscount; u++) {
			ans.base[i]->timings[u] = base->base[tmp[i]]->timings[u];
		}
	}
	free(tmp);
	return ans;
}

void printer(box *base) {
	int i;
	if (base->len == 0) {
		printf("no stores found");
	}
	else {
		for (i = 0; i < base->len; i++) {
			printf("%s \n", base->base[i]->name);
			printf("	adress: %s, %s\n", base->base[i]->address.street, base->base[i]->address.hnum);
			printf("	phones: %s \n", base->base[i]->phones);
			printf("	form:   %s \n", base->base[i]->form);
		}
	}
}

void delit(box* base) {
	int i;
	for (i = 0; i < base->len; i++) {
		free((base->base[i])->name);
		free((base->base[i])->phones);
		free((base->base[i])->special);
		free((base->base[i])->form);
		free((base->base[i])->timings);
		free((base->base[i])->address.street);
		free((base->base[i])->address.hnum);
		free(base->base[i]);
	}
	free(base->base);
}
