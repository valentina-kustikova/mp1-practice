#include <iostream>
#include <fstream>
#include <string>

#include "artist.h"
#include "paintings.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 3) {
        cout << "Incorrect number of arguments" << endl;
        return 1;
    }

    string fileArtist = argv[1];
    string filePaintings = argv[2];

    ArtistLibrary libArtists;
    PaintingsLibrary libPaintings;

    /*  ХУДОЖНИКИ  */

    ifstream fileA(fileArtist);
    if (!fileA) {
        cout << "Error: cannot open artists file" << endl;
        return 1;
    }

    libArtists.ReadFileArtist(fileA);
    fileA.close();

    /*  КАРТИНЫ  */

    ifstream fileP(filePaintings);
    if (!fileP) {
        cout << "Error: cannot open paintings file" << endl;
        return 1;
    }

    libPaintings.ReadFilePaintings(fileP);
    fileP.close();

    /* ПОИСК */

    string name;
    cout << "Enter artist name - ";
    getline(cin, name);

    Artist* foundArtist = libArtists.findArtist(name);

    while (foundArtist == NULL) {
        cout << "Artist not found. Try again: ";
        getline(cin, name);
        foundArtist = libArtists.findArtist(name);
    }

    PaintingsLibrary* foundPaintings = libPaintings.findPaintings(foundArtist->painter_id);

    float percent = 0;

    if (foundPaintings != NULL) {
        percent = foundPaintings->calculateLocationStats();
    }

    /* ВЫВОД */

    cout << *foundArtist
        << " - "
        << foundPaintings->cnt
        << " paintings found\n\n";

    cout << "Paintings:\n";

    cout << *foundPaintings;

    cout << "\nLocation statistics:\n";

    cout << "Private: "
        << percent
        << "% paintings (museum - "
        << 100 - percent
        << "%)" << endl;

    if (foundPaintings != NULL) {
        delete foundPaintings;
    }

    return 0;
}


