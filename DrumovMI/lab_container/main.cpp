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
		std::getline(std::cin, query);
		int elem = 0;
		try {
			switch (query[0]) {
			case '+':
				elem = stoi(query.substr(1));
				v.push_back(elem);
				break;
			case '-':
				elem = stoi(query.substr(1));
				v.remove(elem);
				break;
			case 'q':
				loop = false;
				break;
			}
		}
		catch (std::exception e) {
			std::cerr << e.what() << std::endl;
		};
	}

	std::cout << "Test 2. container<int*>" << std::endl;
	container<int*> vp;
	loop = true;
	while (loop) {
		std::cout << vp << std::endl;
		std::string query;
		std::getline(std::cin, query);
		int elem = 0;
		const int* pelem = &elem;
		try {
			switch (query[0]) {
			case '+':
				elem = stoi(query.substr(1));
				vp.push_back(pelem);
				break;
			case '-':
				elem = stoi(query.substr(1));
				vp.remove(pelem);
				break;
			case 'q':
				loop = false;
				break;
			}
		}
		catch (std::exception e) {
			std::cerr << e.what() << std::endl;
		};
	}

	std::cout << "Test 3. container<container<char>*>" << std::endl;
	container<container<char>*> vs;
	loop = true;
	while (loop) {
		std::cout << vs << std::endl;
		std::string query;
		std::getline(std::cin, query);
		container<char> elem;
		for (size_t i = 1; i < query.size(); i++)
			elem.push_back(query[i]);
		const container<char>* pelem = &elem;
		switch (query[0]) {
		case '+':
			vs.push_back(pelem);
			break;
		case '-':
			try {
				vs.remove(pelem);
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
	return 0;
}