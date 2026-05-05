#include "Header.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

PersonsLibrary personsLibrary(string filename) {
    ifstream fp(filename);
    if (!fp.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        int count = 0;
        string line;
        while (getline(fp, line)) {
            count++;
        }
        personsLibrary.count = count;
    }
}
int numberLines(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return 0;
    }

    int count = 0;
    string line;
    while (getline(file, line)) {
        count++;
    }
    return count;
}

// Перегрузка convertSport
Sport convertSport(const string& input_sport) {
    if (input_sport == "Athletics") return Athletics;
    if (input_sport == "Weightlifting") return Weightlifting;
    if (input_sport == "Boxing") return Boxing;
    if (input_sport == "Tennis") return Tennis;
    if (input_sport == "Football") return Football;
    return Unknown;
}

Sport convertSport(const char* input_sport) {
    return convertSport(string(input_sport));
}

void readFile(vector<Person>& athletes, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        Person p;
        stringstream ss(line);
        string token;

        // 1. ФИО
        getline(ss, token, ';');
        stringstream fio_ss(token);
        getline(fio_ss, p.name.last_name, ' ');
        getline(fio_ss, p.name.first_name, ' ');

        // 2. Пол
        getline(ss, token, ';');
        p.gender = (token == "M") ? M : F;

        // 3. Дата рождения
        getline(ss, token, ';');
        sscanf(token.c_str(), "%d-%d-%d",
            &p.date_of_birth.year,
            &p.date_of_birth.month,
            &p.date_of_birth.day);

        // 4. Страна
        getline(ss, p.country, ';');

        // 5. Город
        getline(ss, p.city, ';');

        // 6. Вид спорта
        getline(ss, token, ';');
        p.sport = convertSport(token);

        // 7. Клуб
        getline(ss, p.club, ';');

        // 8. Дисциплина
        getline(ss, p.discipline, ';');

        // 9. Рекорд
        getline(ss, token, ';');
        p.record = stod(token);

        athletes.push_back(p);
    }

    file.close();
}

void findRecord(const vector<Person>& athletes, const string& input_sport,
    vector<BestEntry>& result) {
    Sport target_sport = convertSport(input_sport);

    if (target_sport == Unknown) {
        cerr << "Unknown sport: " << input_sport << endl;
        return;
    }

    // Первый проход: собираем уникальные дисциплины
    vector<string> unique_disciplines;

    for (const auto& athlete : athletes) {
        if (athlete.sport == target_sport) {
            bool found = false;
            for (const auto& disc : unique_disciplines) {
                if (disc == athlete.discipline) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                unique_disciplines.push_back(athlete.discipline);
            }
        }
    }

    // Второй проход: ищем лучшего по каждой дисциплине
    result.clear();
    for (const auto& discipline : unique_disciplines) {
        BestEntry entry;
        entry.discipline = discipline;
        entry.best_record = -1.0;

        for (size_t i = 0; i < athletes.size(); i++) {
            if (athletes[i].sport == target_sport &&
                athletes[i].discipline == discipline) {
                if (athletes[i].record > entry.best_record) {
                    entry.best_record = athletes[i].record;
                    entry.best_index = static_cast<int>(i);
                }
            }
        }
        result.push_back(entry);
    }
}

void printResult(const vector<Person>& athletes, const vector<BestEntry>& result) {
    if (result.empty()) {
        cout << "No athletes found for this sport" << endl;
        return;
    }

    for (const auto& entry : result) {
        const Person& p = athletes[entry.best_index];
        cout << "\nDiscipline: " << p.discipline << endl;
        cout << "Name: " << p.name.first_name << " " << p.name.last_name << endl;
        cout << "Record: " << p.record << endl;
        cout << "Country: " << p.country << endl;
        cout << "Club: " << p.club << endl;
        cout << "----------------------------------------" << endl;
    }
}