#include"lib.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
void find(book* list, int cnt_s)
{
	char ch, uavtor[99], curr_avtr[99];
	int i = 0, j = 0, ans=0, curr=0;
	printf("Author: ");
	while ((ch = getchar()) != '\n')
	{
		uavtor[i] = ch;
		i++;
	}
	uavtor[i] = '\0';
	for (i = 0; i < cnt_s; i++)
	{
		curr_avtr[curr] = list[i].avtors[0];
		curr++;
		for (j = 1; j <= strlen(list[i].avtors); j++)
		{
			if (list[i].avtors[j] == ','|| list[i].avtors[j] == '\0')
			{ 
				curr_avtr[curr] = '\0';
				if (strcmp(curr_avtr, uavtor) == 0)
				{
					printf("\n%s, %s, %s, %d", list[i].avtors, list[i].name, list[i].pub, list[i].year);
					ans++;
				}
				curr = 0;
			}
			else if (list[i].avtors[j - 1] != ',')
			{
				curr_avtr[curr] = list[i].avtors[j];
				curr++;
			}
		}
	}
	if (ans == 0) { printf("NO"); }
}