#include <stdio.h>
#include <string.h>
#include "libarg.h"

void sort_person(person_info* person, int n) {
	int i, j, min_idx;
	person_info temp;

	for (i = 0; i < n - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			if (strcmp(person[j].surname, person[min_idx].surname) < 0) {
				min_idx = j;
			}
		}
		if (min_idx != i) {
			temp = person[i];
			person[i] = person[min_idx];
			person[min_idx] = temp;
		}
	}
}
