#include "func.h"



int main() {
	system("chcp 1251");
	vacancy* Vacancy;
	const char* path = "list.txt";
	FILE* file;

	if (!(file = open_stream(path))) {
		printf("Файл не найден!");
		return 1;
	}

	int countVacancy;
	if ((countVacancy = count_vacancy(file)) == 0) {
		printf("Вакансий не было найдено в списке!");
		return 1;
	}

	int* a = (int*)malloc(sizeof(int) * countVacancy);
	Vacancy = (vacancy*)malloc(sizeof(vacancy) * countVacancy);
	allocate_memory(Vacancy, countVacancy);
	Vacancy = fill_structures(file, countVacancy);
	if (!(a = search_employee(Vacancy, countVacancy))) {
		printf("Вакансий по вашему запросу не было найдено!");
		return 1;
	}

	output_info(Vacancy, a, countVacancy);
	free_memory(Vacancy);
	free(a);
	fclose(file);
	return 0;
}