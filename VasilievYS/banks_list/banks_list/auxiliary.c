#include"banks.h"
#include"auxiliary.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int cnt_s(const char* fr)
{
	char ch;
	int cnt = 0;
	FILE* fp = fopen(fr, "r");
	if (fp == NULL) { printf("nnnn"); return NULL; }
	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch == '\n') { cnt++; }
	}
	fclose(fp);
	return cnt;
}
void read(const char* fr, banks_library* lib)
{
	int check = 0, i;
	char line[MAX_LEN], temp_line[MAX_LEN], * token, *temp_token;
	FILE* fp = fopen(fr, "r");
	for (i = 0; i < lib->cnt; i++)
	{
		int dep_cnt=0, cur_dep=0;
		fgets(line, sizeof(line), fp);
		//кол-во депозитов
		strcpy(temp_line, line);
		temp_token = strtok(temp_line, ";");
		temp_token = strtok(NULL, ";");
		temp_token = strtok(NULL, ";");
		while (temp_token != NULL)
		{
			if (strchr(temp_token, ',') != NULL) { dep_cnt++; }
			temp_token = strtok(NULL, ";");
		}
		lib->banks[i].deposits_count = dep_cnt;
		lib->banks[i].deposites = (deposit*)malloc(sizeof(deposit) * dep_cnt);
		//
		token = strtok(line, ";");
		strcpy(lib->banks[i].name, token);
		token = strtok(NULL, ";");
		strcpy(lib->banks[i].owner, token);
		token = strtok(NULL, ";");
		while (token != NULL)
		{
			char* comma = strchr(token, ',');
			if (comma == NULL)
			{
				token = strtok(NULL, ";");
				continue;
			}
			*comma = '\0';
			to_low(token);
			strcpy(lib->banks[i].deposites[cur_dep].name, token);
			lib->banks[i].deposites[cur_dep].percentage = atof(comma + 2);
			cur_dep++;
			token = strtok(NULL, ";");
		}
	}
	fclose(fp);
}
void to_low(char* str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		str[i]=tolower(str[i]);
	}
}
void print(bank ans)
{
	int i;
	printf("%s; Ownership form:%s\n",
		ans.name, ans.owner);
}
void free_b(banks_library* lib)
{
	int i;
	for (i = 0; i < lib->cnt; i++)
	{
		free(lib->banks[i].deposites);
	}
	free(lib->banks);
}