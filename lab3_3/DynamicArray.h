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
//---------�������� �������-------------
	//���������� �������� �� ����������� �������
	DynamicArray(T* items, int count) {
		data = new T[count];
		length = count;
		for (int i = 0; i < length; i++) {
			data[i] = items[i];
		}
	}
	//������� ������ �������� �����
	DynamicArray(int size) {
		data = new T[size];
		length = size;
		//Resize(size);
	}
	//���������� �����������
	DynamicArray(DynamicArray<T> &dynamicArray) {
		length = dynamicArray.length;
		data = new T[length];
		for (int i = 0; i < length; i++) {
			data[i] = dynamicArray.Get(i);
		}
	}
//------------������������--------------
	//�������� ������� �� �������
	/*  ����� ����������� ����������:
		IndexOutOfRange (���� ������ �������������, ������/����� 
		����� ��������� ��� ��������� �� �� �������� �������)
	*/
	T Get(int index) {
		assert(index >= 0);
		assert(index < length);
		return data[index];
	}
	//�������� ������ �������
	int  GetSize() {
		return length;
	}
//---------------��������--------------
	//������ ������� �� �������
	//����� ��������� IndexOutOfRange
	void Set(int index, T value) {
		assert(index >= 0);
		assert(index < length);
		data[index] = value;
		//(*this)[index] = value;
	}
	// �������� ������ �������. 
	/*  ���� ������ �������������, ��� 	�������� ���������� � ������ ����� ������.
		���� ����������� � ��������, ������� �� ����������, �������������.
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
	
	// �������� ������ �������. �������� ���������� ������
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

//--------------����������--------------
	~DynamicArray() {
		delete data;
	}
};
