#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "auxli.h"

//подсчет книг
int countingBooks(const char* filename) {
	char buff[MAX_LEN];
	int count_book = 0;

	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("it is global mistake");
		return 0;
	}
	while (1) {
		if (fgets(buff, sizeof(buff), file)) {
			count_book++;
		}
		else break;
	}
	fclose(file);
	return count_book;
}

//чтение и заполнение массива структур

void readFile(int count, Book* masbook, const char* filename) {
	char buff[2048];
	FILE* file = fopen(filename, "r");
	for (int i = 0; i < count; i++) {
		fgets(buff, sizeof(buff), file);
		buff[strcspn(buff, "\n")] = 0;
		strcpy(masbook[i].author, strtok(buff, ";"));
		strcpy(masbook[i].name, strtok(NULL, ";"));
		strcpy(masbook[i].publish, strtok(NULL, ";"));
		masbook[i].year = atoi(strtok(NULL, ";"));
		//printf("%s\n", masbook[i].author);
	}
	fclose(file);
}
//вывод результатов
void printRes(Book* search, int kol_res) {
	if (kol_res == 1) {
		printf("%d book was found\n", kol_res);
	}
	else {
		printf("%d books were found\n", kol_res);
	}
	if (kol_res) {
		for (int i = 0; i < kol_res; i++) {
			printf("%s; %s; %s; %d\n", search[i].author, search[i].name, search[i].publish, search[i].year);
		}
	}

}