#include"banks.h"
#include"auxiliary.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
	return cnt-1;
}
void read(const char* fr, bank* col, int cnt)
{
	int check = 0, i, j;
	char line[512], * token;
	FILE* fp = fopen(fr, "r");
	fgets(line, sizeof(line), fp);
	for (i = 0; i < cnt; i++)
	{
		fgets(line, sizeof(line), fp);
		token = strtok(line, ";");
		j = 0;
		while (token != NULL)
		{
			if (j == 0) { strcpy(col[i].name, token); }
			else if (j == 1) { strcpy(col[i].owner, token); }
			else if (j == 2) { col[i].demand = atof(token); }
			else if (j == 3) { col[i].term = atof(token); }
			else if (j == 4) { col[i].save = atof(token); }
			j++;
			token = strtok(NULL, ";");
		}
	}
	fclose(fp);
}
void print(bank ans)
{
	int i;
	printf("%s; Ownership form:%s; Demand deposit - %.2f%%; Time deposit -  %.2f%%; Savings deposit - %.2f%%\n",
		ans.name, ans.owner, ans.demand, ans.term, ans.save);
}