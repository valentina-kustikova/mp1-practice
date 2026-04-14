#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxx.h"

int countLines(FILE* file) {
    char buffer[MAX_LEN];
    int cnt = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        cnt++;
    }

    return cnt;
}

void readArtists(FILE* file, ArtistLibrary* artists) {
    int i;
    char buffer[MAX_LEN];
    int cnt = artists->cnt;

    for (i = 0; i < cnt; i++) {
        fgets(buffer, sizeof(buffer), file);
        buffer[strcspn(buffer, "\n")] = 0;

        artists->persons[i].painter_id = atoi(strtok(buffer, ";"));
        strcpy(artists->persons[i].name, strtok(NULL, ";"));
        artists->persons[i].birthYear = atoi(strtok(NULL, ";"));
        artists->persons[i].style = stringToStyle(strtok(NULL, ";"));
    }
}

void readPaintings(FILE* file, PaintingsLibrary* paintings) {
    int i;
    char buffer[MAX_LEN];
    int cnt = paintings->cnt;

    for (i = 0; i < cnt; i++) {
        fgets(buffer, sizeof(buffer), file);
        buffer[strcspn(buffer, "\n")] = 0;

        paintings->works[i].artist_id = atoi(strtok(buffer, ";"));
        strcpy(paintings->works[i].title, strtok(NULL, ";"));
        paintings->works[i].year = atoi(strtok(NULL, ";"));
        paintings->works[i].genre = stringToGenre(strtok(NULL, ";"));
        paintings->works[i].location = stringToLocation(strtok(NULL, ";"));
    }
}

void printResult(Artist* foundArtist, PaintingsLibrary* foundPaintings, float percent) {     int i;

int cnt = foundPaintings->cnt;

    if (foundArtist != NULL) {
        printf("%s (%d, %s) - %d paintings found\n",
            foundArtist->name, foundArtist->birthYear, styleToString(foundArtist->style), cnt);

        printf("\nPaintings:\n");
        for (i = 0; i < cnt; i++) {
            printf("%s (%d), %s, %s\n",
                foundPaintings->works[i].title, foundPaintings->works[i].year,
                genreToString(foundPaintings->works[i].genre),
                locationToString(foundPaintings->works[i].location));
        }

        printf("\nLocation statistics:\n");

        printf("Privet: %.1f%% paintings (museum - %.1f%%)",
            percent, 100 - percent);
    }
    else {
        printf("Error: artist not found");
    }


}