#ifndef SHOP_H
#define SHOP_H

typedef enum {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} WeekDay;


typedef enum {
    ALLDAY,
    CLOSED,
    HOURS
} WorkMode;


typedef struct {
    int hours;
    int minutes;
} Time;


typedef struct {
    WeekDay day;           
    WorkMode mode;         
    Time openTime;         
    Time closeTime;        
} DailySchedule;


typedef struct {
    char build[20];
    char street[100];           
} Address;


typedef struct Shop {
    char name[100];              
    Address address;             
    char phones[100];            
    char specialization[50];     
    char forma[50];          
    DailySchedule schedule[7];   
} Shop;

typedef struct {
    Shop* arr;
    int count;
} ShopLib;


void poisk24(ShopLib* shops, ShopLib* result);

#endif