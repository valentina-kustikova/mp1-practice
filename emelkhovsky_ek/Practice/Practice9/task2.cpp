#include "iostream"
#include "task2.h"
using namespace std;
task2::task2(string describe1, date dat, time start1, time finish1) {
	describe = describe1;
	date_m = dat;
	start = start1;
	finish = finish1;
}
task2::~task2() {
	describe.clear();
}
void task2::print() {
	cout <<date_m<<" , "<<start<<"-"<<finish<<" -> "<< describe << endl;
};