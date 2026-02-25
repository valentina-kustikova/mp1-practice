#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

void read_file(FILE* file, char** buf, int* len) {
	if (fseek(file, 0L, SEEK_END)) {
		*buf = NULL;
		*len = 0;
		return;
	}
	long bufsize = ftell(file);
	*buf = (char*)malloc((bufsize + 1) * sizeof(char));
	if (*buf == NULL)
		return NULL;
	fseek(file, 0L, SEEK_SET);
	*len = fread(*buf, sizeof(char), bufsize, file);
	buf[(*len)++] = '\0';
}

int count_char(char *str, char ch) {
	int cnt = 0;
	for (; *str != '\0'; str++)
		cnt += *str == ch;
	return cnt;
}