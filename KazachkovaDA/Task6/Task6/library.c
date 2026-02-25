//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <locale.h>
//#include "library.h"

//struct book* find_books_by_author(struct book* books, int count, const char* author_request)
//{
//    int found = 0;
//
//    for (int i = 0; i < count; i++)
//    {
//
//        if (books[i].author && strstr(books[i].author, author_request))//strstr - указатель на первое вхождение подстроки в строку
//        {
//            printf("Найдена книга:\n");
//            printf("Автор: %s\n", books[i].author);
//            printf("Название: %s\n", books[i].title);
//            printf("Издательство: %s\n", books[i].publisher);
//            printf("Год: %d\n\n", books[i].publishing_year);
//
//            found++;
//        }
//    }
//
//    if (found == 0)
//    {
//        printf("Книги не найдены\n");
//        return NULL;
//    }
//    return books;
//}
