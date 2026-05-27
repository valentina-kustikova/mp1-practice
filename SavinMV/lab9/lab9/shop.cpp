#include "shop.h"
#include "auxiliary.h"
#include <fstream>
#include <cstring>

using namespace std;

DailySchedule::DailySchedule() : day(MONDAY), mode(CLOSED), openTime({ 0,0 }), closeTime({ 0,0 }) {}

DailySchedule::DailySchedule(WeekDay d, WorkMode m, Time open, Time close)
    : day(d), mode(m), openTime(open), closeTime(close) {
}

WeekDay DailySchedule::getDay() const { return day; }
WorkMode DailySchedule::getMode() const { return mode; }
Time DailySchedule::getOpenTime() const { return openTime; }
Time DailySchedule::getCloseTime() const { return closeTime; }

void DailySchedule::setDay(WeekDay d) { day = d; }
void DailySchedule::setMode(WorkMode m) { mode = m; }
void DailySchedule::setOpenTime(const Time& t) { openTime = t; }
void DailySchedule::setCloseTime(const Time& t) { closeTime = t; }

Address::Address() : build("0"), street("") {}

Address::Address(const string& b, const string& s) : build(b), street(s) {}

string Address::getBuild() const { return build; }
string Address::getStreet() const { return street; }

void Address::setBuild(const string& b) { build = b; }
void Address::setStreet(const string& s) { street = s; }

Shop::Shop() : name(""), phones(""), specialization(""), forma("") {}

Shop::Shop(const string& n, const Address& addr, const string& ph,
    const string& spec, const string& f)
    : name(n), address(addr), phones(ph), specialization(spec), forma(f) {
}

string Shop::getName() const { return name; }
Address Shop::getAddress() const { return address; }
string Shop::getPhones() const { return phones; }
string Shop::getSpecialization() const { return specialization; }
string Shop::getForma() const { return forma; }
DailySchedule* Shop::getSchedule() { return schedule; }

void Shop::setName(const string& n) { name = n; }
void Shop::setAddress(const Address& addr) { address = addr; }
void Shop::setPhones(const string& ph) { phones = ph; }
void Shop::setSpecialization(const string& spec) { specialization = spec; }
void Shop::setForma(const string& f) { forma = f; }
void Shop::setSchedule(int dayIndex, const DailySchedule& sch) {
    if (dayIndex >= 0 && dayIndex < 7) schedule[dayIndex] = sch;
}

ShopLib::ShopLib() : arr(nullptr), count(0) {}

ShopLib::ShopLib(const string& filename) {
    this->count = 0;
    string line;
    ifstream fp(filename);

    if (!fp.is_open()) {
        this->arr = nullptr;
        this->count = 0;
        throw "err\n";
    }

    while (getline(fp, line)) {
        this->count++;
    }

    this->arr = new Shop[this->count];
    if (this->arr == nullptr) {
        throw "err\n";
    }

    fp.clear();
    fp.seekg(0, ios::beg);

    for (int i = 0; i < this->count; i++) {
        getline(fp, line);
        parseShopLine(line, this->arr[i]);
    }
    fp.close();
}

ShopLib::ShopLib(const ShopLib& other) {
    this->count = other.count;
    this->arr = new Shop[this->count];
    for (int i = 0; i < this->count; i++) {
        this->arr[i] = other.arr[i];
    }
}

ShopLib::~ShopLib() {
    delete[] this->arr;
}

ShopLib& ShopLib::operator=(const ShopLib& other) {
    if (this != &other) {
        delete[] this->arr;
        this->count = other.count;
        this->arr = new Shop[this->count];
        for (int i = 0; i < this->count; i++) {
            this->arr[i] = other.arr[i];
        }
    }
    return *this;
}

Shop* ShopLib::getArr() const { return arr; }
int ShopLib::getCount() const { return count; }

void ShopLib::SortByName() {
    if (this->arr == nullptr) return;

    for (int i = 0; i < this->count - 1; i++) {
        for (int j = i + 1; j < this->count; j++) {
            if (this->arr[i].getName() > this->arr[j].getName()) {
                Shop temp = this->arr[i];
                this->arr[i] = this->arr[j];
                this->arr[j] = temp;
            }
        }
    }
}

void ShopLib::Filter24hGrocery(ShopLib& result) {
    result.count = 0;

    for (int i = 0; i < this->count; i++) {
        if (this->arr[i].getSpecialization() != "grocery") {
            continue;
        }

        bool is24h = true;
        DailySchedule* schedule = this->arr[i].getSchedule();
        for (int d = 0; d < 7; d++) {
            if (schedule[d].getMode() != ALLDAY) {
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
        if (this->arr[i].getSpecialization() != "grocery") {
            continue;
        }

        bool is24h = true;
        DailySchedule* schedule = this->arr[i].getSchedule();
        for (int d = 0; d < 7; d++) {
            if (schedule[d].getMode() != ALLDAY) {
                is24h = false;
                break;
            }
        }

        if (is24h) {
            result.arr[k++] = this->arr[i];
        }
    }
}