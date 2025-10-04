#include <stdio.h>
int main() {
  int i;
  int max = -1;
  float weight;
  float h;
  float w;
  float d;
  float thick_back_wall = 0.5;
  float thick_side_wall = 1.5;
  float thick_lid = 1.5;
  float thick_door = 1.0;
  float thick_shelf = 1.5;
  float dens_dsp = 0.55;
  float dens_dvp = 0.75;
  float dens_oak = 0.9;
  do {
    scanf_s("%f", &h);
  } while (h<180.0||h>220.0);
  do {
    scanf_s("%f", &w);
  } while (w < 80.0 || w>120.0);
  do {
    scanf_s("%f", &d);
  } while (d < 50.0 || d>90.0);
  for (i = 0; i < 100; i++) {
    if (h > i * (thick_shelf + 40.0)) {
      if (max < i) {
        max = i;
      }
    }
    else {
      break;
    }
  }
  weight = (dens_dvp * h * w * thick_back_wall + dens_dsp * 2 * (h * d * thick_side_wall +
    w * d * thick_lid) + dens_oak * w * h * thick_door + dens_dsp * max * thick_side_wall * d * (w - thick_side_wall*2))/1000;
  printf("weight_cabinet=%f", weight);
  return 0;
}