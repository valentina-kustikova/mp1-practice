#include "stdafx.h"

vacancy::vacancy()
{
	employee = " ";
	nameCompany = " ";
	salary = 0;
	request = " ";
	workCond = " ";
}

string vacancy::getInfoVacancy(int select)
{
	switch (select) {
	case 1: return employee;
	case 2: return nameCompany;
	case 3: return to_string(salary);
	case 4: return workCond;
	case 5: return request;
	default: return "Неправильный ввод параметра";
	}
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



ifstream vacancyLib::read_list(const string& path)
{
	ifstream read(path);
	if (!read)	cerr << "Файл не удалось открыть!" << endl;
	else cout << "Файл по пути " << path << " был успешно открыт!" << endl;
	return read;
}



int vacancyLib::count_vacancy(ifstream& stream)
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



vacancy* vacancyLib::fill_from_txt(ifstream& stream, int countVacancy)
{
	vacancy* Vacancy = new vacancy[countVacancy];
	int i = 0;
	stream.clear();
	stream.seekg(0);

	while (i < countVacancy) {
		stream >> Vacancy[i];
		i++;
	}

	return Vacancy;
}


vacancyLib vacancyLib::search_vacancy()
{
	string search;
	int i = 0, j = 0;
	cout << "Введите название профессии, которую вы ищете: ";
	getchar();
	getline(cin, search);

	int* index = new int[count];

	for (int k = 0; k < count; k++) 
		index[k] = -1;

	while (i < count) {
		if (Vacancy[i].getInfoVacancy(1).compare(search) == 0) {
			index[j] = i;
			j++;
		}
		i++;
	} 

	vacancy* srchVacancy = new vacancy[j];
	for (i = 0; i < j; i++)
	{
		srchVacancy[i] = Vacancy[index[i]];
		//cout << srchVacancy[i];
	}

	vacancyLib res(srchVacancy, j);
	return res;
}


ostream& operator<<(ostream& os, const vacancyLib& vacLib)
{
	for (int i = 0; i < vacLib.count; i++) {
		os << "----------------------------------------" << endl;

		os << vacLib.Vacancy[i];
		os << "----------------------------------------" << endl << endl << endl;
	}
	return os;
}








vacancyLib::vacancyLib()
{
	count = 0;
	Vacancy = nullptr;
}



vacancyLib::vacancyLib(const string& path)
{
	ifstream read;
	read = read_list(path);
	if (!read) throw - 1;

	count = count_vacancy(read);
	Vacancy = new vacancy[count];
	Vacancy = fill_from_txt(read, count);
	read.close();
}

vacancyLib::vacancyLib(vacancy* OutVacancy, int OutCount)
{
	count = OutCount;
	Vacancy = new vacancy[count];
	for (int i = 0; i < count; i++) Vacancy[i] = OutVacancy[i];
}

vacancyLib::vacancyLib(const vacancyLib& vac_copy)
{
	Vacancy = new vacancy[vac_copy.count];
	count = vac_copy.count;
	for (int i = 0; i < count; i++) Vacancy[i] = vac_copy.Vacancy[i];
}

vacancyLib::~vacancyLib()
{
	delete[] Vacancy;
}

vacancyLib& vacancyLib::operator= (const vacancyLib& cp_vac)
{
	if (this == &cp_vac) { // проверяем, что мы не присваиваем объект самому себе
		return *this;
	}
	if (count != cp_vac.count) { // проверяем, если количество элементов изменилось, то освобождаем память и выделяем новую
		delete[] Vacancy;
		count = cp_vac.count;
		Vacancy = new vacancy[count];
	}
	for (int i = 0; i < count; i++) { // копируем значения из объекта cp_vac в текущий
		Vacancy[i] = cp_vac.Vacancy[i];
	}
	return *this; // возвращаем ссылку на текущий объект

}
