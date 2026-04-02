#include <iostream>
#include <string>
#include "school.h"
using namespace std;

int main(int argc, char** argv) {
	try {
		const string s(argv[1]);
		school sch(s);
		sch.sort();
		cout << sch << endl;
	}
	catch (...) {}
	return 0;
}
