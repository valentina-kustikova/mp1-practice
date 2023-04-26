#include "stdafx.h"

int main() {
	system("chcp 1251");
	

	
	string path;
	string test;
	ifstream read;
	vacancy* Vacancy;
	int count = 0;
	int* ind;



	path = enter_path();
	read = read_list(path);
	if (!(count = count_vacancy(read)))
	{
		cerr << "Вакансий не было найдено! Проверьте правильность указанного пути." << endl;
		return 1;
	}



	ind = new int[count]; //cout << count;
	Vacancy = new vacancy[count];
	Vacancy = fill_class(read, count);


	auto srchVacancy = search_vacancy(Vacancy, count);
	int searchedVacancy = get<1>(srchVacancy);
	if (searchedVacancy == NULL)
	{
		cerr << "Искомых вакансий не было найдено!" << endl;
		delete[] Vacancy;
		delete[] ind;
		read.close();
		return 1;
	}
	else
	{
		output_info(get<0>(srchVacancy), get<1>(srchVacancy));
	}
		



	delete[] Vacancy;
	delete[] ind;
	read.close();
	return 0;
}