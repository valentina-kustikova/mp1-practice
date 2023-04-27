#include "func.h"

vacancyLib::vacancyLib(string path)
{
 
	ifstream read;
	countVacancy = 0;
	if (!(read = read_list(path)))
	{
		cout << "���������� ������� ����!";
		Vacancy = nullptr;
	}
	else 
	{
		countVacancy = count_vacancy(read);
		Vacancy = new vacancy[countVacancy];
		Vacancy = fill_struct(read, countVacancy);
	}
	read.close();
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
ifstream read_list(string path) {
	ifstream read(path);

	if (!read)
		return read;
	else
		return read;

}




int count_vacancy(ifstream& read) {
	string line;
	int count = 0, countVacancy = 0;

	while (getline(read, line))
		++count;

	//����������� ����� ��������
	countVacancy = (count + 1 )/ N;
	if (countVacancy == 0) {
		cerr << "Error: ����� �������� �� ����� ���� ������ 0!";
		return 1;
	}
	else
		cout << "����� ��������� ��������: " << countVacancy << endl;

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





vacancy* search_vacancy(vacancyLib Vacancy) {
	string search;
	vacancy* searchedVacancy;
	int* index = new int[Vacancy.countVacancy];
	cout << "������� �������� ���������, ������� �� �����: " << endl;
	getchar();
	getline(cin, search);


	int j = 0, k = 0;
	for (; j < Vacancy.countVacancy; j++) {
		index[j] = -1;
		if (Vacancy.Vacancy[j].employee.compare(search) == 0) {
			index[k] = j;
			k++;
		}
	}

	if (index[0] == -1) {
		return NULL;
	}

	searchedVacancy = new vacancy[k+1];
	
	for (j = 0; j < k; j++)	searchedVacancy[j] = Vacancy.Vacancy[index[j]];

	searchedVacancy[k].employee = " "; //��� ����������� ����� �������

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

