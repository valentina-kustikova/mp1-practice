#include "func.h"

int main() {
	system("chcp 1251");
	  


	//string path;
	//path = input_path();


	////������� �������� ������, �������� �������� � ���������� �������� 
	//ifstream read;
	//if (!(read = read_list(path)))
	//{
	//	return 1;
	//}

	//int countVacancy = 0;
	//countVacancy = count_vacancy(read);
	//vacancy* Vacancy = new vacancy[countVacancy];
	//Vacancy = fill_struct(read, countVacancy);	
	string path;
	path = input_path();
	vacancyLib Vacancy(path);
	
	//����� �� ��������
	vacancy* srchVacancy;
	if (!(srchVacancy = search_vacancy(Vacancy))) {
		cerr << "�������� �� ���� �������!";
		return 1;
	}
	
	cout << "\n�� ����� �������� �� ������ �������:" << "\n\n";
	print_info(srchVacancy);


	delete [] srchVacancy;
	system("pause");
	return 0;
}
