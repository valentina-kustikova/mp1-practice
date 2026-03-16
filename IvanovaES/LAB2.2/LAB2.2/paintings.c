#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paintings.h"

void findPaintings(Painting* paintings, int cnt, char* artistName,
	Painting** foundPaintings, int* foundCountPaintings) {

	int i;
	int k = 0;

	*foundCountPaintings = 0;

	for (i = 0; i < cnt; i++) {
		if (strstr(paintings[i].artistName, artistName) != NULL) {
			(*foundCountPaintings)++;

		}
	}

	if (*foundCountPaintings == 0) {
		*foundPaintings = NULL;
		return;
	}

	*foundPaintings = (Painting*)malloc(*foundCountPaintings * sizeof(Painting));

	for (i = 0; i < cnt; i++) {
		if (strstr(paintings[i].artistName, artistName) != NULL) {
			(*foundPaintings)[k] = paintings[i];
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