#pragma once
#include <iostream>
#include <math.h>
#include "Iterator.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

class Node_Heap {
public:
	int data;
	Node_Heap* parent;
	Node_Heap* left;
	Node_Heap* right;

	Node_Heap() {data = 0; parent = NULL; left = NULL; right = NULL;}
};

class Min_Heap {
public:
	Node_Heap* root;
	int size;

	bool contains (int x) {
		if (root == NULL) throw runtime_error ("Heap is empty.");
		else {
			bool isIn = false;
			Iterator* bft = create_bft_iterator();
			while (bft->has_next()) {
				if (bft->next() == x) {
					isIn = true;
					break;
				}
			}
			delete bft;
			return isIn;
		}
	}

	void insert(int x) {
		if (root == NULL) {
			Node_Heap* new_node = new Node_Heap;
			new_node->data = x;
			root = new_node;
			size++;
		}
		else {
			Node_Heap* current = root;
			size++;
			int sle = size;    // sle: sum of the last level elements
			int level = 0;

			while (1) {
				sle = sle - pow(2, level);
				if (sle <= 0) break;
				else level++;
			}

			sle = size - (pow(2, level) - 1);
			while (level > 1) {
				if (sle <= pow(2, level - 1)) {
					current = current->left;
					level--;
				}
				else {
					current = current->right;
					sle -= pow(2, level -1);
					level--;
				}
			}
			Node_Heap* new_node = new Node_Heap;
			new_node->left = NULL;
			new_node->right = NULL;
			new_node->parent = current;

			if (sle <= pow(2, level -1)) {
				current->left = new_node;
				Heapify(x, new_node);
			}
			else {
				current->right = new_node;
				Heapify(x, new_node);
			}
		}
	}

	Node_Heap* atPosition(int x) {
		if (root == NULL) throw runtime_error("Heap is empty.");
		else if (x > size || x < 1) throw invalid_argument("Invalid position.");
		else {
			Node_Heap* current = root;
			int sle = x;		// sle: sum of the last level elements
			int level = 0;

			while (1) {
				sle = sle - pow(2, level);
				if (sle <= 0) break;
				else level++;
			}

			sle = x - (pow(2, level) - 1);
			while (level > 0) {
				if (sle <= pow(2, level - 1)) {
					current = current->left;
					level--;
				}
				else {
					current = current->right;
					sle -= pow(2, level - 1);
					level--;
				}
			}
			return current;
		}
	}

	void remove(int x) {
		if (root == NULL) throw runtime_error("Heap is empty.");
		else if (root->left == NULL) {
			if (root->data == x) {
				Node_Heap* temporary = root;
				root = NULL;
				delete temporary;
				size--;
			}
			else throw logic_error("There is not node x in the heap.");
		}
		else {
			bool isIn = false;
			int pot_x = 1;  // Position element x 
			Iterator* bft = create_bft_iterator();
			while (bft->has_next()) {
				if (bft->next() == x) {
					isIn = true;
					break;
				}
				else pot_x++;
			}
			delete bft;
			if (isIn == true) {
				if (pot_x == size) {
					Node_Heap* last_node = atPosition(size);
					Node_Heap* parent_last_node = last_node->parent;
					if (size % 2 == 0) {
						parent_last_node->left = NULL;
					}
					else parent_last_node->right = NULL;
					delete last_node;
					size--;
				}
				else {

					Node_Heap* node_delete = atPosition(pot_x);
					Node_Heap* last_node = atPosition(size);
					Node_Heap* parent_last_node = last_node->parent;
					int alternative_data = last_node->data;
					
					if (size % 2 == 0) {
						parent_last_node->left = NULL;
					}
					else parent_last_node->right = NULL;
					delete last_node;
					size--;
					Heapify(alternative_data, node_delete);
				}
			}
			else throw logic_error("There is not node x in the heap.");
		}
	}

	void swap_data(Node_Heap* node1, Node_Heap* node2) {
		int temp = node1->data;
		node1->data = node2->data;
		node2->data = temp;
	}

	void siftDOWN(Node_Heap* nodeIs_changed) {
		Node_Heap* current = nodeIs_changed;
		while (current->left != NULL) {
			if (current->right != NULL) {
				if (current->left->data < current->data || current->right->data < current->data) {
					if (current->left->data < current->right->data) {
						swap_data(current->left, current);
						current = current->left;
					}
					else {
						swap_data(current->right, current);
						current = current->right;
					}
				}
				else break;
			}
			else {
				if (current->left->data < current->data) swap_data(current->left, current);
				else break;
			}
		}
	}

	void siftUP(Node_Heap* nodeIs_changed) {
		Node_Heap* current = nodeIs_changed;
		while (current->parent != NULL) {
			if (current->parent->data > current->data) {
				swap_data(current->parent, current);
				current = current->parent;
			}
			else break;
		}
	}

	void Heapify(int alternative_data, Node_Heap* nodeIs_changed) {

		if (alternative_data < nodeIs_changed->data || nodeIs_changed->data == 0) {
			nodeIs_changed->data = alternative_data;
			siftUP(nodeIs_changed);
		}
		else {
			nodeIs_changed->data = alternative_data;
			siftDOWN(nodeIs_changed);
		}
	}

	class BFT : public Iterator {
	public:
		friend class Min_Heap;
		BFT(Node_Heap*);
		bool has_next() override;
		int next() override;

	private:
		Node_Heap* current;
		Queue<Node_Heap*>* queue;
	};

	class DFT : public Iterator {
	public:
		friend class Min_Heap;
		DFT(Node_Heap*);
		bool has_next() override;
		int next() override;

	private:
		Node_Heap* current;
		Stack<Node_Heap*>* stack;
	};

	Iterator* create_dft_iterator();

	Iterator* create_bft_iterator();

	Min_Heap() { root = NULL; size = 0;}
	~Min_Heap() = default;
};


Iterator* Min_Heap::create_bft_iterator() {
	BFT* new_bft = new BFT(root);
	return new_bft;
}

Min_Heap::BFT::BFT(Node_Heap* start) {
	current = start;
	queue = new Queue<Node_Heap*>();
}

bool Min_Heap::BFT::has_next() {
	if (current != NULL) return 1;
	else return 0;
}

int Min_Heap::BFT::next() {
	if (!has_next()) throw out_of_range("No more elements.");
	else {
		int current_data = current->data;
		if (current->left != NULL) queue->enQueue(current->left);
		if (current->right != NULL) queue->enQueue(current->right);
		if (!queue->isEmpty()) current = queue->deQueue();
		else current = NULL;
		return current_data;
	}
}


Iterator* Min_Heap::create_dft_iterator() {
	DFT* new_dft = new DFT(root);
	return new_dft;
}

Min_Heap::DFT::DFT(Node_Heap* start) {
	current = start;
	stack = new Stack<Node_Heap*>();
}

bool Min_Heap::DFT::has_next() {
	if (current != NULL) return 1;
	else return 0;
}

int Min_Heap::DFT::next() {
	if (!has_next()) throw out_of_range("No more elements.");

	int current_data = current->data;
	if (current->right != NULL) stack->push(current->right);
	if (current->left != NULL) current = current->left;
	else {
		if (!stack->isEmpty()) current = stack->pop();
		else current = NULL;
	}
	return current_data;
}


