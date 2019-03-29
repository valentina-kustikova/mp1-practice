#include "stdio.h"
#include "vector.h"

void main()
{
    int n = 3;
    Vector *v;
    v = Cre(n);
    Fill(v);
    Print(v);
    Vector *u;
    u = Cre(n);
    Fill(u);
    Print(u);
    Vector *a;
    a = Sum(v, u);
    Print(a);
    Vector *b;
    b = Diff(v, u);
    Print(b);

    double m, s, t;
    m = Len(a);
    s = Skal(v, u);
    t = Angle(v, u);
    printf("lenght = %lf \n", m);
    printf("skal = %lf \n", s);
    printf("angl = %lf \n", t);
    DeleteAll(a);
    DeleteAll(b);
    DeleteAll(v);
    DeleteAll(u);
    scanf("%d", &n);
}