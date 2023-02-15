#include <stdio.h>

void main() {

	float h, w, d; // 180 <= h, w <= 220 sm, 50 <= d <= 90 sm
	float th_DSP = 0.015f, th_DVP = 0.005f, th_door = 0.01f; // m
	float back_wall, side_walls, caps, doors, shelves; // cm
	float q_tree = 900.0f, q_DSP = 800.0f, q_DVP = 800.0f; // kg / m^3
	int n; // amount of shelves

	printf("Input h, w, d: \n");
	printf("(180 <= h, w <= 220 sm, 50 <= d <= 90 sm)\n");
	scanf("%f %f %f", &h, &w, &d);

	if (h < 180 || h > 220 || w < 180 || w > 220 || d < 50 || d > 90) {
		printf("Incorrect data.");
		return;
	}
	else {

		// amount of shelves
		n = (int)(h / 40.f);

		// sm > m
		h = h / 100.f;
		w = w / 100.f;
		d = d / 100.f;

		// kg
		back_wall = q_DVP * h * w * th_DVP;
		side_walls = q_DSP * h * d * th_DSP * 2;
		caps = q_DSP * (w - 2 * th_DSP) * (d - th_DVP) * th_DSP * 2;
		doors = q_tree * h * w * th_door;
		shelves = q_DSP * (w - 2 * th_DSP) * (d - th_DVP) * th_DSP * n;

		printf("%f", back_wall + side_walls + caps + doors + shelves);
	}
}