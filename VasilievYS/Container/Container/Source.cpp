#include"Container.h"
#include<iostream>
int main()
{
	Container<int> Cont(4,5);
	std::cout << Cont[3];
	return 0;
}