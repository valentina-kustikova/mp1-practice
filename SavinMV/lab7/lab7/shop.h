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
    char street[100];      
    char building[20];     
} Address;


typedef struct Shop {
    char name[100];              
    Address address;             
    char phones[100];            
    char specialization[50];     
    char ownership[50];          
    DailySchedule schedule[7];   
} Shop;

void search24hGroceries(Shop* array, int count, Shop** search, int* foundCount);

#endif