#ifndef __DATE_H
#define __DATE_H

typedef struct Date {
	int day, month, year;
} Date;

Date to_date(char *str);
void print_date(Date date);

#endif