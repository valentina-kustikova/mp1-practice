#include<stdio.h>
#include<math.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL, "");
	float h_cm, w_cm, d_cm;//��

	float th_dvp = 0.005;//�� � �
	float th_dsp = 0.015;
	float th_wood = 0.01;

	float p_dvp = 720.0;  //��/�^3
	float p_dsp = 620.0;
	float p_wood = 850.0;

	printf("������� ������ h: ");
	scanf_s("%f", &h_cm);
	printf("������� ������ w: ");
	scanf_s("%f", &w_cm);
	printf("������� ������� d: ");
	scanf_s("%f", &d_cm);

	if (h_cm < 180 || h_cm>220) {
		printf("������� ������ ��������");
		return 0;
	}

	if (d_cm < 50 || d_cm>90) {
		printf("������� ������ ��������");
		return 0;
	}

	if (w_cm < 80 || w_cm>120) {
		printf("������� ������ ��������");
		return 0;
	}

	float h = h_cm / 100;
	float w = w_cm / 100;
	float d = d_cm / 100;

	int n_shelves = (int)floor(h_cm / 40.0);

	float vol_back = w * h * th_dvp;
	float vol_sides = 2 * (h * d * th_dsp);
	float vol_roof_botton = 2 * (d * w * th_dsp);
	float vol_doors = 2 * (h * w * th_wood);
	float vol_shelves = n_shelves * (d * w * th_dsp);

	float m_back = vol_back * p_dvp;
	float m_sides = vol_sides * p_dsp;
	float m_roof_botton = vol_roof_botton * p_dsp;
	float m_doors = vol_doors * p_wood;
	float m_shelves = vol_shelves * p_dsp;

	float m = m_back + m_sides + m_roof_botton + m_doors + m_shelves;

	printf("����� ����� (��) = %.2f", m);
	return 0;
}