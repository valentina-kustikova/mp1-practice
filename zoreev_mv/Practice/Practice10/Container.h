#pragma once
#include "Exeption.h"
#include <iostream>
#define STEP 10


template<typename Type>
class Container
{
	Type* arr;
	unsigned size;
	unsigned max_size;

public:
	Container();
	Container(const Container& temp);
	~Container();

	//Добавление элемента
	void Add(const Type& temp);
	//Добавление элемента по указателю
	void Add(const Type* temp);
	//Поиск элемента
	unsigned Find(const Type& temp);
	//Поиск и удаление элемента
	void FindAndRemove(const Type& temp);
	//Удаление элемента по индексу
	void Remove(unsigned index);
	//Вывод содержимого на экран
	void Print();
	//Проверка на полноту
	bool IsFull();
	//Провепка на пустоту
	bool IsEmpty();

	Container<Type>& operator=(const Container<Type>& temp);
	Type& operator[](unsigned index);
};

template<typename Type>
Container<Type>::Container()
{
	size = 0;
	max_size = 0;
	arr = nullptr;
}

template<typename Type>
Container<Type>::Container(const Container& temp)
{
	size = temp.size;
	max_size = temp.max_size;
	arr = new Type[max_size];
	for (unsigned i = 0; i < size; i++)
	{
		arr[i] = temp.arr[i];
	}
}

template<typename Type>
Container<Type>::~Container()
{
	size = 0;
	max_size;
	delete[] arr;
}

template<typename Type>
void Container<Type>::Add(const Type& temp)
{
	if (size == max_size)
	{
		Type* temp_arr = new Type[max_size + STEP];
		for (unsigned i = 0; i < size; i++)
		{
			temp_arr[i] = arr[i];
		}
		max_size += STEP;
		if (arr != nullptr) delete[] arr;
		arr = temp_arr;
	}
	size++;
	arr[size - 1] = temp;
	return;
	throw Exeption(ContainerIsFull);
	return;
}

template<typename Type>
void Container<Type>::Add(const Type* temp)
{
	if (size == max_size)
	{
		Type* temp_arr = new Type[max_size + STEP];
		for (unsigned i = 0; i < size; i++)
		{
			temp_arr[i] = arr[i];
		}
		max_size += STEP;
		if (arr != nullptr) delete[] arr;
		arr = temp_arr;
	}
	size++;
	arr[size - 1] = *temp;
	return;
	return;
}

template<typename Type>
unsigned Container<Type>::Find(const Type& temp)
{
	for (unsigned i = 0; i < size; i++)
	{
		if (temp == arr[i]) return i;
	}
	return -1;
}

template<typename Type>
void Container<Type>::FindAndRemove(const Type& temp)
{
	if (size == 0) return;
	unsigned del;
	del = Find(temp);
	if (del == -1) return;
	Type* temp_arr = new Type[size - 1];
	unsigned i = 0, j = 0;
	while (i < size)
	{
		if (i != del)
		{
			temp_arr[j] = arr[i];
			i++;
			j++;
		}
		else
		{
			i++;
		}
	}
	if (arr != nullptr) delete[] arr;
	size--;
	arr = temp_arr;
}

template<typename Type>
void Container<Type>::Remove(unsigned index)
{
	if (size == 0) return;
	if ((index < 0) || (index >= size))
	{
		throw Exeption(BadIndex);
	}
	Type* temp_arr = new Type[size - 1];
	unsigned i = 0, j = 0;
	while (i < size)
	{
		if (i != index)
		{
			temp_arr[j] = arr[i];
			i++;
			j++;
		}
		else
		{
			i++;
		}
	}
	delete[] arr;
	size--;
	arr = temp_arr;
}

template<typename Type>
Container<Type>& Container<Type>::operator=(const Container<Type>& temp)
{
	if (&temp == this) return *this;
	if (temp.size > max_size)
	{
		throw Exeption(BadContainerSize);
		return *this;
	}
	if (arr != nullptr) delete[] arr;
	size = temp.size;
	arr = new Type[size];
	for (unsigned i; i < size; i++)
	{
		arr[i] = temp.arr[i];
	}
	return *this;
}

template<typename Type>
Type& Container<Type>::operator[](unsigned index)
{
	if ((index < 0) || (index >= size))
	{
		throw Exeption(BadIndex);
	}
	return arr[index];
}

template<typename Type>
void Container<Type>::Print()
{
	for (unsigned i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

template<typename Type>
bool Container<Type>::IsFull()
{
	if (size == max_size) return true;
	return false;
}

template<typename Type>
bool Container<Type>::IsEmpty()
{
	if (size == 0) return true;
	return false;
}

//Супер специализация для Type*

template<typename Type>
class Container<Type*>
{
	Type** arr;
	unsigned size;
	unsigned max_size;

public:
	Container();
	Container(const Container<Type>& temp);
	~Container();

	//Добавление элемента
	void Add(const Type& temp);
	//Добавление элемента по указателю
	void Add(const Type* temp);
	//Поиск элемента
	unsigned Find(const Type& temp);
	//Поиск и удаление элемента
	void FindAndRemove(const Type& temp);
	//Удаление элемента по индексу
	void Remove(unsigned index);
	//Вывод содержимого на экран
	void Print();
	//Проверка на полноту
	bool IsFull();
	//Провепка на пустоту
	bool IsEmpty();

	Container<Type*>& operator=(const Container<Type>& temp);
	Type& operator[](unsigned index);
};

template<typename Type>
Container<Type*>::Container()
{
	size = 0;
	max_size = 0;
	arr = nullptr;
}

template<typename Type>
Container<Type*>::Container(const Container<Type>& temp)
{
	size = temp.size;
	max_size = temp.max_size;
	arr = new Type* [max_size];
	for (unsigned i = 0; i < size; i++)
	{
		arr[i] = new Type;
		arr[i][0] = temp.arr[i][0];
	}
}

template<typename Type>
Container<Type*>::~Container()
{
	for (unsigned i = 0; i < size; i++)
	{
		delete arr[i];
	}
	max_size = 0;
	size = 0;
	delete[] arr;
}

template<typename Type>
void Container<Type*>::Add(const Type& temp)
{
	if (size == max_size)
	{
		Type** temp_arr = new Type*[max_size + STEP];
		for (unsigned i = 0; i < size; i++)
		{
			temp_arr[i] = new Type;
			temp_arr[i][0] = arr[i][0];
		}
		max_size += STEP;
		if (arr != nullptr) delete[] arr;
		arr = temp_arr;
	}
	arr[size] = new Type;
	arr[size][0] = temp;
	size++;
	return;
	return;
}

template<typename Type>
void Container<Type*>::Add(const Type* temp)
{
	if (size == max_size)
	{
		Type** temp_arr = new Type*[max_size + STEP];
		for (unsigned i = 0; i < size; i++)
		{
			temp_arr[i] = new Type;
			temp_arr[i][0] = arr[i][0];
		}
		max_size += STEP;
		if (arr != nullptr) delete[] arr;
		arr = temp_arr;
	}
		arr[size] = new Type;
		arr[size][0] = *temp;
		size++;
		return;
	return;
}

template<typename Type>
unsigned Container<Type*>::Find(const Type& temp)
{
	for (unsigned i = 0; i < size; i++)
	{
		if (temp == arr[i][0]) return i;
	}
	return -1;
}

template<typename Type>
void Container<Type*>::FindAndRemove(const Type& temp)
{
	if (size == 0) return;
	unsigned del;
	del = Find(temp);
	if (del == -1) return;
	if (size > 1)
	{
		arr[del][0] = arr[size - 1][0];
	}
	delete arr[size-1];
	size--;
}

template<typename Type>
void Container<Type*>::Remove(unsigned index)
{
	if ((index < 0) || (index >= size))
	{
		throw Exeption(BadIndex);
	}
	if (size == 0) return;
	if (size > 1)
	{
		arr[index][0] = arr[size - 1][0];
	}
	delete arr[size - 1];
	size--;
}

template<typename Type>
Container<Type*>& Container<Type*>::operator=(const Container<Type>& temp)
{
	for (unsigned i = 0; i < size; i++)
	{
		delete arr[i];
	}
	size = temp.size;
	for (unsigned i = 0; i < size; i++)
	{
		arr[i] = new Type;
		arr[i][0] = temp.arr[i];
	}
}

template<typename Type>
Type& Container<Type*>::operator[](unsigned index)
{
	if ((index < 0) || (index >= size))
	{
		throw Exeption(BadIndex);
	}
	return arr[index][0];
}

template<typename Type>
void Container<Type*>::Print()
{
	for (unsigned i = 0; i < size; i++)
	{
		std::cout << arr[i][0] << std::endl;
	}
}

template<typename Type>
bool Container<Type*>::IsFull()
{
	if (size == max_size) return true;
	return false;
}

template<typename Type>
bool Container<Type*>::IsEmpty()
{
	if (size == 0) return true;
	return false;
}