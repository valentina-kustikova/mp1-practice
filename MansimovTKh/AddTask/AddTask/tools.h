#ifndef _TOOLS_H
#define _TOOLS_H

#define BUFFER_SIZE 1024

void read_data(const char* filename, person_info** person, int* lines);
void print_sort_person(person_info* person, int n);

#endif