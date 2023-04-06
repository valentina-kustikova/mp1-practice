#include "class.h"




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
	string empty, text1, text2, text3, text4, text5;
	int i = 0;
	stream.clear();
	stream.seekg(0);
	while (i < countVacancy) {
		getline(stream, text1);
		getline(stream, text2);
		getline(stream, text3);
		getline(stream, text4);
		getline(stream, text5);
		getline(stream, empty);
		vacancy VacancyCopy(text1, text2, text3, text4, text5);
		Vacancy[i] = VacancyCopy;
		i++;
	}

	return Vacancy;
}



int* search_vacancy(vacancy* Vacancy, int countVacancy)
{
	string search;
	int i = 0, count = 0, j = 0;
	cout << "Введите название профессии, которую вы ищете: ";
	cin >> search;
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

	if (j == 0)
		return NULL;

	output_info(Vacancy, index, j);
	return index;
}



void output_info(vacancy* Vacancy, int* ind, int searchedVacancy)
{
	if (searchedVacancy == 1)
		cout << "По Вашему запросу была найдена 1 вакансия: ";
	else if (searchedVacancy > 4)
		cout << "По Вашему запросу было найдено " << searchedVacancy << " вакансий: ";
	else
		cout << "По Вашему запросу было найдно " << searchedVacancy << " вакансии: ";

	for (int i = 0; i < searchedVacancy; i++) {
		cout << "\n-------------------------------------------\n";
		cout << Vacancy[ind[i]].GetEmployee() << endl;
		cout << "Название компании: " << Vacancy[ind[i]].GetNameCompany() << endl;
		cout << "Оплата труда: " << Vacancy[ind[i]].GetSalary() << " в месяц." << endl;
		cout << "Условия труда: " << Vacancy[ind[i]].GetWorkCond() << endl;
		cout << "Требования к соискателю: " << Vacancy[ind[i]].GetRequest() << endl;
	}
}



//Конструкторы 

vacancy::vacancy()
{
	employee = " ";
	nameCompany = " ";
	salary = " ";
	workCond = " ";
	request = " ";
}

vacancy::vacancy(string employee, string nameCompany, string salary, string workCond, string request)
{
	this->employee = employee;
	this->nameCompany = nameCompany;
	this->salary = salary;
	this->workCond = workCond;
	this->request = request;
}

//Определения геттеров
string vacancy::GetNameCompany()
{
	return nameCompany;
}

string vacancy::GetEmployee()
{
	return employee;
}

string vacancy::GetSalary()
{
	return salary;
}

string vacancy::GetWorkCond()
{
	return workCond;
}

string vacancy::GetRequest()
{
	return request;
}
