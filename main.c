#include <stdio.h>
#include <math.h>

int main()
{
	float x1, y1, r1, x2, y2, r2, L;
	printf("Insert first circle's metrics (coordinates and radius)\n");
	scanf("%f %f %f", &x1, &y1, &r1);
	printf("Insert second circle's metrics (coordinates and radius)\n");
	scanf("%f %f %f", &x2, &y2, &r2);

	L = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	if (x1 == x2 && y1 == y2)
	{
		if (r1 == r2)
		{
			printf("Circles are equal");
			return 0;
		}
		else
		{
			printf("Circles are concentric");
			return 0;
		}
	}

	else if (L > r1 + r2)
	{
		printf("Circles don't intersect and aren't situated inside each other");
		return 0;
	}

	else if (L == r1 + r2)
	{
		printf("Circles have 1 point of intersection and aren't situated inside each other");
		return 0;
	}

	else if (L < r1 + r2)
	{
		if (L < r1 || L < r2)
		{
			if (L == r1 - r2 || L == r2 - r1)
			{
				printf("Circles have 1 point of intersection while one of them is inside of another");
				return 0;
			}
			else if (L < r1 - r2 || L < r2 - r1)
			{
				printf("Circles don't intersect while one of them is inside of another");
				return 0;
			}
			else
			{
				printf("Circles have 2 points of intersection while one of them is inside of another");
				return 0;
			}
		}
		else
		{
			printf("Circles have 2 points of intersection and aren't situated inside each other");
			return 0;
		}
	}
}
