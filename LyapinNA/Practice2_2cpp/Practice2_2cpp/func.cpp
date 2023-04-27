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

	/*if (!(read = read_list(path)))
	{
		cout << "���������� ������� ����!";
		Vacancy = nullptr;
	}
	else 
	{
		countVacancy = count_vacancy(read);
		Vacancy = new vacancy[countVacancy];
		Vacancy = fill_struct(read, countVacancy);
	}*/

	try
	{
		read = read_list(path);
	}
	catch (const int ex)
	{
		cout << "���� ��� ������ ������� ��� ����� �� ����������!" << endl;
		Vacancy = nullptr;
	}
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
	os << "���������: " << vac.employee << endl;
	os << "�������� ��������: " << vac.nameCompany << endl;
	os << "��������: " << vac.salary << endl;
	os << "������� �����: " << vac.workCond << endl;
	os << "���������� � ����������: " << vac.request << endl;
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




string input_path()
{	
	string path;
	cout << "������� ���� � txt �����: ";
	cin >> path;
	return path;
}




//������� �������� ������ ��� ������
ifstream read_list(const string path) {
	ifstream read(path);

	if (!read)
	{
		throw -1;
		return read;
	}
	else return read;

}




int count_vacancy(ifstream& read) {
	string line;
	int count = 0, countVacancy = 0;
	while (getline(read, line)) ++count;
	countVacancy = (count + 1 )/ N;
	if (countVacancy == 0) 
	{
		cerr << "Error: ����� �������� �� ����� ���� ������ 0!";
		return 1;
	}
	else cout << "����� ��������� ��������: " << countVacancy << endl;


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





vacancyLib search_vacancy(vacancyLib InVacancyLibrary) {
	string search;
	vacancy* searchedVacancy;
	int* index = new int[InVacancyLibrary.countVacancy];
	cout << "������� �������� ���������, ������� �� �����: " << endl;
	getchar();
	getline(cin, search);
	int j = 0, k = 0;
	for (; j < InVacancyLibrary.countVacancy; j++) {
		index[j] = -1;
		if (InVacancyLibrary.Vacancy[j].employee.compare(search) == 0) {
			index[k] = j;
			k++;
		}
	}
	if (index[0] == -1) {
		vacancyLib empty;
		return empty;
	}
	searchedVacancy = new vacancy[k];
	for (j = 0; j < k; j++)	searchedVacancy[j] = InVacancyLibrary.Vacancy[index[j]];
	vacancyLib res(searchedVacancy, k);


	return res;
}




void print_info(vacancyLib VacancyLib) {
	int j = 0;
	for (j = 0; j < VacancyLib.countVacancy; j++) {
		cout << "\n\n-----------------------------------\n";
		cout << VacancyLib.Vacancy[j];
		cout << "-----------------------------------\n";
	}	
}

