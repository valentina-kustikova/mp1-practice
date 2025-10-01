#include <stdio.h>
#include <locale.h>

#define LINE 512
#define EPS (1e-8)

/*
* ДСП - 600 кг/м3 = 600 / 1000000 = 0.0006 кг/см3
* ДВП - 750 кг/м3 = 750  / 1000000 = 0.00075 кг/см3
* Дерево - 690 кг/м3 = 690 / 1000000 = 0.00069 кг/см3
*/
int main() {
	const float p_dsp = 0.0006f, p_dvp = 0.00075f, p_wood = 0.00069f;

	float h, w, d;
	char line[LINE];
	int correct_input = 1;

	setlocale(LC_ALL, "ru");
	setlocale(LC_NUMERIC, "C");

	do {
		fgets(line, LINE, stdin);
		printf("Введите высоту h, ширину w и глубину d в сантиметрах: ");
		sscanf_s(line, "%f %f %f", &h, &w, &d);
	} while (h <= 0 || w <= 0 || d <= 0);

	// проверка соответствия введённых данных ограничениям
	if (h < 180 || 220 < h) {
		printf("Высота должна находиться в диапазоне от 180 до 220 см.");
		correct_input = 0;
	}

	if (w < 80 || 120 < w) {
		printf("Ширина должна находиться в диапазоне от 80 до 120 см.");
		correct_input = 0;
	}

	if (d < 50 || 90 < d) {
		printf("Глубина должна находиться в диапазоне от 50 до 90 см.");
		correct_input = 0;
	}

	if (!correct_input) {
		printf("Некорректный ввод.");
		return 0;
	}

	float mass = p_dvp * h * w * 0.5f + 
		2 * p_dsp * h * d * 1.5f +
		2 * p_dsp * w * d * 0.15f +
		    p_wood * h * w * 1.f +
		    p_dsp * w * 0.15f;

	return 0;
}