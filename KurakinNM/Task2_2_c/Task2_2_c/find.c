#include "university.h"

void allAboutUniver(University* univers, char* name, int numOfUnivers)
{
	int i, j;
	for (i = 0; i < numOfUnivers; i++)
	{
		if (strstr(univers[i].name, name))
		{
			printf("Название вуза: %s\n", univers[i].name);
			printf("Адрес: %s\n", univers[i].adres);
			printf("Специальности:\n");
			for (j = 0; j < univers[i].numOfSpecialties; j++)
			{
				printf("%s\n", univers[i].specialties[j]);
				printf("Конкурс прошлого года (Дневной/Вечерний/Заочный): %d/%d/%d\n", univers[i].contestDay[j], univers[i].contestNight[j], univers[i].contestOnline[j]);
				printf("Оплата при договорном обучении: %dр.\n", univers[i].cost[j]);
			}
			printf("\n");
			break;
		};
	}
	if (i == numOfUnivers)
	{
		printf("Вуз не найден.\n");
	}
}

void allAboutSpec(University* univers, char* special, int numOfUnivers)
{
	int i, j, n = 0;
	for (i = 0; i < numOfUnivers; i++)
	{
		for (j = 0; j < univers[i].numOfSpecialties; j++)
		{
			if (strstr(univers[i].specialties[j], special))
			{
				printf("Специальность: %s\n", univers[i].specialties[j]);
				printf("Вуз: %s\n", univers[i].name);
				printf("Конкурс прошлого года (Дневной/Вечерний/Заочный): %d/%d/%d\n", univers[i].contestDay[j], univers[i].contestNight[j], univers[i].contestOnline[j]);
				printf("Оплата при договорном обучении: %dр.\n", univers[i].cost[j]);
				printf("\n");

				n++;
				break;
			}
		}
	}
	if (n == 0)
	{
		printf("Специальность не найдена.\n");
	}
}

void minContestSpec(University* univers, char* special, int numOfUnivers)
{
	int i, j, n = 0;
	int DU = -1, DS = -1;
	int NU = -1, NS = -1;
	int OU = -1, OS = -1;
	for (i = 0; i < numOfUnivers; i++)
	{
		for (j = 0; j < univers[i].numOfSpecialties; j++)
		{
			if (strstr(univers[i].specialties[j], special))
			{
				if (DU != -1)
				{
					if (univers[i].contestDay[j] < univers[DU].contestDay[DS]) { DU = i; DS = j; }
					if (univers[i].contestNight[j] < univers[NU].contestNight[NS]) { NU = i; NS = j; }
					if (univers[i].contestOnline[j] < univers[OU].contestOnline[OS]) { OU = i; OS = j; }
				}
				else
				{
					DU = i; DS = j;
					NU = i; NS = j;
					OU = i; OS = j;
				}
				break;
			}
		}
	}
	if (DU != -1)
	{
		printf("Дневная форма:\n");
		printf("Специальность: %s\n", univers[DU].specialties[DS]);
		printf("Вуз: %s\n", univers[DU].name);
		printf("Конкурс прошлого года: %d\n", univers[DU].contestDay[DS]);
		printf("\n");
		printf("Ночная форма:\n");
		printf("Специальность: %s\n", univers[NU].specialties[NS]);
		printf("Вуз: %s\n", univers[NU].name);
		printf("Конкурс прошлого года: %d\n", univers[NU].contestNight[NS]);
		printf("\n");
		printf("Заочная форма:\n");
		printf("Специальность: %s\n", univers[OU].specialties[OS]);
		printf("Вуз: %s\n", univers[OU].name);
		printf("Конкурс прошлого года: %d\n", univers[OU].contestOnline[OS]);
		printf("\n");
	}
	else printf("Специальность не найдена.\n");
}

void findSpec(University* univers, char* special, int numOfUnivers)
{
	int i, j, c, n = 0;
	for (i = 0; i < numOfUnivers; i++)
	{
		for (j = 0; j < univers[i].numOfSpecialties; j++)
		{
			if (strstr(univers[i].specialties[j], special))
			{
				printf("Название вуза: %s\n", univers[i].name);
				printf("Адрес: %s\n", univers[i].adres);
				printf("Специальности:\n");
				for (c = 0; c < univers[i].numOfSpecialties; c++)
				{
					printf("%s\n", univers[i].specialties[c]);
					printf("Конкурс прошлого года (Дневной/Вечерний/Заочный): %d/%d/%d\n", univers[i].contestDay[c], univers[i].contestNight[c], univers[i].contestOnline[c]);
					printf("Оплата при договорном обучении: %dр.\n", univers[i].cost[c]);
				}
				printf("\n");

				n++;
				break;
			}
		}
	}
	if (n == 0)
	{
		printf("Специальность не найдена.\n");
	}
}

/*void cpy(char* input, char** output, int len)
{

	(*output) = (char*)malloc(len + 1);
	strncpy(*output, input, len + 1);
}

int find(BOOK* lib, BOOK** findedBooks, int numOfBooks, char* str)
{
	int i, j, k, n = 0, strLen;
	char* p;
	strLen = strlen(str) - 1;
	for (i = 0; i < numOfBooks; i++)
	{
		for (j = 0; j < lib[i].numberOfAuthors; j++)
		{
			if (strstr(lib[i].authors[j], str))
			{
				n++;
				break;
			};
		}
	}

	*findedBooks = (BOOK*)malloc(n * sizeof(BOOK));
	n = 0;

	for (i = 0; i < numOfBooks; i++)
	{
		for (j = 0; j < lib[i].numberOfAuthors; j++)
		{
			if (strstr(lib[i].authors[j], str))
			{
				cpy(lib[i].title, &((*findedBooks)[n].title), strlen(lib[i].title));
				cpy(lib[i].ed, &((*findedBooks)[n].ed), strlen(lib[i].ed));

				(*findedBooks)[n].year = lib[i].year;
				(*findedBooks)[n].numberOfAuthors = lib[i].numberOfAuthors;

				(*findedBooks)[n].authors = (char**)malloc(lib[i].numberOfAuthors * sizeof(char*));
				for (k = 0; k < lib[i].numberOfAuthors; k++)
				{
					cpy(lib[i].authors[k], &((*findedBooks)[n].authors[k]), strlen(lib[i].authors[k]));
				}
				n++;
				break;
			}
		}
	}
	return n;
}*/