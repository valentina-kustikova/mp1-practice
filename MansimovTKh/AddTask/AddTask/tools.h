#ifndef _TOOLS_H
#define _TOOLS_H

#define BUFFER_SIZE 1024

void read_data(const char* filename, PersonsLibrary* lib_persons);
void print_sort_person(PersonsLibrary* lib_persons);
void free_persons_lib(PersonsLibrary* lib_persons);

#endif