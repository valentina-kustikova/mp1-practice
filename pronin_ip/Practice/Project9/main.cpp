#include "todolist.h"
void main()
{
	setlocale(LC_ALL, "Russian");
	Todolist todolist;
	cout << "Choose the date" << endl;
	int d, m, y;
	cin >> d >> m >> y;
	if ((d < 0 || d > 31) || (m < 0 || m > 12) || (y > 2019))
		cout << "Not correct date" << endl;
	else
	{
		Date date(d, m, y);
		todolist.Read("myfile.txt");
		todolist.Print(date);
		system("pause");
	}
}