#include <iostream>
#include <string>
#include "school.h"
using namespace std;

int main(int argc, char** argv) {
	try {
		const string file(argv[1]);
		school sch(file);
		sch.sort();
		cout << sch << endl;
	}
	catch (...) {}
	return 0;
}