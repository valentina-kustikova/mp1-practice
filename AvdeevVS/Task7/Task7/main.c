#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "find.h"
#include "additional.h"
int main() {
  int njobless;
  jobless_people* jobless;
  njobless = Number_of_jobless();
  jobless = (jobless_people*)malloc(sizeof(jobless_people) * njobless);
  if (jobless == NULL) {
    printf("Memory is not find");
    return 1;
  }
  Filling_from_file(jobless);
  return 0;
}