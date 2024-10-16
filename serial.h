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

		int temp = (tail + 1) % NumElem;
		if (head == temp) {
			return true;
		}
		else {
			return false;
		}
	}

	void Dequeue() {
		if (Empty()) {
			throw "Очередь пуста!";
		}
		else {
			head = (head + 1) % NumElem;
		}
	}

	void Enqueue(ElType x) {
		if (Full()) {
			throw "Очередь полна!";
		}
		else {
			details[tail] = x;
			tail = (tail + 1) % NumElem;
		}
	}

	int ElemCount() {

		int count = 0;
		int ptr = head;

		while (ptr != tail) {
			ptr = (ptr + 1) % NumElem;
			count++;
		}

		return count;
	}

	void getDetail(ElType& x) {
		if (Empty()) {
			throw "Очередь пуста!";
		}
		x = details[head];
	}

	void getDetail(ElType& x, int offset) {

		if (Empty()) {
			throw "Очередь пуста!";
		}

		if (offset > ElemCount()) {
			throw "Выход за диапазон значений!";
		}

		int ptr = (head + offset) % NumElem;
		x = details[ptr];
	}

};
