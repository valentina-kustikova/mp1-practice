#ifndef _ADDITION_HPP_
#define _ADDITION_HPP_
#include <iostream>

using namespace std;

template <typename T>
class Storage {
  size_t size, capacity;
  static const size_t step = 5;
  T* elements;

public:
  Storage(size_t capacity);
  Storage(size_t capacity, const T& element);
  const Storage<T>& operator=(const Storage<T>& c);
  Storage(const Storage<T>& c);
  Storage(const Storage<T>&& c);
  ~Storage() { delete[] this->elements; };
  void Push_back(T& element);
  int Find(const T& element);
  void Remove(T& element);
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


#endif