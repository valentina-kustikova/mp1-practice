#ifndef PAINTINGS_H
#define PAINTINGS_H

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

enum Genre {
    PORTRAIT = 0,
    RELIGIOUS = 1,
    DRAWING = 2,
    SCULPTURE = 3,
    HISTORY = 4,
    GROUP_PORTRAIT = 5,
    SELF_PORTRAIT = 6,
    MYTHOLOGICAL = 7,
    SEASCAPE = 8,
    LANDSCAPE = 9,
    STILL_LIFE = 10,
    INTERIOR = 11,
    SURREAL = 12,
    POP_ART_GENRE = 13,
};

enum Location {
    MUSEUM = 1,
    PRIVATE = 2,
};

class Painting {

private:
    int artist_id;
    string title;
    int year;
    Genre genre;
    Location location;

public:

    Painting();
    Painting(int id, const string& t, int y, Genre g, Location l);
    Painting(const Painting& other);
    ~Painting();

    friend class PaintingsLibrary;

    const Painting& operator=(const Painting& other);
    friend ostream& operator<<(ostream& out, const Painting& p);
};

class PaintingsLibrary {

private:
    Painting* works;
    int cnt;

public:
    PaintingsLibrary();
    PaintingsLibrary(const PaintingsLibrary& other);
    ~PaintingsLibrary();

    PaintingsLibrary* findPaintings(int artistID);
    float calculateLocationStats();
    void ReadFilePaintings(const string& filePaintings);
    
    Genre stringToGenre(const string& str);
    static string genreToString(Genre genre);
    Location stringToLocation(const string& str);
    static string locationToString(Location location);

    int getCount() const;

    friend ostream& operator<<(ostream& out, const PaintingsLibrary& p);
};

#endif
