#pragma once

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
	//...
} Day;

typedef struct {
	Time start;
	Time finish;
	Day day;
	// DayStatus ?
} OpenCloseDay; // rename

#define DAYS_NUMBER 7

typedef struct {
	char* name;
	Address address;
	OpenCloseDay modes[DAYS_NUMBER];
	char* phones;
	char* special;
	char* form;
} Shop;

typedef struct {
	char name[30];
	char adres[70];
	char phones[50];
	char special[50];
	char form[30];
	int opens[7];
	int closes[7];
} magaz;

typedef struct {
	int len;
	magaz** base;
}box;


box getbase();

box findstores(box *base);

void printer(box *base);

void delit(box *base);