#ifndef __CSV_H
#define __CSV_H

typedef struct _csv {
	char* str;
	char*** cells;
	int     lines_cnt;
	int* cells_cnt;
} csv;

int read_csv(FILE* file, csv* tbl);

#endif