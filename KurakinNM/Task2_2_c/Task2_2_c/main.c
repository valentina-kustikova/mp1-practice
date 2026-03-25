#include "university.h"
#include <locale.h>
#include <string.h>

int main()
{
	DBUniversities DBUnivers;
	int i, j, work = 1,option;
	char str[255];
	system("chcp 1251");
	system("cls");
	read("universities.txt", &DBUnivers);

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
			allAboutUniver(DBUnivers, str);
			break;
		case 2:
			while (getchar() != '\n');
			printf("Введите название специальности: ");
			fgets(str, 255, stdin);
			str[strlen(str) - 1] = '\0';
			//allAboutSpec(univers, str, n);
			break;
		case 3:
			while (getchar() != '\n');
			printf("Введите название специальности: ");
			fgets(str, 255, stdin);
			str[strlen(str) - 1] = '\0';
			//minContestSpec(univers, str, n);
			break;
		case 4:
			while (getchar() != '\n');
			printf("Введите название специальности: ");
			fgets(str, 255, stdin);
			str[strlen(str) - 1] = '\0';
			//findSpec(univers, str, n);
			break;
		case 5:
			output(DBUnivers);
			break;
		default:
			while (getchar() != '\n');
			printf("Некорекный ввод.\n");
			break;
		}
	}

	freeDBU(&DBUnivers);

	return 0;
}