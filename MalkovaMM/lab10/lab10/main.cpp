#include <iostream>
#include <locale.h>
#include "container.h"

using namespace std;

int main()
{
	Container<int> c(2, 1, 1);
	int b = c[1];
	int a = 2;
	c.push_back(a);
	int d = 0;
	cout << c.find(d);
	cout << c.find(a);
	c.remove(a);
	cout << c.find(a);
	return 0;
}