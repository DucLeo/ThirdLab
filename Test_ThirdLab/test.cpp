#include "pch.h"
#include "gtest/gtest.h"
#include "..\ThirdLab\MinHeap.h"
#include "..\ThirdLab\Stack.h"
#include "..\ThirdLab\Queue.h"


class Test_Stack : public ::testing::Test {
public:
	void SetStack(Stack<int>* stack) {
		for (int i = 0; i < 10 ; i++) stack->push(i);
	}
};

TEST_F(Test_Stack, Test_isEmpty) {
	Stack<int>* stack = new Stack<int>;
	ASSERT_TRUE(stack->isEmpty());
	ASSERT_EQ(stack->getsize(), 0);

	SetStack(stack);
	ASSERT_FALSE(stack->isEmpty());
	ASSERT_NE(stack->getsize(), 0);

	delete stack;
}

TEST_F(Test_Stack, Test_getsize) {
	Stack<int>* stack = new Stack<int>;
	ASSERT_EQ(stack->getsize(), 0);

	SetStack(stack);
	ASSERT_EQ(stack->getsize(), 10);

	delete stack;
}

TEST_F(Test_Stack, Test_push) {
	Stack<int>* stack = new Stack<int>;
	stack->push(40);
	ASSERT_EQ(stack->getsize(), 1);
	ASSERT_EQ(stack->pop(), 40);

	stack->push(40);
	stack->push(30);
	stack->push(20);
	stack->push(10);

	ASSERT_EQ(stack->getsize(), 4);
	ASSERT_EQ(stack->pop(), 10);
	ASSERT_EQ(stack->pop(), 20);
	ASSERT_EQ(stack->pop(), 30);
	ASSERT_EQ(stack->pop(), 40);

	delete stack;
}

TEST_F(Test_Stack, Test_pop) {
	Stack<int>* stack = new Stack<int>;
	ASSERT_THROW(stack->pop(), runtime_error);

	SetStack(stack);
	ASSERT_EQ(stack->pop(), 9); ASSERT_EQ(stack->getsize(), 9);
	ASSERT_EQ(stack->pop(), 8); ASSERT_EQ(stack->getsize(), 8);
	ASSERT_EQ(stack->pop(), 7); ASSERT_EQ(stack->getsize(), 7);
	ASSERT_EQ(stack->pop(), 6); ASSERT_EQ(stack->getsize(), 6);
	ASSERT_EQ(stack->pop(), 5); ASSERT_EQ(stack->getsize(), 5);
	ASSERT_EQ(stack->pop(), 4); ASSERT_EQ(stack->getsize(), 4);
	ASSERT_EQ(stack->pop(), 3); ASSERT_EQ(stack->getsize(), 3);
	ASSERT_EQ(stack->pop(), 2); ASSERT_EQ(stack->getsize(), 2);
	ASSERT_EQ(stack->pop(), 1); ASSERT_EQ(stack->getsize(), 1);
	ASSERT_EQ(stack->pop(), 0); ASSERT_EQ(stack->getsize(), 0);
	ASSERT_TRUE(stack->isEmpty());

	delete stack;
}

class Test_Queue : public ::testing::Test {
public:
	void SetQueue(Queue<int>* queue) {
		for (int i = 0; i < 10; i++) queue->enQueue(i);
	}
};

TEST_F(Test_Queue, Test_isEmpty) {
	Queue<int>* queue = new Queue<int>;
	ASSERT_TRUE(queue->isEmpty());
	ASSERT_EQ(queue->getsize(), 0);

	SetQueue(queue);
	ASSERT_FALSE(queue->isEmpty());
	ASSERT_NE(queue->getsize(), 0);

	delete queue;
}

TEST_F(Test_Queue, Test_getsize) {
	Queue<int>* queue = new Queue<int>;
	ASSERT_EQ(queue->getsize(), 0);

	SetQueue(queue);
	ASSERT_EQ(queue->getsize(), 10);

	delete queue;
}

TEST_F(Test_Queue, Test_enQueue) {
	Queue<int>* queue = new Queue<int>;
	queue->enQueue(40);

	ASSERT_EQ(queue->getsize(), 1);
	ASSERT_EQ(queue->deQueue(), 40);

	queue->enQueue(40);
	queue->enQueue(30);
	queue->enQueue(20);
	queue->enQueue(10);

	ASSERT_EQ(queue->getsize(), 4);
	ASSERT_EQ(queue->deQueue(), 40);
	ASSERT_EQ(queue->deQueue(), 30);
	ASSERT_EQ(queue->deQueue(), 20);
	ASSERT_EQ(queue->deQueue(), 10);

	delete queue;
}

TEST_F(Test_Queue, Test_deQueue) {
	Queue<int>* queue = new Queue<int>;
	ASSERT_THROW(queue->deQueue(), runtime_error);

	SetQueue(queue);
	ASSERT_EQ(queue->deQueue(), 0); ASSERT_EQ(queue->getsize(), 9);
	ASSERT_EQ(queue->deQueue(), 1); ASSERT_EQ(queue->getsize(), 8);
	ASSERT_EQ(queue->deQueue(), 2); ASSERT_EQ(queue->getsize(), 7);
	ASSERT_EQ(queue->deQueue(), 3); ASSERT_EQ(queue->getsize(), 6);
	ASSERT_EQ(queue->deQueue(), 4); ASSERT_EQ(queue->getsize(), 5);
	ASSERT_EQ(queue->deQueue(), 5); ASSERT_EQ(queue->getsize(), 4);
	ASSERT_EQ(queue->deQueue(), 6); ASSERT_EQ(queue->getsize(), 3);
	ASSERT_EQ(queue->deQueue(), 7); ASSERT_EQ(queue->getsize(), 2);
	ASSERT_EQ(queue->deQueue(), 8); ASSERT_EQ(queue->getsize(), 1);
	ASSERT_EQ(queue->deQueue(), 9); ASSERT_EQ(queue->getsize(), 0);
	ASSERT_TRUE(queue->isEmpty());

	delete queue;
}

class Test_MinHeap : public ::testing::Test {
public:
	void SetHeap(Min_Heap* heap) {
		heap->insert(5);	//	Empty heap after SetHeap(), heap I		
		heap->insert(3);	//				    1	
		heap->insert(7);	//				
		heap->insert(1);	//			3			   7
		heap->insert(13);	//
		heap->insert(17);	//		5	   13	  17	  19
		heap->insert(19);	//		
		heap->insert(11);	//	11
	}
};

TEST_F(Test_MinHeap, Test_BreadthFirstTraversal) {
	Min_Heap* heap = new Min_Heap();
	SetHeap(heap);
	//Heap is heap I
	Iterator* heap_bft = heap->create_bft_iterator();
	//Breadth-first traversal : 1 3 7 5 13 17 19 11

	ASSERT_EQ(heap_bft->next(), 1);		ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 3);		ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 7);		ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 5);		ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 13);	ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 17);	ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 19);	ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 11);	ASSERT_FALSE(heap_bft->has_next());
	ASSERT_THROW(heap_bft->next(), out_of_range);

	delete heap;
	delete heap_bft;
}

TEST_F(Test_MinHeap, Test_DepthFirstTraversal) {
	Min_Heap* heap = new Min_Heap();
	SetHeap(heap);
	//Heap is heap I
	Iterator* heap_dft = heap->create_dft_iterator();
	//Depth-first traversal: 1 3 5 11 13 7 17 19

	ASSERT_EQ(heap_dft->next(), 1);		ASSERT_TRUE(heap_dft->has_next());
	ASSERT_EQ(heap_dft->next(), 3);		ASSERT_TRUE(heap_dft->has_next());
	ASSERT_EQ(heap_dft->next(), 5);		ASSERT_TRUE(heap_dft->has_next());
	ASSERT_EQ(heap_dft->next(), 11);	ASSERT_TRUE(heap_dft->has_next());
	ASSERT_EQ(heap_dft->next(), 13);	ASSERT_TRUE(heap_dft->has_next());
	ASSERT_EQ(heap_dft->next(), 7);		ASSERT_TRUE(heap_dft->has_next());
	ASSERT_EQ(heap_dft->next(), 17);	ASSERT_TRUE(heap_dft->has_next());
	ASSERT_EQ(heap_dft->next(), 19);	ASSERT_FALSE(heap_dft->has_next());
	ASSERT_THROW(heap_dft->next(), out_of_range);

	delete heap;
	delete heap_dft;
}

TEST_F(Test_MinHeap, Test_contains) {
	//Heap is empty
	Min_Heap* heap = new Min_Heap();

	ASSERT_THROW(heap->contains(0), runtime_error);
	ASSERT_THROW(heap->contains(10), runtime_error);

	SetHeap(heap);
	//Heap is heap I
	ASSERT_TRUE(heap->contains(5));
	ASSERT_FALSE(heap->contains(10));

	delete heap;
}

TEST_F(Test_MinHeap, Test_insert) {
	Min_Heap* heap = new Min_Heap();
	heap->insert(5);
	Iterator* heap_bft = heap->create_bft_iterator();

	ASSERT_EQ(heap_bft->next(), 5);		ASSERT_FALSE(heap_bft->has_next());
	ASSERT_THROW(heap_bft->next(), out_of_range);
	ASSERT_EQ(heap->size, 1);

	heap->insert(3);
	heap_bft = heap->create_bft_iterator();

	ASSERT_EQ(heap_bft->next(), 3);		ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 5);		ASSERT_FALSE(heap_bft->has_next());
	ASSERT_THROW(heap_bft->next(), out_of_range);
	ASSERT_EQ(heap->size, 2);

	heap->insert(7);
	heap->insert(1);
	heap->insert(13);
	heap->insert(17);
	heap->insert(19);
	heap->insert(11);
	//Heap is heap I

	heap_bft = heap->create_bft_iterator();
	//Breadth-first traversal : 1 3 7 5 13 17 19 11

	ASSERT_EQ(heap_bft->next(), 1);		ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 3);		ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 7);		ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 5);		ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 13);	ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 17);	ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 19);	ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 11);	ASSERT_FALSE(heap_bft->has_next());
	ASSERT_THROW(heap_bft->next(), out_of_range);
	ASSERT_EQ(heap->size, 8);

	delete heap;
	delete heap_bft;
}

TEST_F(Test_MinHeap, Test_remove) {
	//Heap is empty
	Min_Heap* heap = new Min_Heap();
	ASSERT_THROW(heap->remove(0), runtime_error);
	ASSERT_THROW(heap->remove(10), runtime_error);

	heap->insert(10);

	ASSERT_THROW(heap->remove(0), logic_error);

	heap->remove(10);
	ASSERT_EQ(heap->size, 0);

	heap->insert(10);
	heap->insert(100);
	heap->remove(10);

	Iterator* heap_bft = heap->create_bft_iterator();

	ASSERT_EQ(heap_bft->next(), 100);		ASSERT_FALSE(heap_bft->has_next());
	ASSERT_THROW(heap_bft->next(), out_of_range);
	ASSERT_EQ(heap->size, 1);

	heap->remove(100);
	//Heap is empty
	SetHeap(heap);
	//Heap is heap I
	heap->remove(11);
	heap_bft = heap->create_bft_iterator();
	//Breadth - first traversal : 1 3 7 5 13 17 19

	ASSERT_EQ(heap_bft->next(), 1);		ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 3);		ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 7);		ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 5);		ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 13);	ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 17);	ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 19);	ASSERT_FALSE(heap_bft->has_next());
	ASSERT_THROW(heap_bft->next(), out_of_range);
	ASSERT_EQ(heap->size, 7);

	heap->remove(3);
	heap_bft = heap->create_bft_iterator();
	//Breadth - first traversal : 1 5 7 19 13 17

	ASSERT_EQ(heap_bft->next(), 1);		ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 5);		ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 7);		ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 19);	ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 13);	ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 17);	ASSERT_FALSE(heap_bft->has_next());
	ASSERT_THROW(heap_bft->next(), out_of_range);
	ASSERT_EQ(heap->size, 6);

	heap->remove(1);
	heap_bft = heap->create_bft_iterator();
	//Breadth - first traversal : 5 13 7 19 17

	ASSERT_EQ(heap_bft->next(), 5);		ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 13);	ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 7);		ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 19);	ASSERT_TRUE(heap_bft->has_next());
	ASSERT_EQ(heap_bft->next(), 17);	ASSERT_FALSE(heap_bft->has_next());
	ASSERT_THROW(heap_bft->next(), out_of_range);
	ASSERT_EQ(heap->size, 5);

	delete heap;
	delete heap_bft;
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
