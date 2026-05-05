#include "Header.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    string filename;
    string input;

    if (argc < 2) {
        throw "Error with argc";
        return 1;
    }

    PersonsLibrary PersonsLibrary(argv[1]);

    int line_count = numberLines(filename);
    if (line_count <= 0) {
        cerr << "Error: File is empty or cannot be read" << endl;
        return 1;
    }

    // Загружаем данные
    vector<Person> athletes;
    readFile(athletes, filename);

    if (athletes.empty()) {
        cerr << "Error: No athletes loaded" << endl;
        return 1;
    }

    cout << "\nLoaded " << athletes.size() << " athletes successfully." << endl;

    // Запрашиваем вид спорта
    cout << "\nEnter name of sport: ";
    getline(cin, input);

    // Ищем рекордсменов
    vector<BestEntry> result;
    findRecord(athletes, input, result);

    // Выводим результат
    printResult(athletes, result);

    return 0;
}