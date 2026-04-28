#ifndef HEADER_H
#define HEADER_H
#define MAX_LEN 100
#define MAX_BUFF 2048

typedef struct {
	char first_name[MAX_LEN];
	char last_name[MAX_LEN];
} Person_data;

typedef struct {
	int day;
	int month;
	int year;
} Birsday;

typedef enum {
	M,
	F
} Gender;

typedef enum {
	Athletics,
	Weightlifting,
	Boxing,
	Tennis,
	Football,
	Unknown
} Sport;



typedef struct {
	Person_data name;
	Gender gender;
	Birsday date_of_birth;
	char country[MAX_LEN];
	char city[MAX_LEN];
	Sport sport;
	char club[MAX_LEN];
	char discipline[MAX_LEN];
	double record;
} Person;


typedef struct {
	int count;
	Person* array;
} PersonsLibrary;

typedef struct {
	char discipline[MAX_LEN];
	int best_index;
	double best_record;
} BestEntry;

int numberLines(const char* filename);
void readFile(PersonsLibrary info, const char* filename);
Sport convertSport(char* input_sport);
void findRecord(PersonsLibrary info, char* input);
void findRecord(PersonsLibrary info, char* input_sport, BestEntry** result, int* countResult);
void printResult(PersonsLibrary info, BestEntry* result, int countResult);
#endif 