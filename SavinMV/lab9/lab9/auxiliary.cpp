#include "auxiliary.h"
#include <string>
#include <sstream>

using namespace std;

ostream& operator << (ostream& out, const Address& a) {
    out << a.getBuild() << ", " << a.getStreet();
    return out;
}

ostream& operator << (ostream& out, const Shop& a) {
    out << "Name: " << a.getName() << endl;
    out << "Address: " << a.getAddress() << endl;
    out << "Phone: " << a.getPhones() << endl;
    out << "Specialization: " << a.getSpecialization() << endl;
    out << "Forma: " << a.getForma() << endl;
    out << "Hours: OPEN 24/7";
    return out;
}

ostream& operator << (ostream& out, const ShopLib& a) {
    if (a.getCount() == 0) {
        out << "No 24/7 grocery stores found" << endl;
        return out;
    }

    if (a.getCount() == 1) {
        out << "Found " << a.getCount() << " 24/7 grocery store:" << endl << endl;
    }
    else {
        out << "Found " << a.getCount() << " 24/7 grocery stores:" << endl << endl;
    }

    for (int i = 0; i < a.getCount(); i++) {
        out << "STORE #" << (i + 1) << endl;
        out << endl;
        out << a.getArr()[i] << endl;
        out << endl << endl;
    }
    return out;
}

void parseSchedule(DailySchedule* schedule, const string& scheduleStr) {
    string temp = scheduleStr;
    size_t start = 0;
    size_t commaPos;

    do {
        commaPos = temp.find(',', start);
        string token;

        if (commaPos != string::npos) {
            token = temp.substr(start, commaPos - start);
            start = commaPos + 1;
        }
        else {
            token = temp.substr(start);
            start = temp.length();
        }

        while (token.length() > 0 && token[0] == ' ') token.erase(0, 1);

        if (token.empty()) continue;

        size_t spacePos = token.find(' ');
        if (spacePos != string::npos) {
            string dayAbbr = token.substr(0, spacePos);
            string mode = token.substr(spacePos + 1);

            while (mode.length() > 0 && mode[0] == ' ') mode.erase(0, 1);

            int dayIndex = -1;

            if (dayAbbr == "Mon") dayIndex = MONDAY;
            else if (dayAbbr == "Tue") dayIndex = TUESDAY;
            else if (dayAbbr == "Wed") dayIndex = WEDNESDAY;
            else if (dayAbbr == "Thu") dayIndex = THURSDAY;
            else if (dayAbbr == "Fri") dayIndex = FRIDAY;
            else if (dayAbbr == "Sat") dayIndex = SATURDAY;
            else if (dayAbbr == "Sun") dayIndex = SUNDAY;

            if (dayIndex != -1) {
                schedule[dayIndex].setDay(static_cast<WeekDay>(dayIndex));

                if (mode == "allday") {
                    schedule[dayIndex].setMode(ALLDAY);
                }
                else if (mode == "closed") {
                    schedule[dayIndex].setMode(CLOSED);
                }
                else {
                    schedule[dayIndex].setMode(HOURS);
                    
                }
            }
        }
    } while (start < temp.length());
}

void parseShopLine(const string& line, Shop& shop) {
    string temp = line;
    size_t start = 0;
    int fieldNum = 0;
    size_t semicolonPos;

    do {
        semicolonPos = temp.find(';', start);
        string field;

        if (semicolonPos != string::npos) {
            field = temp.substr(start, semicolonPos - start);
            start = semicolonPos + 1;
        }
        else {
            field = temp.substr(start);
            start = temp.length();
        }

        while (field.length() > 0 && field[0] == ' ') field.erase(0, 1);

        switch (fieldNum) {
        case 0:
            shop.setName(field);
            break;

        case 1: {
            size_t commaPos = field.find(',');
            Address addr;
            if (commaPos != string::npos) {
                string build = field.substr(0, commaPos);
                string street = field.substr(commaPos + 1);
                while (street.length() > 0 && street[0] == ' ') street.erase(0, 1);
                addr.setBuild(build);
                addr.setStreet(street);
            }
            else {
                addr.setBuild("0");
                addr.setStreet(field);
            }
            shop.setAddress(addr);
        }
              break;

        case 2:
            shop.setPhones(field);
            break;

        case 3:
            shop.setSpecialization(field);
            break;

        case 4:
            shop.setForma(field);
            break;

        case 5:
            parseSchedule(shop.getSchedule(), field);
            break;
        }

        fieldNum++;
    } while (start < temp.length() && fieldNum < 6);
}