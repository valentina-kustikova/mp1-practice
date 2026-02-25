#ifndef __HR_DB_H
#define __HR_DB_H

struct Employee {
	struct Passport {
		int series, number;
		char *issued_by;
		char *issue_date;
		char *birthday;
		char *place_of_residence;
	} passport;
	char *education;
	char *specialty;
	char *department;
	char *position;
	int salary;
	
};

#endif