#pragma once
#include<vector>


template <typename Comparable>
class MinBinaryHeap
{
public:
	explicit MinBinaryHeap(int capacity = 100);
	explicit MinBinaryHeap(const std::vector<Comparable> & items);
	bool isEmpty() const;
	const Comparable & findMin() const;

	void insert(const Comparable & x);
	void insert(Comparable && x);

	void deleteMin();
	void deleteMin(Comparable & minItem);
	void makeEmpty();

private:
	int currentSize; // number of elements in heap
	std::vector<Comparable> array; // the heap array
	void buildHeap();
	void percolateDown(int hole); // shift down method in BOBO's course

};