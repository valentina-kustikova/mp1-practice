#include "list.hpp"
#include "additional.hpp"

int main() {

	const std::string file_name = "list.txt";
	phrase_library quotes(file_name);
	phrase_library founded;

	std::string request_word;
	const std::string exit = "exit";

	do {
		std::cout<< "Enter the key word: ";
		std::cin >> request_word;
		
		if (request_word == exit)
		{
			return 0;
		}

		quotes.find_quotes_by_key_words(request_word, founded);
		std::cout << founded;

	} while (1);

}

