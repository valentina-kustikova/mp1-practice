#include <stdio.h>
#include <locale.h>

int main() {

	float m_side, m_cap, m_back, m_shelf, m_door, po_DVP, po_DSP, po_dereva, a, b, c;

	float h, w, d;

	a = 0.5f, b = 1.5f, c = 1.f, po_DVP = 0.000735f, po_DSP = 0.0008f, po_dereva = 0.0007f;

	do
	{
		printf_s("Vvedite h ");

		scanf_s("%f", &h);

	}

	while (h > 220.f || h < 180.f);

	do
	{
		printf_s("Vvedite w ");

		scanf_s("%f", &w);

	}

	while (w > 120.f || w < 80.f);

	do
	{
		printf_s("Vvedite d ");

		scanf_s("%f", &d);

	}

	while (d > 90.f || d < 50.f);

	m_back = (h + b * 2.f) * w * a * po_DVP;
	m_side = h * d * b * 2.f * po_DSP;
	m_cap = w * d * b * 2.f * po_DSP;
	m_door = (h + 2.f * b) * w * c * po_dereva;
	m_shelf = b * (w - 2.f * b) * d * ((((int)h) / 40) - 1) * po_DSP;


	printf_s("Massa = %f", m_back + m_side + m_cap + m_door + m_shelf);

	return 0;

}
