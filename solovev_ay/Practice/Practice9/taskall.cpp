#include "taskall.h"
#include <iostream>
using namespace std;


taskall::taskall()
{
	date();
}

taskall::~taskall()
{
	Date.~date();
}

taskall::taskall(const taskall & tmp)
{
	descrip = tmp.descrip;
	Date = tmp.Date;
}

date taskall::proverka()
{
	return Date;
}

void taskall::settime(time)
{
	cout << "kek";
}

void taskall::settimeend(time)
{
	cout << "kek";
}

void taskall::fwrite(ofstream & file)
{
	file  << 2 << " " << Date.getday() << "." << Date.getmonth() << "." << Date.getyear()<< " " << descrip<<"\n";
}

/*void taskall::fread(ifstream & file)
{
	unsigned _day, _month, _year, _beginstart, _beginend, _endstart, _endend, kek;
	char temp, temp1, temp2;
	file >>kek>> _day >> temp >> _month >> temp >> _year >> descrip;
	Date = date(_day, _month, _year);
	getline(file, descrip, '\n');
}
*/
void taskall::input()
{
	Date.input();
	cin >> descrip;
}

void taskall::print()
{
	cout << Date.getday() << "." << Date.getmonth() << "." << Date.getyear() << " " << descrip << endl;
}