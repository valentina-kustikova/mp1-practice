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

	friend vacancy* fill_class(ifstream& stream, int countVacancy);
	//friend vacancyLib& search_vacancy(vacancyLib vaclib);

	friend ostream& operator << (ostream& os, const vacancy& vac);
	friend istream& operator >> (istream& is, vacancy& vac);
};





class vacancyLib {
private: 
	vacancy* Vacancy;
	int count;
public:
	vacancyLib();
	vacancyLib(const string& path);
	vacancyLib(vacancy* OutVacancy, int OutCount);
	vacancyLib(const vacancyLib& vac_copy);
	~vacancyLib();
	vacancyLib& operator= (const vacancyLib& cp_vac);

	friend ostream& operator << (ostream& os, const vacancyLib& vacLib);
	friend vacancyLib search_vacancy(vacancyLib& vaclib);
};






vacancy* fill_class(ifstream& stream, int countVacancy);
string enter_path();
ifstream read_list(const string& path);
int count_vacancy(ifstream& stream);
vacancyLib search_vacancy(vacancyLib& vaclib);
