#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roster.h"
#include "auxli.h"


int countingstudents(const char* filename) {
	char buff[MAX_LEN];
	int count_students = 0;

	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("it is global mistake");
		return 0;
	}
	while (1) {
		if (fgets(buff, sizeof(buff), file)) {
			count_students++;
		}
		else break;
	}
	fclose(file);
	return count_students;
}



void readFile(int count, student* mas_student, const char* filename) {
	char buff[2048];
	FILE* file = fopen(filename, "r");
	for (int i = 0; i < count; i++) {
		fgets(buff, sizeof(buff), file);
		buff[strcspn(buff, "\n")] = 0;
		strcpy(mas_student[i].name, strtok(buff, ";"));
		strcpy(mas_student[i].stclass, strtok(buff, ";"));
		strcpy(mas_student[i].gender, strtok(buff, ";"));
		strcpy(mas_student[i].birth, strtok(buff, ";"));
		strcpy(mas_student[i].homeadress, strtok(buff, ";"));
	}
	fclose(file);
}
void printRes(student* search, int kol_res) {
	if (kol_res == 1) {
		printf("%d student was found\n", kol_res);
	}
	else {
		printf("%d students were found\n", kol_res);
	}
	if (kol_res) {
		for (int i = 0; i < kol_res; i++) {
			printf("%s; %s; %s; %s; %s\n", search[i].name, search[i].stclass, search[i].gender, search[i].birth, search[i].homeadress);
		}
	}

}