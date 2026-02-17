#include<stdio.h>
#include<stdlib.h>
#include"lib.h"
#include"auxiliary.h"
#define _CRT_SECURE_NO_WARNINGS
int main()
{
	int cnt;
	book* col;
	cnt = cnt_s("data.txt");
	col = (book*)malloc(sizeof(book) * cnt);
	read("data.txt", col, cnt);
	find(col, cnt);
	return 0;
}