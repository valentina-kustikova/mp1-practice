#ifndef _SHOP_H
#define _SHOP_H

#include <iostream>
#include <string>

using namespace std;

// Дни недели
enum WeekDay {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

// Режим работы
enum WorkMode {
    ALLDAY,
    CLOSED,
    HOURS
};

// Структура для времени
struct Time {
    int hours;
    int minutes;
;
};

// Структура для расписания на один день
struct DailySchedule {
    WeekDay day;
    WorkMode mode;
    Time openTime;
    Time closeTime;
};

// Структура для адреса
struct Address {
    string build;
    string street;

    friend ostream& operator << (ostream& out, const Address& a);
};

// Структура магазина
struct Shop {
    string name;
    Address address;
    string phones;
    string specialization;
    string forma;
    DailySchedule schedule[7];

    friend ostream& operator << (ostream& out, const Shop& a);
};

// Структура библиотеки магазинов
struct ShopLib {
    Shop* arr;
    int count;

    ShopLib() : arr(nullptr), count(0) {};
    ShopLib(const string& filename);
    ShopLib(const ShopLib& other);
    ~ShopLib();

    void Filter24hGrocery(ShopLib& result);
    void SortByName();

    friend ostream& operator << (ostream& out, const ShopLib& a);
};

#endif