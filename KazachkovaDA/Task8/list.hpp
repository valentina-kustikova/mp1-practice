#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct quote{
	string the_line;
	string author;
	string source;
	string theme;
	vector <string> key_words;
	int key_words_count;

	quote();
}; 

typedef struct phrase_library {
	quote* phrases;
	int count;

	phrase_library();
	phrase_library(const string&);
	~phrase_library() {delete[] this->phrases; }
	void find_quotes_by_key_words(phrase_library&, const char*, phrase_library);
	friend ostream& operator<< (ostream&, const phrase_library&);
};

#endif
