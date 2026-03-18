#ifndef	ADDITIONAL_H
#define ADDITIONAL_H

struct quote* file_to_struct(const char* file_name, int* count);//должна возвращать струкртуру-бибилиотеку
void to_lowercase(const char* srs, char* dest);
void print_found_quotes
(struct quote* found_quotes, int found_count);
void free_memory(struct quote* quotes, int count);//должна очищать память структуры-библиотеки

#endif