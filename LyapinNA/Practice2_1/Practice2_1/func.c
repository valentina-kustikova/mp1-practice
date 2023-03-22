#include "func.h"



FILE* open_stream(const char* path) {
	FILE* read;
	read = fopen(path, "r");

	if (read == NULL) 
		return NULL;
	return read;
}



int count_vacancy(FILE* read) {
	int vacancy_count = 0, lines_count = 1;

	while (feof(read) == 0)
	{
		if (fgetc(read) == '\n')
			lines_count++;
	}

	vacancy_count = (lines_count + 1) / N;
	printf("%d\n\n", vacancy_count);
	return vacancy_count;
}



void allocate_memory(vacancy** Vacancy, int countVacancy) {
	(*Vacancy) = (vacancy*)malloc(sizeof(vacancy) * countVacancy);
}



vacancy* fill_structures(FILE* file, int vacancyCount) {
	vacancy* Vacancy;
	int stringCount = vacancyCount * N, j = 0, v = 0, i = 1;
	char* text = (char*)malloc(100);
	allocate_memory(&Vacancy, vacancyCount);
	fseek(file, 0, SEEK_SET);


	for (i = 0; i < vacancyCount; i++) {
		fgets(text, 100, file);
		strcpy(Vacancy[i].employee, text);
		fgets(text, 100, file);
		strcpy(Vacancy[i].name_company, text);
		fgets(text, 100, file);
		strcpy(Vacancy[i].salary, text);
		fgets(text, 100, file);
		strcpy(Vacancy[i].work_cond, text);
		fgets(text, 100, file);
		strcpy(Vacancy[i].request, text);
	}
	
	free(text);
	return Vacancy;
}



int* search_employee(vacancy* Vacancy, int countVacancy) {
	int i = 0, j = 0;
	int* res;
	res = (int*)malloc(4 * countVacancy);
	char str[20];
	char* str2;
	printf("Какую должность вы ищете?\t");
	gets(str);
	str2 = strcat(str, "\n");

	for (; i < countVacancy; i++) {
		res[i] = -1;
		if (strcmp(str2, Vacancy[i].employee) == 0)
		{
			res[j] = i;
			j++;
		}
	}

	if (res[0] == -1)
		return NULL;

	return res;
}



void output_info(vacancy* Vacancy, int* ind, int countVacancy) {
	int sizeMas = 0;

	for (int i = 0; i < countVacancy; i++) {
		if (ind[i] != -1) {
			sizeMas++;
		}
		else
			break;
	}
	printf("\n\nКоличество найденных вакансий: %d", sizeMas);
	for (int i = 0; i < sizeMas; i++) {
		printf("\nДолжность: %s Компания: %s Заработная плата: %s ", Vacancy[ind[i]].employee, Vacancy[ind[i]].name_company, Vacancy[ind[i]].salary);
		printf("Условия работы: %s Требования к вакансии: %s \n", Vacancy[ind[i]].work_cond, Vacancy[ind[i]].request);
	}
}



void free_memory(vacancy* Vacancy) {
	free(Vacancy);
}