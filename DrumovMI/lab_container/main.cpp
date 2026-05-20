#include <iostream>
#include <string>
#include "container.hpp"

int main() {
	container<int> v;
	std::cout << "Test 1. container<int>"  << std::endl;
	bool loop = true;
	while (loop) {
		std::cout << v << std::endl;
		std::string query;
		std::cin >> query;
		int elem = 0;
		switch (query[0]) {
		case '+':
			elem = stoi(query.substr(1));
			v.push_back(elem);
			break;
		case '-':
			elem = stoi(query.substr(1));
			try {
				v.remove(elem);
			}
			catch (std::exception e) {
				std::cerr << e.what() << std::endl;
			};
			break;
		case 'q':
			loop = false;
			break;
		}
	}

	std::cout << "Test 2. container<int*>" << std::endl;
	container<int*> v1;
	const int a = 1;
	const int* pa = &a;
	v1.push_back(pa);
	v1.push_back(pa);
	v1.push_back(pa);
	std::cout << v1 << std::endl;
	v1.pop_back();
	std::cout << v1 << std::endl;
	return 0;
}