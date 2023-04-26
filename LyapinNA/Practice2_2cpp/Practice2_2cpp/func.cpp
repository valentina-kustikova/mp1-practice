#include "func.h"





ostream& operator<<(ostream& os, const vacancy& vac)
{
	os << "Профессия: " << vac.employee << endl;
	os << "Название компании: " << vac.nameCompany << endl;
	os << "Зарплата: " << vac.salary << endl;
	os << "Условия труда: " << vac.workCond << endl;
	os << "Требования к соискателю: " << vac.request << endl;
	return os;
}



istream& operator>>(istream& is, vacancy& vac)
{
	string umpty;
	getline(is, vac.employee);
	getline(is, vac.nameCompany);
	getline(is, vac.salary);
	getline(is,	vac.workCond);
	getline(is, vac.request);
	getline(is, umpty);
	return is;
}




//Функция открытия потока для чтения
ifstream read_list(string path) {
	ifstream read(path);

	if (!read)
		cerr << "Произошла ошибка при открытия файла для чтения!" << endl;
	else
		cout << "Поток был успешно открыт!" << endl;

	return read;
}





int count_vacancy(ifstream& read) {
	string line;
	int count = 0, countVacancy = 0;

	while (getline(read, line))
		++count;

	//Определение числа вакансий
	countVacancy = (count + 1 )/ N;
	if (countVacancy == 0) {
		cerr << "Error: Число вакансий не может быть равным 0!";
		return 1;
	}
	else
		cout << "Число найденных вакансий: " << countVacancy << endl;

	return countVacancy;
}





vacancy* fill_struct(ifstream& read, int countVacancy) {
	vacancy* Vacancy = new vacancy[countVacancy];

	read.clear();
	read.seekg(0);
	int i = 0;
	for (; i < countVacancy; i++) read >> Vacancy[i];
	return Vacancy;
}





vacancy* search_vacancy(vacancy* Vacancy, int countVacancy) {
	int j = 0, k = 0;
	string search;
	vacancy* searchedVacancy;
	int* index = new int[countVacancy];
	cout << "Введите название профессии, которую вы ищете: " << endl;
	getline(cin, search);


	for (; j < countVacancy; j++) {
		index[j] = -1;
		if (Vacancy[j].employee.compare(search) == 0) {
			index[k] = j;
			k++;
		}
	}

	if (index[0] == -1) {
		return NULL;
	}


	searchedVacancy = new vacancy[k+1];
	
	for (j = 0; j < k; j++)	searchedVacancy[j] = Vacancy[index[j]];

	searchedVacancy[k].employee = " "; //для обозначения конца массива

	return searchedVacancy;
}




void print_info(vacancy* Vacancy) {
	int j = 0;
	for (j = 0; Vacancy[j].employee != " "; j++) {
		cout << "\n\n-----------------------------------\n";
		cout << Vacancy[j];
		cout << "-----------------------------------\n";
	}	
}