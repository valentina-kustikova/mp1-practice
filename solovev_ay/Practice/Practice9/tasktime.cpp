#include "tasktime.h"
#include <iostream>
using namespace std;

date tasktime::proverka()
{
	return Date;
}


void tasktime::settime(time kek)
{
	a = kek;
}

void tasktime::settimeend(time roflantigr)
{
	aend = roflantigr;
}

void tasktime::setend(time fak)
{
	aend = fak;
}

void tasktime::input()
{
	a.inputtime();
	aend.inputtime();
	Date.input();
	cin >> descrip;
}

void tasktime::print()
{
	cout << a.gethour() << ":" << a.getmin() << "-" << aend.gethour() << ":" << aend.getmin() << " " << Date.getday() << "." << Date.getmonth() << "." << Date.getyear() <<" "<<descrip << endl;
}


void tasktime::fwrite(ofstream & file)
{
	/*if((Date.getday()<10)&&(Date.getmonth()>10))
		file <<1<<" "<< 0 << Date.getday() << "." << Date.getmonth() << "." << Date.getyear() <<" "<< a.gethour() << ":" << a.getmin() << " "<<aend.gethour() << ":" << aend.getmin() << " "<<descrip<<"\n";
	if((Date.getmonth()<10)&&(Date.getday()>10))
		file << 1 << " " <<  Date.getday() << "." <<0<< Date.getmonth() << "." << Date.getyear() << " " << a.gethour() << ":" << a.getmin() << " " << aend.gethour() << ":" << aend.getmin() << " " << descrip << "\n";
	if((Date.getday()<10)&&(Date.getmonth()<10))
		file << 1 << " " <<0<< Date.getday() << "." << 0 << Date.getmonth() << "." << Date.getyear() << " " << a.gethour() << ":" << a.getmin() << " " << aend.gethour() << ":" << aend.getmin() << " " << descrip << "\n";
		*/
	file << 1 << " " << Date.getday() << "." << Date.getmonth() << "." << Date.getyear() << " " << a.gethour() << ":" << a.getmin() << " " << aend.gethour() << ":" << aend.getmin() << " " << descrip << "\n";
}

/*void tasktime::fread(ifstream & file)
{
	unsigned _day, _month, _year, _beginstart, _beginend, _endstart, _endend, kek;
	char temp, temp1, temp2;
	file >>kek>> _beginstart >> temp >> _beginend >> temp >> _endstart >> temp >> _endend >> _day >> temp >> _month >> temp >> _year >> descrip;
	Date = date(_day, _month, _year);
	a = time(_beginstart, _beginend);
	aend = time(_endstart, _endend);
	getline(file, descrip, '\n');
}
*/

tasktime::tasktime()
{
	a;
	Date;
}

tasktime::~tasktime()
{
	a.~time();
	Date.~date();
}

tasktime::tasktime(time team, time end, date gate)
{
	a = team;
	aend = end;
	Date = gate;
}