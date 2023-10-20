#include<stdio.h>
#include<math.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL, "Russian");
	double h = 0, w = 0, d = 0;
	float pld = 720, pldvp = 820, pldsp = 800;
	printf("Введите значение высоты ширины и глубины шкафа: ");
	//контроль ввода
	do {
		scanf("%lf %lf %lf", &h, &w, &d);
		if (h < 180 || h>220 || w < 80 || w>120 || d < 50 || d>90) {
			printf("Некорректные данные \n");
			printf("Введите значение высоты ширины и глубины шкафа: ");
		}
	} while (h < 180 || h>220 || w < 80 || w>120 || d < 50 || d>90);
	//перевод в си
	h = h / 100.0;
	w /= 100.0;
	d /= 100.0;
	double td = 1.0 / 100.0;
	double tdsp = 15.0 / 1000.0;
	double tdvp = 5.0 / 1000.0;

	//расчитываем массу элементов шкафа
	double bokov = h * d * tdsp * pldsp , nst= h * w * tdvp * pldvp , nvn = w * d * tdsp * pldsp , dveri = w * h * td * pld ; //2*боковины 2*накл верхн и нижн ДВЕРИ УЖЕ 2
	//printf("%lf %lf %lf %lf \n", bokov, nst, nvn, dveri);
	// считаем количество полок и массу одной полки массу
	int kp = h/(tdsp + 0.4);
	double mp = (w - 2 * tdsp) * d * tdsp * pldsp;
	//printf("%lf \n", mp);
	//расчитываем массу шкафа
	double massa = bokov * 2 + nst + nvn * 2 + dveri + mp * kp ;
	
	printf("Масса шкафа = %lf ", massa);
	printf("кг.");

	return 0;
}