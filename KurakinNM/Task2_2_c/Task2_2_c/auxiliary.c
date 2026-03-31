#define _CRT_SECURE_NO_WARNINGS

#include "university.h"

void freeDBU(DBUniversities* DB)
{
	int i, j;
	for (i = 0; i < DB->count; i++) {
		for (j = 0; j < DB->universities[i].numOfSpecialties; j++)
		{
			free(DB->universities[i].specialties[j]);
		}
		free(DB->universities[i].name);
		free(DB->universities[i].adres.city);
		free(DB->universities[i].adres.street);
		free(DB->universities[i].adres.home);
		free(DB->universities[i].contestDay);
		free(DB->universities[i].contestNight);
		free(DB->universities[i].contestOnline);
		free(DB->universities[i].cost);
	}
	free(DB->universities);
}

void cpy(char** output, const char* input)
{
	int len = strlen(input);
	(*output) = (char*)malloc(len + 1);
	strncpy(*output, input, len + 1);
}

void CopyU(University* universityCopy, const University universityOriginal)
{
	int i;
	universityCopy->numOfSpecialties = universityOriginal.numOfSpecialties;
	universityCopy->specialties = (char**)malloc(universityOriginal.numOfSpecialties * sizeof(char*));
	universityCopy->contestDay = (unsigned int*)malloc(universityOriginal.numOfSpecialties * sizeof(unsigned int));
	universityCopy->contestNight = (unsigned int*)malloc(universityOriginal.numOfSpecialties * sizeof(unsigned int));
	universityCopy->contestOnline = (unsigned int*)malloc(universityOriginal.numOfSpecialties * sizeof(unsigned int));
	universityCopy->cost = (unsigned int*)malloc(universityOriginal.numOfSpecialties * sizeof(unsigned int));
	for (i = 0; i < universityOriginal.numOfSpecialties; i++)
	{
		cpy(&(universityCopy->specialties[i]), universityOriginal.specialties[i]);
		universityCopy->contestDay[i] = universityOriginal.contestDay[i];
		universityCopy->contestNight[i] = universityOriginal.contestNight[i];
		universityCopy->contestOnline[i] = universityOriginal.contestOnline[i];
		universityCopy->cost[i] = universityOriginal.cost[i];
	}
	cpy(&(universityCopy->adres.city), universityOriginal.adres.city);
	cpy(&(universityCopy->adres.street), universityOriginal.adres.street);
	cpy(&(universityCopy->adres.home), universityOriginal.adres.home);
	cpy(&(universityCopy->name), universityOriginal.name);
}

void CopyUOnlyOneSpec(University* universityCopy, const University universityOriginal, char* spec)
{
	int i;
	universityCopy->numOfSpecialties = 1;
	universityCopy->specialties = (char**)malloc(sizeof(char*));
	universityCopy->contestDay = (unsigned int*)malloc(sizeof(unsigned int));
	universityCopy->contestNight = (unsigned int*)malloc(sizeof(unsigned int));
	universityCopy->contestOnline = (unsigned int*)malloc(sizeof(unsigned int));
	universityCopy->cost = (unsigned int*)malloc(sizeof(unsigned int));
	for (i = 0; i < universityOriginal.numOfSpecialties; i++)
	{
		if (strstr(universityOriginal.specialties[i], spec)) {
			cpy(&(universityCopy->specialties[0]), universityOriginal.specialties[i]);
			universityCopy->contestDay[0] = universityOriginal.contestDay[i];
			universityCopy->contestNight[0] = universityOriginal.contestNight[i];
			universityCopy->contestOnline[0] = universityOriginal.contestOnline[i];
			universityCopy->cost[0] = universityOriginal.cost[i];
			break;
		}
	}
	cpy(&(universityCopy->adres.city), universityOriginal.adres.city);
	cpy(&(universityCopy->adres.street), universityOriginal.adres.street);
	cpy(&(universityCopy->adres.home), universityOriginal.adres.home);
	cpy(&(universityCopy->name), universityOriginal.name);
}

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