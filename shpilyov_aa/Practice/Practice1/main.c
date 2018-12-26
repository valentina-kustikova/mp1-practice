#include<stdio.h>
#include<locale.h>
void main()
{
	setlocale(LC_ALL, "Rus");
	int p_dcp = 750, p_dvp = 950, p_derevo = 550, kolvo_polok;
	float M, m_zad_stenok, m_bok_stenok, m_krishok, m_dveri, m_polok, h, w, d, tol_1 = 0.005, tol_2 = 0.015, tol_3 = 0.01;
	printf("Введите высоту шкафа,(м): ");
	scanf("%f",&h);
	printf("Введите ширину шкафа,(м): ");
	scanf("%f", &w);
	printf("Введите глубину шкафа,(м): ");
	scanf("%f", &d);
	if ((h >= 1.8f) && (h < 2))
		kolvo_polok = 4;
	else if ((h >= 2) && (h <= 2.2f))
		kolvo_polok = 5;
	else
	{
		printf("Высота указана неверно!");
		return;
	}
	if ((h >= 1.8f) && (h <= 2.2f) && (w >= 0.8f) && (w <= 1.2f) && (d >= 0.5f) && (d <= 0.9f))
	{
		m_zad_stenok = 2 * p_dvp * h * w * tol_1;
		m_bok_stenok = 2 * p_dcp * h * d * tol_2;
		m_krishok = 2 * p_dcp * w * d * tol_2;
		m_dveri = 2 * p_derevo * h * w * tol_3;
		m_polok = kolvo_polok * p_dcp * w * d * tol_2;
		M = m_zad_stenok + m_bok_stenok + m_krishok + m_dveri + m_polok;
		printf("Масса шкафа = %.2f кг", M);
	}
	else
	{
		printf("Неверные данные!");
		return;
	}
}