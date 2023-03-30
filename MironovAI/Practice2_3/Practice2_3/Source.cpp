#include <iostream>
#include <string>
#include <vector>
#include "Header.h"
#include <fstream>
using namespace std;



//Input data
int BanksData::read(BanksData*& data, int* p, const string& path) {

    ifstream infile(path);
    if (!infile) {
        cout << "This file isn`t exist" << endl;
        return 1;
    }
    else {
        infile >> (*p);
        int n = *p;
        int q;
        data = new BanksData[n];
        for (int i = 0; i < n; i++) {
            infile >> data[i];

        }
        infile.close();
        return 0;
    }


    return 0;
}



//overloading operations
ifstream& operator>>(ifstream& buf, Deposit& data)
{
    buf >> data.name >> data.period >> data.conditions;
    return buf;
}
ostream& operator<<(ostream& buf, const Deposit& data)
{
    buf << data.name << " " << data.period << " " << data.conditions << endl;
    return buf;
}
ifstream& operator>>(ifstream& buf, BanksData& data)
{
    buf >> data.name >> data.ownership >> data.count;
    data.deposits.resize(data.count);

    for (int j = 0; j < data.count; j++) {
        buf >> data.deposits[j];
    }
    return buf;
}
ostream& operator<<(ostream& buf, const BanksData& data)
{

    buf << data.name << " " << data.ownership << " " << data.count << endl;

    for (int j = 0; j < data.count; j++) {
        buf << data.deposits[j];
    }
    cout << endl;
    return buf;
}

//user interaction
void input_path(string& path) {
    cout << "Input a path with file type: " << endl;
    cin >> path;
    cout << "\nYour path: \n" << path << " \n" << endl;
}
void input_user_data(int* user_year, float* user_money) {
    do {
        cout << "For how long would you like to open a deposit?" << endl;
        cin >> (*user_year);

        if ((*user_year) <= 0 || (*user_year) >= 100) {
            cout << "Wrong period, try again" << endl;
        }
    } while ((*user_year) <= 0 || (*user_year) >= 100);
    do {
        cout << "How much would you like to open a deposit for (rubles)? " << endl;
        cin >> (*user_money);

        if ((*user_money) <= 0) {
            cout << "Wrong period, try again" << endl;
        }
    } while ((*user_money) <= 0);
}

//functions for comparing
pair<int, float> BanksData::best_deposit(int user_year, float user_money) {
    float profit = 0;
    int  id = -1;
    for (int j = 0; j < count; j++) {
        if (user_year % deposits[j].get_period() == 0) {
            float tmp_profit = user_money * (pow(1 + (deposits[j].get_condition() * 0.01), user_year));// formule
            if (profit < tmp_profit) {
                profit = tmp_profit;
                id = j;
            }
        }
    }
    pair<int, float> q;
    q.first = id;
    q.second = profit;
    return q;
}
triple comparing(BanksData* data, int user_year, float user_money, int n) {
    triple ans;
    BanksData best_data = data[0];
    best_data.set_best_suggestion(best_data.best_deposit(user_year, user_money));
    ans.id1 = 0;
    ans.id2 = best_data.get_best_suggestion().first;
    ans.profit = best_data.get_best_suggestion().second;
    for (int i = 1; i < n; i++) {
        data[i].set_best_suggestion(data[i].best_deposit(user_year, user_money));
        if (best_data < data[i]) {
            best_data = data[i];
            ans.id1 = i;
            ans.id2 = data[i].get_best_suggestion().first;
            ans.profit = data[i].get_best_suggestion().second;
        }
    }
    return ans;
}


//BanksData getters 
pair<int, float> BanksData::get_best_suggestion() const
{
    return best_suggestion;
}
string BanksData::get_name() const
{
    return name;
}
string BanksData::get_ownership() const
{
    return ownership;
}
vector<Deposit> BanksData::get_deposits() const
{
    return deposits;
}

//BanksData setter
void BanksData::set_best_suggestion(pair <int, float> new_suggestion)
{
    best_suggestion = new_suggestion;
}

//Deposit getters
int Deposit::get_period() const
{
    return period;
}
float Deposit::get_condition() const
{
    return conditions;
}
string Deposit::get_name() const
{
    return name;
}

