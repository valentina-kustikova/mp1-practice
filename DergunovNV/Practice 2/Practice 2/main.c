#include <stdio.h>
#include <locale.h>
int main() {
    double h, w, d;
    setlocale(LC_ALL, "ru");
    int p_tree = 640, p_dvp = 700, p_dsp = 800; //dvp = 700 dsp 800 tree 640
    double t_dvp = 5.0 / 1000.0, t_dsp = 15.0 / 1000.0, t_tree = 1.0 / 100.0;
    do {
        printf("¬ведите высоту, ширину и глубину: ");
        scanf("%lf %lf %lf", &h, &w, &d);
        if ((h < 180 || h > 220) || (w < 80 || w > 120) || (d < 50 || d > 90)){
            printf("¬ведены некорректные данные\n");
        }
    } while (((h < 180 || h > 220) || (w < 80 || w > 120) || (d < 50 || d > 90)));
    h = h / 100.0;
    w = w / 100.0;
    d = d / 100.0;
    double massa = h * w * t_dvp * p_dvp + 2 * (h * d * t_dsp * p_dsp) + 2 * (t_dsp * w * d * p_dsp) + (h * w * t_tree * p_tree);
    int countp = h / (0.4 + t_dsp);
    double m_polki = (w - 2 * t_dsp) * d * t_dsp * p_dsp;
    double massa1 = massa + m_polki * countp;
    printf("%lf", massa1);
    return 0;
    }

