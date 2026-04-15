#include <iostream>
#include <string>
#include "school.h"
using namespace std;

int main(int argc, char** argv) {
	if (argc < 2) {
		cout << "Incorrect parameters!\n";
		return 1;
	}
	try {
		const string file(argv[1]);
		school sch(file);
		sch.sort();
		cout << sch << endl;
	}
	catch (...) {}
	return 0;
}