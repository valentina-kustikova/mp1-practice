#ifndef AUXILIARY_H
#define AUXILIARY_H

struct book* file_to_struct(const char* file_name, int* count);
void free_memory(struct book* books, int count);

#endif