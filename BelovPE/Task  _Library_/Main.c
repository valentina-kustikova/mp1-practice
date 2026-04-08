#include "library.h"
#include "auxiliary.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    printf("Библиотека запущена\n");

    FILE* f = fopen("C:\\Users\\peter\\OneDrive\\Desktop\\books.txt", "r");

    if (f == NULL) {
        printf("Файл не найден!\n");
        return 1;
    }

    readFile(f);

    if (lib != NULL) {
        search();
        freeLibrary();
    }

    printf("Конец выполнения\n");
    return 0;
}