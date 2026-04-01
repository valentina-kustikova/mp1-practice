#ifndef PAINTINGS_H
#define PAINTINGS_H

#define MAX_LEN 2048

typedef enum {
	PORTRAIT = 0,
	RELIGIOUS = 1,
	DRAWING = 2,
	SCULPTURE = 3,
	HISTORY = 4,
	GROUP_PORTRAIT = 5,
	SELF_PORTRAIT = 6,
	MYTHOLOGICAL = 7,
	SEASCAPE = 8,
	LANDSCAPE = 9,
	STILL_LIFE = 10,
	INTERIOR = 11,
	SURREAL = 12,
	POP_ART = 13,
} Genre;

typedef enum {
	MUSEUM = 0,
	PRIVATE = 1,
} Location;

typedef struct Painting {
	// int painting_id;
	char artistName[MAX_LEN]; // int artist_id;
	char title[MAX_LEN];
	int year;
	char genre[MAX_LEN]; // Genre genre;
	char location[MAX_LEN]; // Location location
} Painting;

typedef struct PaintingsLibrary {
	Painting* works;
	int cnt;
} PaintingsLibrary;

PaintingsLibrary* findPaintings(PaintingsLibrary* paintings, char* artistName);

float calculateLocationStats(PaintingsLibrary* paintings);

#endif