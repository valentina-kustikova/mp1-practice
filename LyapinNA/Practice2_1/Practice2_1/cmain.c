#include "func.h"



int main() {
	system("chcp 1251");
	vacancy* Vacancy;
	char* path = "list.txt";
	FILE* file;

	if (!(file = open_stream(path))) {
		printf("���� �� ������!");
		return 1;
	}

	int countVacancy;
	if ((countVacancy = count_vacancy(file)) == 0) {
		printf("�������� �� ���� ������� � ������!");
		return 1;
	}

	int* a = (int*)malloc(sizeof(int) * countVacancy);
	allocate_memory(&Vacancy, countVacancy);
	Vacancy = fill_structures(file, countVacancy);
	if (!(a = search_employee(Vacancy, countVacancy))) {
		printf("�������� �� ������ ������� �� ���� �������!");
		return 1;
	}

	output_info(Vacancy, a, countVacancy);
	free_memory(Vacancy);
	fclose(file);
	return 0;
}