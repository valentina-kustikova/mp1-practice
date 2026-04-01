#ifndef DATA_H
#define DATA_H

typedef struct {
	int company_id;
	char* name;
	char* addres;
}Company;

typedef struct {
	int vacancy_id;
	int company_id;
	char* name;
	char* conditions;
	char* requirements;
	float salary;
}Vacancy;

typedef struct {
	Company* arr;
	int size;
}DbCompanies;

typedef struct {
	Vacancy* arr;
	int size;
}DbVacancies;

// DbCompanies* comp_s, DbVacancies* vcn_s
void find_vacancy(DbCompanies* comp_s, DbVacancies* vcn_s, DbCompanies* new_comp_s, char* users_choice);
void different_company(DbCompanies* old_valid, DbCompanies* new_valid);

#endif