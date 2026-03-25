#include <iostream>
#include <string>
#include "school.h"
using namespace std;

int main(int argc, char** argv) {
	school sch(argv[1]);
	sch.list[0].print();

	string s = "abcdefghijklmnop";
	return 0;
}