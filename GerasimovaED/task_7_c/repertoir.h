#ifndef IS_REPERTOIR_INCLUDED
#define IS_REPERTOIR_INCLUDED

#define MAX_SIZE 1024

typedef struct {
	char* name;
	char* director;
	char* country;
	int year;
	unsigned int budget;
	unsigned int fees;
}Film;

typedef struct {
	Film* info;
	int cnt;
}FilmLibrary;

int director_counter(char* director_name, FilmLibrary* _rep);
FilmLibrary director_finder(char* director_name, FilmLibrary* _rep, int cnt);
void free_array(FilmLibrary* arr);

#endif