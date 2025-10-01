#include <stdio.h>
#include <locale.h>

#define LINE 512
#define EPS (1e-8)

/*
* ��� - 600 ��/�3 = 600 / 1000000 = 0.0006 ��/��3
* ��� - 750 ��/�3 = 750  / 1000000 = 0.00075 ��/��3
* ������ - 690 ��/�3 = 690 / 1000000 = 0.00069 ��/��3
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
		printf("������� ������ h, ������ w � ������� d � �����������: ");
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

	float mass = p_dvp * h * w * 0.5f + 
		2 * p_dsp * h * d * 1.5f +
		2 * p_dsp * w * d * 0.15f +
		    p_wood * h * w * 1.f +
		    p_dsp * w * 0.15f;

	return 0;
}