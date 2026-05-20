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
  Storage(size_t capacity);
  Storage(size_t capacity, size_t new_step);
  Storage(size_t capacity, const T& element, bool dummy);
  const Storage<T>& operator=(const Storage<T>& c);
  Storage(const Storage<T>& c);
  Storage(Storage<T>&& c);
  ~Storage() { delete[] this->elements; };
  void Push_back(T element);
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
  T** elements;

public:
  Storage(size_t capacity);
  Storage(size_t capacity, size_t new_step);
  const Storage<T*>& operator=(const Storage<T*>& c);
  T*& operator[](size_t i) const;
  Storage(const Storage<T*>& c);
  Storage(Storage<T*>&& c);
  ~Storage();
  void Push_back(T* element, const size_t size_element);
  int Find(const T*& element, const size_t size_element) const;
  void Remove(const T*& element, const size_t size_element);

  friend ostream& operator<<(ostream& out, const Storage<T*>& c) {
    out << "{ ";
    for (size_t i = 0; i < c.size; i++) {
      out << *(c.elements[i]) << ' ';
    }
    out << " }";
    return out;
  };
 };
  
 template <typename T>
 Storage<T>::Storage(size_t capacity) {
   this->size = 0;
   this->capacity = capacity;
   this->elements = new T[this->capacity];
 }

 template <typename T>
 Storage<T>::Storage(size_t capacity, size_t new_step) :step(new_step) {
   if (new_step == 0) {
     throw "Error --> THE_STEP_IS_ZERO";
   }
   this->size = 0;
   this->capacity = capacity;
   this->elements = new T[this->capacity];
 };

 template <typename T>
 Storage<T>::Storage(size_t capacity, const T& element, bool dummy) {
   this->size = capacity;
   this->capacity = capacity;
   this->elements = new T[this->capacity];
   for (size_t i = 0; i < this->size; i++) {
     this->elements[i] = element;
   }
 };

 template <typename T>
 const Storage<T>& Storage<T>::operator=(const Storage<T>& c) {
   if (this == &c) {
     return *this;
   }
   if (this->capacity != c.capacity) {
     delete[] this->elements;
     this->capacity = c.capacity;
     elements = new T[this->capacity];
   }
   this->size = c.size;
   for (size_t i = 0; i < this->size; i++) {
     this->elements[i] = c.elements[i];
   }
   return *this;
 };

 template <typename T>
 Storage<T>::Storage(const Storage<T>& c) {
   this->size = c.size;
   this->capacity = c.capacity;
   this->elements = new T[this->capacity];
   for (size_t i = 0; i < this->size; i++) {
     this->elements[i] = c.elements[i];
   }
 };

 template <typename T>
 Storage<T>::Storage(Storage<T>&& c) {
   this->size = c.size;
   this->capacity = c.capacity;
   this->elements = c.elements;
   c.elements = nullptr;
   c.size = 0;
   c.capacity = 0;
 };

 template <typename T>
 void Storage<T>::Push_back(T element) {
   if (this->size == this->capacity) {
     capacity += this->step;
     T* tmp = new T[capacity];
     for (size_t i = 0; i < size; i++) {
       tmp[i] = this->elements[i];
     }
     delete[] this->elements;
     this->elements = tmp;
     delete[] tmp;
   }
   this->elements[size++] = element;
 };

 template <typename T>
 int Storage<T>::Find(const T& element) const {
   for (size_t i = 0; i < size; i++) {
     if (this->elements[i] == element) {
       return static_cast<int>(i);
     }
   }
   return -1;
 };

 template <typename T>
 void Storage<T>::Remove(const T& element) {
   int index = Find(element);
   if (index == -1) {
     throw "Error --> Element is not found";
   }
   this->elements[index] = this->elements[--size];
 };

 template <typename T>
 const T& Storage<T>::operator[](size_t i) const {
   if (i >= size) {
     throw "Error --> OUT_OF_RANGE";
   }
   return this->elements[i];
 };
 //-------------------------------------------------------
 template <typename T>
 Storage<T*>::Storage(size_t capacity) {
   this->size = 0;
   this->capacity = capacity;
   this->elements = new T * [this->capacity]{};
 };

 template <typename T>
 Storage<T*>::Storage(size_t capacity, size_t new_step) :step(new_step) {
   if (new_step == 0) {
     throw "Error --> THE_STEP_IS_ZERO";
   }
   this->size = 0;
   this->capacity = capacity;
   this->elements = new T * [this->capacity]{};
 };

 template <typename T>
 const Storage<T*>& Storage<T*>::operator=(const Storage<T*>& c) {
   if (this == &c) {
     return *this;
   }
   if (this->capacity != c.capacity) {
     for (size_t i = 0; i < this->capacity; i++) {
       delete this->elements[i];
     }
     delete[] this->elements;
     this->size = c.size;
     this->capacity = c.capacity;
     elements = new T * [this->capacity]{};
     for (size_t i = 0; i < this->size; i++) {
       this->elements[i] = new T(*(c.elements[i]);
     }
   }
   return *this;
 };

 template <typename T>
 T*& Storage<T*>::operator[](size_t i) const {
   if (i >= this->size) {
     throw "Error --> OUT_OF_RANGE";
   }
   return this->elements[i];
 };

 template <typename T>
 Storage<T*>::Storage(const Storage<T*>& c) {
   this->size = c.size;
   this->capacity = c.capacity;
   this->elements = new T * [this->capacity]{};
   for (size_t i = 0; i < this->size; i++) {
     this->elements[i] = new T(*c.elements[i]); //elements[i] = c.elements[i]
   }
 };

 template <typename T>
 Storage<T*>::Storage(Storage<T*>&& c) {
   this->size = c.size;
   this->capacity = c.capacity;
   this->elements = c.elements;
   c.elements = nullptr;
   c.size = 0;
   c.capacity = 0;
 };

 template <typename T>
 Storage<T*>::~Storage() {
   for (size_t i = 0; i < this->capacity; i++) {
     delete this->elements[i];
   }
   delete[] this->elements;
 };

 template <typename T>
 void Storage<T*>::Push_back(T* element, const size_t size_element) {
   if (this->size == this->capacity) {
     capacity += this->step;
     T** temp = new T * [capacity] {};
     for (size_t i = 0; i < size; i++) {
       temp[i] = this->elements[i];
     }
     for (size_t i = 0; i < size; i++) {
       delete this->elements[i];
     }
     delete[] elements;
     this->elements = temp;
     for (size_t i = 0; i < size; i++) {
       delete temp[i];
     }
     delete[] temp;
   }
   this->elements[size++] = new T(*element); //statis argument a in main and use delete with a ---> stack data 
 };

 template <typename T>
 int Storage<T*>::Find(const T*& element, const size_t size_element) const {
   for (size_t i = 0; i < size; i++) {
     if (*(elements[i]) == *(element)) {
       return static_cast<int>(i);
     }
   }
   return -1;
 };

 template <typename T>
 void Storage<T*>::Remove(const T*& element, const size_t size_element) {
   int index = Find(element, size_element);
   if (index == -1) {
     throw "Error --> Element is not found";
   }
   delete elements[index];
   elements[index] = elements[--size];
   elements[size] = nullptr;
 };
#endif