#include"MinHeap.h"
#include<utility>

/*
** establish heap order property from an artitrary
** arrangement of items. Runs in linear time
*/
template <typename Comparable>
void MinBinaryHeap<Comparable>::buildHeap()
{
	for (int i = currentSize / 2; i > 0; --i)
		percolateDown(i);
}

// the explicit can be ignored in the implementation 
template <typename Comparable>
MinBinaryHeap<Comparable>::MinBinaryHeap(const std::vector<Comparable> & items)
{
	for (int i = 0; i < items.size(); ++i)
		array[i + 1] = items[i];
	buildHeap();
}

template <typename Comparable>
void MinBinaryHeap<Comparable>::insert(const Comparable & x)
{
	if (currentSize == array.size() - 1)
		array.resize(2 * array.size() );
	// pocolate up 
	int hole = ++currentSize;
	Comparable copy = x;

	array[0] = std::move(copy);// turn copy into a rvalue variable
	for (; x < array[hole / 2]; hole /= 2)
		array[hole] = std::move(array[hole / 2]); // 
	array[hole] = std::move(array[0]);
}

template <typename Comparable>
void MinBinaryHeap<Comparable>::deleteMin()
{
	if (isEmpty())
		throw new std::exception("The heap is empty"); //throw UnderflowException{ };
	array[1] = std::move(array[currentSize--]);
	percolateDown(1);

}

// remove the minimum item and place it in the minItem
template <typename Comparable>
void MinBinaryHeap<Comparable>::deleteMin(Comparable & minItem)
{
	if (isEmpty())
		throw new std::exception("The heap is empty");
	array[1] = std::move(array[currentSize--]);
	percolateDown(1);
}

template <typename Comparable>
void MinBinaryHeap<Comparable>::percolateDown(int hole)
{
	int child;
	Comparable tmp = std::move(array[hole]);
	for (; hole * 2 <= currentSize; hole = child)
	{
		child = hole * 2;
		if (child != currentSize && array[child + 1] < array[child])
			++child;
		if (array[child] < tmp)
			array[hole] = std::move(array[child]);
		else
			break;
	}
	array[hole] = std::move(tmp);
}