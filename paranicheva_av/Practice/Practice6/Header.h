#ifndef HEADER_H
#define HEADER_H

 typedef struct 
{
	int n;
	double *a;
}Vector;

Vector* Add(int nn);
Vector* Fill(Vector *v);
void Print(Vector *v);
void Sum(Vector *v, Vector *vv, Vector *s);
void Sub(Vector *v, Vector *vv, Vector *ss);
double Com(Vector *v, Vector *vv);
double Length(Vector *a);
double Angle(Vector *v, Vector *vv);
void Delete(Vector *а);

#endif
