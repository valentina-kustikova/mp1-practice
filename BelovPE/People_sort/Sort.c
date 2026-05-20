#include "Sort.h"

void Sort_with_choise(LibraryInfo* library) {
    for (int i = 0; i < library->count - 1; i++) {
        int min_index = i;


        for (int j = i + 1; j < library->count; j++) {
            char* surname1 = library->person[j]->fullname.Surname;
            char* surname2 = library->person[min_index]->fullname.Surname;

            // strcmp возвращает <0 если surname1 < surname2
            if (strcmp(surname1, surname2) < 0) {
                min_index = j;
            }
        }


        if (min_index != i) {
            PersonInfo* temp = library->person[i];
            library->person[i] = library->person[min_index];
            library->person[min_index] = temp;
        }
    }
}