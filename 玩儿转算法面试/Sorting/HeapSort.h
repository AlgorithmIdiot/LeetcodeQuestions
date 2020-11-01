#pragma once
/*
this standard heapsort uses the maximum heap
The code to perform heapsort is given in Figure 7.10.The slight complication is that,
unlike the binary heap, where the data begin at array index 1, the array for heapsort contains
data in position 0. Thus the code is a little different from the binary heap code.The
changes are minor.

*/
#include<utility>
#include<vector>

inline int leftChild(int i)
{
	return 2 * i + 1;
}

// a is the array to be sorted
// i is the starting index to percolate
// n is the logical length of the heap array

template<typename Comparable>
void percDown(std::vector<Comparable>& a, int i, int n)
{
	int child;
	Comparable tmp;
	for (tmp = std::move(a[i]); leftChild(i) < n; i = child)
	{
		child = leftChild(i);

		if (child != n - 1 && a[child] < a[child + 1])
		{
			child++;
		}
		if (tmp < a[child])
		{
			a[i] = std::move(a[child]);
		}
		else
			break;
	}
	a[i] = std::move(tmp);
}

template<typename Comparable>
void heapsort(std::vector<Comparable> & a)
{
	// build heap
	for (int i = a.size() / 2 - 1; i >= 0; --i)
	{
		percDown(a, i, a.size());
	}

	// deleteMax
	for (int j = a.size() - 1; j > 0; --j)
	{
		std::swap(a[0], a[j]);
		percDown(a, 0, j);
	}

}
