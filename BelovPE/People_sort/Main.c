#include "Work_with_data.h"

// в C++ использовать тоже обычный enum и memset() можно использовать


int main(int argc, char** argv) {
    int count = 0;
    char buffer[512];    
    char* filename;


    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    filename = argv[1];


    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("File not found\n");
        return 1;
    }


    count = Count_the_data(file);


    LibraryInfo* library = Create_the_library(count);
    if (!library) {
        printf("Error of library\n");
        return 1;
    }
    rewind(file);


    Read_the_File(buffer, file, count, library);
    fclose(file);
    

    Sort_with_choise(library);

    
    Print_people(library);
    

    Cleaning_of_memories(library);
    printf("Memory is free\n");

    
    return 0;
}