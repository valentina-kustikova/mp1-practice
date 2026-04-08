#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paintings.h"

PaintingsLibrary* findPaintings(PaintingsLibrary* paintings, char* artistName) {


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
	return result;
}

float calculateLocationStats(PaintingsLibrary* paintings){

	int i, privateCount = 0;
	int cnt = paintings->cnt;
	if (cnt == 0) {
		return 0;
	}

	for (i = 0; i < cnt; i++) {
		if (strstr(paintings->works[i].location, "private") != NULL) {
			privateCount++;
		}
	}
	return (float)privateCount / paintings->cnt * 100;
}