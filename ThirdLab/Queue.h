#pragma once
#include <iostream>

using namespace std;

template <class T>
class Queue {
private:
	class Element {
	public:
		T data;
		Element* next;
	};

	Element* head;
	Element* tail;
	size_t size;

public:
	bool isEmpty() {
		if (head == NULL) return true;
		else return false;
	}

	void enQueue(T x) {
		Element* new_node = new Element;
		new_node->data = x;
		new_node->next = NULL;
		if (isEmpty()) {
			tail = new_node;
			head = tail;
		}
		else {
			if (head->next == NULL) head->next = new_node;
			tail->next = new_node;
			tail = tail->next;
		}
		size++;
	}

	T deQueue() {
		if (isEmpty()) throw runtime_error("Queue is empty.");
		else {
			Element* temporary = head;
			if (temporary->next == NULL) {
				head = NULL;
				tail = NULL;
			}
			else head = head->next;
			T value = temporary->data;
			delete temporary;
			size--;
			return value;
		}
	}

	size_t getsize() { return size; }

	Queue() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	~Queue() = default;
};