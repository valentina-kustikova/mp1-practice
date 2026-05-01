#include "list.hpp"
#include <fstream>
using namespace std;

phrase_library::phrase_library()
{
	phrases = nullptr;
	count = 0;
}

phrase_library::phrase_library(const string& file_name)
{
	ifstream file(file_name);
	if (file.is_open() == false)
	{
		throw "File reading error";
	}

	string line;
	int n = 0;
	while (getline(file, line)) {
		n++;
	}

	if (n == 0)
	{
		throw "No info found in the file";
	}

	phrases = new quote[n];

	//since you have reached (and attempted to read past)
	// the end of the file, the eof and fail flags will be set. You need to clear them using ifile.clear
	file.clear();
	file.seekg(0, ios::beg);

	for (int i = 0; i < n; i++) {
		string the_line, author, source, theme, key_words, a_word;

		getline(file, line, ';');
		the_line = line;
		phrases[i].the_line = the_line;

		getline(file, line, ';');
		author = line;
		phrases[i].author = author;

		getline(file, line, ';');
		source = line;
		phrases[i].source = source;

		getline(file, line, ';');
		theme = line;
		phrases[i].theme = theme;

		getline(file, line, ';');
		key_words = line;

		






}