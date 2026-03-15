#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <windows.h>
#include "find.h"
#include "additional.h"
int main(int argc, char** argv) {
  int njobless;
  int nrequired_indexes = 0;
  int* required_indexes = NULL;
  jobless_people* jobless;
  /*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,
    FOREGROUND_GREEN);*/
  if (argc < 2) {
    printf("Fatal:Incorrect parameters!");
    return 1;
  }
  njobless = Number_of_jobless(argv[1]);
  jobless = (jobless_people*)malloc(sizeof(jobless_people) * njobless);
  if (jobless == NULL) {
    printf("Fatal_jobless ---> couldn't allocate memory");
    return 1;
  }
  Filling_from_file(jobless, argv[1]);
  Finding_right_options(jobless, njobless, &nrequired_indexes, &required_indexes);
  Print_of_result(jobless, required_indexes, nrequired_indexes, njobless);
  Clearing_memory(jobless, njobless, required_indexes);
  return 0;
}