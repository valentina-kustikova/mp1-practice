#include <stdio.h>
#include <string.h>
#include "libarg.h"

void sort_person(PersonsLibrary* lib_persons){
	if (lib_persons == NULL || lib_persons->persons == NULL || lib_persons->count <= 0) return;
	int i, j, min_idx;
	for (i = 0; i < lib_persons->count - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < lib_persons->count; j++) {
			if (strcmp(lib_persons->persons[j].full_name.surname,
					   lib_persons->persons[min_idx].full_name.surname) < 0) {
				min_idx = j;
			}
			else if (strcmp(lib_persons->persons[j].full_name.surname, lib_persons->persons[min_idx].full_name.surname) == 0) {
				if (strcmp(lib_persons->persons[j].full_name.name, lib_persons->persons[min_idx].full_name.name) < 0) {
					min_idx = j;
				}
				else if (strcmp(lib_persons->persons[j].full_name.name, lib_persons->persons[min_idx].full_name.name) == 0) {
					if (strcmp(lib_persons->persons[j].full_name.patronymic, lib_persons->persons[min_idx].full_name.patronymic) < 0) {
						min_idx = j;
					}
				}
			}
		}
		if (min_idx != i) {
			PersonInfo temp = lib_persons->persons[i];
			lib_persons->persons[i] = lib_persons->persons[min_idx];
			lib_persons->persons[min_idx] = temp;
		}
	}
}
