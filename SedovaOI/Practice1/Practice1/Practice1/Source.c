//табличные значения для ДСП: 650 кг/м^3, ДВП: 800 кг/м^3, дерева: 550 кг/м^3//
#include<stdio.h>
int main()
{
	double h, w, d, a, massa_zadnya_chast, massa_dverey, massa_polok, massa_verha_and_niza, massa_bokovyih_sten, massa_shcafa;
	int n = 0;
	printf("Vvedite znachenia v sm:"); //запрос на ввод размеров
	scanf("%lf %lf %lf", &h, &w, &d);
	if ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90)) // проверка на корректность ввеедённых данных 
	{
		printf("Nekorrektnyi vvod");
		return 1;
	}
	a = h - 3; //высота боковых стен 
	h *= 0.01; //перевод в метры 
	w *= 0.01;
	d *= 0.01;
	{
		massa_zadnya_chast = h * w * 0.005 * 800; //масса задней части шкафа
		massa_dverey = h * w * 0.01 * 550; //масса дверей
		while (a >= 40) //цикл на подсчёт количества полок
		{
			a -= 40;
			n++;
		}
		massa_polok = n * (w - 0.03) * d * 650 * 0.015; //масса полок
		massa_verha_and_niza = 2 * d * w * 0.015 * 650; //масса накладных верха и низа
		massa_bokovyih_sten = 2 * (h - 0.03) * d * 0.015 * 650; //масса боковых стен
		massa_shcafa = massa_zadnya_chast + massa_dverey + massa_polok + massa_verha_and_niza + massa_bokovyih_sten; //подсчёт общей массы шкафа
		printf("%lf", massa_shcafa);

	}
	return 0;
}
//пояснение по сборке шкафа: верх и низ накладываем на боковые стенки, поэтому из высоты вычитаем толщину обеих крышек, от общей ширины вычитаем толщину стенок и получаем ширину