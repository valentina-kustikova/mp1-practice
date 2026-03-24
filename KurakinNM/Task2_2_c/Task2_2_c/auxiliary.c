#define _CRT_SECURE_NO_WARNINGS

#include "university.h"

void bariers(char* str, int* start, int* numOfSims)
{
	while (str[*start] == ' ') (*start)++;
	while (str[*numOfSims - 1] == ' ') (*numOfSims)--;
	*numOfSims -= *start;
}

void readWord(char* input, char** output)
{
	int start = 0, numOfSims = strlen(input);
	bariers(input, &start, &numOfSims);
	(*output) = (char*)malloc(numOfSims + 1);
	strncpy(*output, input + start, numOfSims);
	(*output)[numOfSims] = '\0';
}
void readNumLine(char** input, unsigned int* outNums, int len)
{
	int i;
	char* num;
	for (i = 0; i < len; i++)
	{
		readWord(*input, &num);
		outNums[i] = atoi(num);
		*input = strtok(NULL, "|;");
	}
}

int read(char* fileName, UNIV** universities)
{
	FILE* f;
	int n = 0, i, j;
	char* num;
	char buffer[255]; char* token;
	unsigned int* numOfSpecialties;

	f = fopen(fileName, "r");
	while (!feof(f))
	{
		fgets(buffer, 255, f);
		n++;
	}


	numOfSpecialties = (unsigned int*)malloc(n * sizeof(unsigned int));
	for (i = 0; i < n; i++) { numOfSpecialties[i] = 0; }
	i = 0;
	fseek(f, 0, SEEK_SET);
	for (i = 0; i < n; i++)
	{
		fgets(buffer, 255, f);
		token = strtok(buffer, ";");
		token = strtok(NULL, ";");
		token = strtok(NULL, ";");
		while (token != NULL)
		{
			token = strstr(token + 1, "|");
			numOfSpecialties[i]++;
		}
	}


	*universities = (UNIV*)malloc(n * sizeof(UNIV));
	for (i = 0; i < n; i++)
	{
		(*universities)[i].numOfSpecialties = numOfSpecialties[i];
		(*universities)[i].specialties = (char**)malloc(numOfSpecialties[i] * sizeof(char*));
		(*universities)[i].contestDay = (unsigned int*)malloc(numOfSpecialties[i] * sizeof(unsigned int));
		(*universities)[i].contestNight = (unsigned int*)malloc(numOfSpecialties[i] * sizeof(unsigned int));
		(*universities)[i].contestOnline = (unsigned int*)malloc(numOfSpecialties[i] * sizeof(unsigned int));
		(*universities)[i].cost = (unsigned int*)malloc(numOfSpecialties[i] * sizeof(unsigned int));
	}
	free(numOfSpecialties);


	fseek(f, 0, SEEK_SET);
	for (i = 0; i < n; i++)
	{
		fgets(buffer, 255, f);
		token = strtok(buffer, "|;");
		readWord(token, &((*universities)[i].name));
		token = strtok(NULL, "|;");
		readWord(token, &((*universities)[i].adres));
		token = strtok(NULL, "|;");
		for (j = 0; j < (*universities)[i].numOfSpecialties; j++)
		{
			readWord(token, &((*universities)[i].specialties[j]));
			token = strtok(NULL, "|;");
		}
		/*for (j = 0; j < (*universities)[i].numOfSpecialties; j++)
		{
			readWord(token, &num);
			(*universities)[i].contestDay[j] = atoi(num);
			token = strtok(NULL, ",;");
		}*/
		readNumLine(&token, (*universities)[i].contestDay, (*universities)[i].numOfSpecialties);
		readNumLine(&token, (*universities)[i].contestNight, (*universities)[i].numOfSpecialties);
		readNumLine(&token, (*universities)[i].contestOnline, (*universities)[i].numOfSpecialties);
		readNumLine(&token, (*universities)[i].cost, (*universities)[i].numOfSpecialties);
	}

	fclose(f);

	return n;
}

void output(UNIV* univs, int numOfUnivers)
{
	int i, j;
	for (i = 0; i < numOfUnivers; i++)
	{
		printf("Название вуза: %s\n", univs[i].name);
		printf("Адрес: %s\n", univs[i].adres);
		printf("Специальности:\n");
		for (j = 0; j < univs[i].numOfSpecialties; j++)
		{
			printf("%s\n", univs[i].specialties[j]);
			printf("Конкурс прошлого года (Дневной/Вечерний/Заочный): %d/%d/%d\n", univs[i].contestDay[j], univs[i].contestNight[j], univs[i].contestOnline[j]);
			printf("Оплата при договорном обучении: %dр.\n", univs[i].cost[j]);
		}
		printf("\n");
	}
}