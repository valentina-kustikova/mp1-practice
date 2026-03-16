#ifndef PAINTINGS_H
#define PAINTINGS_H

#define MAX_LEN 2048

typedef struct Painting {
	char artistName[MAX_LEN];
	char title[MAX_LEN];
	int year;
	char genre[MAX_LEN];
	char location[MAX_LEN];
} Painting;

void findPaintings(Painting* paintings, int cnt, char* artistName,
	Painting** result, int* foundCountPaintings);

void calculateLocationStats(Painting* paintings, int cnt,
	int* museumCount, int* privateCount);

#endif