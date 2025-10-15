#include <stdio.h>
#include <locale.h>

#define LINE 512

/*
* ДСП - 800 кг/м3
* ДВП - 735 кг/м3
* Дерево - 700 кг/м3
*/

int main() {
	const float p_dsp = 800.f, p_dvp = 735.f, p_wood = 700.f;

	float h, w, d, m_back, m_side, m_cover, m_doors, m_shelf, mass;
	int shelves_count;
	char line[LINE];
	int correct_input = 1;

	setlocale(LC_ALL, "ru");
	setlocale(LC_NUMERIC, "C");

	do {
		printf("Введите высоту h, ширину w и глубину d в сантиметрах: ");
		fgets(line, LINE, stdin);
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

	shelves_count = ((int) h <= 200) ? 4 : 5;

	m_back = p_dvp * h * w * 0.5f;
	m_side =  p_dsp * h * d * 1.5f;
	m_cover = p_dsp * w * (d + 1.5f) * 1.5f;
	m_doors = p_wood * h * w * 1.f;
	m_shelf = p_dsp * (w - 3.f) * d * 1.5f;

	mass = (m_back + 2 * m_side + 2 * m_cover + m_doors + shelves_count * m_shelf) / 1000000.f;

	printf("Масса шкафа с введёнными характеристиками равна %f кг", mass);

	return 0;
}