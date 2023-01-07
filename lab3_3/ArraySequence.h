#pragma once
#include "Sequence.h"
#include "DynamicArray.h"
#include <string.h>

template <class T> class ArraySequence : public Sequence<T> {
private:
	DynamicArray<T>* arr;
	ArraySequence(DynamicArray<T>* array) :
		arr(array) {}
public:
	ArraySequence() :
		arr(new DynamicArray<T>(0)) {}

	ArraySequence(int count) :
		arr(new DynamicArray<T>(count)) {}

	ArraySequence(T* items, int count) :
		arr(new DynamicArray<T>(items, count)) {}

	ArraySequence(const ArraySequence<T>& sequence) :
		arr(new DynamicArray<T>(*sequence.arr)) {}

	ArraySequence<T>& operator=(const ArraySequence<T>& other)	{
		if (this == &other) {
			return *this;
		}
		arr = new DynamicArray<T>(*other.arr);
		return *this;
	}
	//------------������������--------------
	//�������� ������ ������� � ������
	T GetFirst() {
		return this->Get(0);
	}
	//�������� ��������� ������� � ������
	T GetLast() {
		return this->Get(arr->GetSize() - 1);
	}
	//�������� ������� �� �������
	T Get(int index) {
		return arr->Get(index);
	}
	//�������� ������ �� ���� ���������, ������� � startIndex � ���������� endIndex
	ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) {
		ArraySequence<T>* tmp = new ArraySequence<T>;
		tmp->Resize(endIndex - startIndex + 1);
		for (int i = startIndex; i <= endIndex; ++i) {
			tmp->Set(i - startIndex, this->Get(i));
		}
		return tmp;
	}
	//�������� ����� ������
	int GetLength()	{
		return arr->GetSize();
	}
	//---------------��������--------------
	//������ ������� �� �������
	void Set(int index, T value) {
		arr->Set(index, value);
	}
	//��������� ������� � ����� ������
	void Append(T item) {
		arr->Resize(GetLength() + 1);
		arr->Set(GetLength() - 1, item);
		//InsertAt(item, GetLength());
	}
	//��������� ������� � ������ ������
	void Prepend(T item) {
		arr->ResizeRight(arr->GetSize() + 1);
		arr->Set(0, item);
	}
	//��������� ������� � �������� �������
	void InsertAt(T item, int index) {
		int new_len = this->GetLength() + 1;
		this->Resize(new_len);
		T tmp;
		int dif = new_len - index;
		for (int i = 0; i < dif; ++i) {
			tmp = this->Get(new_len - i - 2);
			this->Set(new_len - i - 1, tmp);
		}
		this->Set(index, item);
	}
	//�������� ��� ������
	Sequence <T>* Concat(Sequence <T>* list) {
		ArraySequence<T>* newSequence = new ArraySequence<T>(*this);
		for (int i = 0; i < list->GetLength(); ++i)	{
			newSequence->Append(list->Get(i));
		}
		return newSequence;
	}
	// �������� ������ �������.
	void Resize(int newSize) {
		arr->Resize(newSize);
	}
	// �������� ������ �������. �������� ���������� ������
	void ResizeRight(int newSize) {
		arr->ResizeRight(newSize);
	}

	void RemoveAt(int index){
		T tmp;
		for (int i = index + 1; i < GetLength(); ++i)
		{
			tmp = this->Get(i);
			arr->Set(i - 1, tmp);
		}
		arr->Resize(arr->GetSize() - 1);
	}

	string to_string() const {
		stringstream ss;
		for (int i = 0; i < arr->GetSize(); ++i) {
			ss << this->arr->Get(i) << " ";
		}
		return ss.str();
	}

	friend ostream& operator<<(ostream& out, const ArraySequence<T>& t) {
		out << t.to_string();
		return out;
	}

	T& operator[](int index) {
		return (*arr)[index];
		//return Get(index);
	}

//--------------����������--------------
	~ArraySequence() {
		delete arr;
	}
};