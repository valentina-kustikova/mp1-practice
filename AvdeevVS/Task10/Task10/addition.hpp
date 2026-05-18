#ifndef _ADDITION_HPP_
#define _ADDITION_HPP_
#include <iostream>
#include "addition.cpp"

using namespace std;

template <typename T>
class Storage {
  size_t size, capacity;
  const size_t step = 3;
  T* elements;

public:
  Storage(size_t capacity);
  Storage(size_t capacity, size_t new_step);
  Storage(size_t capacity, const T& element);
  const Storage<T>& operator=(const Storage<T>& c);
  Storage(const Storage<T>& c);
  Storage(Storage<T>&& c);
  ~Storage() { delete[] this->elements; };
  void Push_back(T& element);
  int Find(const T& element) const;
  void Remove(const T& element);
  const T& operator[](size_t i) const;

  friend ostream& operator<<(ostream& out, const Storage<T>& c) {
    out << "{ ";
    for (size_t i = 0; i < c.size; i++) {
      out << c.elements[i] << " ";
    }
    out << "}";
    return out;
  }
};

template <typename T>
class Storage<T*> {
  size_t size, capacity;
  const size_t step = 3;
  size_t* spectrum_lenghts;
  T** elements;

public:
  Storage(size_t capacity);
  Storage(size_t capacity,size_t new_step);
  const Storage<T*>& operator=(const Storage<T*>& c);
  T*& operator[](size_t i) const;
  Storage(const Storage<T*>& c);
  Storage(Storage<T*>&& c);
  ~Storage();
  void Push_back(T*& element, const size_t size_element);
  int Find(const T*& element, const size_t size_element) const;
  void Remove(const T*& element, const size_t size_element);
};

#endif