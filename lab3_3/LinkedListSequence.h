#pragma once
#include "Sequence.h"
#include "LinkedList.h"

template <class T> class LinkedListSequence : public Sequence<T> {
private:
	LinkedList<T>* inner_list;
public:
	//---------�������� �������-------------
	//���������� �������� �� ����������� �������
	LinkedListSequence(T* items, int count) {
		inner_list = new LinkedList<T>(items, count);
	}
	//������� ������ ������
	LinkedListSequence() {
		inner_list = new LinkedList<T>;
	}
	//���������� �����������
	LinkedListSequence(LinkedListSequence <T>& list) {
		inner_list = new LinkedList<T>;
		for (int i = 0; i < list.GetLength(); ++i) {
			this->Append(list.Get(i));
		}
	}
	//------------������������--------------
	//�������� ������ ������� � ������
	T GetFirst() {
		return inner_list->GetFirst();
	}
	//�������� ��������� ������� � ������
	T GetLast() {
		return inner_list->GetLast();
	}
	//�������� ������� �� �������
	T Get(int index) {
		return inner_list->Get(index);
	}
	//�������� ������ �� ���� ���������, ������� � startIndex � ���������� endIndex
	LinkedListSequence<T>* GetSubsequence(int startIndex, int endIndex) {
		LinkedList<T>* tmp_list = new LinkedList<T>(*(inner_list->GetSubList(startIndex, endIndex)));
		LinkedListSequence<T>* tmp_list_seq = new LinkedListSequence<T>;
		for (int i = 0; i < tmp_list->GetLength(); i++) {
			tmp_list_seq->Append(tmp_list->Get(i));
		}
		delete tmp_list;
		return (LinkedListSequence<T>*)tmp_list_seq;
	}
	//�������� ����� ������
	int GetLength() {
		return inner_list->GetLength();
	}
	//---------------��������--------------
	//������ ������� �� �������
	void Set(int index, T value) {
		inner_list->Set(index, value);
	}
	//��������� ������� � ����� ������
	void Append(T item) {
		inner_list->Append(item);
	}
	//��������� ������� � ������ ������
	void Prepend(T item) {
		inner_list->Prepend(item);
	}
	//��������� ������� � �������� �������
	void InsertAt(T item, int index) {
		inner_list->InsertAt(item, index);
	}
	//�������� ��� ������
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

	//--------------����������--------------
	~LinkedListSequence() {
		delete inner_list;
	}
};
