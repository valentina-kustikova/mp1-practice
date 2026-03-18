#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "artist.h"

Artist* findArtist(ArtistLibrary* artists, char* name) {
	
	int i;
	int cnt = artists->cnt;

	for (i = 0; i < cnt; i++) {
		if (strstr(artists->persons[i].name, name) != NULL) {
			return &artists->persons[i];
		}
	}
	return NULL;
}