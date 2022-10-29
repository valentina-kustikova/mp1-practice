#include <math.h>
#include <stdio.h>

#define dcp 0.0008
#define dvp 0.0007
#define wood 0.00065

/*
Задача про объем шкафа
Плотность дерева - 0.00065 кг/см3
Плотность дсп - 0.0008 кг/см3
Плотность двп - 0.0007 кг/см3
*/

int main() {
    //Ввод переменных
    float h, b, d, m, k, m_backwall, m_sidewall, m_topwall, m_doors, m_shelfs; 

    //Запрос переменных 
    printf("\tEnter the height(180-220cm), width(80-120cm), deepth(50-90cm)\n");
    do{
        scanf("%f%f%f", &h, &b, &d); 
    }while(( h < 180 ) || ( h > 220) || ( b < 80 ) || ( b > 120 ) || ( d < 50 ) || ( d > 90 ));

    //Количество полок  
    if( h < 200 ) k = 4;
    else k = 5;
    
    //Ввод формул
    m_backwall = dvp * h * b * 0.5;
    m_sidewall = dcp * h * d * 1.5;
    m_topwall = dcp * b * d * 1.5;
    m_doors = wood * b * h;
    m_shelfs = k * dcp * b * d;
    m = m_backwall + 2 * m_sidewall + 2 * m_topwall + m_doors + m_shelfs;

    //Вывод ответа нна экран
    printf("Weight is %.0f ", m);
    printf("kg\n");

    system("pause");
    return 0;
}


