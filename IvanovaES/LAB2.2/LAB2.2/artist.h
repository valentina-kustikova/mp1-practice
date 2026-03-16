#ifndef ARTIST_H
#define ARTIST_H

#define MAX_LEN 2048

typedef struct Artist{
	char name[MAX_LEN];
	int birthYear;
	char style[MAX_LEN];
} Artist;

void findArtist(Artist* artists, int cnt, char* name, Artist** foundArtist);

#endif