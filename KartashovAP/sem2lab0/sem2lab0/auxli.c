#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "auxli.h"

int numberBooks(const char* filename) {
	char buff[1024];
	int count = 0;
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("Ошибка открытия файла");
		return 0;  // Возвращайте 0 при ошибке, а не 1
	}

	while (fgets(buff, sizeof(buff), file) != NULL) {
		count++;
	}

	fclose(file);
	return count;
}

void readFile(int count, struct Book* array, const char* filename) {
	char buff[2048];
	FILE* file = fopen(filename, "r");
	for (int i = 0; i < count; i++) {
		fgets(buff, sizeof(buff), file);
		buff[strcspn(buff, "\n")] = 0;
		strcpy(array[i].author, strtok(buff, ";"));
		strcpy(array[i].name, strtok(NULL, ";"));
		strcpy(array[i].publisher, strtok(NULL, ";"));
		array[i].year = atoi(strtok(NULL, ";"));
	}
	fclose(file);
}

void printResults(struct Book* search, int k) {
	if (k == 1) {
		printf("%d book were found\n", k);
	}
	else {
		printf("%d books were found\n", k);
	}
	if (k) {
		for (int i = 0; i < k; i++) {
			printf("%s; %s; %s; %d\n", search[i].author, search[i].name, search[i].publisher, search[i].year);
		}
	}

}