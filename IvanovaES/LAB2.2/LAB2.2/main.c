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
	int museum = 0, private = 0;
	float percent;
	ArtistLibrary libArtists;
	Artist* foundArtist;
	PaintingsLibrary libPaintings;
	PaintingsLibrary* foundPaintings;
	char name[MAX_LEN];

	if (argc < 3) {
		printf("Incorrect number of arguments");
		return 1;
	}
	fileArtist = argv[1];
	filePaintings = argv[2];

	//      ×ÈÒÀÅÌ ÕÓÄÎÆÍÈÊÎÂ

	file = fopen(fileArtist, "r");
	if (file == NULL) {
		printf("Error: cant open artist.txt");
		return 1;
	}

	libArtists.cnt = countLines(file);
	rewind(file);
	
	libArtists.persons = malloc(libArtists.cnt * sizeof(Artist));
	readArtists(file, &libArtists);
	fclose(file);

	//     ×ÈÒÀÅÌ ÊÀÐÒÈÍÛ

	file = fopen(filePaintings, "r");
	if (file == NULL) {
		printf("Error: cant open paintings.txt");
		return 1;
	}

	libPaintings.cnt = countLines(file);
	rewind(file);

	libPaintings.works = malloc(libPaintings.cnt * sizeof(Painting));
	readPaintings(file, &libPaintings);
	fclose(file);

	//       ÏÎÈÑÊ

	printf("Enter artist name - ");
	scanf("%[^\n]", name);
	
	foundArtist = findArtist(&libArtists, name);
	foundPaintings = findPaintings(&libPaintings, name);

	if (foundPaintings->cnt > 0) {
		percent = calculateLocationStats(foundPaintings);
	}

	//        ÐÅÇÓËÜÒÀÒÛ

	printResult(foundArtist, foundPaintings, percent);

	free(libArtists.persons);
	free(libPaintings.works);
	if (foundPaintings != NULL) {
		free(foundPaintings->works);
		free(foundPaintings);
	}

	return 0;

}