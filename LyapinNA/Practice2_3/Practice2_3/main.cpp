#include "class.h"

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
	if (!(ind = search_vacancy(Vacancy, count)))
	{
		cerr << "Искомых вакансий не было найдено!" << endl;
		return 1;
	}
		



	delete[] Vacancy;
	delete[] ind;
	read.close();
	return 0;
}