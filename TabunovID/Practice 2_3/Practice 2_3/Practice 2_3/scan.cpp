#define STRLEN 10

#include "action.h"
#include <iostream>
#include <fstream>
#include "action.h"

using namespace std;

void My_scan(teamarray& book) {
	string filepath;
	cin >> filepath;
	ifstream file(filepath);
	file >> book.length;
	book.teams = new team[book.length];
	for (size_t i = 0; i < book.length; i++)
	{
		file >> book.teams[i];
	}
}

void output() {
	teamarray book;
	book.teams = NULL;
	book.length = 0;
	My_scan(book);
	size_t best_id = 0;
	if (book.teams != NULL) {
		for (size_t i = 1; i < book.length; i++)
		{
			if (book.teams[best_id].Points < book.teams[i].Points)
				best_id = i;
		}
		/*cout << book.teams[best_id].Name << endl << book.teams[best_id].City <<
			endl <<book.teams[best_id].Games << endl << book.teams[best_id].Players
			<< endl << book.teams[best_id].Points;*/
			/*cout << book.teams[best_id];*/
		cout << book.teams[best_id];
	}
}

using namespace std;

