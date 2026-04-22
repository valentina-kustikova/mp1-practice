#define _CRT_SECURE_NO_WARNINGS
#include "pol.h"
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#define MAX_LEN 1000
using namespace std;

polinom::polinom(const string fname, int num)//посмотреть как со стринг файл читать
{
	int dg = 1;
	int i = 0;
	string t;
	char line[MAX_LEN];
	string context = NULL;
	FILE* f = fopen(fname, "r");
	if (f == NULL)
	{
		throw "Файл по заданному пути не существует";
	}

	fgets(line, sizeof(line), f);
	if (num == 2)
		fgets(line, sizeof(line), f);
	for (; line[i] != '\0'; i++)
	{
		if (line[i] == ';')
			dg++;
	}
	dg--;
	polinom p(dg);
	fclose(f);
	f = fopen(fname, "r");
	fgets(line, sizeof(line), f);
	if (num == 2)
		fgets(line, sizeof(line), f);
	t = strtok_s(line, ";", &context);
	p.coef[dg] = atoi(t);
	i = dg - 1;
	for (; i >= 0; i--)
	{
		t = strtok_s(NULL, ";", &context);
		p.coef[i] = atoi(t);
	}
	fclose(f);
	return p;
}

polinom::polinom(int deg)
{
	this->deg = deg;
	this->coef = new int[deg];
}

polinom::polinom(const polinom &p)
{
	this->deg = p.deg;
	this->coef = new int[p.deg];
	for (int i = 0; i <= p.deg; i++)
	{
		this->coef[i] = p.coef[i];
	}
}

polinom::~polinom()
{
	delete[] this->coef;
}

polinom polinom::operator +(const polinom& p)
{
	int mindeg = min(this->deg, p.deg);
	int maxdeg = max(this->deg, p.deg);
	int i = 0;
	int degnew;
	polinom ps(maxdeg);
	for (; i <= mindeg; i++)
	{
		ps.coef[i] = this->coef[i] + p.coef[i];
	}
	if (mindeg != maxdeg)
		if (this->deg == mindeg)
		{
			for (i = mindeg + 1; i <= maxdeg; i++)
			{
				ps.coef[i] = p.coef[i];
			}
		}
		else
		{
			for (i = mindeg + 1; i <= maxdeg; i++)
			{
				ps.coef[i] = this->coef[i];
			}
		}
	degnew = ps.deg;
	for (i = ps.deg; i >= 0; i--)
	{
		if (ps.coef[i] == 0) {
			degnew = degnew - 1;
		}
		else
			break;
	}
	polinom psnew(degnew);
	for (i = 0; i <= degnew; i++)
	{
		psnew.coef[i] = ps.coef[i];
	}
	return psnew;
}
polinom polinom::operator -(const polinom& p)
{
	int i = 0;
	polinom p2(p.deg);
	for (; i <= p2.deg; i++)
	{
		p2.coef[i] = -p.coef[i];
	}
	polinom pm = *this + p2;
	return pm;
}
polinom polinom::operator -()
{
	int i = 0;
	polinom p(this->deg);
	for (; i <= p.deg; i++)
	{
		p.coef[i] = -p.coef[i];
	}
	return p;
}
polinom polinom::operator *(const polinom&p)
{
	polinom pu(this->deg + p.deg);
	int k = 0;
	for (; k <= pu.deg; k++)
	{
		pu.coef[k] = 0;
	}
	int i = 0;
	for (; i <= this->deg; i++)
	{
		int j;
		for (j = 0; j <= p.deg; j++)
		{
			pu.coef[i + j] += this->coef[i] * p.coef[j];
		}
	}
	return pu;
}
int polinom::pznach(double  x)
{
	int zn = 0;
	int i = 0;
	double xvalue = 1.0;
	for (; i <= this->deg; i++)
	{
		zn += this->coef[i] * xvalue;
		xvalue *= x;
	}
	return zn;
}
polinom polinom::pdif()
{
	int i = 1;
	polinom pd(this->deg - 1);
	for (; i <= this->deg; i++)
	{
		pd.coef[i - 1] = this->coef[i] * i;
	}
	return pd;
}
const polinom& polinom::operator =(const polinom& p)
{
	this->deg = p.deg;
	this->coef = new int[p.deg];
	for (int i = 0; i <= p.deg; i++)
	{
		this->coef[i] = p.coef[i];
	}
}
std::ostream& operator << (std::ostream& out, const polinom& p)
{
	for (int i = 0; i < p.deg; i++)
		out << p.coef[i] << " ";
	return out;
}
std::istream& operator >> (std::istream& in, const polinom& p)
{
	for (int i = 0; i < p.deg; i++)
		in >> p.coef[i];//проверить как работает
	return in;
}

/*
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
*/

