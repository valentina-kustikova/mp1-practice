#pragma once
#define dayscount 7

typedef struct {
	char* street;
	char* hnum;
} Address;

typedef struct {
	int hours;
	int minutes;
} Time;

typedef enum {
	MONDAY = 0,
	TUESDAY = 1,
	WEDNSDAY = 2,
	THURSDAY = 3,
	FRIDAY = 4,
	SATURDAY = 5,
	SUNDAY = 6,
} Day;

typedef enum {
	open = 2,
	close = 1,
	alldayopen = 0
} daystatus;

typedef struct {
	Time start;
	Time finish;
	Day day;
	daystatus status;
} timing;

typedef struct {
	char* name;
	Address address;
	char* phones;
	char* special;
	char* form;
	timing timings[dayscount];
} Shop;

typedef struct {
	int len;
	Shop** base;
} box;


box getbase(char *argv);

box findstores(box *base);

void printer(box *base);

void delit(box *base);