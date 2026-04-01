#include"banks.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int find(banks_library* lib, char* udep)
{
	int idx_ans = 0, idx, i, j, cnt_b = 0;
	float* percent_list = (float*)malloc(sizeof(float) * lib->cnt), max_p;
	int* idx_list = (int*)malloc(sizeof(int) * lib->cnt);
	for (i = 0; i < lib->cnt; i++)
	{
		for (j = 0; j < lib->banks[i].deposits_count; j++)
		{
			if (strstr(lib->banks[i].deposites[j].name, udep))
			{
				idx_list[cnt_b] = i;
				percent_list[cnt_b] = lib->banks[i].deposites[j].percentage;
				cnt_b++;
				break;
			}
		}
	}
	if (cnt_b == 0) { free(percent_list); free(idx_list); return -1; }
	max_p = percent_list[0];
	idx = 0;
	for (i = 1; i < cnt_b; i++)
	{
		if (percent_list[i] > max_p) { max_p = percent_list[i]; idx = i; }
	}
	idx_ans = idx_list[idx];
	free(percent_list);
	free(idx_list);
	return idx_ans;

}