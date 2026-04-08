#ifndef _LIBARG_H
#define _LIBARG_H

typedef enum {
	male,
	female,
	unknown
} Gender;

typedef struct {
	char* surname;
	char* name;
	char* patronymic;
}FullName;

typedef struct {
	int day; 
	int month;
	int year;
} Date;

typedef struct {
	char* index; 
	char* country;
	char* region_city;
	char* street;
}Address;

typedef struct {
	FullName full_name;
	Gender gender;
	char* nation;
	int height;
	int weight;
	Date date_of_birth;
	char* number;
	Address address;
} PersonInfo;


typedef struct {
	PersonInfo* persons;
	int count;
} PersonsLibrary;

void sort_person(PersonsLibrary* lib_persons);

#endif

