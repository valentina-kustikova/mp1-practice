#pragma once
#include "stdafx.h"



class vacancy {

private:
	string nameCompany;
	string employee;
	string salary;
	string workCond;
	string request;

public:
	vacancy();
	vacancy(string employee, string nameCompany, string salary, string workCond, string request);
	string GetNameCompany();
	string GetEmployee();
	string GetSalary();
	string GetWorkCond();
	string GetRequest();
	friend vacancy* fill_class(ifstream& stream, int countVacancy);
	friend int* search_vacancy(vacancy* Vacancy, int countVacancy);
};



vacancy* fill_class(ifstream& stream, int countVacancy);
string enter_path();
ifstream read_list(string path);
int count_vacancy(ifstream& stream);
int* search_vacancy(vacancy* Vacancy, int countVacancy);
void output_info(vacancy* Vacancy, int* ind, int searchedVacancy);
