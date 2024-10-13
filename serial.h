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













/*

#ifndef _POSLEDOVATELNAYA
#define _POSLEDOVATELNAYA
#include <iostream>
using namespace std;
#define MaxEl 6


template<class ElType>
class Queue
{
	ElType element[MaxEl];
	int head;
	int tail;

public:
	Queue()
	{
		head = 0;
		tail = 0;
	}

	bool isEmpty()
	{
		return head == tail;
	}

	bool isFull()
	{
		return head == (tail + 1) % MaxEl;
	}

	bool enQueue(ElType x)
	{
		if (isFull())
			return false;
		else
		{
			element[tail] = x;
			tail = (tail + 1) % MaxEl;
			return true;
		}
	}

	bool deQueue(ElType& x)
	{
		if (retFirst(x))
		{
			head = (head + 1) % MaxEl;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool retFirst(ElType& x)
	{
		if (isEmpty())
		{
			cout << "Error 1 - queue is empty!" << endl;
			return false;
		}
		else
		{
			x = element[head];
			return true;
		}
	}

	int retN()
	{
		if (tail > head)
			return tail - head;
		else
			return (tail - 0) + (MaxEl - head);
	}
};
#endif
*/
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
