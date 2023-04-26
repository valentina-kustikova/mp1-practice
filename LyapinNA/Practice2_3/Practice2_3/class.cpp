#include "stdafx.h"

vacancy::vacancy()
{
	employee = " ";
	nameCompany = " ";
	salary = 0;
	request = " ";
	workCond = " ";
}

ostream& operator<<(ostream& os, const vacancy& vac)
{
	os << vac.employee << endl;
	os << "Название компании: " << vac.nameCompany << endl;
	os << "Оплата труда: " << vac.salary << " в месяц." << endl;
	os << "Условия труда: " << vac.workCond << endl;
	os << "Требования к соискателю: " << vac.request << endl;
	return os;
}

istream& operator>>(istream& is, vacancy& vac)
{
	string salary, empty;
	getline(is, vac.employee);
	getline(is, vac.nameCompany);
	getline(is, salary);
	vac.salary = atoi(salary.c_str());
	getline(is, vac.workCond);
	getline(is, vac.request);
	getline(is, empty);
	return is;
}



string enter_path()
{	
	string path;
	cout << "Введите путь: ";
	cin >> path;
	return path;
}



ifstream read_list(string path)
{
	ifstream read(path);
	if (!read)	cerr << "Файл не удалось открыть!" << endl;
	else cout << "Файл по пути " << path << " был успешно открыт!" << endl;
	return read;
}



int count_vacancy(ifstream& stream)
{
	string text;
	int count = 1;
	while (getline(stream, text))
		count++;
	count /= 6;
	if (count == 0)
		return NULL;
	return count;
}



vacancy* fill_class(ifstream& stream, int countVacancy)
{
	vacancy* Vacancy = new vacancy[countVacancy];
	string empty, salary;
	int i = 0;
	stream.clear();
	stream.seekg(0);

	while (i < countVacancy) {
		stream >> Vacancy[i];
		i++;
	}

	return Vacancy;
}



tuple <vacancy*, int> search_vacancy(vacancy* Vacancy, int countVacancy)
{
	string search;
	int i = 0, count = 0, j = 0;
	cout << "Введите название профессии, которую вы ищете: ";
	getchar();
	getline(cin, search);

	int* index = new int[countVacancy];

	for (int k = 0; k < countVacancy; k++) 
		index[k] = -1;

	while (i < countVacancy) {
		if (Vacancy[i].employee.compare(search) == 0) {
			index[j] = i;
			j++;
		}
		i++;
	}

	vacancy* srchVacancy = new vacancy[j];

	for (i = 0; i < j; i++) srchVacancy[i] = Vacancy[index[i]];

	if (j == 0)
		return make_tuple(srchVacancy, NULL);

	return make_tuple(srchVacancy, j);
}




void output_info(vacancy* Vacancy, int searchedVacancy)
{
	if (searchedVacancy == 1)
		cout << "По Вашему запросу была найдена 1 вакансия: ";
	else if (searchedVacancy > 4)
		cout << "По Вашему запросу было найдено " << searchedVacancy << " вакансий: ";
	else
		cout << "По Вашему запросу было найдно " << searchedVacancy << " вакансии: ";


	for (int i = 0; i < searchedVacancy; i++) {
		cout << "\n-------------------------------------------\n";
		cout << Vacancy[i];
	}
}

