#include "shop.h"
#include "auxiliary.h"
#include <fstream>

using namespace std;

// Конструктор с именем файла
ShopLib::ShopLib(const string& filename) {
    this->count = 0;
    string line;
    ifstream fp(filename);

    if (!fp.is_open()) {
        this->arr = nullptr;
        this->count = 0;
        throw "err\n";
    }

    // Подсчёт количества строк
    while (getline(fp, line)) {
        this->count++;
    }

    this->arr = new Shop[this->count];
    if (this->arr == nullptr) {
        throw "err\n";
    }

    // Возвращаемся к началу файла
    fp.clear();
    fp.seekg(0, ios::beg);

    // Чтение данных
    for (int i = 0; i < this->count; i++) {
        getline(fp, line);
        parseShopLine(line, this->arr[i]);
    }
    fp.close();
    
}



// Конструктор копирования
ShopLib::ShopLib(const ShopLib& other) {
    this->count = other.count;
    this->arr = new Shop[this->count];

    for (int i = 0; i < this->count; i++) {
        this->arr[i] = other.arr[i];
    }
}

// Деструктор
ShopLib::~ShopLib() {
    delete[] this->arr;
}

// Сортировка по названию
void ShopLib::SortByName() {
    if (this->arr == nullptr) return;

    for (int i = 0; i < this->count - 1; i++) {
        for (int j = i + 1; j < this->count; j++) {
            if (this->arr[i].name > this->arr[j].name) {
                Shop temp = this->arr[i];
                this->arr[i] = this->arr[j];
                this->arr[j] = temp;
            }
        }
    }
}

// Фильтрация: круглосуточные продуктовые магазины
void ShopLib::Filter24hGrocery(ShopLib& result) {
    result.count = 0;

    // Подсчёт подходящих магазинов
    for (int i = 0; i < this->count; i++) {
        if (this->arr[i].specialization != "grocery") {
            continue;
        }

        bool is24h = true;
        for (int d = 0; d < 7; d++) {
            if (this->arr[i].schedule[d].mode != ALLDAY) {
                is24h = false;
                break;
            }
        }

        if (is24h) {
            result.count++;
        }
    }

    if (result.count == 0) {
        result.arr = nullptr;
        return;
    }

    result.arr = new Shop[result.count];
    if (result.arr == nullptr) {
        result.count = 0;
        return;
    }

    int k = 0;
    for (int i = 0; i < this->count; i++) {
        if (this->arr[i].specialization != "grocery") {
            continue;
        }

        bool is24h = true;
        for (int d = 0; d < 7; d++) {
            if (this->arr[i].schedule[d].mode != ALLDAY) {
                is24h = false;
                break;
            }
        }

        if (is24h) {
            result.arr[k++] = this->arr[i];
        }
    }
}

// Оператор вывода для ShopLib
ostream& operator << (ostream& out, const ShopLib& a) {
    if (a.count == 0) {
        out << "No 24/7 grocery stores found" << endl;
        return out;
    }

    if (a.count == 1) {
        out << "Found " << a.count << " 24/7 grocery store:" << endl << endl;
    }
    else {
        out << "Found " << a.count << " 24/7 grocery stores:" << endl << endl;
    }

    for (int i = 0; i < a.count; i++) {
        out << "STORE #" << (i + 1) << endl;
        out <<  endl;
        out << a.arr[i] << endl;
        out << endl << endl;
    }
    return out;
}