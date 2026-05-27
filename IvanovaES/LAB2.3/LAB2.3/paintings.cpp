#include <string>
#include "paintings.h"

using namespace std;


Painting::Painting() {
    artist_id = 0;
    title = "";
    year = 0;
    genre = PORTRAIT;
    location = MUSEUM;
}

Painting::Painting(int id, const string& t, int y, Genre g, Location l) {
    artist_id = id;
    title = t;
    year = y;
    genre = g;
    location = l;
}

Painting::Painting(const Painting& other) {
    artist_id = other.artist_id;
    title = other.title;
    year = other.year;
    genre = other.genre;
    location = other.location;
}

PaintingsLibrary::PaintingsLibrary(const PaintingsLibrary& other) {
    cnt = other.cnt;
    works = new Painting[cnt];
    for (int i = 0; i < cnt; i++) {
        works[i] = other.works[i];
    }
}

Painting::~Painting() {}

const Painting& Painting::operator=(const Painting& other) {
    if (this != &other) {
        artist_id = other.artist_id;
        title = other.title;
        year = other.year;
        genre = other.genre;
        location = other.location;
    }
    return *this;
}

PaintingsLibrary::PaintingsLibrary() {
    works = NULL;
    cnt = 0;
}

PaintingsLibrary::~PaintingsLibrary() {
    delete[] works;
}

PaintingsLibrary* PaintingsLibrary::findPaintings(int artistID) {
    int count = 0;

    for (int i = 0; i < cnt; i++) {
        if (works[i].artist_id == artistID) {
            count++;
        }
    }

    if (count == 0) {
        return NULL;
    }

    PaintingsLibrary* result = new PaintingsLibrary;
    result->cnt = count;
    result->works = new Painting[count];

    int k = 0;

    for (int i = 0; i < cnt; i++) {
        if (works[i].artist_id == artistID) {
            result->works[k] = works[i];
            k++;
        }
    }

    return result;
}

float PaintingsLibrary::calculateLocationStats() {

    if (cnt == 0) {
        return 0;
    }

    int privateCount = 0;

    for (int i = 0; i < cnt; i++) {
        if (works[i].location == PRIVATE) {
            privateCount++;
        }
    }

    return (float)privateCount / cnt * 100;
}

void PaintingsLibrary::ReadFilePaintings(const string& filePaintings) {
    ifstream file(filePaintings);
    if (!file.is_open()) {
        throw runtime_error("Error: cannot open artists file");
    }
    
    string line;
    cnt = 0;

    while (getline(file, line)) {
        cnt++;
    }
    file.clear();
    file.seekg(0);

    works = new Painting[cnt];

    int i = 0;
    while (getline(file, line)) {
        int pos = 0;

        string artistIdStr = line.substr(0, line.find(';'));
        pos = line.find(';') + 1;
        line = line.substr(pos);

        string title = line.substr(0, line.find(';'));
        pos = line.find(';') + 1;
        line = line.substr(pos);

        string yearStr = line.substr(0, line.find(';'));
        pos = line.find(';') + 1;
        line = line.substr(pos);

        string genreStr = line.substr(0, line.find(';'));
        pos = line.find(';') + 1;
        string locationStr = line.substr(pos);

        works[i].artist_id = stoi(artistIdStr);
        works[i].title = title;
        works[i].year = stoi(yearStr);
        works[i].genre = stringToGenre(genreStr);
        works[i].location = stringToLocation(locationStr);

        i++;
    }
    file.close();
}

ostream& operator<<(ostream& out, const Painting& p) {

    out << p.title << " (" << p.year << "), "
        << PaintingsLibrary::genreToString(p.genre) << ", "
        << PaintingsLibrary::locationToString(p.location);

    return out;
}

ostream& operator<<(ostream& out, const PaintingsLibrary& p) {
    for (int i = 0; i < p.cnt; i++) {
        out << p.works[i] << endl;
    }
    return out;
}

Genre PaintingsLibrary::stringToGenre(const string& str) {
    if (str == "portrait") return PORTRAIT;
    if (str == "religious") return RELIGIOUS;
    if (str == "drawing") return DRAWING;
    if (str == "sculpture") return SCULPTURE;
    if (str == "history") return HISTORY;
    if (str == "group_portrait") return GROUP_PORTRAIT;
    if (str == "self_portrait") return SELF_PORTRAIT;
    if (str == "mythological") return MYTHOLOGICAL;
    if (str == "seascape") return SEASCAPE;
    if (str == "landscape") return LANDSCAPE;
    if (str == "still_life") return STILL_LIFE;
    if (str == "interior") return INTERIOR;
    if (str == "surreal") return SURREAL;
    if (str == "pop_art") return POP_ART_GENRE;

    return PORTRAIT;
}

string PaintingsLibrary::genreToString(Genre genre) {
    switch (genre) {
    case PORTRAIT: return "portrait";
    case RELIGIOUS: return "religious";
    case DRAWING: return "drawing";
    case SCULPTURE: return "sculpture";
    case HISTORY: return "history";
    case GROUP_PORTRAIT: return "group_portrait";
    case SELF_PORTRAIT: return "self_portrait";
    case MYTHOLOGICAL: return "mythological";
    case SEASCAPE: return "seascape";
    case LANDSCAPE: return "landscape";
    case STILL_LIFE: return "still_life";
    case INTERIOR: return "interior";
    case SURREAL: return "surreal";
    case POP_ART_GENRE: return "pop_art";
    default: return "unknown";
    }
}

Location PaintingsLibrary::stringToLocation(const string& str) {
    if (str == "museum") return MUSEUM;
    if (str == "private") return PRIVATE;
    return MUSEUM;
}

string PaintingsLibrary::locationToString(Location location) {
    switch (location) {
    case MUSEUM: return "museum";
    case PRIVATE: return "private";
    default: return "unknown";
    }
}







