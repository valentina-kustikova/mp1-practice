#ifndef _CONTAINER_H_
#define _CONTAINER_H_
#include <iostream>
using namespace std;
template <typename T, int maxsize>
class container {
private:
    T* a;
    int count;
public:
    container();
    container(const container&);
    container(T*, int);
    ~container();

    bool full() const;
    bool empty() const;

    int search(T) const;
    void add(const T);
    void del(T);

    T& operator[](int);
    const T& operator[](int)const;

    friend ostream& operator<<(ostream& out, const container& arr) {
        if (arr.count == 0) {
            out << "The container is empty";
            return out;
        }
        for (int i = 0; i < arr.count; i++)
            out << arr[i] << ", ";
        out<<" "<<endl;
        return out;
    };

    friend istream& operator>>(istream& put, container& arr) {
        cout << "Put elements:)" << endl;
        for (int i = 0; i < arr.count; i++)
            put >> arr[i];
        return put;
    };
};
    //-------------------конструкторы, деструкторы--------------------
    template<typename T, int maxsize>//сделано
    container<T, maxsize>::container() {
        count = 0;
        a = new T[maxsize];
    }

    template<typename T, int maxsize>//сделано
    container<T, maxsize>::container(const container& arr) {
        if (arr == NULL)
            throw emptycontcopy();
        count = arr.count;
        a = new T[maxsize];
        for (int i = 0; i < count; i++)
            a[i] = arr.a[i];
    }

    template<typename T, int maxsize>//сделано
    container<T, maxsize>::container(T* arr, int c) {
        if (c <= 0)
            throw uncorrectsize();
        if (arr == NULL)
            throw emptycont();
        count = c;
        a = new T[maxsize];
        for (int i = 0; i < count; i++)
            a[i] = arr[i];
    }

    template<typename T, int maxsize>//сделано
    container<T, maxsize>::~container() {
        count = 0;
        delete[] a;
    }
    //------------определение пустой/полный--------------//сделано
    template<typename T, int maxsize>
    bool container<T, maxsize>::full() const {
        return(count == maxsize);
    }

    template<typename T, int maxsize>
    bool container<T, maxsize>::empty() const{
        return(count == 0);
    }
    //-----------------основные функции-------------------
    template<typename T, int maxsize>//поиск заданного элемента
    int container<T, maxsize>::search(T element) const{
        for (int i = 0; i < count; i++)
            if (a[i] == element)
                return i;
        return -1;
    }

    template<typename T, int maxsize>//добавление элемента в конец
    void container<T, maxsize>::add(const T element) {
        if (full())
            throw fullcont();
        a[count] = element;
        count++;
    }

    template<typename T, int maxsize>//удаление элемента по индексу
    void container<T, maxsize>::del(T index) {
        if (empty())
            throw emptycont();
        if ((index < 0) || (index > maxsize)) 
            throw uncorrectsize();
        a[index] = a[count]
        a[count] = 0;
        count--;
    }
    //---------------операции связанные с []--------------------
    template<typename T, int maxsize>
    T& container<T, maxsize>::operator[](int index) {
        if ((index < 0) || (index >= count))
            throw uncorrectsize();
        return a[index];
    }

    template<typename T, int maxsize>
    const T& container<T, maxsize>::operator[](int index) const {
        if ((index < 0) || (index >= count))
            throw uncorrectsize();
        return a[index];
    }

    class emptycont : std::exception {
        const std::string what_str = "The container is empty";
    public:
        const char* what() const;
    };
    class fullcont : std::exception {
        const std::string what_str = "The container is full";
    public:
        const char* what() const;
    };
    class emptycontcopy : std::exception {
        const std::string what_str = "The array is empty for copying!";
    public:
        const char* what() const;
    };
    class uncorrectsize : std::exception {
        const std::string what_str = "Not correct size!";
    public:
        const char* what() const;
    };
#endif 

