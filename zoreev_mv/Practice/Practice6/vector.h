//Все вектора перед использованием должны быть создан

#pragma once
#include <stdio.h>
#include <math.h>

typedef struct {
    double* array;
    int size;
} vector;

//Создание вектора без инициализации
void vector_create(vector* temp, int size);

//Ввод вектора
void vector_input(vector* temp);

//Сложение векторов 
int vector_add(vector* result,vector a, vector b);

//Вычитание из вектора a вектора b
int vector_sub(vector* result, vector a, vector b);

//Скаляроное произведение векторов
int vector_scalar(double* result, vector a, vector b);

//Умножение вектора на число
int vector_multiply(vector* result, vector a, double m);

//Вычисление длинны векторов
int vector_length(double* result, vector temp);

//Вычисление угла между векторами
int vector_angle(double* result, vector a, vector b);

//Печать вектора
void vector_print(vector a);