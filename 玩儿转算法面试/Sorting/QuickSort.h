#pragma once
#include<vector>
#include<algorithm>
//#include<>
int RandomInRange(int start, int  end)
{
	return rand() % (end - start + 1) + start;
}
int Partition( std::vector<int> & data, int start, int end)
{
	if (data.empty() || start < 0 || end >= (int)data.size())
		throw new std::exception("Invalid Parameters");
	int index = RandomInRange(start, end);
	std::swap(data[index], data[end]); // put the indexed element at the end of the array
	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small; // small mark the position of last number smaller than the indexed value
			if (small != index)
				std::swap(data[index], data[small]); 
		}
	}
	++small;
	std::swap(data[small], data[end]);
	return small;
}


void QuickSort( std::vector<int>& data, int start, int end)
{
	if (start == end)
		return;

	int index = Partition(data, start, end);
	if (index > start)
		QuickSort(data, start, index - 1);
	if (index < end)
		QuickSort(data, index + 1, end);
}


