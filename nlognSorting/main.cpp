#include<iostream>
#include<algorithm>
#include"SortTestHelper.h"
#include"MergeSort.h"
#include"InsertionSort.h"
#include"QuickSort.h"
#include"QuickSort2.h"
#include"QuickSort3Ways.h"

int main(){
	int n = 1000000;
	int *arr= SortTestHelper::generateRandomArray(n,1,n);
	int *arr2 = SortTestHelper::copyIntArray(arr,n);
	int *arr3 = SortTestHelper::copyIntArray(arr,n);
	//selectionSort(arr,n);
	//SortTestHelper::printArray(arr,n);
	SortTestHelper::testSort("Merge Sort", mergeSort,arr,n);
	SortTestHelper::testSort("Quick Sort", quickSort,arr2,n);	
	SortTestHelper::testSort("Quick Sort3", quickSort3Ways,arr3,n);	
	delete [] arr;// because we use the new in generateRandomArray
	delete [] arr2;
	delete [] arr3;
	return 0;
}

