#include"lib.h"
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
	return cnt;
}
void read(const char* fr, book* col, int cnt)
{
	int check = 0, i, j;
	char line[512], *token;
	FILE* fp = fopen(fr, "r");
	for (i = 0; i < cnt; i++)
	{
		fgets(line, sizeof(line), fp);
		token = strtok(line, ";");
		j = 0;
		while (token != NULL)
		{
			if (j == 0) { strcpy(col[i].avtors, token);}
			else if (j == 1) { strcpy(col[i].name, token);}
			else if (j == 2) { strcpy(col[i].pub, token);}
			else if (j == 3) { col[i].year = atoi(token);}
			j++;
			token = strtok(NULL, ";");
		}
	}
	fclose(fp);
}
void print(book* ans, int cnt_ans)
{
	int i;
	if (cnt_ans != 0)
	{
		for (i = 0; i < cnt_ans; i++)
		{
			printf("%s; %s; %s; %d\n", ans[i].avtors, ans[i].name, ans[i].pub, ans[i].year);
		}
	}
	else { printf("NO"); }
}
