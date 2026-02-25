#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "auxiliary.h"
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Rus");
    int n = countbooks("task6.txt");
    Book* bss = createbooks("task6.txt", n);
    int i = 0;
    int f = 0;
    char author[256];
    printf("Введите ФИО автора (пример: L. N. Tolstoy) : \n");
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = '\0';
    for (; i < n; i++)
    {
        if (findByauthor(&bss[i], author))
        {
            f = 1;
            prbook(&bss[i]);
        }
    }
    if (f == 0)
        printf("Книг этого автора нет в картотеке");
    freeb(bss, n);
    return 0;
}
