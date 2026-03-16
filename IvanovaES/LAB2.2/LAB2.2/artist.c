#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "artist.h"

void findArtist(Artist* artists, int cnt, char* name, Artist** foundArtist) {
	
	int i;
	*foundArtist = NULL;

	for (i = 0; i < cnt; i++) {
		if (strstr(artists[i].name, name) != NULL) {
			*foundArtist = &artists[i];
		}
	}
	return;
}