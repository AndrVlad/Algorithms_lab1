#pragma once
#include <iostream>
using namespace std;
int ptr;

template<class ElType>
class Queue
{
private:
	struct Elem {
		ElType detail;
		Elem* next = NULL;
	};

public:

	Elem* head;
	Elem* tail;

	Queue() {
		head = tail = NULL;
	}

	void InitQueue() {
		if (!Empty()) {
			Elem* ptr = head;
			Elem* temp = NULL;

			while (ptr != NULL) {
				temp = ptr;
				ptr = ptr->next;
				delete temp;
			}
		}
		else {
			head = NULL;
			tail = NULL;
		}
	}

	bool Empty() {
		if (head == NULL && tail == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Dequeue(ElType x) {
		Elem* temp = NULL;
		if (Empty()) {
			return false;
		}
		else if (head == tail) {
			delete head;
			head = NULL;
			tail = NULL;
		}
		else {
			temp = head;
			head = head->next;
			delete temp;
		}

		return true;
	}

	bool Enqueue(ElType x) {

		Elem* element = new Elem;
		element->detail = x;

		if (Empty()) {
			element->next = NULL;
			head = tail = element;
		}
		else {
			tail->next = element;
			tail = element;
		}

		return true;
	}
	/*
	bool ShowQueue() {
		if (Empty()) {
			return false;
		}
		else {
			ptr = head;
			while (ptr != tail) {
				//cout << " -> " << details[ptr];
				cout << " -> " << details[ptr].kod;
				ptr = (ptr + 1) % NumElem;
			}

		}
		return true;
	}
	*/

	int ElemCount() {

		if (Empty()) {
			return false;
		}

		int count = 0;
		Elem* ptr = head;

		while (ptr != NULL) {
			ptr = ptr->next;
			count++;
		}

		return count;
	}
	
	bool getDetail(ElType& x) {
		if (Empty()) {
			return false;
		}
		x = head->detail;
		return true;
	}
	
	bool getDetail(ElType& x, int offset) {

		Elem* ptr;
		ptr = head;

		while (offset != 0) {
			ptr = ptr->next;
			offset--;
		}
		
		x = ptr->detail;

		return true;
	}
	
};