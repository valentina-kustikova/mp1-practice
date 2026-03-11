#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"
#include "utility.h"

int read_csv(FILE* file, csv* tbl) {
	int i, line, len;
	char* pch;
	if (file == NULL || tbl == NULL)
		return 1;

	tbl->str = NULL;
	read_file(file, &(tbl->str), &len);
	tbl->lines_cnt = 1 + count_char(tbl->str, '\n');
	tbl->cells_cnt = (int*)calloc(tbl->lines_cnt, sizeof(int));
	tbl->cells = (char***)malloc(tbl->lines_cnt * sizeof(char**));

	pch = tbl->str;
	line = 0;
	while (line < tbl->lines_cnt) {
		char *end_line = strchr(pch, '\n');
		char *next_token;
		if (end_line != NULL)
			*end_line = '\0';

		tbl->cells_cnt[line] = 1 + count_char(pch, ';');
		tbl->cells[line] = (char**)malloc(tbl->cells_cnt[line] * sizeof(char*));

		pch = strtok_s(pch, ";", &next_token);
		for (i = 0; i < tbl->cells_cnt[line]; i++) {
			tbl->cells[line][i] = pch;
			pch = strtok_s(NULL, ";", &next_token);
		}

		line++;
		pch = end_line + 1;
	}
	return 0;
}