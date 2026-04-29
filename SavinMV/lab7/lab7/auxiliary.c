#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shop.h"
#include "auxiliary.h"


Time parseTime(const char* timeStr) {
    Time t;
    t.hours = 0;
    t.minutes = 0;
    sscanf(timeStr, "%d:%d", &t.hours, &t.minutes);
    return t;
}


void parseScheduleString(const char* scheduleStr, DailySchedule* schedule) {

    for (int i = 0; i < 7; i++) {
        schedule[i].day = (WeekDay)i;
        schedule[i].mode = CLOSED;
        schedule[i].openTime.hours = 0;
        schedule[i].openTime.minutes = 0;
        schedule[i].closeTime.hours = 0;
        schedule[i].closeTime.minutes = 0;
    }

    char temp[1024];
    strcpy(temp, scheduleStr);

    char* token = strtok(temp, ",");
    while (token != NULL) {
        while (*token == ' ') token++;

        char dayAbbr[4];
        char modeOrHours[20];

        if (sscanf(token, "%3s %s", dayAbbr, modeOrHours) == 2) {
            int dayIndex = -1;

            if (strcmp(dayAbbr, "Mon") == 0) dayIndex = MONDAY;
            else if (strcmp(dayAbbr, "Tue") == 0) dayIndex = TUESDAY;
            else if (strcmp(dayAbbr, "Wed") == 0) dayIndex = WEDNESDAY;
            else if (strcmp(dayAbbr, "Thu") == 0) dayIndex = THURSDAY;
            else if (strcmp(dayAbbr, "Fri") == 0) dayIndex = FRIDAY;
            else if (strcmp(dayAbbr, "Sat") == 0) dayIndex = SATURDAY;
            else if (strcmp(dayAbbr, "Sun") == 0) dayIndex = SUNDAY;

            if (dayIndex != -1) {
                if (strcmp(modeOrHours, "allday") == 0) {
                    schedule[dayIndex].mode = ALLDAY;
                }
                else if (strcmp(modeOrHours, "closed") == 0) {
                    schedule[dayIndex].mode = CLOSED;
                }
                else {
                    char openTimeStr[6], closeTimeStr[6];
                    if (sscanf(modeOrHours, "%5s", openTimeStr, closeTimeStr) == 2) {
                        schedule[dayIndex].mode = HOURS;
                        schedule[dayIndex].openTime = parseTime(openTimeStr);
                        schedule[dayIndex].closeTime = parseTime(closeTimeStr);
                    }
                }
            }
        }
        token = strtok(NULL, ",");
    }
}

int countShops(const char* filename) {
    char buff[1024];
    int count = 0;
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Err %s\n", filename);
        return 1;
    }

    while (fgets(buff, sizeof(buff), file) != NULL) {
        count++;
    }

    fclose(file);
    return count;
}

void readFile(int count, Shop* array, const char* filename) {
    char buff[4096];
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Err %s\n", filename);
        return;
    }

    for (int i = 0; i < count; i++) {
        if (fgets(buff, sizeof(buff), file) == NULL) {
            break;
        }

        buff[strcspn(buff, "\n")] = 0;

        char* token = strtok(buff, ";");
        if (token) strcpy(array[i].name, token);

        token = strtok(NULL, ";");
        if (token) {
            char* space = strchr(token, ' ');
            strcpy(array[i].address.building, token);
            strcpy(array[i].address.street, space + 1);
        }

        strcpy(array[i].phones, strtok(NULL, ";"));
        strcpy(array[i].specialization, strtok(NULL, ";"));
        strcpy(array[i].ownership, strtok(NULL, ";"));

        token = strtok(NULL, ";");
        if (token) {
            parseScheduleString(token, array[i].schedule);
        }
    }

    fclose(file);
}


void printResults(Shop* search, int count) {
    if (count == 0) {
        printf("\nNo 24/7 grocery stores found\n");
        return;
    }

    if (count == 1) {
        printf("\nFound %d 24/7 grocery store:\n", count);
    }
    else {
        printf("\nFound %d 24/7 grocery stores:\n\n", count);
    }


    for (int i = 0; i < count; i++) {
        printf("\nSTORE #%d\n", i + 1);
        printf("Name:           %s\n", search[i].name);
        printf("Address:        %s\n", search[i].address.street);
        printf("Phone(s):       %s\n", search[i].phones);
        printf("Specialization: %s\n", search[i].specialization);
        printf("Ownership:      %s\n", search[i].ownership);
        printf("Hours:          OPEN 24/7\n\n");
        
        
    }
    
}