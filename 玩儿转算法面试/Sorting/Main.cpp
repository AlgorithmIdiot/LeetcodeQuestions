#include"QuickSort.h"
#include"MergeSort.h"
#include<iostream>
#include<utility>
#include"HeapSort.h"
//QuickSort(a, 0, a.size()-1);
//MergeSort(a, 0, a.size()-1);
//std::for_each(a.begin(), a.end(), [](int n) {std::cout << " " << n; });

int main() {
	std::vector<double> a{1,3,2,4,5,6,8,7,9};

	heapsort(a);
	std::for_each(a.begin(), a.end(), [](int n) {std::cout << " " << n; });
	std::cin.get();
	return 0;
}