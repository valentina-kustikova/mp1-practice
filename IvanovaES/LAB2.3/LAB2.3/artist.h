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

struct Artist {
    int painter_id;
    string name;
    int birthYear;
    Style style;
    
    Artist();
    Artist(int id, const string& n, int year, Style s);
    Artist(const Artist& other);
    ~Artist();
    
    const Artist& operator=(const Artist& other);
    friend ostream& operator<<(ostream& out, const Artist& a);
};

struct ArtistLibrary {
    Artist* persons;
    int cnt;
    
    ArtistLibrary();
    ArtistLibrary(const ArtistLibrary& other);
    ~ArtistLibrary();
    
    Artist* findArtist(const string& name);
    void ReadFileArtist(ifstream& file);

    friend ostream& operator<<(ostream& out, const ArtistLibrary& a);
};

Style stringToStyle(const string& str);
string styleToString(Style style);

#endif