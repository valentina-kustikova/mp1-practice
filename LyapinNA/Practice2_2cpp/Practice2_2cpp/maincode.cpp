#include "func.h"

int main() {
	system("chcp 1251");
	  


	int countVacancy = 0;
	string path = "list.txt";
	ifstream read;




	//Функции открытия потока, подсчета вакансий и заполнения структур 
	read = read_list(path);
	countVacancy = count_vacancy(read);
	vacancy* Vacancy = new vacancy[countVacancy];
	Vacancy = fill_struct(read, countVacancy);	

	

	//Поиск по названию
	vacancy* srchVacancy;
	if (!(srchVacancy = search_vacancy(Vacancy, countVacancy))) {
		cerr << "Вакансий не было найдено!";
		return 1;
	}
	
	cout << "\nМы нашли вакансии по Вашему запросу:" << "\n\n";
	print_info(srchVacancy);


	read.close();
	delete[] srchVacancy;
	delete [] Vacancy;
	system("pause");
	return 0;
}
