#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliary.h"

int read_csv(FILE *file, csv *tbl) {
	int i, line;
	char *start;
	int len = 0;
	if (tbl == NULL)
		return 1;
	tbl->str = NULL;
	if (file == NULL)
		return 1;
	if (fseek(file, 0L, SEEK_END) == 0) {
		long bufsize = ftell(file);
		tbl->str = (char *) malloc((bufsize + 1) * sizeof(char));
		if (tbl->str == NULL)
			return 1;
		fseek(file, 0L, SEEK_SET);
		len = fread(tbl->str, sizeof(char), bufsize, file);
		tbl->str[len++] = '\0';
	}
	for (i = 0; i < len; i++) {
		if (tbl->str[i] == '\n')
			tbl->lines_cnt++;
	}
	tbl->cells_cnt = (int *) calloc(tbl->lines_cnt, sizeof(int));
	tbl->cells = (char ***) malloc(tbl->lines_cnt * sizeof(char **));
	start = tbl->str;
	line = 0;
	while (line < tbl->lines_cnt) {
		int cell = 0;
		for (i = 0; tbl->str[i] != '\n' && tbl->str[i] != '\0'; i++)
			if (tbl->str[i] == ';')
				tbl->cells_cnt[line]++;
		tbl->cells[line] = (char **) malloc(tbl->cells_cnt[line] * sizeof(char *));
		if (tbl->cells_cnt[line] > 0)
			tbl->cells[line][cell++] = start;
		for (;*start != '\n' && *start != '\0'; start++) {
			if (*start == ';') {
				*start = '\0';
				tbl->cells[line][cell++] = start + 1;
			}
		}
		line++;
	}
	return 0;
}
