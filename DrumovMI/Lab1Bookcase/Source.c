#include <stdio.h>
#include <locale.h>

#define LINE 512

/*
* ��� - 800 ��/�3
* ��� - 735 ��/�3
* ������ - 700 ��/�3
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
		printf("������� ������ h, ������ w � ������� d � �����������: ");
		fgets(line, LINE, stdin);
		sscanf_s(line, "%f %f %f", &h, &w, &d);
	} while (h <= 0 || w <= 0 || d <= 0);

	// �������� ������������ �������� ������ ������������
	if (h < 180 || 220 < h) {
		printf("������ ������ ���������� � ��������� �� 180 �� 220 ��.");
		correct_input = 0;
	}

	if (w < 80 || 120 < w) {
		printf("������ ������ ���������� � ��������� �� 80 �� 120 ��.");
		correct_input = 0;
	}

	if (d < 50 || 90 < d) {
		printf("������� ������ ���������� � ��������� �� 50 �� 90 ��.");
		correct_input = 0;
	}

	if (!correct_input) {
		printf("������������ ����.");
		return 0;
	}

	shelves_count = ((int) h <= 200) ? 4 : 5;

	m_back = p_dvp * h * w * 0.5f;
	m_side =  p_dsp * h * d * 1.5f;
	m_cover = p_dsp * w * (d + 1.5f) * 1.5f;
	m_doors = p_wood * h * w * 1.f;
	m_shelf = p_dsp * (w - 3.f) * d * 1.5f;

	mass = (m_back + 2 * m_side + 2 * m_cover + m_doors + shelves_count * m_shelf) / 1000000.f;

	printf("����� ����� � ��������� ���������������� ����� %f ��", mass);

	return 0;
}