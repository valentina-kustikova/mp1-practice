#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#define N 6
using namespace std;




struct vacancy {
	string employee;
	string nameCompany;
	string salary;
	string workCond;
	string request;

	friend ostream& operator << (ostream& os, const vacancy& vac);
	friend istream& operator >> (istream& is, vacancy& vac);
};


struct vacancyLib {
	int countVacancy;
	vacancy* Vacancy;


	vacancyLib();
	vacancyLib(vacancy* vac, int count);
	vacancyLib(const string& path);
	vacancyLib(const vacancyLib& copy_vac);
	~vacancyLib();
};



string input_path();
ifstream read_list(const string path); 
int count_vacancy(ifstream& read);
vacancy* fill_struct(ifstream& read, int countVacancy);
vacancyLib search_vacancy(vacancyLib Vacancy);
void print_info(vacancyLib VacancyLib);
