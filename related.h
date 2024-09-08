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
		ElType* next;
	};

	Elem* head;
	Elem* tail;
	
public:

	Queue() {
		head = tail = NULL;
	}

	void InitQueue() {
		head = tail = 0;
	}

	bool Empty() {
		if (head == tail == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Dequeue(ElType x) {
		if (Empty()) {
			return false;
		}
		else {
			head = (head + 1) % NumElem;
			return true;
		}
	}

	bool Enqueue(ElType x) {
		if (Empty()) {
			return false;
		}
		else if (Empty()) {
			details[head] = x;
			tail = (tail + 1) % NumElem;
		}
		else {
			details[tail] = x;
			//tail = (tail % (NumElem - 1)) + 1;
			tail = (tail + 1) % NumElem;

		}

		return true;
	}

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



	int ElemCount() {

		if (Empty()) {
			return false;
		}

		int count = 0;
		int ptr = head;

		while (ptr != tail) {
			ptr = (ptr + 1) % NumElem;
			count++;
		}

		return count;
	}

	bool getDetail(ElType& x) {
		if (Empty()) {
			return false;
		}

		x = details[head];
		return true;
	}

	bool getDetail(ElType& x, int offset) {

		int ptr = (head + offset) % NumElem;
		x = details[ptr];

		return true;
	}

};