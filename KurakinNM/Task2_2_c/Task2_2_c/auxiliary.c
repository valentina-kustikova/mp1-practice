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
		*input = strtok(NULL, ",;");
		free(num);
	}
}

void readFloatLine(char** input, float* outNums, int len)
{
	int i;
	char* num;
	for (i = 0; i < len; i++)
	{
		readWord(*input, &num);
		outNums[i] = atof(num);
		*input = strtok(NULL, ",;");
		free(num);
	}
}

void read(char* fileName, DBUniversities* DBunivers)
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
	DBunivers->count = n;


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
			token = strstr(token + 1, ",");
			numOfSpecialties[i]++;
		}
	}


	DBunivers->universities = (University*)malloc(n * sizeof(University));
	for (i = 0; i < n; i++)
	{
		DBunivers->universities[i].numOfSpecialties = numOfSpecialties[i];
		DBunivers->universities[i].specialties = (char**)malloc(numOfSpecialties[i] * sizeof(char*));
		DBunivers->universities[i].contestDay = (unsigned int*)malloc(numOfSpecialties[i] * sizeof(unsigned int));
		DBunivers->universities[i].contestNight = (unsigned int*)malloc(numOfSpecialties[i] * sizeof(unsigned int));
		DBunivers->universities[i].contestOnline = (unsigned int*)malloc(numOfSpecialties[i] * sizeof(unsigned int));
		DBunivers->universities[i].cost = (unsigned int*)malloc(numOfSpecialties[i] * sizeof(unsigned int));
	}
	free(numOfSpecialties);


	fseek(f, 0, SEEK_SET);
	for (i = 0; i < n; i++)
	{
		fgets(buffer, 255, f);
		token = strtok(buffer, ",;");
		readWord(token, &(DBunivers->universities[i].name));
		token = strtok(NULL, ",;");
		readWord(token, &(DBunivers->universities[i].adres.city));
		token = strtok(NULL, ",;");
		readWord(token, &(DBunivers->universities[i].adres.street));
		token = strtok(NULL, ",;");
		readWord(token, &(DBunivers->universities[i].adres.home));
		token = strtok(NULL, ",;");
		for (j = 0; j < DBunivers->universities[i].numOfSpecialties; j++)
		{
			readWord(token, &(DBunivers->universities[i].specialties[j]));
			token = strtok(NULL, ",;");
		}
		/*for (j = 0; j < (*universities)[i].numOfSpecialties; j++)
		{
			readWord(token, &num);
			(*universities)[i].contestDay[j] = atoi(num);
			token = strtok(NULL, ",;");
		}*/
		readNumLine(&token, DBunivers->universities[i].contestDay, DBunivers->universities[i].numOfSpecialties);
		readNumLine(&token, DBunivers->universities[i].contestNight, DBunivers->universities[i].numOfSpecialties);
		readNumLine(&token, DBunivers->universities[i].contestOnline, DBunivers->universities[i].numOfSpecialties);
		readFloatLine(&token, DBunivers->universities[i].cost, DBunivers->universities[i].numOfSpecialties);
	}

	fclose(f);
	return n;
}

void output(DBUniversities univs)
{
	int i, j;
	for (i = 0; i < univs.count; i++)
	{
		printf("Название вуза: %s\n", univs.universities[i].name);
		printf("Адрес: %s, %s, %s\n", univs.universities[i].adres.city, univs.universities[i].adres.street, univs.universities[i].adres.home);
		printf("Специальности:\n");
		for (j = 0; j < univs.universities[i].numOfSpecialties; j++)
		{
			printf("%s\n", univs.universities[i].specialties[j]);
			printf("Конкурс прошлого года (Дневной/Вечерний/Заочный): %d/%d/%d\n",
				univs.universities[i].contestDay[j], univs.universities[i].contestNight[j], univs.universities[i].contestOnline[j]);
			printf("Оплата при договорном обучении: %.2fр.\n", univs.universities[i].cost[j]);
		}
		printf("\n");
	}
}