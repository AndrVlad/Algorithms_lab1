#pragma once
#include <iostream>
using namespace std;
const int NumElem = 6;
int ptr;

template<class ElType>
class Queue
{
private:
	ElType details[NumElem];

public:

	int head, tail;

	Queue() {
		head = tail = 0;
	}

	void InitQueue() {
		head = tail = 0;
	}

	bool Empty() {
		if (head == tail) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Full() {
		if ((head == 0 && tail == NumElem - 1) || (tail == head - 1)) {
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
		if (Full()) {
			return false;
		}
		else if (Empty()) {
			details[head] = x;
			tail = (tail + 1) % NumElem;
		}
		else {
			details[tail] = x;
			tail = (tail + 1) % NumElem;

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

	bool getDetail(ElType &x) {
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
