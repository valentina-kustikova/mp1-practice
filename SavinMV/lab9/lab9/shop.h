#ifndef _SHOP_H
#define _SHOP_H

#include <iostream>
#include <string>

using namespace std;

enum WeekDay {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

enum WorkMode {
    ALLDAY,
    CLOSED,
    HOURS
};

struct Time {
    int hours;
    int minutes;
};

class DailySchedule {
private:
    WeekDay day;
    WorkMode mode;
    Time openTime;
    Time closeTime;

public:
    // Конструкторы
    DailySchedule();
    DailySchedule(WeekDay d, WorkMode m, Time open = { 0,0 }, Time close = { 0,0 });

    // Геттеры
    WeekDay getDay() const;
    WorkMode getMode() const;
    Time getOpenTime() const;
    Time getCloseTime() const;

    // Сеттеры
    void setDay(WeekDay d);
    void setMode(WorkMode m);
    void setOpenTime(const Time& t);
    void setCloseTime(const Time& t);
};


class Address {
private:
    string build;
    string street;

public:
    // Конструкторы
    Address();
    Address(const string& b, const string& s);

    // Геттеры
    string getBuild() const;
    string getStreet() const;

    // Сеттеры
    void setBuild(const string& b);
    void setStreet(const string& s);

    friend ostream& operator << (ostream& out, const Address& a);
};

class Shop {
private:
    string name;
    Address address;
    string phones;
    string specialization;
    string forma;
    DailySchedule schedule[7];

public:
    // Конструкторы
    Shop();
    Shop(const string& n, const Address& addr, const string& ph,
        const string& spec, const string& f);

    // Геттеры
    string getName() const;
    Address getAddress() const;
    string getPhones() const;
    string getSpecialization() const;
    string getForma() const;
    DailySchedule* getSchedule(); // возвращает указатель на массив

    // Сеттеры
    void setName(const string& n);
    void setAddress(const Address& addr);
    void setPhones(const string& ph);
    void setSpecialization(const string& spec);
    void setForma(const string& f);
    void setSchedule(int dayIndex, const DailySchedule& sch);

    friend ostream& operator << (ostream& out, const Shop& a);
};

class ShopLib {
private:
    Shop* arr;
    int count;

public:
    // Конструкторы и деструктор
    ShopLib();
    ShopLib(const string& filename);
    ShopLib(const ShopLib& other);
    ~ShopLib();

    // Оператор присваивания
    ShopLib& operator=(const ShopLib& other);

    // Геттеры
    Shop* getArr() const;
    int getCount() const;

    // Методы
    void Filter24hGrocery(ShopLib& result);
    void SortByName();

    friend ostream& operator << (ostream& out, const ShopLib& a);
};

#endif
