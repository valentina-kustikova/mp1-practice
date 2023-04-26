#pragma once


class vacancy {

private:
	string nameCompany;
	string employee;
	int salary;
	string workCond;
	string request;

public:
	vacancy();

	friend vacancy* fill_class(ifstream& stream, int countVacancy);
	friend tuple <vacancy*, int> search_vacancy(vacancy* Vacancy, int countVacancy);
	friend void output_info(vacancy* Vacancy, int searchedVacancy);

	friend ostream& operator << (ostream& os, const vacancy& vac);
	friend istream& operator >> (istream& is, vacancy& vac);
};



vacancy* fill_class(ifstream& stream, int countVacancy);
string enter_path();
ifstream read_list(string path);
int count_vacancy(ifstream& stream);
tuple <vacancy*, int> search_vacancy(vacancy* Vacancy, int countVacancy);
void output_info(vacancy* Vacancy, int searchedVacancy);
