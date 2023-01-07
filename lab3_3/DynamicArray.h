#pragma once

#include <iostream>
using namespace std;

#include <cassert>

template <class T> class DynamicArray
{
private:
	T* data = nullptr;
	int length = 0;

public:
//---------Создание объекта-------------
	//Копировать элементы из переданного массива
	DynamicArray(T* items, int count) {
		data = new T[count];
		length = count;
		for (int i = 0; i < length; i++) {
			data[i] = items[i];
		}
	}
	//Создать массив заданной длины
	DynamicArray(int size) {
		data = new T[size];
		length = size;
		//Resize(size);
	}
	//Копирующий конструктор
	DynamicArray(DynamicArray<T> &dynamicArray) {
		length = dynamicArray.length;
		data = new T[length];
		for (int i = 0; i < length; i++) {
			data[i] = dynamicArray.Get(i);
		}
	}
//------------Декомпозиция--------------
	//Получить элемент по индексу
	/*  Может выбрасывать исключения:
		IndexOutOfRange (если индекс отрицательный, больше/равен 
		числу элементов или указывает на не заданный элемент)
	*/
	T Get(int index) {
		assert(index >= 0);
		assert(index < length);
		return data[index];
	}
	//Получить размер массива
	int  GetSize() {
		return length;
	}
//---------------Операции--------------
	//Задать элемент по индексу
	//Может выбросить IndexOutOfRange
	void Set(int index, T value) {
		assert(index >= 0);
		assert(index < length);
		data[index] = value;
		//(*this)[index] = value;
	}
	// Изменить размер массива. 
	/*  Если размер увеличивается, все 	элементы копируются в начало новой памяти.
		Если уменьшается – элементы, которые не помещаются, отбрасываются.
	*/
	void Resize(int newSize) {
		assert(newSize >= 0);
		T* tmpData = new T[newSize];
		int tmpSize = (newSize > length) ? length : newSize;
		for (int i = 0; i < tmpSize; i++) {
			tmpData[i] = data[i];
		}
		delete[] data;
		data = tmpData;
		length = newSize;
	}
	
	// Изменить размер массива. Элементы сдвигаются вправо
	void ResizeRight(int newSize) {
		assert(newSize >= 0);
		T* tmpData = new T[newSize];
		int i_start = (newSize > length) ? (newSize - length) : 0;
		for (int i = i_start; i < newSize; i++) {
			tmpData[i] = data[i];
		}
		delete data;
		data = tmpData;
		length = newSize;
	}

	T& operator[](int index) {
		if (index >= length || index < 0)
		{
			throw std::out_of_range("Invalid index " + std::to_string(index));
		}
		return data[index];
	}

//--------------Деструктор--------------
	~DynamicArray() {
		delete data;
	}
};
