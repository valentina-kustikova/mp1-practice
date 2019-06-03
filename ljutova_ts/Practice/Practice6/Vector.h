#pragma once 
#include <stdio.h> 

typedef struct
{
	int size;
	int *V;
}Vector;

Vector Create(int n);
Vector fill();
void Delete(Vector x);
Vector Sum(Vector V1, Vector V2);
Vector Sub(Vector V1, Vector V2);
Vector scalar(Vector V1, Vector V2);
float Length(Vector V);
float Angle(Vector V1, Vector V2);
Vector Output(Vector x);
