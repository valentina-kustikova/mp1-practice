#include"lib.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

book* find(book* list, int cnt_s, char *uavtor)
{
	int i = 0, cnt_ans = 0, * idx_ans = (int*)malloc(sizeof(int) * cnt_s), k = 0;
	book* ans;
	// todo: никаких выводов, создаем новый массив
	for (i = 0; i < cnt_s; i++)
	{
		if (strstr(list[i].avtors, uavtor))
		{
			cnt_ans++;
			idx_ans[i] = 1;
		}
		else { idx_ans[i] = -1; }
	}
	ans = (book*)malloc(sizeof(book) * cnt_ans);
	for (i = 0; i < cnt_s; i++)
	{
		if (idx_ans[i] == 1) { ans[k] = list[i]; k++; }
	}
	free(idx_ans);
	return ans;
	 // todo: через коды ошибок
}