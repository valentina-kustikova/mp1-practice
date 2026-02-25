#include <stdio.h>
#include <stdlib.h>
#include "date.h"

struct Date to_date(char *str) {
	// str must point to string "DD/MM/YYYY", where:
	// DD, MM, YYYY are numbers representing day, month, year
	// WARNING: the function doesn't check validity of the date
	struct Date ans = {
		.day = (str[0] - '0') * 10 + (str[1] - '0'),
		.month = (str[3] - '0') * 10 + (str[4] - '0'),
		.year = (str[6] - '0') * 1000 + (str[7] - '0') * 100 + (str[8] - '0') * 10 + (str[9] - '0')
	};
	return ans;
}

void print_date(struct Date date) {

}