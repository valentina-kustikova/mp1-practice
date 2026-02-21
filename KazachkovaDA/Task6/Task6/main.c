#include <stdio.h>
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "Russian");

	struct book 
	{
	char* author, * title, * publisher;
	int publishing_year;
	};

	char file_name[] = "library.txt";
	int * pFileName = &file_name;
	
	
	
	return 0;

}