#ifndef AUXX_H
#define AUXX_H

#include <stdio.h>
#include "artist.h"
#include "paintings.h"

int countLines(FILE* file);
void readArtists(FILE* file, Artist* artists, int cnt);
void readPaintings(FILE* file, Painting* paintings, int cnt);
void printResult(Artist* foundArtist, Painting* paintings, int cnt,
    int museumCount, int privateCount);

#endif
