#pragma once
#include "Sequence.h"
#include "LinkedList.h"

template <class T> class LinkedListSequence : public Sequence<T> {
private:
	LinkedList<T>* inner_list;
public:
	//---------Создание объекта-------------
	//Копировать элементы из переданного массива
	LinkedListSequence(T* items, int count) {
		inner_list = new LinkedList<T>(items, count);
	}
	//Создать пустой список
	LinkedListSequence() {
		inner_list = new LinkedList<T>;
	}
	//Копирующий конструктор
	LinkedListSequence(LinkedListSequence <T>& list) {
		inner_list = new LinkedList<T>;
		for (int i = 0; i < list.GetLength(); ++i) {
			this->Append(list.Get(i));
		}
	}
	//------------Декомпозиция--------------
	//Получить первый элемент в списке
	T GetFirst() {
		return inner_list->GetFirst();
	}
	//Получить последний элемент в списке
	T GetLast() {
		return inner_list->GetLast();
	}
	//Получить элемент по индексу
	T Get(int index) {
		return inner_list->Get(index);
	}
	//Получить список из всех элементов, начиная с startIndex и заканчивая endIndex
	LinkedListSequence<T>* GetSubsequence(int startIndex, int endIndex) {
		LinkedList<T>* tmp_list = new LinkedList<T>(*(inner_list->GetSubList(startIndex, endIndex)));
		LinkedListSequence<T>* tmp_list_seq = new LinkedListSequence<T>;
		for (int i = 0; i < tmp_list->GetLength(); i++) {
			tmp_list_seq->Append(tmp_list->Get(i));
		}
		delete tmp_list;
		return (LinkedListSequence<T>*)tmp_list_seq;
	}
	//Получить длину списка
	int GetLength() {
		return inner_list->GetLength();
	}
	//---------------Операции--------------
	//Задать элемент по индексу
	void Set(int index, T value) {
		inner_list->Set(index, value);
	}
	//Добавляет элемент в конец списка
	void Append(T item) {
		inner_list->Append(item);
	}
	//Добавляет элемент в начало списка
	void Prepend(T item) {
		inner_list->Prepend(item);
	}
	//Вставляет элемент в заданную позицию
	void InsertAt(T item, int index) {
		inner_list->InsertAt(item, index);
	}
	//Сцепляет два списка
	Sequence <T>* Concat(Sequence <T>* list) {
		Sequence<T>* copy = new LinkedListSequence(*this);
		for (int i = 0; i < list->GetLength(); ++i) {
			copy->Append(list->Get(i));
		}
		return copy;

	}

	void RemoveAt(int index) {
		inner_list->RemoveAt(index);
	}

	//--------------Деструктор--------------
	~LinkedListSequence() {
		delete inner_list;
	}
};
