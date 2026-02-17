#include"lib.h"
#include"auxiliary.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
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
	int check = 0;
	int i;
	FILE* fp = fopen(fr, "r");
	for (i = 0; i < cnt; i++)
	{
		check = fscanf(fp, "%99[^;]; %99[^;]; %99[^;]; %d%*c%*c", col[i].avtors, col[i].name, col[i].pub, &col[i].year);
	}
	fclose(fp);
}