#include "Sort.h"

void Sort_with_choise(LibraryInfo* library) {
    for (int i = 0; i < library->count - 1; i++) {
        int min_index = i;


        for (int j = i + 1; j < library->count; j++) {
            char* surname1 = library->person[j]->fullname.Surname;
            char* surname2 = library->person[min_index]->fullname.Surname; // equal по имени и отчеству
            char* name1 = library->person[j]->fullname.Name;
            char* name2 = library->person[min_index]->fullname.Name;
            char* patronymic1 = library->person[j]->fullname.Patronymic;
            char* patronymic2 = library->person[min_index]->fullname.Patronymic;

            // strcmp возвращает < 0 если surname1 < surname2. ѕо аналогии работают остальные проверки
            int surname_cmp = strcmp(surname1, surname2);

            if (surname_cmp < 0) min_index = j;
            else if (surname_cmp == 0) {

                int name_cmp = strcmp(name1, name2);

                if (name_cmp < 0) min_index = j;
                else if (name_cmp == 0) {

                    int patronymic_cmp = strcmp(patronymic1, patronymic2);

                    if (patronymic_cmp < 0) min_index = j;
                }
            }
        }
        


        if (min_index != i) {
            PersonInfo* temp = library->person[i];
            library->person[i] = library->person[min_index];
            library->person[min_index] = temp;
        }
    }
}