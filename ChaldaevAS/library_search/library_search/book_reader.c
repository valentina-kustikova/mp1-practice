#define _CRT_SECURE_NO_WARNINGS
#include "book_reader.h"

void trim_string(char* str) {
    char* end;

    while (*str == ' ' || *str == '\t' || *str == '\n') {
        str++;
    }

    end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r')) {
        end--;
    }
    *(end + 1) = '\0';
}

int read_books_from_file(const char* filename, Book books[], int max_books) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("ERR: Ошибка открытия файла %s\n", filename);
        return -1;
    }

    char line[MAX_STR_LEN * 4];
    int book_count = 0;
    int line_num = 0;

    printf(">Чтение файла\n");

    while (fgets(line, sizeof(line), file) && book_count < max_books) {
        line_num++;
        Book* book = &books[book_count];
        char year_str[MAX_STR_LEN];

        line[strcspn(line, "\n")] = 0;

        if (strlen(line) == 0) {
            continue;
        }

        printf("Строка %d: %s\n", line_num, line);

        int parsed = sscanf(line, "%[^;];%[^;];%[^;];%s",
            book->authors,
            book->title,
            book->publisher,
            year_str);

        if (parsed == 4) {
            trim_string(book->authors);
            trim_string(book->title);
            trim_string(book->publisher);

            book->year = atoi(year_str);

            printf(">Авторы: %s\n", book->authors);
            printf(">Название: %s\n", book->title);
            printf(">Издательство: %s\n", book->publisher);
            printf(">Год: %d\n", book->year);

            book_count++;
        }
        else {
            printf("ERR: Ошибка парсинга строки (прочитано %d полей из 4)\n", parsed);
        }
    }

    fclose(file);
    printf("Всего прочитано книг: %d\n", book_count);
    return book_count;
}