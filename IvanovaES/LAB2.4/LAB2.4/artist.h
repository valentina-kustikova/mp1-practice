#ifndef ARTIST_H
#define ARTIST_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

enum Style {
    RENAISSANCE = 0,
    BAROQUE = 1,
    IMPRESSIONISM = 2,
    POST_IMPRESSIONISM = 3,
    CUBISM = 4,
    SURREALISM = 5,
    POP_ART_STYLE = 6,
};

class Artist {

private:
    int painter_id;
    string name;
    int birthYear;
    Style style;

public:
    Artist();
    Artist(int id, const string& n, int year, Style s);
    Artist(const Artist& other);
    ~Artist();

    friend class ArtistLibrary;

    int getPainterID() const;
    const Artist& operator=(const Artist& other);
    friend ostream& operator<<(ostream& out, const Artist& a);
};

class ArtistLibrary {

private:
    Artist* persons;
    int cnt;

    Style stringToStyle(const string& str);    
public:
    ArtistLibrary();
    ArtistLibrary(const ArtistLibrary& other);
    ~ArtistLibrary();

    Artist* findArtist(const string& name) const;
    void ReadFileArtist(const string& fileArtist);

    static string styleToString(Style style);
    friend ostream& operator<<(ostream& out, const ArtistLibrary& a);
};

#endif