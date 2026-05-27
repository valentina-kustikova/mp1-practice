#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paintings.h"

Genre stringToGenre(char* str) {
	if (strcmp(str, "portrait") == 0) return PORTRAIT;
	if (strcmp(str, "religious") == 0) return RELIGIOUS;
	if (strcmp(str, "drawing") == 0) return DRAWING;
	if (strcmp(str, "sculpture") == 0) return SCULPTURE;
	if (strcmp(str, "history") == 0) return HISTORY;
	if (strcmp(str, "group_portrait") == 0) return GROUP_PORTRAIT;
	if (strcmp(str, "self_portrait") == 0) return SELF_PORTRAIT;
	if (strcmp(str, "mythological") == 0) return MYTHOLOGICAL;
	if (strcmp(str, "seascape") == 0) return SEASCAPE;
	if (strcmp(str, "landscape") == 0) return LANDSCAPE;
	if (strcmp(str, "still_life") == 0) return STILL_LIFE;
	if (strcmp(str, "interior") == 0) return INTERIOR;
	if (strcmp(str, "surreal") == 0) return SURREAL;
	if (strcmp(str, "pop_art") == 0) return POP_ART_GENRE;
	return PORTRAIT;
}

char* genreToString(Genre genre) {
	switch (genre) {
	case PORTRAIT: return "portrait";
	case RELIGIOUS: return "religious";
	case DRAWING: return "drawing";
	case SCULPTURE: return "sculpture";
	case HISTORY: return "history";
	case GROUP_PORTRAIT: return "group_portrait";
	case SELF_PORTRAIT: return "self_portrait";
	case MYTHOLOGICAL: return "mythological";
	case SEASCAPE: return "seascape";
	case LANDSCAPE: return "landscape";
	case STILL_LIFE: return "still_life";
	case INTERIOR: return "interior";
	case SURREAL: return "surreal";
	case POP_ART_GENRE: return "pop_art";
	default: return "unknown";
	}
}

Location stringToLocation(char* str) {
	if (strcmp(str, "museum") == 0) return MUSEUM;
	if (strcmp(str, "private") == 0) return PRIVATE;
	return MUSEUM;
}

char* locationToString(Location location) {
	switch (location) {
	case MUSEUM: return "museum";
	case PRIVATE: return "private";
	default: return "unknown";
	}
}

PaintingsLibrary* findPaintings(PaintingsLibrary* paintings, int artistId) {


	int i;
	int k = 0, foundCountPaintings = 0;
	int cnt = paintings->cnt;

	for (i = 0; i < cnt; i++) {
		if (paintings->works[i].artist_id  == artistId) {
			foundCountPaintings++;

		}
	}

	if (foundCountPaintings == 0) {
		return NULL;
	}

	PaintingsLibrary* result = malloc(sizeof(PaintingsLibrary));
	result->cnt = foundCountPaintings;
	result->works = malloc(foundCountPaintings * sizeof(Painting));

	for (i = 0; i < cnt; i++) {
		if (paintings->works[i].artist_id == artistId) {
			result->works[k] = paintings->works[i];
			k++;
		}
	}
	return result;
}

float calculateLocationStats(PaintingsLibrary* paintings){

	int i, privateCount = 0;
	int cnt = paintings->cnt;
	if (cnt == 0) {
		return 0;
	}

	for (i = 0; i < cnt; i++) {
		if (paintings->works[i].location == PRIVATE) {
			privateCount++;
		}
	}
	return (float)privateCount / paintings->cnt * 100;
}