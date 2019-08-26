#ifndef _VECTOR_H_
#define _VECTOR_H_

typedef struct {
    int n;//размерность 
    float *x;//набор компонент
}vector;
vector create();
void del(vector c);
void output(vector c);
vector sum(vector a, vector b);
vector dif(vector a, vector b);
double length(vector a);
float scalar(vector a, vector b);
double angle(vector a, vector b);

#endif
