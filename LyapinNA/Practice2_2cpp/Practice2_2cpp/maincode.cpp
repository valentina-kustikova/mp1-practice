#include "func.h"

int main() {
	system("chcp 1251");
	  	
	string path;
	path = input_path();
	vacancyLib Vacancy(path);
	
	//����� �� ��������
	vacancyLib srchVacancy = search_vacancy(Vacancy);
	if (srchVacancy.countVacancy == 0) {
		cerr << "�������� �� ���� �������!";
		return 1;
	}
	
	cout << "\n�� ����� �������� �� ������ �������:" << "\n\n";
	print_info(srchVacancy);


	system("pause");
	return 0;
}
