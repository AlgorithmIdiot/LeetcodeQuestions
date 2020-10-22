#pragma once
#include<vector>
#include<iostream>


template<typename T>
void Merge(std::vector<T>& data,int left , int midleft, int right)
{
	int n1 = midleft - left + 1; 
	int n2 = right - midleft ;  
	// this constructor can construct whithin the range [ left, right) 
	//template< class InputIt >
	//vector(InputIt first, InputIt last,
	//	const Allocator& alloc = Allocator());
	std::vector<T> leftarray(data.begin() + left, data.begin() + midleft + 1); //[left, midleft]
	std::vector<T> rightarry(data.begin() + midleft + 1, data.end());  //[midleft+1, right] 
	int i = 0, j = 0;
	int index = left;
	while (i < n1 && j < n2) {
		if (leftarray[i] < rightarry[j])
		{
			data[index] = leftarray[i];
			i++;
			
		}
		else
		{
			data[index] = rightarry[j];
			j++;
		}
		index++;
	}
	while (i < n1)
	{
		data[index] = leftarray[i];
		i++;
		index++;
	}
	while (j < n2)
	{
		data[index] = rightarry[j];
		j++;
		index++;
	}

}


template<typename T>
void MergeSort(std::vector<T>& data, int left, int right)
{
	if (left < right) {
		int mid = left + (right - left) / 2; // same as (left+ right)/2  but avoid overflow for larger values
		MergeSort(data, left, mid);
		MergeSort(data, mid + 1, right);
		Merge(data, left, mid, right);
	}
}