#include "university.h"

void allAboutUniver(DBUniversities* univers, char* name)
{
	int i, j;
	for (i = 0; i < univers->count; i++)
	{
		if (strstr(univers->universities[i].name, name))
		{
			printf("Название вуза: %s\n", univers->universities[i].name);
			printf("Адрес: %s, %s, %s\n", univers->universities[i].adres.city, univers->universities[i].adres.street, univers->universities[i].adres.home);
			printf("Специальности:\n");
			for (j = 0; j < univers->universities[i].numOfSpecialties; j++)
			{
				printf("%s\n", univers->universities[i].specialties[j]);
				printf("Конкурс прошлого года (Дневной/Вечерний/Заочный): %d/%d/%d\n",
					univers->universities[i].contestDay[j], univers->universities[i].contestNight[j], univers->universities[i].contestOnline[j]);
				printf("Оплата при договорном обучении: %.2fр.\n", univers->universities[i].cost[j]);
			}
			printf("\n");
			break;
		};
	}
	if (i == univers->count)
	{
		printf("Вуз не найден.\n");
	}
}

void allAboutSpec(DBUniversities* univs, char* special)
{
	int i, j, n = 0;
	for (i = 0; i < univs->count; i++)
	{
		for (j = 0; j < univs->universities[i].numOfSpecialties; j++)
		{
			if (strstr(univs->universities[i].specialties[j], special))
			{
				printf("Специальность: %s\n", univs->universities[i].specialties[j]);
				printf("Вуз: %s\n", univs->universities[i].name);
				printf("Конкурс прошлого года (Дневной/Вечерний/Заочный): %d/%d/%d\n",
					univs->universities[i].contestDay[j], univs->universities[i].contestNight[j], univs->universities[i].contestOnline[j]);
				printf("Оплата при договорном обучении: %.2fр.\n", univs->universities[i].cost[j]);
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

void minContestSpec(DBUniversities* universResult, DBUniversities* univers, char* special)
{
	int i, j, n = 0;
	int DU = -1, DS = -1;
	int NU = -1, NS = -1;
	int OU = -1, OS = -1;
	for (i = 0; i < univers->count; i++)
	{
		for (j = 0; j < univers->universities[i].numOfSpecialties; j++)
		{
			if (strstr(univers->universities[i].specialties[j], special))
			{
				if (DU != -1)
				{
					if (univers->universities[i].contestDay[j] < univers->universities[DU].contestDay[DS]) { DU = i; DS = j; }
					if (univers->universities[i].contestNight[j] < univers->universities[NU].contestNight[NS]) { NU = i; NS = j; }
					if (univers->universities[i].contestOnline[j] < univers->universities[OU].contestOnline[OS]) { OU = i; OS = j; }
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
	if (DU == -1) printf("Специальность не найдена.\n");
	else {
		if (DU != NU && NU != OU && DU != OU) {
			universResult->count = 3;
			universResult->universities = (University*)malloc(3 * sizeof(University));
			CopyUOnlyOneSpec(&(universResult->universities[0]), &(univers->universities[DU]), special);
			CopyUOnlyOneSpec(&(universResult->universities[1]), &(univers->universities[NU]), special);
			CopyUOnlyOneSpec(&(universResult->universities[2]), &(univers->universities[OU]), special);
		}
		else if (DU == NU && NU == OU) {
			universResult->count = 1;
			universResult->universities = (University*)malloc(1 * sizeof(University));
			CopyUOnlyOneSpec(&(universResult->universities[0]), &(univers->universities[DU]), special);
		}
		else {
			universResult->count = 2;
			universResult->universities = (University*)malloc(2 * sizeof(University));
			CopyUOnlyOneSpec(&(universResult->universities[0]), &(univers->universities[DU]), special);
			if (DU != NU) CopyUOnlyOneSpec(&(universResult->universities[1]), &(univers->universities[NU]), special);
			else CopyUOnlyOneSpec(&(universResult->universities[1]), &(univers->universities[OU]), special);
		};
	}
	/* {
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
	else printf("Специальность не найдена.\n");*/
}

void findSpec(DBUniversities* univs)
{
	int i, j;
	int DS = -1;
	int NS = -1;
	int OS = -1;
	for (i = 0; i < univs->count; i++)
	{
		DS = -1;
		NS = -1;
		OS = -1;
		printf("Название вуза: %s\n", univs->universities[i].name);
		printf("Адрес: %s, %s, %s\n", univs->universities[i].adres.city,
			univs->universities[i].adres.street, univs->universities[i].adres.home);

		for (j = 0; j < univs->universities[i].numOfSpecialties; j++)
		{
			if (DS != -1)
			{
				if (univs->universities[i].contestDay[j] < univs->universities[i].contestDay[DS]) DS = j;
				if (univs->universities[i].contestNight[j] < univs->universities[i].contestNight[NS]) NS = j;
				if (univs->universities[i].contestOnline[j] < univs->universities[i].contestOnline[OS]) OS = j;
			}
			else
			{
				DS = j;
				NS = j;
				OS = j;
			}
		}
		printf("Минимальный дневной конкурс: %d\nСпециальность: %s\n",
			univs->universities[i].contestDay[DS], univs->universities[i].specialties[DS]);
		printf("Минимальный вечерний конкурс: %d\nСпециальность: %s\n",
			univs->universities[i].contestNight[NS], univs->universities[i].specialties[NS]);
		printf("Минимальный заочный конкурс: %d\nСпециальность: %s\n\n",
			univs->universities[i].contestOnline[OS], univs->universities[i].specialties[OS]);
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