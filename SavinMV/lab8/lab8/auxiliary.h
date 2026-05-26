#ifndef _AUXILIARY_H
#define _AUXILIARY_H

#include "shop.h"

// Вспомогательные функции (не внутри конструкторов)
void parseSchedule(DailySchedule* schedule, const string& scheduleStr);
void parseShopLine(const string& line, Shop& shop);


#endif
