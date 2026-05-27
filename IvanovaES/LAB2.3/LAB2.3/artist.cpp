#include <string>
#include "artist.h"

using namespace std;

Artist::Artist() {
    painter_id = 0;
    name = "";
    birthYear = 0;
    style = RENAISSANCE;
}

Artist::Artist(int id,const string& n, int year, Style s) {
    painter_id = id;
    name = n;
    birthYear = year;
    style = s;
}

Artist::Artist(const Artist& other) {
    painter_id = other.painter_id;
    name = other.name;
    birthYear = other.birthYear;
    style = other.style;
}

Artist::~Artist() {}

const Artist& Artist::operator=(const Artist& other) {
    if (this != &other) {
        painter_id = other.painter_id;
        name = other.name;
        birthYear = other.birthYear;
        style = other.style;
    }
    return *this;
}

ostream& operator<<(ostream& out, const Artist& a) {
    out << a.name << " (" << a.birthYear << ", "
        << styleToString(a.style) << ")";
    return out;
}

ArtistLibrary::ArtistLibrary() {
    persons = NULL;
    cnt = 0;
}

ArtistLibrary::ArtistLibrary(const ArtistLibrary& other) {
    cnt = other.cnt;
    persons = new Artist[cnt];
    for (int i = 0; i < cnt; i++) {
        persons[i] = other.persons[i];
    }
}

ArtistLibrary::~ArtistLibrary() {
    delete[] persons;
}

Artist* ArtistLibrary::findArtist(const string& name) {
    for (int i = 0; i < cnt; i++) {
        if (persons[i].name.find(name) != string::npos) {
            return &persons[i];
        }
    }
    return nullptr;
}

void ArtistLibrary::ReadFileArtist(ifstream& file) {
    string line;
    cnt = 0;

    while (getline(file, line)) {
        cnt++;
    }
    file.clear();
    file.seekg(0);
    
    persons = new Artist[cnt];

    int i = 0;

    while (getline(file, line)) {

        int pos = 0;

        string idStr = line.substr(0, line.find(';'));
        pos = line.find(';') + 1;
        line = line.substr(pos);

        string name = line.substr(0, line.find(';'));
        pos = line.find(';') + 1;
        line = line.substr(pos);

        string yearStr = line.substr(0, line.find(';'));
        pos = line.find(';') + 1;
        string styleStr = line.substr(pos);

        persons[i].painter_id = stoi(idStr);
        persons[i].name = name;
        persons[i].birthYear = stoi(yearStr);
        persons[i].style = stringToStyle(styleStr);

        i++;
    }
}

ostream& operator<<(ostream& out, const ArtistLibrary& a) {
    for (int i = 0; i < a.cnt; i++) {
        out << a.persons[i] << endl;
    }
    return out;
}

Style stringToStyle(const string& str) {
    if (str == "Renaissance") return RENAISSANCE;
    if (str == "Baroque") return BAROQUE;
    if (str == "Impressionism") return IMPRESSIONISM;
    if (str == "Post_Impressionism") return POST_IMPRESSIONISM;
    if (str == "Cubism") return CUBISM;
    if (str == "Surrealism") return SURREALISM;
    if (str == "Pop_Art") return POP_ART_STYLE;
    return RENAISSANCE;
}

string styleToString(Style style) {
    switch (style) {
    case RENAISSANCE: return "Renaissance";
    case BAROQUE: return "Baroque";
    case IMPRESSIONISM: return "Impressionism";
    case POST_IMPRESSIONISM: return "Post_Impressionism";
    case CUBISM: return "Cubism";
    case SURREALISM: return "Surrealism";
    case POP_ART_STYLE: return "Pop_Art";
    default: return "Unknown";
    }
}



