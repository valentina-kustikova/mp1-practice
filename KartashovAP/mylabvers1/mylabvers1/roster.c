#include <string.h>
#include <stdlib.h>
#include "roster.h"


void searching(student* mas_student, int count_student, const char* poiskclass, student** search, int* countClassStudent) {
	int kol = 0;
	int i, j;
	*countClassStudent = 0;
	for (i = 0; i < count_student; i++) {
		if (strcmp(mas_student[i].stclass, poiskclass) != NULL) {
			(*countClassStudent)++;
		}
	}
	if (*countClassStudent == 0) {
		*search = NULL;
		return;
	}
	*search = (student*)malloc((*countClassStudent) * sizeof(student));
	for (j = 0; j < count_student; j++) {
		if (strstr(mas_student[j].stclass, poiskclass) != NULL) {
			strcpy((*search)[kol].name, mas_student[j].name);
			strcpy((*search)[kol].stclass, mas_student[j].stclass);
			strcpy((*search)[kol].gender, mas_student[j].gender);
			strcpy((*search)[kol].birth, mas_student[j].birth);
			strcpy((*search)[kol].homeadress, mas_student[j].homeadress);
			kol++;

		}
	}
}