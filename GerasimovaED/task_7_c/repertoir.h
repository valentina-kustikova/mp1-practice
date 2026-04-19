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
}FILM;

void director_counter(char director_name[], int cnt, FILM _rep[], int* dir_cnt);
void director_finder(char director_name[], int cnt, FILM _rep[], int dir_cnt, FILM dir_rep[]);
void free_arrays(int cnt, int dir_cnt, FILM _rep[], FILM dir_rep[]);

#endif