#define D 10
#define S 100
#define P 500
#define T 1000
typedef struct{
  char writer[S];
  char name[T];
  char publish[P];
  char year[D];
} book;
void Search(int* req, book* num, int n);