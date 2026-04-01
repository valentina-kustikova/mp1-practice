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
	POP_ART = 6,
} Style;

typedef struct Artist {
	// int painter_id;
	char name[MAX_LEN];
	int birthYear; // Date
	char style[MAX_LEN];
} Artist;

typedef struct ArtistLibrary {
	Artist* persons;
	int cnt;
} ArtistLibrary;

Artist* findArtist(ArtistLibrary* artists, char* name);

#endif