#include "stdafx.h"

int main() {
	system("chcp 1251");

	try
	{
		string path = enter_path();
		vacancyLib vacancyData(path);
		vacancyLib searchedVacancyData;
		searchedVacancyData = vacancyData.search_vacancy();
		cout << searchedVacancyData;
	}
	catch (const int ex)
	{
		return 1;
	}

	return 0;
}