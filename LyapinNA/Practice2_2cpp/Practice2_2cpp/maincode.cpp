#include "func.h"

int main() {
	system("chcp 1251");
	  	
	string path;
	path = input_path();
	vacancyLib Vacancy(path);
	
	//Поиск по названию
	vacancyLib srchVacancy = search_vacancy(Vacancy);
	if (srchVacancy.countVacancy == 0) {
		cerr << "Вакансий не было найдено!";
		return 1;
	}
	
	cout << "\nМы нашли вакансии по Вашему запросу:" << "\n\n";
	print_info(srchVacancy);


	system("pause");
	return 0;
}
