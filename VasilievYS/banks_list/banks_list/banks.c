#include"banks.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int find(bank* list, int cnt_s, char* udep)
{
	int idx_ans=0, i;
	float k;
	if (strstr("Demand deposit", udep)) 
	{
		k = list[0].demand;
		for (i = 1; i < cnt_s; i++)
		{
			if (list[i].demand > k) { k = list[i].demand; idx_ans = i; }
		}
	}
	else if (strstr("Time deposit", udep)) 
	{
		k = list[0].term;
		for (i = 1; i < cnt_s; i++)
		{
			if (list[i].term > k) { k = list[i].term; idx_ans = i; }
		}
	}
	else if (strstr("Savings deposit", udep)) 
	{
		k = list[0].save;
		for (i = 1; i < cnt_s; i++)
		{
			if (list[i].save > k) { k = list[i].save; idx_ans = i; }
		}
	}
	else
	{
		return -1;
	}
	return idx_ans;
}