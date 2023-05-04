#include "func.h"

int main() {
	system("chcp 1251");
	  	
	string path;
	path = input_path();

	try
	{
		vacancyLib VacancyBase(path);
		//cout << VacancyBase;
		vacancyLib srchVacancy = VacancyBase.search_vacancy();

		if (srchVacancy.countVacancy == 0) {
			cerr << "Вакансий не было найдено!";
			return 1;
		}
	
		cout << "\nМы нашли вакансии по Вашему запросу:" << "\n\n";
		cout << srchVacancy << endl;
	}
	catch (const int ex) 
	{
		cout << "Путь был введен неверно или файла не существует!" << endl;
		return 1;			
	}
	


	system("pause");
	return 0;
}
