#include "university.h"

void allAboutUniver(DBUniversities univers, char* name)
{
	int i, j;
	for (i = 0; i < univers.count; i++)
	{
		if (strstr(univers.universities[i].name, name))
		{
			printf("Íàçâàíèå âóçà: %s\n", univers.universities[i].name);
			printf("Àäðåñ: %s, %s, %s\n", univers.universities[i].adres.city, univers.universities[i].adres.street, univers.universities[i].adres.home);
			printf("Ñïåöèàëüíîñòè:\n");
			for (j = 0; j < univers.universities[i].numOfSpecialties; j++)
			{
				printf("%s\n", univers.universities[i].specialties[j]);
				printf("Êîíêóðñ ïðîøëîãî ãîäà (Äíåâíîé/Âå÷åðíèé/Çàî÷íûé): %d/%d/%d\n",
					univers.universities[i].contestDay[j], univers.universities[i].contestNight[j], univers.universities[i].contestOnline[j]);
				printf("Îïëàòà ïðè äîãîâîðíîì îáó÷åíèè: %.2fð.\n", univers.universities[i].cost[j]);
			}
			printf("\n");
			break;
		};
	}
	if (i == univers.count)
	{
		printf("Âóç íå íàéäåí.\n");
	}
}

void allAboutSpec(DBUniversities univs, char* special)
{
	int i, j, n = 0;
	for (i = 0; i < univs.count; i++)
	{
		for (j = 0; j < univs.universities[i].numOfSpecialties; j++)
		{
			if (strstr(univs.universities[i].specialties[j], special))
			{
				printf("Ñïåöèàëüíîñòü: %s\n", univs.universities[i].specialties[j]);
				printf("Âóç: %s\n", univs.universities[i].name);
				printf("Êîíêóðñ ïðîøëîãî ãîäà (Äíåâíîé/Âå÷åðíèé/Çàî÷íûé): %d/%d/%d\n",
					univs.universities[i].contestDay[j], univs.universities[i].contestNight[j], univs.universities[i].contestOnline[j]);
				printf("Îïëàòà ïðè äîãîâîðíîì îáó÷åíèè: %.2fð.\n", univs.universities[i].cost[j]);
				printf("\n");

				n++;
				break;
			}
		}
	}
	if (n == 0)
	{
		printf("Ñïåöèàëüíîñòü íå íàéäåíà.\n");
	}
}

void minContestSpec(DBUniversities* universResult, DBUniversities univers, char* special)
{
	int i, j, n = 0;
	int DU = -1, DS = -1;
	int NU = -1, NS = -1;
	int OU = -1, OS = -1;
	for (i = 0; i < univers.count; i++)
	{
		for (j = 0; j < univers.universities[i].numOfSpecialties; j++)
		{
			if (strstr(univers.universities[i].specialties[j], special))
			{
				if (DU != -1)
				{
					if (univers.universities[i].contestDay[j] < univers.universities[DU].contestDay[DS]) { DU = i; DS = j; }
					if (univers.universities[i].contestNight[j] < univers.universities[NU].contestNight[NS]) { NU = i; NS = j; }
					if (univers.universities[i].contestOnline[j] < univers.universities[OU].contestOnline[OS]) { OU = i; OS = j; }
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
	if (DU == -1) printf("Ñïåöèàëüíîñòü íå íàéäåíà.\n");
	else {
		if (DU != NU && NU != OU && DU != OU) {
			universResult->count = 3;
			universResult->universities = (University*)malloc(3 * sizeof(University));
			CopyUOnlyOneSpec(&(universResult->universities[0]), univers.universities[DU], special);
			CopyUOnlyOneSpec(&(universResult->universities[1]), univers.universities[NU], special);
			CopyUOnlyOneSpec(&(universResult->universities[2]), univers.universities[OU], special);
		}
		else if (DU == NU && NU == OU) {
			universResult->count = 1;
			universResult->universities = (University*)malloc(1 * sizeof(University));
			CopyUOnlyOneSpec(&(universResult->universities[0]), univers.universities[DU], special);
		}
		else {
			universResult->count = 2;
			universResult->universities = (University*)malloc(2 * sizeof(University));
			CopyUOnlyOneSpec(&(universResult->universities[0]), univers.universities[DU], special);
			if (DU != NU) CopyUOnlyOneSpec(&(universResult->universities[1]), univers.universities[NU], special);
			else CopyUOnlyOneSpec(&(universResult->universities[1]), univers.universities[OU], special);
		};
	}
	/* {
		printf("Äíåâíàÿ ôîðìà:\n");
		printf("Ñïåöèàëüíîñòü: %s\n", univers[DU].specialties[DS]);
		printf("Âóç: %s\n", univers[DU].name);
		printf("Êîíêóðñ ïðîøëîãî ãîäà: %d\n", univers[DU].contestDay[DS]);
		printf("\n");
		printf("Íî÷íàÿ ôîðìà:\n");
		printf("Ñïåöèàëüíîñòü: %s\n", univers[NU].specialties[NS]);
		printf("Âóç: %s\n", univers[NU].name);
		printf("Êîíêóðñ ïðîøëîãî ãîäà: %d\n", univers[NU].contestNight[NS]);
		printf("\n");
		printf("Çàî÷íàÿ ôîðìà:\n");
		printf("Ñïåöèàëüíîñòü: %s\n", univers[OU].specialties[OS]);
		printf("Âóç: %s\n", univers[OU].name);
		printf("Êîíêóðñ ïðîøëîãî ãîäà: %d\n", univers[OU].contestOnline[OS]);
		printf("\n");
	}
	else printf("Ñïåöèàëüíîñòü íå íàéäåíà.\n");*/
}

void findSpec(DBUniversities univs)
{
	int i, j;
	int DS = -1;
	int NS = -1;
	int OS = -1;
	for (i = 0; i < univs.count; i++)
	{
		DS = -1;
		NS = -1;
		OS = -1;
		printf("Íàçâàíèå âóçà: %s\n", univs.universities[i].name);
		printf("Àäðåñ: %s, %s, %s\n", univs.universities[i].adres.city,
			univs.universities[i].adres.street, univs.universities[i].adres.home);

		for (j = 0; j < univs.universities[i].numOfSpecialties; j++)
		{
			if (DS != -1)
			{
				if (univs.universities[i].contestDay[j] < univs.universities[i].contestDay[DS]) DS = j;
				if (univs.universities[i].contestNight[j] < univs.universities[i].contestNight[NS]) NS = j;
				if (univs.universities[i].contestOnline[j] < univs.universities[i].contestOnline[OS]) OS = j;
			}
			else
			{
				DS = j;
				NS = j;
				OS = j;
			}
		}
		printf("Ìèíèìàëüíûé äíåâíîé êîíêóðñ: %d\nÑïåöèàëüíîñòü: %s\n",
			univs.universities[i].contestDay[DS], univs.universities[i].specialties[DS]);
		printf("Ìèíèìàëüíûé âå÷åðíèé êîíêóðñ: %d\nÑïåöèàëüíîñòü: %s\n",
			univs.universities[i].contestNight[NS], univs.universities[i].specialties[NS]);
		printf("Ìèíèìàëüíûé çàî÷íûé êîíêóðñ: %d\nÑïåöèàëüíîñòü: %s\n\n",
			univs.universities[i].contestOnline[OS], univs.universities[i].specialties[OS]);
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
