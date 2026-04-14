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
	POP_ART_GENRE = 13,
} Genre;

typedef enum {
	MUSEUM = 1,
	PRIVATE = 2,
} Location;

typedef struct Painting {
	int artist_id;
	char title[MAX_LEN];
	int year;
	Genre genre;
	Location location;
} Painting;

typedef struct PaintingsLibrary {
	Painting* works;
	int cnt;
} PaintingsLibrary;

Genre stringToGenre(char* str);
char* genreToString(Genre genre);
Location stringToLocation(char* str);
char* locationToString(Location location);

PaintingsLibrary* findPaintings(PaintingsLibrary* paintings, int artistId);

float calculateLocationStats(PaintingsLibrary* paintings);

#endif