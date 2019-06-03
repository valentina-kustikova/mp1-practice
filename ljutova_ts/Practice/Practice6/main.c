#include "Vector.h" 

void main()
{
	Vector v1, v2, v3, s, m, sc;
	float l;
	v1 = fill();
	Output(v1);

	v2 = fill();
	Output(v2);

	s = Sum(v1, v2);
	Output(s);
	Delete(s);

	m = Sub(v1, v2);
	Output(m);
	Delete(m);

    printf("Scalar between the vectors : %.2f \n", scalar(v1, v2));

	printf("length of your vector1 : %.2f \n", Length(v1));
	printf("length of your vector2 : %.2f \n", Length(v2));

	printf("the angle between the vectors : %.2f \n", Angle(v1, v2));
}
