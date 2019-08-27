#include "iostream"
#include "task1.h"
using namespace std;
task1::task1(string describe1, date dat) {
	describe = describe1;
	date_m = dat;
}
task1::~task1() {
	describe.clear();
}
void task1::print() {
	cout <<date_m<<" -> "<< describe << endl;
};