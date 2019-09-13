#pragma once 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define Pi 3.1415;

typedef struct
{
    int dim;
    double *coord;
} vect;

int dimcheck(vect p, vect q);

void vect_print (vect p);
void vect_del (vect p);

vect vect_read ();
vect vect_invert (vect p);
vect vect_null (int n);
vect vect_plus (vect p, vect q);
vect vect_minus (vect p, vect q);

double vect_scp (vect p, vect q);
double vect_len (vect p);
double vect_angle (vect p, vect q);
