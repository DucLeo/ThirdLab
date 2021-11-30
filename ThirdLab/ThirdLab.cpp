#include <iostream>
#include "MinHeap.h"

using namespace std;

int main() {
	Min_Heap heap;
	
	heap.insert(2);
	heap.insert(3);
	heap.insert(4);
	heap.insert(5);
	heap.insert(6);
	heap.insert(7);
	heap.insert(8);
	heap.insert(9);

	cout << "Breadth-first traversal: ";
	Iterator* heap_bft = heap.create_bft_iterator();
	while (heap_bft->has_next()) cout << heap_bft->next() << " ";
	cout << endl;

	cout << "\nDepth-first   traversal: ";
	Iterator* heap_dft = heap.create_dft_iterator();
	while (heap_dft->has_next()) cout << heap_dft->next() << " ";
	cout << endl << endl;

	if (heap.contains(5)) cout << "Element 5 is in the heap." << endl;
	else cout << "Element 5 is not in the heap." << endl;

	if (heap.contains(10)) cout << "Element 10 is in the heap." << endl;
	else cout << "Element 10 is not in the heap." << endl;

	heap.remove(9);

	cout << "\nBreadth-first traversal after removing 9: ";
	heap_bft = heap.create_bft_iterator();
	while (heap_bft->has_next()) cout << heap_bft->next() << " ";
	cout << endl;

	cout << "\nDepth-first   traversal after removing 9: ";
	heap_dft = heap.create_dft_iterator();
	while (heap_dft->has_next()) cout << heap_dft->next() << " ";
	cout << endl;

	heap.insert(1);

	cout << "\nBreadth-first traversal after inserting 1: ";
	heap_bft = heap.create_bft_iterator();
	while (heap_bft->has_next()) cout << heap_bft->next() << " ";
	cout << endl;

	cout << "\nDepth-first   traversal after inserting 1: ";
	heap_dft = heap.create_dft_iterator();
	while (heap_dft->has_next()) cout << heap_dft->next() << " ";
	cout << endl;

	heap.remove(2);

	cout << "\nBreadth-first traversal after removing 2: ";
	heap_bft = heap.create_bft_iterator();
	while (heap_bft->has_next()) cout << heap_bft->next() << " ";
	cout << endl;

	cout << "\nDepth-first   traversal after removing 2: ";
	heap_dft = heap.create_dft_iterator();
	while (heap_dft->has_next()) cout << heap_dft->next() << " ";
	cout << endl;

	heap.remove(1);

	cout << "\nBreadth-first traversal after removing 1: ";
	heap_bft = heap.create_bft_iterator();
	while (heap_bft->has_next()) cout << heap_bft->next() << " ";
	cout << endl;

	cout << "\nDepth-first   traversal after removing 1: ";
	heap_dft = heap.create_dft_iterator();
	while (heap_dft->has_next()) cout << heap_dft->next() << " ";
	cout << endl;
	
	return 0;
}
