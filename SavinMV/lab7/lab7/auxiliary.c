
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shop.h"
#include "auxiliary.h"


void parseScheduleString(const char* scheduleStr, DailySchedule* schedule) {

    char temp[1024];
    strcpy(temp, scheduleStr);

    char* token = strtok(temp, ",");
    while (token != NULL) {
        while (*token == ' ') token++;

        char dayAbbr[4];
        char mode[20];

        if (sscanf(token, "%3s %6s", dayAbbr, mode) == 2) {
            int dayIndex = -1;

            if (strcmp(dayAbbr, "Mon") == 0) dayIndex = MONDAY;
            else if (strcmp(dayAbbr, "Tue") == 0) dayIndex = TUESDAY;
            else if (strcmp(dayAbbr, "Wed") == 0) dayIndex = WEDNESDAY;
            else if (strcmp(dayAbbr, "Thu") == 0) dayIndex = THURSDAY;
            else if (strcmp(dayAbbr, "Fri") == 0) dayIndex = FRIDAY;
            else if (strcmp(dayAbbr, "Sat") == 0) dayIndex = SATURDAY;
            else if (strcmp(dayAbbr, "Sun") == 0) dayIndex = SUNDAY;

            if (dayIndex != -1) {
                if (strcmp(mode, "allday") == 0) {
                    schedule[dayIndex].mode = ALLDAY;
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
        fgets(buff, sizeof(buff), file);
        buff[strcspn(buff, "\n")] = 0;

        char* token = strtok(buff, ";");
        strcpy(array[i].name, token);
               
        strcpy(array[i].address.build, strtok(NULL, ","));
        strcpy(array[i].address.street, strtok(NULL, ";"));
        
        

        strcpy(array[i].phones, strtok(NULL, ";"));
        strcpy(array[i].specialization, strtok(NULL, ";"));
        strcpy(array[i].forma, strtok(NULL, ";"));

        token = strtok(NULL, ";");
        
        parseScheduleString(token, array[i].schedule);
        
    }

    fclose(file);
}


void printResults(ShopLib* result) {
    if (result->count == 0) {
        printf("\nNo 24/7 grocery stores found\n");
        return;
    }

    if (result->count == 1) {
        printf("\nFound %d 24/7 grocery store:\n", result->count);
    }
    else {
        printf("\nFound %d 24/7 grocery stores:\n\n", result->count);
    }


    for (int i = 0; i < result->count; i++) {
        printf("\nSTORE #%d\n", i + 1);
        printf("Name:            %s\n", result->arr[i].name);
        printf("Address: \n");
        printf("-House number    %s\n", result->arr[i].address.build);
        printf("-Street          %s\n", result->arr[i].address.street);
        printf("Phone:          %s\n", result->arr[i].phones);
        printf("Specialization: %s\n", result->arr[i].specialization);
        printf("Forma:          %s\n", result->arr[i].forma);
        printf("Hours:           OPEN 24/7\n\n");    
    }
    
}

