#include <string>
#include "school.h"
using namespace std;

birth_date::birth_date(string s) {
	if (s.size() < 10) throw "Too short date!";
	this->day = stoi("" + s[0] + s[1]);
	this->month = stoi("" + s[3] + s[4]);
	string b = "";
	for (int i = 6; i < s.size(); i++) b += s[i];
	this->year = stoi(b);
}

school::school(string s) {

}