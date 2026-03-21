#ifndef __SCH_H_
#define __SCH_H_

struct birth_date {
	int day, month, year;
	
	birth_date(string);
};

struct home_address {
	int index, home, flat;
	string country, region, district, city, street;

	home_address(string);
};

struct school {
	string name, klass, gen;
	birth_date date;
	home_address home;

	school(string);
	school operator < (const school&);
};

#endif