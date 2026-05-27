#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
    unknown,
    female,
    male
} Gender;

typedef struct {
    char* Surname;
    char* Name;
    char* Patronymic;
} FullName;

typedef struct {
    int Day;
    int Month;
    int Year;
} Birthday;

typedef struct {
    char* MailIndex;
    char* Country;
    char* Region;
    char* District;
    char* City;
    char* Street;
    char* House;
    unsigned Apartment;
} Address;

typedef struct {
    FullName fullname;
    Gender gender;
    char* nationality;
    float height;
    float weight;
    Birthday date;
    char* phone;
    Address address;
} PersonInfo;

typedef struct {
    PersonInfo** person;   // массив указателей на структуры
    int count;
} LibraryInfo;


void Sort_with_choise(LibraryInfo* library);
