#pragma once
#include "Exeption.h"
#include "Container.h"
#include <iostream>

int main()
{
	Container<int*> cont;
	unsigned control, index;
	int input;
	do {
		std::cout << "add, remove, remove by index, find, print, exit" << std::endl;
		std::cin >> control;
		try {
			switch (control)
			{
			case 1:
				std::cout << "Input value ";
				std::cin >> input;
				cont.Add(input);
				break;
			case 2:
				std::cout << "Input value ";
				std::cin >> input;
				cont.FindAndRemove(input);
				break;
			case 3:
				std::cout << "Input index ";
				std::cin >> index;
				cont.Remove(index);
				break;
			case 4:
				std::cout << "Input value ";
				std::cin >> input;
				std::cout << cont.Find(input) << std::endl;
				break;
			case 5:
				cont.Print();
				std::cout << std::endl;
				break;
			}
		}
		catch (Exeption & exp)
		{
			switch (exp.exp_type)
			{
			case ContainerIsEmpty:
				std::cout << "Container is empty" << std::endl;
				break;
			case ContainerIsFull:
				std::cout << "Container is full" << std::endl;
				break;
			case BadContainerSize:
				std::cout << "Bad container size" << std::endl;
				break;
			case BadIndex:
				std::cout << "Bad index" << std::endl;
				break;
			}
		}
	} while (control != 6);
}