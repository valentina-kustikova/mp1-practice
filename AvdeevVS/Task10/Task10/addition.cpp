#include "addition.hpp"

template <typename T>
Storage<T>::Storage(size_t capacity) {
  this->size = 0;
  this->capacity = capacity;
  this->elements = new T[this->capacity];
}

template <typename T>
Storage<T>::Storage(size_t capacity,const T& element) {
  this->size = capacity;
  this->capacity = capacity;
  this->elements = new T[this->capacity];
  for (size_t i; i < this->size; i++) {
    this->elements[i] = element;
  }
}

template <typename T>
const Storage<T>& Storage<T>::operator=(const Storage<T>& c) {
  if (this == &c) {
    return;
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
  return this*;
}

template <typename T>
Storage<T>::Storage(const Storage<T>& c) {
  this->size =c.size;
  this->capacity = c.capacity;
  this->elements = new T[this->capacity];
  for (size_t i = 0; i < this->size; i++) {
    this->elements[i] = c.elements[i];
  }
}

template <typename T>
Storage<T>::Storage(const Storage<T>&& c) {
  this->size = c.size;
  this->capacity = c.capacity;
  this->elements = new T[this->capacity];
  for (size_t i = 0; i < this->size; i++) {
    this->elements[i] = c.elements[i];
  }
  c.elements = nullptr;
  c.size = 0;
  c.capacity = 0;
}

template <typename T>
const T& Storage<T>::operator[](size_t i) const{
  if (i >= capacity) {
    throw "Error --> OUT_OF_RANGE";
  }
  return this->elements[i];
  }

template <typename T>
int Storage<T>::Find(const T& element) {
  for (size_t i = 0; i < size; i++) {
    if (this->elements[i] == element) {
      return i;
      break;
    }
  }
  return -1;
}

template <typename T>
void Storage<T>::Remove(T& element) {
  int index = Find(element);
  if (index == -1) {
    return;     //reason of throw???
    //thow "Error --> Element is not found";
  }
  this->elements[index] = this->elements[--size];
}

template <typename T>
void Storage<T>::Push_back(T& element) {
  if (this->size == this->capacity) {
    Storage<T> equal = *this;
    delete[] this->elements;
    this->elements = new T[capacity + this->step];
    for (size_t i = 0; i < size; i++) {
      this->elements[i] = equal.elements[i];
    }
  }
  this->elements[size++] = element;
}
