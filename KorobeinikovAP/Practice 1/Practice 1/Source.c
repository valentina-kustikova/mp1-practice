#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	float Qdsp, Qdvp, Q, h, w, d, t_back, t_covers, t_sides, t_door, t_shelves, m_back, m_sides, m_covers, m_door, k_shelves, count, m_shelves, res;
	float o1 = 1.8, o2 = 2.2, o3 = 0.8, o4 = 1.2, o5 = 0.5, o6 = 0.9;
	Qdsp = 800;
	Qdvp = 750;
	Q    = 640;
	float eps = 0.00000001;
	printf("Input h ");
	scanf("%f", &h);
	if (((fabs(h - o1) > eps) && (h < o1 )) || ((fabs(h - o2) > eps) && (h > o2 ))) {
		printf("Incorrect data,  1.8 <= h <= 2.2 ");
		return 0;
	}
	printf("Input w ");
	scanf("%f", &w);
	if (((fabs(w - o3) > eps) && (w < o3)) || ((fabs(w - o4) > eps) && (w > 04))) {
		printf("Incorrect data,  0.8 <= w <= 1.2 ");
		return 0;
	}
	printf("Input d ");
	scanf("%f", &d);
	if (((fabs(d - o5) > eps) && (d < o5)) || ((fabs(d - o6) > eps) && (d > o6))) {
		printf("Incorrect data,  0.5 <= d <= 0.9 ");
		return 0;
	}
	t_back    = 0.005;
	t_sides   = 0.015;
	t_covers  = 0.015;
	t_door    = 0.01;
	t_shelves = 0.015;
	m_back    = Qdvp * (t_back * h * w);
	m_sides   = 2 * (Qdsp * (t_sides * h * d));
	m_covers  = 2 * (Qdsp * (t_covers * (w-0.03) * d)); 
	m_door    = Q * (t_door * h * w);
	k_shelves = h / (0.415) - 1.03;
	count = (int)k_shelves;
	m_shelves = count * (Qdsp * (t_shelves * (w-0.03) * d)); 
	res       = m_back + m_covers + m_door + m_shelves + m_sides;
	printf ("mass = %f ", res);
}