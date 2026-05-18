#ifndef _ADDITION_HPP_
#define _ADDITION_HPP_
#include <iostream>

using namespace std;

template <typename T>
class Storage {
  size_t size, capacity;
  const size_t step = 3;
  T* elements;

public:
  Storage(size_t capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->elements = new T[this->capacity];
  };
  Storage(size_t capacity, size_t new_step) :step(new_step) {
    if (new_step == 0) {
      throw "Error --> THE_STEP_IS_ZERO";
    }
    this->size = 0;
    this->capacity = capacity;
    this->elements = new T[this->capacity];
  };
  Storage(size_t capacity, const T& element, bool dummy) {
    this->size = capacity;
    this->capacity = capacity;
    this->elements = new T[this->capacity];
    for (size_t i = 0; i < this->size; i++) {
      this->elements[i] = element;
    }
  };
  const Storage<T>& operator=(const Storage<T>& c) {
    if (this == &c) {
      return *this;
    }
    if (this->capacity != c.capacity) {
      delete[] this->elements;
      this->size = c.size;
      this->capacity = c.capacity;
      elements = new T[this->capacity];
    }
    for (size_t i = 0; i < this->size; i++) {
      this->elements[i] = c.elements[i];
    }
    return *this;
  };
  Storage(const Storage<T>& c) {
    this->size = c.size;
    this->capacity = c.capacity;
    this->elements = new T[this->capacity];
    for (size_t i = 0; i < this->size; i++) {
      this->elements[i] = c.elements[i];
    }
  };
  Storage(Storage<T>&& c) {
    this->size = c.size;
    this->capacity = c.capacity;
    this->elements = c.elements;
    /*this->elements = new T[this->capacity];
    for (size_t i = 0; i < this->size; i++) {
      this->elements[i] = c.elements[i];
    }*/
    c.elements = nullptr;
    c.size = 0;
    c.capacity = 0;
  };
  ~Storage() { delete[] this->elements; };
  void Push_back(T element) {
    if (this->size == this->capacity) {
      Storage<T> equal = *this;
      delete[] this->elements;
      capacity += this->step;
      this->elements = new T[capacity];
      for (size_t i = 0; i < size; i++) {
        this->elements[i] = equal.elements[i];
      }
    }
    this->elements[size++] = element;
  };
  int Find(const T& element) const {
    for (size_t i = 0; i < size; i++) {
      if (this->elements[i] == element) {
        return static_cast<int>(i);
        break;
      }
    }
    return -1;
  };
  void Remove(const T& element) {
    int index = Find(element);
    if (index == -1) {
      return;     //reason of throw???
      //thow "Error --> Element is not found";
    }
    this->elements[index] = this->elements[--size];
  };
  const T& operator[](size_t i) const{
    if (i >= size) {
      throw "Error --> OUT_OF_RANGE";
    }
    return this->elements[i];
  };

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
  Storage(size_t capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->elements = new T * [this->capacity] {};

    this->spectrum_lenghts = new size_t[this->capacity]{};
  };
  Storage(size_t capacity, size_t new_step) :step(new_step) {
    if (new_step == 0) {
      throw "Error --> THE_STEP_IS_ZERO";
    }
    this->size = 0;
    this->capacity = capacity;
    this->elements = new T * [this->capacity] {};

    this->spectrum_lenghts = new size_t[this->capacity]{};
  };
  const Storage<T*>& operator=(const Storage<T*>& c) {
    if (this == &c) {
      return *this;
    }
    if (this->capacity != c.capacity) {
      for (size_t i = 0; i < this->capacity; i++) {
        delete this->elements[i];
      }
      delete[] this->elements;
      delete[] this->spectrum_lenghts;
      this->size = c.size;
      this->capacity = c.capacity;
      elements = new T * [this->capacity] {};
      spectrum_lenghts = new size_t[this->capacity]{};
    }
    for (size_t i = 0; i < this->size; i++) {
      spectrum_lenghts[i] = c.spectrum_lenghts[i];
      elements[i] = new T[spectrum_lenghts[i]];
      for (size_t j = 0; j < spectrum_lenghts[i]; j++) {
        elements[i][j] = c.elements[i][j];
      }
    }
    return *this;
  };
  T*& operator[](size_t i) const{
    if (i >= this->size) {
      throw "Error --> OUT_OF_RANGE";
    }
    return this->elements[i];
  };
  Storage(const Storage<T*>& c) {
    this->size = c.size;
    this->capacity = c.capacity;
    this->elements = new T * [this->capacity] {};
    this->spectrum_lenghts = new size_t[this->capacity]{};
    for (size_t i = 0; i < this->size; i++) {
      spectrum_lenghts[i] = c.spectrum_lenghts[i];
      elements[i] = new T[spectrum_lenghts[i]];
      for (size_t j = 0; j < spectrum_lenghts[i]; j++) {
        elements[i][j] = c.elements[i][j];
      }
    }
  };
  Storage(Storage<T*>&& c) {
    this->size = c.size;
    this->capacity = c.capacity;
    this->elements = c.elements;
    this->spectrum_lenghts = c.spectrum_lenghts;
    c.elements = nullptr;
    c.spectrum_lenghts = nullptr;
    c.size = 0;
    c.capacity = 0;
  };
  ~Storage() {
    for (size_t i = 0; i < this->capacity; ++i) {
      delete this->elements[i];
    }
    delete[] this->elements;
    delete[] this->spectrum_lenghts;
  };
  void Push_back(T* element, const size_t size_element) {
    if (this->size == this->capacity) {
      Storage<T*> equal = *this;
      delete[] this->elements;
      delete[] this->spectrum_lenghts;
      capacity += this->step;
      this->elements = new T * [capacity] {};
      this->spectrum_lenghts = new size_t[capacity]{};
      for (size_t i = 0; i < this->size; i++) {
        spectrum_lenghts[i] = equal.spectrum_lenghts[i];
        elements[i] = new T[spectrum_lenghts[i]];
        for (size_t j = 0; j < spectrum_lenghts[i]; j++) {
          elements[i][j] = equal.elements[i][j];
        }
      }
    }
    spectrum_lenghts[size++] = size_element;
    elements[size - 1] = new T[size_element];
    for (size_t j = 0; j < spectrum_lenghts[size - 1]; j++) {
      elements[size - 1][j] = element[j];
    }
  };
  int Find(const T*& element, const size_t size_element) const {
    bool flag = false;
    for (size_t i = 0; i < size; i++) {
      flag = true;
      if (spectrum_lenghts[i] != size_element) continue;
      for (size_t j = 0; j < spectrum_lenghts[i]; j++) {
        if (elements[i][j] != element[j]) {
          flag = false;
          break;
        }
      }
      if (flag) return static_cast<int>(i);
    }
    return -1;
  };
  void Remove(const T*& element, const size_t size_element) {
    int index = Find(element, size_element);
    if (index == -1) {
      return;
    }
    //this->elements[index] = this->elements[--size];
    delete[] elements[index];
    elements[index] = new T[spectrum_lenghts[size - 1]];
    for (size_t i; i < spectrum_lenghts[size - 1]; i++) {
      elements[index][i] = elements[size - 1][i];
    }
    size--;
    elements[size] = nullptr;
    spectrum_lenghts[size] = 0;
  };

  friend ostream& operator<<(ostream& out, const Storage<T*>& c) {
    out << "{ ";
    for (size_t i = 0; i < c.size; i++) {
      out << "[";
      for (size_t j = 0; j < c.spectrum_lenghts[i]; j++) {
        out << c.elements[i][j];
        if (j < c.spectrum_lenghts[i] - 1) out << ", ";
      }
      out << "]";
      if (i < c.size - 1) out << ", ";
    }
    out << " }";
    return out;
  }
};

#endif