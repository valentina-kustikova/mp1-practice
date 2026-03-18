#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paintings.h"

void findPaintings(PaintingsLibrary* paintings, char* artistName) {

	int i;
	int k = 0, foundCountPaintings = 0;
	int cnt = paintings->cnt;

	for (i = 0; i < cnt; i++) {
		if (strstr(paintings->works[i].artistName, artistName) != NULL) {
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
		if (strstr(paintings->works[i].artistName, artistName) != NULL) {
			result->works[k] = paintings->works[i];
			k++;
		}
	}
}

void calculateLocationStats(Painting* paintings, int cnt,
	int* museumCount, int* privateCount) {
	
	int i;
	
	*museumCount = 0;
	*privateCount = 0;

	for (i = 0; i < cnt; i++) {
		if (strstr(paintings[i].location, "museum") != NULL) {
			(*museumCount)++;
		}
		else if (strstr(paintings[i].location, "private") != NULL) {
			(*privateCount)++;
		}
	}
}