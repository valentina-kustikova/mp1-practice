#include "func.h"



vacancyLib::vacancyLib()
{
	Vacancy = nullptr;
	countVacancy = 0;
}



vacancyLib::vacancyLib(vacancy* vac, int count)
{
	Vacancy = vac;
	countVacancy = count;
}



vacancyLib::vacancyLib(const string& path)
{
 
	ifstream read;
	countVacancy = 0;
	read = read_list(path);
	

	countVacancy = count_vacancy(read);
	Vacancy = new vacancy[countVacancy];
	Vacancy = fill_struct(read, countVacancy);
	read.close();
}



vacancyLib::vacancyLib(const vacancyLib& copy_vac)
{
	countVacancy = copy_vac.countVacancy;
	vacancy* NewVacancy = new vacancy[copy_vac.countVacancy];
	for (int i = 0; i < copy_vac.countVacancy; i++) NewVacancy[i] = copy_vac.Vacancy[i];
	Vacancy = NewVacancy;
}



vacancyLib::~vacancyLib()
{
	delete[] Vacancy;
}


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


ostream& operator<<(ostream& os, const vacancyLib vac)
{
	for (int j = 0; j < vac.countVacancy; j++) {
		cout << "\n\n-----------------------------------\n";
		cout << vac.Vacancy[j];
		cout << "-----------------------------------\n";
	}
	return os;
}



string input_path()
{	
	string path;
	cout << "Введите путь к txt файлу: ";
	cin >> path;
	return path;
}




//Функция открытия потока для чтения
ifstream vacancyLib::read_list(const string path) {
	ifstream read(path);

	if (!read)
	{
		throw -1;
	}
	else { return read; }

}




int vacancyLib::count_vacancy(ifstream& read) {
	string line;
	int count = 0, countVacancy = 0;
	while (getline(read, line)) ++count;
	countVacancy = (count + 1 )/ N;
	if (countVacancy == 0) 
	{
		cerr << "Error: Число вакансий не может быть равным 0!";
		return 1;
	}
	else cout << "Число найденных вакансий: " << countVacancy << endl;


	return countVacancy;
}





vacancy* vacancyLib::fill_struct(ifstream& read, int countVacancy) {
	vacancy* Vacancy = new vacancy[countVacancy];
	read.clear();
	read.seekg(0);
	int i = 0;
	for (; i < countVacancy; i++) read >> Vacancy[i];


	return Vacancy;
}





vacancyLib vacancyLib::search_vacancy() {
	string search;
	vacancy* searchedVacancy;
	int* index = new int[countVacancy];
	cout << "Введите название профессии, которую вы ищете: " << endl;
	getchar();
	getline(cin, search);
	int j = 0, k = 0;
	for (; j < countVacancy; j++) {
		index[j] = -1;
		if (Vacancy[j].employee.compare(search) == 0) {
			index[k] = j;
			k++;
		}
	}
	if (index[0] == -1) {
		vacancyLib empty;
		return empty;
	}
	searchedVacancy = new vacancy[k];
	for (j = 0; j < k; j++)	searchedVacancy[j] = Vacancy[index[j]];
	vacancyLib res(searchedVacancy, k);


	return res;
}


