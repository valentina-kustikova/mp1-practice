#include "func.h"

int main() {
	system("chcp 1251");
	  


	int countVacancy = 0;
	string path = "list.txt";
	ifstream read;




	//������� �������� ������, �������� �������� � ���������� �������� 
	read = read_list(path);
	countVacancy = count_vacancy(read);
	vacancy* Vacancy = new vacancy[countVacancy];
	Vacancy = fill_struct(read, countVacancy);	

	

	//����� �� ��������
	vacancy* srchVacancy;
	if (!(srchVacancy = search_vacancy(Vacancy, countVacancy))) {
		cerr << "�������� �� ���� �������!";
		return 1;
	}
	
	cout << "\n�� ����� �������� �� ������ �������:" << "\n\n";
	print_info(srchVacancy);


	read.close();
	delete[] srchVacancy;
	delete [] Vacancy;
	system("pause");
	return 0;
}
