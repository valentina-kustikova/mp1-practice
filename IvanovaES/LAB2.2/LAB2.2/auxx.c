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

        strcpy(artists->persons[i].name, strtok(buffer, ";"));
        artists->persons[i].birthYear = atoi(strtok(NULL, ";"));
        strcpy(artists->persons[i].style, strtok(NULL, ";"));
    }
}

void readPaintings(FILE* file, PaintingsLibrary* paintings) {
    int i;
    char buffer[MAX_LEN];
    int cnt = paintings->cnt;

    for (i = 0; i < cnt; i++) {
        fgets(buffer, sizeof(buffer), file);
        buffer[strcspn(buffer, "\n")] = 0;

        strcpy(paintings->works[i].artistName, strtok(buffer, ";"));
        strcpy(paintings->works[i].title, strtok(NULL, ";"));
        paintings->works[i].year = atoi(strtok(NULL, ";"));
        strcpy(paintings->works[i].genre, strtok(NULL, ";"));
        strcpy(paintings->works[i].location, strtok(NULL, ";"));
    }
}

void printResult(Artist* foundArtist, PaintingsLibrary* foundPaintings, float percent) {     int i;

int cnt = foundPaintings->cnt;

    if (foundArtist != NULL) {
        printf("%s (%d, %s) - %d paintings found\n",
            foundArtist->name, foundArtist->birthYear, foundArtist->style, cnt);

        printf("\nPaintings:\n");
        for (i = 0; i < cnt; i++) {
            printf("%s (%d), %s, %s\n",
                foundPaintings->works[i].title, foundPaintings->works[i].year,
                foundPaintings->works[i].genre, foundPaintings->works[i].location);
        }

        printf("\nLocation statistics:\n");

        printf("Privet: %.1f%% paintings (museum - %.1f%%)",
            percent, 100 - percent);
    }
    else {
        printf("Error: artist not found");
    }


}