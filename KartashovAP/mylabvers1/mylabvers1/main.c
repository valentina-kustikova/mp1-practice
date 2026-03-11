#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roster.h"
#include "auxli.h"

int main(int argc, char** argv) {
	char poiskclass[MAX_LEN], * filename;
	int count_student, countClassStudent;
	student* search;
	student* mas_student;
	if (argc < 2) {
		printf("incorrect of argument");
		return 1;
	}
	filename = argv[1];

	count_student = countingstudents(filename); 
	mas_student = (student*)malloc(count_student * sizeof(student)); 
	readFile(count_student, mas_student, filename); 

	printf("\nEnter, please, class of students\n");
	scanf("%1023[^\n]", poiskclass);


	searching(mas_student, count_student, poiskclass, &search, &countClassStudent);
	printRes(search, countClassStudent);

	free(mas_student);
	free(search);

	return 0;
}