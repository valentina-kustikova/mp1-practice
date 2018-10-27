#include<stdio.h>
void main() {
  double pl_DVP, pl_DSP, pl_d, m, m_stenka, m_2bokovini, m_2krishi, m_2dveri, m_polki;
  double w, h, d;
  printf("Vvedite (v m): w (ot 0.8 do 1.2), h (ot 1.8 do 2.2), d (ot 0.5 do 0.9)\n");
  scanf_s("%lf %lf %lf", &w, &h, &d);
  printf("Vvedite (v kg/(m^3)): pl_DVP, pl_DSP, pl_d\n");
  scanf_s("%lf %lf %lf", &pl_DVP, &pl_DSP, &pl_d);
  if ((w < 0.8) || (w > 1.2) || (h < 1.8) || (h > 2.2) || (d < 0.5) || (d > 0.9) || (pl_DVP <= 0) || (pl_DSP <= 0) || (pl_d <= 0)) 
  {
    printf("Vvedeni nepravilnie parametri\n");
    return; 
  }
  m_stenka = (h * w * 0.005) * pl_DVP;
  m_2bokovini = 2 * (h * d * 0.015) * pl_DSP;
  m_2krishi = 2 * (w * d * 0.015) * pl_DSP;
  m_2dveri = 2 * (h * (w / 2) * 0, 01) * pl_d;
  m_polki = ((h / 0.4) * w * d * 0.015) * pl_DSP;
  m = m_stenka + m_2bokovini + m_2krishi + m_polki + m_2dveri;
  printf("%lf kg\n", m);
}