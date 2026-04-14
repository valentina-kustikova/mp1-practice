#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "artist.h"

Style stringToStyle(char* str) {
	if (strcmp(str, "Renaissance") == 0) return RENAISSANCE;
	if (strcmp(str, "Baroque") == 0) return BAROQUE;
	if (strcmp(str, "Impressionism") == 0) return IMPRESSIONISM;
	if (strcmp(str, "Post_Impressionism") == 0) return POST_IMPRESSIONISM;
	if (strcmp(str, "Cubism") == 0) return CUBISM;
	if (strcmp(str, "Surrealism") == 0) return SURREALISM;
	if (strcmp(str, "Pop_Art") == 0) return POP_ART_STYLE;
	return RENAISSANCE;
}

char* styleToString(Style style) {
	switch (style) {
	case RENAISSANCE: return "Renaissance";
	case BAROQUE: return "Baroque";
	case IMPRESSIONISM: return "Impressionism";
	case POST_IMPRESSIONISM: return "Post_Impressionism";
	case CUBISM: return "Cubism";
	case SURREALISM: return "Surrealism";
	case POP_ART_STYLE: return "Pop_Art";
	default: return "Unknown";
	}
}

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