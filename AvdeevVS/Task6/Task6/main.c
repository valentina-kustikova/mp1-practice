#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "library.h"
#include "auxiliary.h"

int main(int argc,char** argv) {
  //D.Protsko   E.Shklarsky
  int nBooks, nAuthorBooks;
  char stop[5] = "stop";
  book* books;
  int* indecesAuthorBooks = NULL;
  if (argc < 2) {
      printf("Incorrect parameters");
      return 1;
  }
  nBooks = get_books_num(argv[1]);
  books = (book*)malloc(sizeof(book) * nBooks);
  read_books(books, argv[1]);
  while (1) {
    char author[MAX_NAME_LEN];
    printf("Input author name or stop to exit:");
    scanf("%s", author);
    if (strcmp(author, stop) == 0) {
      printf("The end!");
      break;
    }
    indecesAuthorBooks = NULL;
    Search(books, nBooks, author, &indecesAuthorBooks, &nAuthorBooks);
    print_books(books, nBooks, indecesAuthorBooks, nAuthorBooks);
    if (indecesAuthorBooks != NULL) {
        free(indecesAuthorBooks);
    }
  }
  free(books);  
  return 0;
}