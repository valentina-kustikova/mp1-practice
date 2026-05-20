#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <string>

struct quote{
	std::string the_line;
	std::string author;
	std::string source;
	std::string theme;
	std::string* key_words;
	int key_words_count;

	quote();
	~quote() {delete[] this->key_words;}
	const quote& operator=(const quote&);
}; 

struct phrase_library {
	quote* phrases;
	int count;

	phrase_library();
	phrase_library(const std::string&);
	~phrase_library() {delete[] this->phrases; }
	void find_quotes_by_key_words(const std::string&, phrase_library&);
	friend std::ostream& operator<< (std::ostream&, const phrase_library&);
};

#endif
