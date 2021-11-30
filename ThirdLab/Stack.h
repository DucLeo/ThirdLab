#pragma once
#include <iostream>

using namespace std;

template <class T>
class Stack {
private:
	class Element {
	public:
		T data;
		Element* next;
	};
	Element* top;
	size_t size;

public:
	bool isEmpty() {
		if (top == NULL) return true;
		else return false;
	}

	void push(T x) {
		Element* new_node = new Element;
		new_node->data = x;
		if (isEmpty()) {
			new_node->next = NULL;
			top = new_node;
		}
		else {
			new_node->next = top;
			top = new_node;
		}
		size++;
	}

	T pop() {
		if (isEmpty()) throw runtime_error("Stack is empty.");
		else {
			Element* temporary = top;
			if (top->next == NULL) top = NULL;
			else top = temporary->next;
			T value_popped = temporary->data;
			delete temporary;
			size--;
			return value_popped;
		}
	}

	size_t getsize() { return size;}

	Stack() {
		top = NULL;
		size = 0;
	}

	~Stack() = default;
};
