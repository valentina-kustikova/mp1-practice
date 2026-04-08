#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "funcs.h"
#include "data.h"

void u_answer(char** user, int max) {
	int choice;
	char c;
	(*user) = (char*)malloc(max_simbols_in_line);

	while (1) {
		int cnt = 0, is_valid = 1, i;
		printf("Enter your choice: ");
		scanf("%s", *user);

		while ((c = getchar()) != '\n') {
			cnt++;
		}

		for (i = 0; (*user)[i] != '\0'; i++) {
			if (!isdigit((*user)[i])) {
				is_valid = 0;
				break;
			}
		}

		if ((*user)[0] == '\0') {
			is_valid = 0;
		}

		if (is_valid && cnt == 0) {
			choice = atoi(*user);
			if (choice >= 0 && choice <= max) {
				break;
			}
		}

		printf("The command was entered incorrectly!\n\n");
	}
}

int scan_company(char* link) {
	FILE* fp = fopen(link, "r");
	char* str = (char*)malloc(sizeof(char) * max_simbols_in_line);
	int cnt = 0;

	if (fp == NULL) {
		printf("Opening error 1!\n");
		return 1;
	}

	while (fgets(str, max_simbols_in_line, fp)) {
		cnt++;
	}

	printf("The file1 has been scanned.\n");
	fclose(fp);
	free(str);

	return cnt-1;
}

int scan_vacancy(char* link) {
	FILE* fp = fopen(link, "r");
	char* str = (char*)malloc(sizeof(char) * max_simbols_in_line);
	int cnt = 0;

	if (fp == NULL) {
		printf("Opening error 2!\n");
		return 1;
	}

	while (fgets(str, max_simbols_in_line, fp)) {
		cnt++;
	}

	printf("The file2 has been scanned.\n");
	fclose(fp);
	free(str);

	return cnt - 1;
}

void fill_company(DbCompanies *Db, char* link) {
	FILE* fp = fopen(link, "r");
	char str[max_simbols_in_line], * token, * context;
	int cnt = 0, i, current_vac = 0;

	if (fp == NULL) {
		printf("Opening error 1!\n");
		return 1;
	}

	fgets(str, max_simbols_in_line, fp);
	while (fgets(str, max_simbols_in_line, fp)) {
		char* line_copy = _strdup(str);

		token = strtok_s(line_copy, ";", &context);

		Db->arr[current_vac].company_id = 0;
		Db->arr[current_vac].name = NULL;
		Db->arr[current_vac].addres = NULL;

		while (*token == ' ') token++;
		Db->arr[current_vac].company_id = atoi(token);
		token = strtok_s(NULL, ";", &context);

		while (*token == ' ') token++;
		Db->arr[current_vac].name = _strdup(token);
		token = strtok_s(NULL, ";", &context);

		while (*token == ' ') token++;
		Db->arr[current_vac].addres = _strdup(token);
		token = strtok_s(NULL, ";", &context);

		current_vac++;
		free(line_copy);
	}

	fclose(fp);
}

void fill_vacancy(DbVacancies* Db, char* link){
	FILE* fp = fopen(link, "r");
	char str[max_simbols_in_line], * token, * context;
	int cnt = 0, i, current_vac = 0;

	if (fp == NULL) {
		printf("Opening error 2!\n");
		return 1;
	}

	fgets(str, max_simbols_in_line, fp);
	while (fgets(str, max_simbols_in_line, fp)) {
		char* line_copy = _strdup(str);

		token = strtok_s(line_copy, ";", &context);

		Db->arr[current_vac].vacancy_id = 0;
		Db->arr[current_vac].company_id = 0;
		Db->arr[current_vac].name = NULL;
		Db->arr[current_vac].conditions = NULL;
		Db->arr[current_vac].requirements = NULL;
		Db->arr[current_vac].salary = 0;


		while (*token == ' ') token++;
		Db->arr[current_vac].vacancy_id = atoi(token);
		token = strtok_s(NULL, ";", &context);

		while (*token == ' ') token++;
		Db->arr[current_vac].company_id = atoi(token);
		token = strtok_s(NULL, ";", &context);

		while (*token == ' ') token++;
		Db->arr[current_vac].name = _strdup(token);
		token = strtok_s(NULL, ";", &context);

		while (*token == ' ') token++;
		Db->arr[current_vac].conditions = _strdup(token);
		token = strtok_s(NULL, ";", &context);

		while (*token == ' ') token++;
		Db->arr[current_vac].requirements = _strdup(token);
		token = strtok_s(NULL, ";", &context);

		while (*token == ' ') token++;
		Db->arr[current_vac].salary = atoi(token);
		token = strtok_s(NULL, ";", &context);

		current_vac++;
		free(line_copy);
	}

	fclose(fp);
}

void enter_the_vcn(char** users_choice) {
	*users_choice = (char*)malloc(max_simbols_in_line);
	while (1) {
		int i, flag = 0, cnt = 0, c = 0;

		printf("Enter the post to search: ");
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

int print_company(DbCompanies* dif_valid_comp_s) {
	int i, cnt = 0;
	system("cls");
	for (i = 0; i < dif_valid_comp_s->size; i++) {
		printf("--------------------------------------------------------------\n");
		printf("| %d) %s, %s", ++cnt, dif_valid_comp_s->arr[i].name, dif_valid_comp_s->arr[i].addres);
	}

	if (cnt == 0) {
		printf("Empty\n");
		return 0;
	}
	else {
		printf("--------------------------------------------------------------\n");
		printf("| 0. Exit\n");
		printf("--------------------------------------------------------------\n");
		return 1;
	}
}

void print_info(Company* valid_comp, DbVacancies* vcn_s){
	int i;
	system("cls");
	printf("ID: %d \nCompany: %s ,%s", valid_comp->company_id, valid_comp->name, valid_comp->addres);
	printf("________________________________________\n");
	for (i = 0; i < vcn_s->size; i++) {
		if (vcn_s->arr[i].company_id == valid_comp->company_id) {
			printf("| Name: %s\n", vcn_s->arr[i].name);
			printf("| Conditions: %s \n", vcn_s->arr[i].conditions);
			printf("| Requirements: %s \n", vcn_s->arr[i].requirements);
			printf("| Salary: %.2f \n", vcn_s->arr[i].salary);
			printf("\n");
		}
	}
}

void free_company(DbCompanies* Db) {
	int i;
	if (Db->size > 0) {
		for (i = 0; i < (*Db).size; i++) {
			free(Db->arr[i].name);
			free(Db->arr[i].addres);
		}
		free(Db->arr);
	}
}

void free_vacancy(DbVacancies* Db) {
	int i;
	if (Db->size > 0) {
	for (i = 0; i < (*Db).size; i++) {
			free(Db->arr[i].name);
			free(Db->arr[i].conditions);
			free(Db->arr[i].requirements);
		}
		free(Db->arr);
	}
}
