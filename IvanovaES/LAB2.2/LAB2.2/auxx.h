#ifndef AUXX_H
#define AUXX_H

#include <stdio.h>
#include "artist.h"
#include "paintings.h"

int countLines(FILE* file);
void readArtists(FILE* file, ArtistLibrary* artists);
void readPaintings(FILE* file, PaintingsLibrary* paintings);
void printResult(Artist* foundArtist, PaintingsLibrary* foundPaintings, float result);

#endif