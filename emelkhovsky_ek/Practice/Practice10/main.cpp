#include <iostream>
#include "container.h"
#include <locale.h>
#include <conio.h>
using namespace std;
int main() {
        int index, element;
        int mas1[5] = { 1,2,3,4,5 };
        float mas2[3] = { 0.1f,0.2f,0.3f };
        float mas22[3] = { 0.1f,0.2f,0.3f };
        int mas3[2] = { 0 };
        int mas4[1] = {};
        setlocale(LC_ALL, "rus");
        container<int, 10> array1(mas1, 5);
        container<float, 5> array2(mas2, 3);
        container<int, 1> array3(mas3, 1);

        try {
            container<int, 2> array4(mas4, -3);//исключение из-за неправильного размера и пустого контейнера 4
        }
        catch (uncorrectsize) {
            std::cout << "Not correct size!\n";
        }
    
        cout << "1ый контейнер:" << endl;
        cout << array1;
        cout << "2ой контейнер:" << endl;
        cout << array2;
        cout << "3ий контейнер:" << endl;
        cout << array3;

        //------------------------------------добавление--------------------------------------
        cout << "Введите элемент, который хотите добавить в 1ый массив" << endl;//без исключений
        cin >> element;
        array1.add(element);
        cout << array1 << endl;

        try {
            cout << "Введите элемент, который хотите добавить в 3ий массив" << endl;//исключение из-за полного контейнера 3
            cin >> element;
            array3.add(element);
        }
        catch (fullcont) {
            std::cout << "The container is full!\n";
        }
        
        //------------------------------удаление-----------------------------
        try {
            cout << "Удаление:" << endl;
            array2.del(0);
            cout << array2 << endl;
            array2.del(1);
            cout << array2 << endl;
            array2.del(2);
            array2.del(0);//исключение из-за пустого контейнера
        }
        catch (emptycont) {
            std::cout << "The container is empty!\n";
        }
        cout << "Попытка удалить из 2 массива -1ый элемент:"<< endl;
        try {
            array2.del(-1);//исключение из-за несуществующего элемента
        }
        catch (uncorrectsize) {
            std::cout << "Not correct size!\n";
        }
        //----------------------------поиск---------------------------
        cout << "Введите элемент, который вы хотите найти в массиве 1" << endl;
        cin >> element;
        element = array1.search(element);
        cout << "Это " << element << "-ый элемент" << endl;

        cout << "Попытка найти в 1ом конейнере 1000:" << endl;
        try {
            array1.search(1000);//исключение из-за несуществующего элемента
        }
        catch (uncorrectsize) {
            std::cout << "Not correct size!\n";
        }
        //-------------------------вывод элемента------------------------
        cout << "Введите индекс элемента, кторый вы хотите вывести из массива 1" << endl;
        cin >> index;
        cout << "Элемент:"<<array1[index] << endl;

        cout << "Попытка найти в 1ом конейнере -35 элемент:" << endl;
        try {
            cout << array1[1000] << endl;//исключение из-за несуществующего индекса
        }
        catch (uncorrectsize) {
            std::cout << "Not correct size!\n";
        }
//-------------------2222222222222222222222222222222222222222222222222222222222------------------------------------------
        int *mass1[5];
        int i;
        for ( i = 0; i < 5; i++)
            mass1[i] = &mas1[i];
        container<int*, 10> arrayy1(mass1, 5);
        container<int*, 10> arrayy2(arrayy1);

        try {
        cout << "1ый контейнер:" << endl;
        cout << arrayy1;
        cout << "2ой контейнер:" << endl;
        cout << arrayy2;
        int a = 6;
        int* a1 = &a;
        arrayy1.add(a1);
        cout << "1ый контейнер:" << endl;
        cout << arrayy1;
        }
        catch (fullcont) {
            std::cout << "The container is full!\n";
        }

        try {
            cout << "Удаление" << endl;
            arrayy1.del(&arrayy1[0]);
            cout << arrayy1 << endl;;
        }
        catch (emptycont) {
            std::cout << "The container is empty!\n";
        }

        try {
            cout << &arrayy1[-2] << endl;;
        }
        catch (uncorrectsize) {
            std::cout << "Not correct size!\n";
        }
        _getch();
}