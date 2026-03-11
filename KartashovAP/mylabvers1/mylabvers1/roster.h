#ifndef ROSTER_H
#define ROSTER_H

#define MAX_LEN 1024


typedef struct student {
	char name[MAX_LEN];
	char stclass[MAX_LEN];
	char gender[MAX_LEN];
	char birth[MAX_LEN];
	char homeadress[MAX_LEN];
} student;

void searching(student* mas_student, int count_student, const char* poiskclass, student** search, int* countClassStudent);

#endif 
