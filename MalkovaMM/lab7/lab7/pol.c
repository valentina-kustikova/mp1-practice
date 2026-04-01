#include "pol.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int degpol(const char* fname, int num)
{
	int dg = 1;
	int i = 0;
	FILE* f = fopen(fname, "r");
	char line[MAX_LEN];
	if (f == NULL)
	{
		printf("Файл по заданному пути не существует");
		return -1;
	}
	
	fgets(line, sizeof(line), f);
	if (num==2)
		fgets(line, sizeof(line), f);
	for (; line[i] != '\0'; i++)
	{
		if (line[i] == ';')
			dg++;
	}
	dg--;
	fclose(f);
	return dg;
}
polinom pcreate(const char* fname, int deg, int num)
{
	polinom p;
	int i = 0;
	char* t;
	char line[MAX_LEN];
	char* context = NULL;
	FILE* f;
	p.deg = deg;
	p.coef = (int*)malloc((deg + 1) * sizeof(int));
	f = fopen(fname, "r");
	fgets(line, sizeof(line), f);
	if (num == 2)
		fgets(line, sizeof(line), f);
	t = strtok_s(line, ";", &context);
	p.coef[deg] = atoi(t);
	i = deg-1;
	for (; i >=0; i--)
	{
		t = strtok_s(NULL, ";", &context);
		p.coef[i] = atoi(t);
	}
	return p;
}
polinom pplus(polinom* p1, polinom* p2)
{
	int mindeg = min(p1->deg, p2->deg);
	int maxdeg = max(p1->deg, p2->deg);
	int i = 0;
	int degnew;
	polinom ps, psnew;
	ps.deg = maxdeg;
	ps.coef = (int*)malloc((ps.deg + 1) * sizeof(int));
	for (; i <= mindeg; i++)
	{
		ps.coef[i] = p1->coef[i] + p2->coef[i];
	}
	if (p1->deg == mindeg)
	{
		for (i = mindeg + 1; i <= maxdeg; i++)
		{
			ps.coef[i] = p2->coef[i];
		}
	}
	else
	{
		for (i = mindeg + 1; i <= maxdeg; i++)
		{
			ps.coef[i] = p1->coef[i];
		}
	}
	degnew = ps.deg;
	for (i=ps.deg; i>=0; i--)
	{
		if (ps.coef[i] == 0) {
			degnew = degnew - 1;
			printf("%d", degnew);
		}
		else
			break;
	}
	psnew.deg = degnew;
	psnew.coef = (int*)realloc(ps.coef, (psnew.deg + 1) * sizeof(int));
	return psnew;
}
polinom pminus(polinom* p1, polinom* p2) 
{
	int i = 0;
	polinom pm;
	polinom pp2;
	pp2.deg = p2->deg;
	for (; i <= p2->deg; i++)
	{
		pp2.coef[i] = -p2->coef[i];
	}
	pm = pplus(&p1, &pp2);
	return pm;
}
polinom pumn(polinom* p1, polinom* p2)
{
	polinom pu;
	pu.deg = p1->deg + p2->deg;
	pu.coef = (int*)malloc((pu.deg + 1) * sizeof(int));
	int k = 0;
	for (; k <= pu.deg; k++)
	{
		pu.coef[k] = 0;
	}
	int i = 0;
	for (; i <= p1->deg; i++)
	{
		int j;
		for (j=0; j <= p2->deg; j++)
		{
			pu.coef[i + j] += p1->coef[i] * p2->coef[j];
		}
	}
	return pu;
}
int pznach(polinom* p, double x)
{
	int zn = 0;
	int i = 0;
	double xvalue = 1.0;
	for (; i <= p->deg; i++)
	{
		zn += p->coef[i] * xvalue;
		xvalue *= x;
	}
	return zn;
}
polinom pdif(polinom* p)
{
	int i = 1;
	polinom pd;
	pd.deg = p->deg - 1;
	pd.coef = (int*)malloc((pd.deg + 1) * sizeof(int));
	
	for (; i <= p->deg; i++)
	{
		pd.coef[i - 1] = p->coef[i] * i;
	}
	return pd;
}
void pprint(polinom* p)
{
	int i;
	int deg = p->deg;
	printf("Степень: %d\nКоэффициенты: ", deg);
	for (i = deg; i >= 0; i--)
	{
		printf("%d ", p->coef[i]);
	}
}