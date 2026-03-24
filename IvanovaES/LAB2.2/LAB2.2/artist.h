#ifndef ARTIST_H
#define ARTIST_H

#define MAX_LEN 2048

typedef struct Artist {
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