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

typedef struct PaintingsLibrary {
	Painting* works;
	int cnt;
} PaintingsLibrary;

PaintingsLibrary* findPaintings(PaintingsLibrary* paintings, char* artistName);

float calculateLocationStats(PaintingsLibrary* paintings);

#endif