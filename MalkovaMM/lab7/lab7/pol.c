#include "pol.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

polinom pcreate(int deg)
{
	polinom p;
	p.deg = deg;
	p.coef = (int*)malloc((deg + 1) * sizeof(int));
}
polinom pplus(polinom* p1, polinom* p2)
{
	int mindeg = min((*p1).deg, (*p2).deg);
	int maxdeg = max((*p1).deg, (*p2).deg);
	int i = 0;
	polinom ps;
	ps.deg = maxdeg;
	ps.coef = (int*)malloc((ps.deg + 1) * sizeof(int));
	for (; i <= mindeg; i++)
	{
		ps.coef[i] = (*p1).coef[i] + (*p2).coef[i];
	}
	if ((*p1).deg == mindeg)
	{
		for (i = mindeg + 1; i <= maxdeg; i++)
		{
			ps.coef[i] = (*p2).coef[i];
		}
	}
	else
	{
		for (i = mindeg + 1; i <= maxdeg; i++)
		{
			ps.coef[i] = (*p1).coef[i];
		}
	}
	return ps;
}
polinom pminus(polinom* p1, polinom* p2)
{
	int mindeg = min((*p1).deg, (*p2).deg);
	int maxdeg = max((*p1).deg, (*p2).deg);
	int i = 0;
	polinom pm;
	pm.deg = maxdeg;
	pm.coef = (int*)malloc((pm.deg + 1) * sizeof(int));
	for (; i <= mindeg; i++)
	{
		pm.coef[i] = abs((*p1).coef[i] - (*p2).coef[i]);
	}
	if ((*p1).deg == mindeg)
	{
		for (i = mindeg + 1; i <= maxdeg; i++)
		{
			pm.coef[i] = (*p2).coef[i];
		}
	}
	else
	{
		for (i = mindeg + 1; i <= maxdeg; i++)
		{
			pm.coef[i] = (*p1).coef[i];
		}
	}
	return pm;
}
polinom pumn(polinom* p1, polinom* p2)
{
	polinom pu;
	pu.deg = (*p1).deg + (*p2).deg;
	pu.coef = (int*)malloc((pu.deg + 1) * sizeof(int));
	int k = 0;
	for (; k <= pu.deg; k++)
	{
		pu.coef[k] = 0;
	}
	int i = 0;
	int j = 0;
	for (; i <= (*p1).deg; i++)
	{
		for (; j <= (*p2).deg; j++) 
		{
			pu.coef[i + j] += (*p1).coef[i] * (*p2).coef[j];
		}
	}
	return pu;
}
int pznach(polinom* p, double x)
{
	int zn = 0;
	int i = 0;
	for (; i <= (*p).deg; i++)
	{
		zn += (*p).coef[i] * pow(x, i);
	}
	return zn;
}
polinom pdif(polinom* p)
{
	polinom pd;
	pd.deg = (*p).deg - 1;
	pd.coef = (int*)malloc((pd.deg + 1) * sizeof(int));
	int i = 1;
	for (; i <= (*p).deg; i++)
	{
		pd.coef[i - 1] = (*p).coef[i] * i;
	}
	return pd;
}