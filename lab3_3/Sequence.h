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
	
	//---------Создание объекта-------------
	Sequence() {}
	Sequence(T* items, int count) {}

	//------------Декомпозиция--------------
	//Получить первый элемент в списке
	virtual T GetFirst() = 0;
	//Получить последний элемент в списке
	virtual T GetLast() = 0;
	//Получить элемент по индексу
	virtual T Get(int index) = 0;
	//Получить список из всех элементов, начиная с startIndex и заканчивая endIndex
	virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
	//Получить длину списка
	virtual int GetLength() = 0;

	//---------------Операции--------------
	//Задать элемент по индексу
	virtual void Set(int index, T value) = 0;
	//Добавляет элемент в конец списка
	virtual void Append(T item) = 0;
	//Добавляет элемент в начало списка
	virtual void Prepend(T item) = 0;
	//Вставляет элемент в заданную позицию
	virtual void InsertAt(T item, int index) = 0;
	//Сцепляет два списка
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

	//--------------Деструктор--------------
	virtual ~Sequence<T>() {}
};