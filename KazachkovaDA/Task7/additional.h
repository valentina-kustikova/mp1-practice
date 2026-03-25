#ifndef	ADDITIONAL_H
#define ADDITIONAL_H

phrase_library* file_to_struct(const char* file_name, int* count);//должна возвращать струкртуру-бибилиотеку
void to_lowercase(const char* srs, char* dest);
void print_found_quotes(phrase_library* library);
void free_memory(phrase_library* library);//должна очищать память структуры-библиотеки

#endif