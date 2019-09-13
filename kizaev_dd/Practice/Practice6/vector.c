#define _CRT_SECURE_NO_WARNINGS
#include "vector.h" 

//memory for a new vector

int dimcheck (vect p, vect q)
{
    if (p.dim == q.dim)
        return 1;
    else
        return 0; 
}

vect vect_memo (int n)
{
    vect p;
    p.dim = n;
    p.coord = (double*) malloc (sizeof (double) * p.dim);
    return p;
}

vect vect_null (int n)
{
     vect p = vect_memo (n);

    for (int i = 0; i < n; i++)
        p.coord[i] = 0.0;

    return p;
}

//reading coordinates

vect vect_read ()
{
    int n = 0;
    
    do
    {
        printf ("Dimension? ");
        scanf ("%d", &n);    
    }
    while (n<=0);

    vect p = vect_memo (n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter %d coordinate: \n", i+1);
        scanf ("%lf", &p.coord[i]);
    }
    return (p);
}

//deleting

void vect_del (vect p)
{
    p.dim = 0;
    free(p.coord);
}

// p + q

vect vect_plus (vect p, vect q)
{
    vect sum = vect_null (p.dim);

    if (dimcheck (p,q) == 1)
    {
        
        for (int i = 0; i < p.dim; i++)
        {
            sum.coord[i] = q.coord[i] + p.coord[i];
        }
        return sum;
    }
    else
    {
        printf ("sum: error - different dimensions \n");
        return sum;
    }
}


// p => -p

vect vect_invert (vect p)
{
    vect p_inv = vect_memo (p.dim);

    for (int i = 0; i < p.dim; i++)
    {
        p_inv.coord[i] = p.coord[i] * (-1);
    }
    return p_inv;
}

// p - q = p + (-q)

vect vect_minus (vect p, vect q)
{
    if (dimcheck (p,q) == 1)
        return (vect_plus (p, vect_invert (q)));
    else
    {
        printf ("difference: error - different dimensions \n");
        return (vect_null (p.dim));
    }
}

// scalar prod

double vect_scp (vect p, vect q)
{
    double scp = 0.0;
    if (dimcheck (p,q) == 1)
    {
        for (int i = 0; i < p.dim; i++)
        {
            scp += p.coord[i] * q.coord[i];
        }
        return scp;
    }
    else
    {
        printf("scalar product: error - different dimensions \n");
        return 0.0f;
    }
}

// length 

double vect_len (vect p)
{
    double len = sqrt (vect_scp (p, p));
    return len;
}

// angle

double vect_angle (vect p, vect q)
{
    if (dimcheck (p,q) == 1)
    {
        double chisl = vect_scp (p, q);
        double znam = vect_len (p) * vect_len (q);
        double angle = acos(chisl/znam) * 180 / Pi;
        return angle;
    }
    else
    printf("angle: error - different dimensions \n");
    return 0.0;
}

void vect_print (vect p)
{
    if (p.dim == 0)
        printf("vector is null \n");
    else
    {
        printf("(");
        for (int i = 0; i < p.dim; i++)
            printf(" %.3lf", p.coord[i]);
        printf(" )\n\n");
    }
}