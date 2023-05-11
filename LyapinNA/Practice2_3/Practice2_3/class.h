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

	string getInfoVacancy(int select);
	friend ostream& operator << (ostream& os, const vacancy& vac);
	friend istream& operator >> (istream& is, vacancy& vac);
};





class vacancyLib {
private: 
	vacancy* Vacancy;
	int count;
	vacancy* fill_from_txt(ifstream& stream, int countVacancy);
	ifstream read_list(const string& path);
	int count_vacancy(ifstream& stream);

public:
	vacancyLib();
	vacancyLib(const string& path);
	vacancyLib(vacancy* OutVacancy, int OutCount);
	vacancyLib(const vacancyLib& vac_copy);
	~vacancyLib();
	vacancyLib search_vacancy();

	vacancyLib& operator= (const vacancyLib& cp_vac);
	friend ostream& operator << (ostream& os, const vacancyLib& vacLib);
};




string enter_path();
