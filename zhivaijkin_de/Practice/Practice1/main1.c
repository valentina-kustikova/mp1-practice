#include<stdio.h>
#include<math.h>
#include<locale.h>

void main()
{
    float n;
    float m; //Масса
    float hz, wz; //Задняя стенка
    float db; //Боковина
    float dsp, dvp, wood, tdsp, tdvp, twood; //Плотности и толщина
    float Vz, Vd, Vb, Vtop, Vn; //Объемы
    tdsp=0.015;
    tdvp=0.005;
    twood=0.01;
    setlocale (LC_CTYPE,"rus");
    printf("Высота шкафа (от 180см до 220см) =");
    scanf("%f", &hz);
    printf("Ширина шкафа (от 80см до 120см) =");
    scanf("%f", &wz);
    printf("Глубина боковины (от 50см до 90см) =");
    scanf("%f", &db);
    printf("Введите плотность ДСП\n");
    scanf("%f", &dsp);
    printf("Введите плотность ДВП\n");
    scanf("%f", &dvp);
    printf("Введите плотность дерева\n");
    scanf("%f", &wood);
    if ((hz < 180)||(hz > 220)||(db < 50)||(db > 90)||(wz < 80)||(wz > 120))
    {
        printf("Значение высоты (ширины, глубины) находится вне диапазона");
        return;
    }
	hz = hz / 100;
	db = db / 100;
	wz = wz / 100;
    if ((dsp <= 0)||(dvp <= 0)||(wood <= 0))
    {
        printf("Некорректный ввод плотности");
        return;
    }
    //Расчет количества и толщины полок
    n=((hz - 2 * 0.015) / (0.4 + 0.015) * (wz - 2 * 0.015) * (db - 0.005));
    //Расчет объемов
    Vz=(hz*wz*tdvp);
    Vd=(hz*wz*twood);
    Vb=(hz*db*tdsp);
    Vtop=(wz*db*tdsp);
    Vn=(n*(db*wz*tdsp));
    //Расчет массы
    m=(dsp*(Vb+Vtop+Vn)+(dvp*Vz)+(wood*Vd));
    printf("Масса шкафа (кг) = %f ", m);
    return;
}