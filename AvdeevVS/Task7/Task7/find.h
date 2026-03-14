#ifndef find
#define find
#define S 100
#define P 50
#define D 200
#define T 1000
typedef struct {
  int day;
  int month;
  int year;
} birth1;
typedef struct {
  char post[S];
  char place[S];
  char reason[P];
} last_job1;
typedef struct {
  char phone[P];
  char adress[S];
} contact1;
typedef struct {
  char name[S];
  birth1 birth;
  char craft[P];
  char education[D];
  last_job1 last_job;
  char family[P];
  contact1 contact;
} jobless;
#endif