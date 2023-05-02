#include "stdafx.h"

int main() {
	system("chcp 1251");
	string path = enter_path();
	vacancyLib vacancyData(path);
	cout << vacancyData;
	cout << "\n\n\n\n\n";


	vacancyLib searchedVacancyData;
	searchedVacancyData = search_vacancy(vacancyData);

	cout << searchedVacancyData;
	return 0;
}