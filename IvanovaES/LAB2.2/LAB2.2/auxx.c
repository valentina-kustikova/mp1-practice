#define _CRT_SECURE_NO_WARNINGS
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

void readArtists(FILE* file, Artist* artists, int cnt) {
    int i;
    char buffer[MAX_LEN];

    for (i = 0; i < cnt; i++) {
        fgets(buffer, sizeof(buffer), file);
        buffer[strcspn(buffer, "\n")] = 0;

        strcpy(artists[i].name, strtok(buffer, ";"));
        artists[i].birthYear = atoi(strtok(NULL, ";"));
        strcpy(artists[i].style, strtok(NULL, ";"));
    }
}

void readPaintings(FILE* file, Painting* paintings, int cnt) {
    int i;
    char buffer[MAX_LEN];

    for (i = 0; i < cnt; i++) {
        fgets(buffer, sizeof(buffer), file);
        buffer[strcspn(buffer, "\n")] = 0;

        strcpy(paintings[i].artistName, strtok(buffer, ";"));
        strcpy(paintings[i].title, strtok(NULL, ";"));
        paintings[i].year = atoi(strtok(NULL, ";"));
        strcpy(paintings[i].genre, strtok(NULL, ";"));
        strcpy(paintings[i].location, strtok(NULL, ";"));
    }
}

void printResult(Artist* foundArtist, Painting* foundPaintings, int cnt,
    int museumCount, int privateCount) {
    int i;
    float privatePercent;
    
    if (foundArtist != NULL) {
        printf("%s (%d, %s) - %d paintings found\n",
            foundArtist->name, foundArtist->birthYear, foundArtist->style, cnt);
       
        printf("\nPaintings:\n");
        for (i = 0; i < cnt; i++) {
            printf("%s (%d), %s, %s\n",
                foundPaintings[i].title, foundPaintings[i].year,
                foundPaintings[i].genre, foundPaintings[i].location);
        }
        
        printf("\nLocation statistics:\n");
        
        privatePercent = (float)privateCount / cnt * 100;

        printf("Privet: %.1f%% paintings (museum - %.1f%%)",
            privatePercent, 100 - privatePercent);
    }
    else {
        printf("Error: artist not found");
    }

    
}

