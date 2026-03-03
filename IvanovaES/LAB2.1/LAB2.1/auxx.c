#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxx.h"
#include "library.h"

int cntBooks(FILE* file) {
	char buffer[2048];
	int cnt = 0;

	while (fgets(buffer, sizeof(buffer),file) != NULL){
		cnt++;
	}

	return cnt;
}

void readFile(BookData* array, int cnt, FILE* file) {
	int i;
	char buffer[2048];

	for (i = 0; i < cnt; i++) {
		fgets(buffer, sizeof(buffer), file);
		buffer[strcspn(buffer, "\n")] = 0;
		
		strcpy(array[i].author, strtok(buffer, ";"));
		strcpy(array[i].name, strtok(NULL, ";"));
		strcpy(array[i].publishing, strtok(NULL, ";"));
		array[i].year = atoi(strtok(NULL, ";"));
	}
}

void printResult(BookData* result, int k) {
	int i;
	if (k != 0) {
		printf("%d book/books found:\n", k);
	}
	else {
		printf("Books not found");
	}

	if (k > 0) {
		for (i = 0; i < k; i++) {
			printf("%s; %s; %s; %d\n", result[i].author, result[i].name, 
				result[i].publishing, result[i].year);
		}
	}
}