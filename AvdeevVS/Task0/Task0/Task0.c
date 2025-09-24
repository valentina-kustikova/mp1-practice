#include <stdio.h>
#include <math.h>
int main() {
  float x1, x2, y1, y2, r1, r2;
  scanf_s("%f%f%f%f%f%f", &x1, &y1, &r1, &x2, &y2, &r2);
  float s = sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  if ((r1 <= 0) || (r2 <= 0)) {
    printf("necorr radius");
    return 1;
  }
  if ((r1 == r2) && (x1 == x2) && (y1 == y2)) {
    printf("sovpadayut");
    return 0;
  }
  if ((r1 + r2) < s) {
    printf("ne peresekautsa");
    return 0;
  }
  if ((r1 + r2) == s) {
    printf("casanie vnesh");
    return 0;
  }
  if (fabs(r1 - r2) == s) {
    printf("casanie vnutr");
    return 0;
  }
  if ((s < (r1 + r2)) && (s > fabs(r1 - r2))) {
    printf("peresechenye");
    return 0;
  }
  if (s < fabs(r1 - r2)) {
    printf("odna v drugoi bez casanii");
    return 0;
  }
  return 0;
}