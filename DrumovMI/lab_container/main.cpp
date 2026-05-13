#include <iostream>
#include <string>
#include "container.hpp"

int main() {
	container<int> v;
	while (true) {
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
		}
		std::cout << v << std::endl;
	}
	return 0;
}