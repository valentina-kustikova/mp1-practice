#include "auxiliary.h"
#include <string>
#include <sstream>

using namespace std;



// Реализация перегрузки операторов Address
ostream& operator << (ostream& out, const Address& a) {
    out << a.build << ", " << a.street;
    return out;
}

// Реализация перегрузки оператора вывода Shop
ostream& operator << (ostream& out, const Shop& a) {
    out << "Name: " << a.name << endl;
    out << "Address: " << a.address << endl;
    out << "Phone: " << a.phones << endl;
    out << "Specialization: " << a.specialization << endl;
    out << "Forma: " << a.forma << endl;
    out << "Hours: OPEN 24/7";
    return out;
}


// Функция для парсинга расписания (с использованием string)
void parseSchedule(DailySchedule* schedule, const string& scheduleStr) {
    

    string temp = scheduleStr;
    size_t start = 0;
    size_t commaPos;

    // Разбор строки по запятым
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

        // Убираем пробелы в начале токена
        while (token.length() > 0 && token[0] == ' ') token.erase(0, 1);
        

        if (token.empty()) continue;

        // Ищем пробел между днём и режимом
        size_t spacePos = token.find(' ');
        if (spacePos != string::npos) {
            string dayAbbr = token.substr(0, spacePos);
            string mode = token.substr(spacePos + 1);

            // Убираем пробелы в режиме
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
                if (mode == "allday") {
                    schedule[dayIndex].mode = ALLDAY;
                }
            }
        }
    } while (start < temp.length());
}

// Функция для парсинга строки магазина (с использованием string)
void parseShopLine(const string& line, Shop& shop) {
    

    string temp = line;
    size_t start = 0;
    int fieldNum = 0;
    size_t semicolonPos;

    // Разбор строки по точкам с запятой
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

        // Убираем пробелы в начале поля
        while (field.length() > 0 && field[0] == ' ') field.erase(0, 1);
        

        switch (fieldNum) {
        case 0:  // название
            shop.name = field;
            break;

        case 1:  // адрес (номер дома, улица)
        {
            size_t commaPos = field.find(',');
            if (commaPos != string::npos) {
                shop.address.build = field.substr(0, commaPos);
                string street = field.substr(commaPos + 1);
                while (street.length() > 0 && street[0] == ' ') street.erase(0, 1);
                shop.address.street = street;
            }
            else {
                shop.address.build = "0";
                shop.address.street = field;
            }
        }
        break;

        case 2:  // телефон
            shop.phones = field;
            break;

        case 3:  // специализация
            shop.specialization = field;
            break;

        case 4:  // форма собственности
            shop.forma = field;
            break;

        case 5:  // расписание
            parseSchedule(shop.schedule, field);
            break;
        }

        fieldNum++;
    } while (start < temp.length() && fieldNum < 6);
}




