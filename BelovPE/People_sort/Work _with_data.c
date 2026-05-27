#include "Work_with_data.h"


int Count_the_data(FILE* file) {
    int ch;
    int count = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') count++;
    }

    printf("Count of people: %d\n", count);

    return count;
}


LibraryInfo* Create_the_library(int count) {
    LibraryInfo* library = malloc(count * sizeof(LibraryInfo));
    if (!library) {
        printf("Memory allocation failed\n");
        return NULL;
    }


    library->count = count;
    library->person = malloc(count * sizeof(PersonInfo*));
    if (!library->person) {
        printf("Memory allocation failed\n");
        free(library);
        return NULL;
    }

    return library;
}


void Read_the_File(char* buffer, FILE* file, LibraryInfo* library) {
    int i = 0;
    while (fgets(buffer, 512, file) && i < library->count) {

        buffer[strcspn(buffer, "\n")] = '\0';

        PersonInfo* pers = malloc(sizeof(PersonInfo));
        if (!pers) {
            printf("Memory allocation for person failed!\n");
            break;
        }


        memset(pers, 0, sizeof(PersonInfo));

        char* context = NULL;
        char* token = strtok_s(buffer, ";", &context);


        if (token) {
            pers->fullname.Surname = _strdup(token);
        }
        token = strtok_s(NULL, ";", &context);
        if (token) {
            pers->fullname.Name = _strdup(token);
        }
        token = strtok_s(NULL, ";", &context);
        if (token) {
            pers->fullname.Patronymic = _strdup(token);
        }


        token = strtok_s(NULL, ";", &context);
        if (token) {
            if (strcmp(token, "Male") == 0) pers->gender = male;
            else if (strcmp(token, "Female") == 0) pers->gender = female;
            else pers->gender = unknown;
        }


        token = strtok_s(NULL, ";", &context);
        if (token) {
            pers->nationality = _strdup(token);
        }


        token = strtok_s(NULL, ";", &context);
        if (token) {
            pers->height = (float)atof(token);
        }


        token = strtok_s(NULL, ";", &context);
        if (token) {
            pers->weight = (float)atof(token);
        }


        token = strtok_s(NULL, ";", &context);
        if (token) {
            pers->date.Day = atoi(token);
        }
        token = strtok_s(NULL, ";", &context);
        if (token) {
            pers->date.Month = atoi(token);
        }
        token = strtok_s(NULL, ";", &context);
        if (token) {
            pers->date.Year = atoi(token);
        }


        token = strtok_s(NULL, ";", &context);
        if (token) {
            pers->phone = _strdup(token);
        }


        token = strtok_s(NULL, ";", &context);
        if (token) {
            pers->address.MailIndex = _strdup(token);
        }
        token = strtok_s(NULL, ";", &context);
        if (token) {
            pers->address.Country = _strdup(token);
        }
        token = strtok_s(NULL, ";", &context);
        if (token) {
            pers->address.Region = _strdup(token);
        }
        token = strtok_s(NULL, ";", &context);
        if (token) {
            pers->address.District = _strdup(token);
        }
        token = strtok_s(NULL, ";", &context);
        if (token) {
            pers->address.City = _strdup(token);
        }
        token = strtok_s(NULL, ";", &context);
        if (token) {
            pers->address.Street = _strdup(token);
        }
        token = strtok_s(NULL, ";", &context);
        if (token) {
            pers->address.House = _strdup(token);
        }
        token = strtok_s(NULL, ";", &context);
        if (token) {
            pers->address.Apartment = atoi(token);
        }


        library->person[i] = pers;
        i++;
    }
}


void Print_people(LibraryInfo* library) {
    for (int i = 0; i < library->count; i++) {
        PersonInfo* pers = library->person[i];
        printf("%d. %s %s %s ; ", i + 1,
            pers->fullname.Surname,
            pers->fullname.Name,
            pers->fullname.Patronymic);
        printf("Gender: %s ; ",
            pers->gender == male ? "Male" :
            (pers->gender == female ? "Female" : "Unknown"));
        printf("Nation: %s ; ", pers->nationality);
        printf("Height: %.2f ; Weight: %.2f\n", pers->height, pers->weight);
        printf("   Birth: %02d.%02d.%d ; Phone: %s\n",
            pers->date.Day, pers->date.Month, pers->date.Year, pers->phone);
        printf("   Address: %s, %s, %s, %s, %s, %s, %s, %d\n\n\n",
            pers->address.MailIndex, pers->address.Country,
            pers->address.Region, pers->address.District,
            pers->address.City, pers->address.Street,
            pers->address.House, pers->address.Apartment);
    }
}


void Cleaning_of_memories(LibraryInfo* library) {
    for (int i = 0; i < library->count; i++) {
        PersonInfo* pers = library->person[i];
        free(pers->fullname.Surname);
        free(pers->fullname.Name);
        free(pers->fullname.Patronymic);
        free(pers->nationality);
        free(pers->phone);
        free(pers->address.MailIndex);
        free(pers->address.Country);
        free(pers->address.Region);
        free(pers->address.District);
        free(pers->address.City);
        free(pers->address.Street);
        free(pers->address.House);

        free(pers);
    }
    free(library->person);
}