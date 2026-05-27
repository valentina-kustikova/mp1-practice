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

    try {
      /*  времхе  */

      libArtists.ReadFileArtist(fileArtist);
      libPaintings.ReadFilePaintings(filePaintings);

      /* онхяй */

      string name;
      cout << "Enter artist name - ";
      getline(cin, name);

      Artist* foundArtist = libArtists.findArtist(name);

      while (foundArtist == NULL) {
        cout << "Artist not found. Try again: ";
        getline(cin, name);
        foundArtist = libArtists.findArtist(name);
      }

      PaintingsLibrary* foundPaintings = libPaintings.findPaintings(foundArtist->getPainterID());

      float percent = 0;

      if (foundPaintings != NULL) {
        percent = foundPaintings->calculateLocationStats();
      }

      /* бшбнд */

      cout << *foundArtist
        << " - "
        << foundPaintings->getCount()
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
    }
    catch (const std::exception& ex) {
      cout << ex.what() << endl;
    }

    return 0;
}