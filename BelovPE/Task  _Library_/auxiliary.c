#include "auxiliary.h"
#include "library.h"

void freeLibrary() {
    if (lib == NULL) return;  // lib видна благодар€ extern

    for (int i = 0; i < bookCount; i++) {  // bookCount видна благодар€ extern
        free(lib[i].authors);
        free(lib[i].name);
        free(lib[i].publisher);
    }

    free(lib);
    lib = NULL;
    bookCount = 0;

    printf("ѕам€ть освобождена\n");
}