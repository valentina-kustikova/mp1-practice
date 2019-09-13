#define _CRT_SECURE_NO_WARNINGS
#include "Vector.h" 

void main()
{
    vect v1, v2, v3;
    double c;

    printf ("enter v1 \n");
    v1 = vect_read();
    printf ("check: v1 is \n");
    vect_print (v1);

    printf ("enter v2 \n");
    v2 = vect_read();
    printf ("check: v2 is \n");
    vect_print (v2);

    printf ("v1 + v2 = \n");
    v3 = vect_plus (v1, v2);
    if (dimcheck (v1,v2)) vect_print (v3);

    printf ("v1 - v2 = \n");
    v3 = (vect_minus (v1, v2));
    if (dimcheck (v1,v2)) vect_print (v3);

    c = vect_scp (v1, v2);
    if (dimcheck (v1,v2)) printf ("v1 * v2 (scalar) = %.3lf \n", c);
    printf ("|v1| = %.3lf \n", vect_len (v1));
    printf ("|v2| = %.3lf \n", vect_len (v2));

    c = vect_angle (v1, v2);
    if (dimcheck (v1,v2)) printf ("<(v1, v2) = %.3lf \n", c);

    vect_del (v1);
    vect_del (v2);
    vect_del (v3);
    system ("pause");
}