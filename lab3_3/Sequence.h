#pragma once
#include <iostream>
#include <functional>

using namespace std;

template <class T> class Sequence {
public:
	friend std::ostream& operator<<(std::ostream& s, const Sequence<T>& seq)
	{
		s << "{";
		if (seq.GetLength() > 0)
		{
			s << seq[0];
			for (int i = 1; i < seq.GetLength(); ++i)
			{
				s << ", " << seq[i];
			}
		}
		s << "}";
		return s;
	}
	
	//---------�������� �������-------------
	Sequence() {}
	Sequence(T* items, int count) {}

	//------------������������--------------
	//�������� ������ ������� � ������
	virtual T GetFirst() = 0;
	//�������� ��������� ������� � ������
	virtual T GetLast() = 0;
	//�������� ������� �� �������
	virtual T Get(int index) = 0;
	//�������� ������ �� ���� ���������, ������� � startIndex � ���������� endIndex
	virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
	//�������� ����� ������
	virtual int GetLength() = 0;

	//---------------��������--------------
	//������ ������� �� �������
	virtual void Set(int index, T value) = 0;
	//��������� ������� � ����� ������
	virtual void Append(T item) = 0;
	//��������� ������� � ������ ������
	virtual void Prepend(T item) = 0;
	//��������� ������� � �������� �������
	virtual void InsertAt(T item, int index) = 0;
	//�������� ��� ������
	virtual Sequence <T>* Concat(Sequence <T>* list) = 0;

	virtual void RemoveAt(int index) = 0;

	T Reduce(
		std::function<T(const T& val, const T& acc)> f,
		const T& initial)
	{
		T val = initial;
		for (int i = 0; i < GetLength(); ++i)
		{
			val = f(Get(i), val);
		}
		return val;
	}

	//--------------����������--------------
	virtual ~Sequence<T>() {}
};