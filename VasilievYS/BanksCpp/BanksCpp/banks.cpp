#include"banks.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
bank banks_library::find(const std::string& udep)
{
	int check = 0;
	int* idx_list = new int[cnt];
	float* percent_list = new float[cnt];
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < banks[i].depostes_cnt; j++)
		{
			if (banks[i].deposites[j].name.find(udep) != std::string::npos)
			{
				idx_list[check] = i;
				percent_list[check] = banks[i].deposites[j].percentage;
				check++;
				break;
			}
		}
	}
	if (check == 0) { 
		delete[]idx_list; 
		delete[]percent_list; 
		throw std::string("No matches");
	}
	float max_p = percent_list[0];
	int idx = 0;
	for (int i = 1; i < check; i++)
	{
		if (percent_list[i] > max_p) { max_p = percent_list[i]; idx = i; }
	}
	int ans_idx = idx_list[idx];
	delete[]idx_list;
	delete[]percent_list;
	return banks[ans_idx];
}