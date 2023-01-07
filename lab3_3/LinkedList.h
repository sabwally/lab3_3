#pragma once

#include <iostream>
using namespace std;

#include <cassert>

template <class T> class Item {
public:
	T data;
	Item<T>* next;
	Item<T>* previous;
};

template <class T> class LinkedList
{
private:
	Item<T>* head;
	Item<T>* tail;
	int length;
public:
//-----------�������� �������----------
	//���������� �������� �� ����������� �������
	LinkedList(T* items, int count) {
		head = NULL;
		tail = NULL;
		length = 0;
		for (int i = 0; i < count; ++i) {
			Append(items[i]);
		}
	}
	//������� ������ ������
	LinkedList() {
		head = NULL;
		tail = NULL;
		length = 0;
	}
	//���������� �����������
	LinkedList(LinkedList <T> &list) {
		head = NULL;
		tail = NULL;
		length = 0;
		for (int i = 0; i < list.length; ++i) {
			Append(list.Get(i));
		}
	}
//------------������������--------------
	//�������� ������ ������� � ������
	//����� ����������� ����������
	T GetFirst() {
		assert(length > 0);
		return T(head->data);
	}
	//�������� ��������� ������� � ������
	//����� ����������� ����������
	T GetLast() {
		assert(length > 0);
		return T(tail->data);
	}
	//�������� ������� �� �������
	/*  ����� ����������� ����������:
		IndexOutOfRange (���� ������ �������������, ������/�����
		����� ��������� ��� ��������� �� �� �������� �������)
	*/
	T Get(int index) {
		assert(!(index == 0 && length == 0));
		assert(index >= 0);
		assert(index < length);
		Item<T>* tmp = head;
		for (int i = 0; i < index; ++i) {
			tmp = tmp->next;
		}
		return tmp->data;
	}
	//�������� ������ �� ���� ���������, ������� � startIndex � ���������� endIndex
	/*	����� ����������� ����������:
		IndexOutOfRange (���� ���� �� ���� �� �������� �������������
		��� ������/����� ����� ���������)
	*/
	LinkedList<T>* GetSubList(int startIndex, int endIndex) {
		assert(startIndex >= 0);
		assert(startIndex < length);
		assert(endIndex >= 0);
		assert(endIndex < length);
		LinkedList<T>* buf = new LinkedList<T>();
		for (int i = startIndex; i < endIndex; ++i) {
			buf->Append(Get(i));
		}
		return buf;
	}
	//�������� ����� ������
	int GetLength() {
		return length;
	}
//---------------��������--------------
	//������ ������� �� �������
	//����� ��������� IndexOutOfRange
	void Set(int index, T value) {
		assert(!(index == 0 && length == 0));
		assert(index >= 0);
		assert(index < length);
		Item<T>* tmp = head;
		for (int i = 0; i < index; ++i) {
			tmp = tmp->next;
		}
		tmp->data = value;
	}
	//��������� ������� � ����� ������
	void Append(T item) {
		++length;
		Item<T>* tmp = new Item<T>;
		tmp->next = NULL;
		tmp->data = item;
		if (head == NULL) {
			head = tmp;
			head->previous = NULL;
			tail = head;
		}
		else {
			tail->next = tmp;
			tmp->previous = tail;
			tail = tmp;
		}
	}
	//��������� ������� � ������ ������
	void Prepend(T item) {
		++length;
		Item<T>* tmp = new Item<T>;
		tmp->next = NULL;
		tmp->data = item;
		if (head == NULL) {
			head = tmp;
			head->previous = NULL;
			tail = head;
		}
		else {
			head->previous = tmp;
			tmp->next = head;
			head = tmp;
		}
	}
	//��������� ������� � �������� �������
	//����� ����������� ����������
	void InsertAt(T item, int index) {
		assert(index >= 0);
		assert(index <= length);
		if (index == 0) {
			Prepend(item);
		} 
		else if (index == length) {
			Append(item);
		}
		else {
			Item <T>* item_prev = head;
			for (int i = 0; i < index - 1; ++i) {
				item_prev = item_prev->next;
			}
			++length;
			Item<T>* tmp = new Item<T>;
			tmp->data = item;
			tmp->next = item_prev->next;
			tmp->previous = item_prev;
			item_prev->next->previous = tmp;
			item_prev->next = tmp;
		}
	}
	//�������� ��� ������
	LinkedList<T>* Concat(LinkedList<T>* list) {
		for (int i = 0; i < list->length; ++i) {
			Append(list->Get(i));
		}
		return this;
	}

	void RemoveAt(int index)
	{
		Item<T>* toBeRemoved = head;
		for (int i = 0; i < index; ++i) {
			toBeRemoved = toBeRemoved->next;
		}
		if (toBeRemoved->previous != nullptr)
		{
			toBeRemoved->previous->next = toBeRemoved->next;
		}
		if (toBeRemoved->next != nullptr)
		{
			toBeRemoved->next->previous = toBeRemoved->previous;
		}

		if (toBeRemoved == tail)
		{
			tail = toBeRemoved->previous;
		}
		if (toBeRemoved == head)
		{
			head = toBeRemoved->next;
		}

		delete toBeRemoved;
		length--;
	}
//--------------����������--------------
	~LinkedList() {
		Item<T>* ptr = head, *ptr_prev;
		while (ptr) {
			ptr_prev = ptr;
			ptr = ptr->next;
			delete ptr_prev;
		}
		//delete list  ???
	}
};