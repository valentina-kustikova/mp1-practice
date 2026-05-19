#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>

using namespace std;

template <typename T>
class Container {
private:
    T* elems;
    int size;
    int count;
    int step;

public:
    Container(int, int);
    Container(const Container<T>& other);
    ~Container();

    void InsertElem(const T& elem);
    void DeleteElem(const T& elem);
    int SearchIdx(const T& elem) const;

    T& operator[](int idx);

    const Container<T>& operator=(const Container<T>& other);

    int getCount() const;
    void containerRealloc(int newSize);
};

/*   ŒÕ—“–” “Œ–€  */

template <typename T>
Container<T>::Container(int startSize, int startStep) {
    size = startSize;
    step = startStep;
    count = 0;

    elems = new T[size];
}

template <typename T>
Container<T>::Container(const Container<T>& other) {
    size = other.size;
    count = other.count;
    step = other.step;

    elems = new T[size];

    for (int i = 0; i < count; i++) {
        elems[i] = other.elems[i];
    }
}

/*  ƒ≈—“–” “Œ–  */

template <typename T>
Container<T>::~Container() {
    delete[] elems;
}

/*  INSERT  */

template <typename T>
void Container<T>::InsertElem(const T& elem) {
    if (count == size) {
        containerRealloc(size + step);
    }
    elems[count] = elem;
    count++;
}

/*  SEARCH  */

template <typename T>
int Container<T>::SearchIdx(const T& elem) const {
    for (int i = 0; i < count; i++) {

        if (elems[i] == elem) {
            return i;
        }
    }
    return -1;
}

/*  DELETE  */

template <typename T>
void Container<T>::DeleteElem(const T& elem) {
    int idx = SearchIdx(elem);

    if (idx == -1) {
        throw exception("Element not found");
    }

    for (int i = idx; i < count - 1; i++) {
        elems[i] = elems[i + 1];
    }
    count--;
}

/*  []  */

template <typename T>
T& Container<T>::operator[](int idx) {

    if (idx < 0 || idx >= count) {
        throw exception("Index out of range");
    }
    return elems[idx];
}

/*  =  */

template <typename T>
const Container<T>& Container<T>::operator=(const Container<T>& other) {
    if (this == &other) {
        return *this;
    }

    delete[] elems;

    size = other.size;
    count = other.count;
    step = other.step;

    elems = new T[size];

    for (int i = 0; i < count; i++) {
        elems[i] = other.elems[i];
    }
    return *this;
}

/*  GET COUNT  */

template <typename T>
int Container<T>::getCount() const {
    return count;
}

/* REALLOC */

template <typename T>
void Container<T>::containerRealloc(int newSize) {
    if (newSize <= 0) {
        throw runtime_error("Invalid size");
    }

    T* newArr = new T[newSize];
    
    for (int i = 0; i < count; i++) {
        newArr[i] = elems[i];
    }
    delete[] elems;

    elems = newArr;
    size = newSize;
}

/*  —œ≈÷»¿À»«¿÷»ﬂ T*  */

template <typename T>
class Container<T*> {

private:
    T** elems;
    int size;
    int count;
    int step;

public:
    Container(int startSize = 5, int stepSize = 5);
    Container(const Container<T*>& other);
    ~Container();

    void InsertElem(T* elem);
    void DeleteElem(T* elem);
    int SearchIdx(T* elem) const;

    T*& operator[](int idx);

    const Container<T*>& operator=(const Container<T*>& other);

    int getCount() const;
    void containerRealloc(int newSize);
};

/*   ŒÕ—“–” “Œ–€  */

template <typename T>
Container<T*>::Container(int startSize, int stepSize) {
    size = startSize;
    step = stepSize;
    count = 0;
    elems = new T * [size];
}

template <typename T>
Container<T*>::Container(const Container<T*>& other) {
    size = other.size;
    count = other.count;
    step = other.step;

    elems = new T* [size];
    for (int i = 0; i < count; i++) {
        elems[i] = new T(*other.elems[i]);
    }
}

/*  ƒ≈—“–” “Œ–  */

template <typename T>
Container<T*>::~Container() {
    for (int i = 0; i < count; i++) {
        delete elems[i];
    }
    delete[] elems;
}

/*  INSERT  */

template <typename T>
void Container<T*>::InsertElem(T* elem) {
    if (count == size) {
        int newSize = size + step;
        T* newArr = new T[newSize];

        for (int i = 0; i < count; i++) {
            newArr[i] = elems[i];
        }

        delete[] elems;
        elems = newArr;
        size = newSize;
    }
    elems[count] = elem;
    count++;
}

/*  SEARCH  */

template <typename T>
int Container<T*>::SearchIdx(T* elem) const {
    for (int i = 0; i < count; i++) {

        if (*elems[i] == *elem) {
            return i;
        }
    }
    return -1;
}

/*  DELETE  */

template <typename T>
void Container<T*>::DeleteElem(T* elem) {
    int idx = SearchIdx(elem);

    if (idx == -1) {
        throw exception("Element not found");
    }

    delete elems[idx];

    for (int i = idx; i < count - 1; i++) {
        elems[i] = elems[i + 1];
    }
    count--;
}

/*  []  */

template <typename T>
T*& Container<T*>::operator[](int idx) {
    if (idx < 0 || idx >= count) {
        throw exception("Index out of range");
    }
    return elems[idx];
}

/*  =  */

template <typename T>
const Container<T*>& Container<T*>::operator=(const Container<T*>& other) {
    if (this == &other) {
        return *this;
    }

    for (int i = 0; i < count; i++) {
        delete elems[i];
    }

    delete[] elems;

    size = other.size;
    count = other.count;
    step = other.step;

    elems = new T* [size];

    for (int i = 0; i < count; i++) {
        elems[i] = new T(*other.elems[i]);
    }
    return *this;
}

/* REALLOC */

template <typename T>
void Container<T*>::containerRealloc(int newSize) {
    if (newSize <= 0) {
        throw runtime_error("Invalid size");
    }

    T** newArr = new T* [newSize];

    for (int i = 0; i < count; i++) {
        newArr[i] = elems[i];
    }
    delete[] elems;

    elems = newArr;
    size = newSize;
}

#endif
