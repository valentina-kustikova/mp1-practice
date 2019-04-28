#include "Container.h"
#include <iostream>
int main()
{
	Container<int> c;

	c.add(21).add(45).add(23).add(24).add(25).add(26).add(27).add(28).add(29);
	c.add(10);
	c.add(11);
	for (size_t i = 0; i < c.sz(); i++)
		std::cout << c[i] << ' ';
	std::cout << '\n';

	c[0] = 30;
	for (size_t i = 0; i < c.sz(); i++)
		std::cout << c[i] << ' ';
	std::cout << '\n';

	c.remove(45);
	for (size_t i = 0; i < c.sz(); i++)
		std::cout << c[i] << ' ';
	std::cout << '\n';
}