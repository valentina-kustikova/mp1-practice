#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "artist.h"
#include "paintings.h"
#include "auxx.h"

int main(int argc, char* argv[]) {
	char* fileArtist;
	char* filePaintings;
	FILE* file;
	int cntArtists, cntPaintings, foundCountPaintings, museum, private;
	Artist* artists;
	Artist* foundArtist;
	Painting* paintings;
	Painting* foundPaintings;
	char name[MAX_LEN];

	if (argc < 3) {
		printf("Incorrect number of arguments");
		return 1;
	}
	fileArtist = argv[1];
	filePaintings = argv[2];

	//      ◊»“¿≈Ã ’”ƒŒ∆Õ» Œ¬

	file = fopen(fileArtist, "r");
	if (file == NULL) {
		printf("Error: cant open artist.txt");
		return 1;
	}

	cntArtists = countLines(file);
	rewind(file);
	
	artists = malloc(cntArtists * sizeof(Artist));
	readArtists(file, artists, cntArtists);
	fclose(file);

	//     ◊»“¿≈Ã  ¿–“»Õ€

	file = fopen(filePaintings, "r");
	if (file == NULL) {
		printf("Error: cant open paintings.txt");
		return 1;
	}

	cntPaintings = countLines(file);
	rewind(file);

	paintings = malloc(cntPaintings * sizeof(Painting));
	readPaintings(file, paintings, cntPaintings);
	fclose(file);

	//       œŒ»— 

	printf("Enter artist name - ");
	scanf("%[^\n]", name);
	
	findArtist(artists, cntArtists, name, &foundArtist);
	findPaintings(paintings, cntPaintings, name, 
		&foundPaintings, &foundCountPaintings);

	museum = 0;
	private = 0;
	if (foundCountPaintings > 0) {
		calculateLocationStats(foundPaintings, foundCountPaintings,
			&museum, &private);
	}

	//        –≈«”À‹“¿“€

	printResult(foundArtist, foundPaintings, foundCountPaintings,
		museum, private);

	free(artists);
	free(paintings);
	if (foundPaintings != NULL) free(foundPaintings);

	return 0;

}