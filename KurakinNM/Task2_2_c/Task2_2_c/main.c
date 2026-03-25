#include "university.h"
#include <locale.h>
#include <string.h>

int main()
{
	University* univers;
	int n, i, j, work = 1,option;
	char str[255];
	system("chcp 1251");
	system("cls");
	n = read("universities.txt", &univers);

	while(work)
	{
		printf("===========================================\n");
		printf("Выберите режим поиска (1 - всё о данном вузе, 2 - всё о данной специальности, 3 - поиск минимального конкурса по данной специальности, 4 - по специальностям каждого вуза, 5 - вывести все вузы, 0 - выход):");
		scanf_s("%d", &option);
		switch (option)
		{
		case 0:
			work = 0;
			break;
		case 1:
			while (getchar() != '\n');
			printf("Введите название вуза: ");
			fgets(str, 255, stdin);
			str[strlen(str) - 1] = '\0';
			allAboutUniver(univers, str, n);
			break;
		case 2:
			while (getchar() != '\n');
			printf("Введите название специальности: ");
			fgets(str, 255, stdin);
			str[strlen(str) - 1] = '\0';
			allAboutSpec(univers, str, n);
			break;
		case 3:
			while (getchar() != '\n');
			printf("Введите название специальности: ");
			fgets(str, 255, stdin);
			str[strlen(str) - 1] = '\0';
			minContestSpec(univers, str, n);
			break;
		case 4:
			while (getchar() != '\n');
			printf("Введите название специальности: ");
			fgets(str, 255, stdin);
			str[strlen(str) - 1] = '\0';
			findSpec(univers, str, n);
			break;
		case 5:
			output(univers, n);
			break;
		default:
			while (getchar() != '\n');
			printf("Некорекный ввод.\n");
			break;
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < univers[i].numOfSpecialties; j++)
		{
			free(univers[i].specialties[j]);
		}
		free(univers[i].name);
		free(univers[i].adres.city);
		free(univers[i].adres.street);
		free(univers[i].adres.home);
		free(univers[i].contestDay);
		free(univers[i].contestNight);
		free(univers[i].contestOnline);
		free(univers[i].cost);
	}
	free(univers);

	return 0;
}