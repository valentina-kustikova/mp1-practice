#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "find.h"
#include "additional.h"
int main(int argc, char** argv) {
  int nrequired_indexes = 0;
  int* required_indexes = NULL;
  jobless_base jobless;
  if (argc < 2) {
    printf("Fatal:Incorrect parameters!");
    return 1;
  }
  jobless.njobless = Number_of_jobless(argv[1]);
  jobless.persons = (jobless_people*)malloc(sizeof(jobless_people) * jobless.njobless);
  if (jobless.persons == NULL) {
    printf("Fatal_jobless ---> couldn't allocate memory");
    return 1;
  }
  Filling_from_file(jobless, argv[1]);
  Finding_right_options(jobless, &nrequired_indexes, &required_indexes);
  Print_of_result(jobless, required_indexes, nrequired_indexes);
  Clearing_memory(jobless, required_indexes);
  return 0;
}