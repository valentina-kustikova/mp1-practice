#ifndef AUXILIARY_H
#define AUXILIARY_H

struct book* file_to_struct(const char* file_name, int* count);
void to_lowercase(const char* srs, char* dest);
void print_found_books(struct book* found_books, int found_count);
void free_memory(struct book* books, int count);

#endif