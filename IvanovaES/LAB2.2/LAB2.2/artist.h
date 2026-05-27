#ifndef ARTIST_H
#define ARTIST_H

#define MAX_LEN 2048

typedef enum {
	RENAISSANCE = 0,
	BAROQUE = 1,
	IMPRESSIONISM = 2,
	POST_IMPRESSIONISM = 3,
	CUBISM = 4,
	SURREALISM = 5,
	POP_ART_STYLE = 6,
} Style;

typedef struct Artist {
	int painter_id;
	char name[MAX_LEN];
	int birthYear; // Date
	Style style;
} Artist;

typedef struct ArtistLibrary {
	Artist* persons;
	int cnt;
} ArtistLibrary;

Style stringToStyle(char* str);
char* styleToString(Style style);
Artist* findArtist(ArtistLibrary* artists, char* name);

#endif