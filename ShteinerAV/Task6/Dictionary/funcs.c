#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "funcs.h"
#include "library.h"

void u_answer(char *user) {
	char c;
	int cnt;
	while (1) {
		cnt = 0;
		printf("Enter your choice: ");
		scanf("%c", user);

		while ((c = getchar()) != '\n') cnt++;
		
		if (*user >= '0' && *user <= '2' && cnt == 0) {
			break;
		}
		else {
			printf("The command was entered incorrectly!\n\n");
		}
	}
}

int scan_file(char* link) {
	FILE* fp = fopen(link, "r");
	char* str = (char*)malloc(sizeof(char) * max_simbols_in_line);
	int cnt = 0;

	if (fp == NULL) {
		printf("Opening error!");
		return 1;
	}

	while (fgets(str, max_simbols_in_line, fp)) {
		cnt++;
	}

	printf("The file has been scanned.\n");
	fclose(fp);
	free(str);

	return cnt;
}

void fill_arr(Book* arr, char* link) {
	FILE* fp = fopen(link, "r");
	char str[max_simbols_in_line], * token, * context;
	int cnt = 0, i, current_book = 0;

	if (fp == NULL) {
		printf("Opening error!");
		return 1;
	}

	while (fgets(str, max_simbols_in_line, fp)) {
		char* line_copy = _strdup(str);
		token = strtok_s(line_copy, ";", &context);

		arr[current_book].authors = NULL;
		arr[current_book].cnt_authors = 0;
		arr[current_book].books_name = NULL;
		arr[current_book].publishing = NULL;
		arr[current_book].year = 0;

		char* author_copy = _strdup(token), * au_token, * au_context;
		int cnt_au = 0;
		au_token = strtok_s(author_copy, ",", &au_context);

		while (au_token != NULL) {
			cnt_au++;
			au_token = strtok_s(NULL, ",", &au_context);
		}
		free(author_copy);

		arr[current_book].authors = (char**)malloc(cnt_au * sizeof(char*));
		arr[current_book].cnt_authors = cnt_au;
		author_copy = _strdup(token);
		au_context = NULL;
		int id = 0;
		au_token = strtok_s(author_copy, ",", &au_context);

		while (id < cnt_au) {
			while (*au_token == ' ') au_token++;
			arr[current_book].authors[id++] = _strdup(au_token);
			au_token = strtok_s(NULL, ",", &au_context);
		}
		free(author_copy);
		token = strtok_s(NULL, ";", &context);

		while (*token == ' ') token++;
		arr[current_book].books_name = _strdup(token);
		token = strtok_s(NULL, ";", &context);

		while (*token == ' ') token++;
		arr[current_book].publishing = _strdup(token);
		token = strtok_s(NULL, ";", &context);

		while (*token == ' ') token++;
		arr[current_book].year = atoi(token);

		current_book++;
		free(line_copy);
	}

	fclose(fp);
}

void enter_the_author(char** users_choice) {
	*users_choice = (char*)malloc(max_simbols_in_line);
	while (1) {
		int i, flag = 0, cnt = 0, c = 0;
		printf("Enter the authors last name to search: ");
		scanf(" %s", *users_choice); 

		while ((c = getchar()) != '\n') cnt++;

		for (i = 0; i < strlen(*users_choice); i++) {
			if ((*users_choice)[i] < 65 || ((*users_choice)[i] > 90 && (*users_choice)[i] < 97) || (*users_choice)[i] > 122) {
				flag = 1;
				break;
			}
		}

		if (flag == 1 || cnt != 0) {
			printf("Input error!\n");
		}
		else {
			break;
		}
	}
}

void print_books(Book* id_books, int size) {
	int i, j, cnt=0;
	for (i = 0; i < size; i++) {
		printf("---------------------------------------------------\n");
		printf("| Author: ");
		for (j = 0; j < id_books[i].cnt_authors; j++) {	
			printf("%s ", id_books[i].authors[j]);
		}
		printf("\n");
		printf("| Title: %-40s \n", id_books[i].books_name);
		printf("| Publisher: %-36s \n", id_books[i].publishing);
		printf("| Year: %-41d \n", id_books[i].year);
		cnt++;
	}

	if (cnt == 0) {
		printf("Empty\n");
	}
	else {
		printf("---------------------------------------------------\n");
	}
	
}
