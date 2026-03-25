#include "library.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int* find(book *books, char* aut, int n) {
	int i, k = 0;
	int* ans;
	for (i = 0; i < n; i++) {
		if (strstr(books[i].authors, aut) != NULL) {
			k++;
		}
	}
	ans = (int*)malloc(sizeof(int) * (k + 1));
	if (ans == NULL) {
		printf("memory error");
	}
	ans[0] = k;
	k = 1;
	for (i = 0; i < n; i++) {
		if (strstr(books[i].authors, aut) != NULL) {
			ans[k] = i;
			k++;
		}
	}
	return ans;
}

void printer(book *books, int* ans) {
	int n = ans[0], i;
	printf("finded books: \n");
	for (i = 1; i < n + 1; i++) {
		printf("%99s; %99s; %99s; %d", books[ans[i]].authors, books[ans[i]].name, books[ans[i]].publisher, books[ans[i]].year);
	}
}