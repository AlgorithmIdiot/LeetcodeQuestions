#include<iostream>
#include<algorithm>
#include"SortTestHelper.h"
#include"MergeSort.h"
#include"InsertionSort.h"
#include"QuickSort.h"

// partition arr[l...r]
// return p, to make arr[l...p-1]< arr[p]; arr[p+1...r] >arr[p]
template<typename T>
int __partition2(T arr[], int l,int r)
{
	std::swap(arr[rand()%(r-l+1)+l],arr[l] );
	T v = arr[l];
	// arr[l+1...i)<= v ; arr(j...r) > =v
	int i = l+1 ,j = r;
	while(true){
		while (i<=r &&arr[i]<v) i++;
		while (j>= l+1 && arr[j]>v) j--;
		if (i > j ) break;
		std::swap(arr[i],arr[j]);
		i++;
		j--;
	}
	std::swap(arr[l],arr[j]);
	return j;
}

template<typename T>
void __quickSort2(T arr[], int l,int r){
	if (l>=r)
		return;
	int p = __partition2(arr,l,r);
	__quickSort2(arr,l,p-1);
	__quickSort2(arr,p+1,r);
}

template<typename T>
void quickSort2(T arr[], int n)
{
	srand(time(NULL));
	__quickSort2(arr,0,n-1);
}

int main(){
	int n = 1000000;
	int *arr= SortTestHelper::generateRandomArray(n,1,n);
	int *arr2 = SortTestHelper::copyIntArray(arr,n);
	int *arr3 = SortTestHelper::copyIntArray(arr,n);
	//selectionSort(arr,n);
	//SortTestHelper::printArray(arr,n);
	SortTestHelper::testSort("Merge Sort", mergeSort,arr,n);
	SortTestHelper::testSort("Quick Sort", quickSort,arr2,n);	
	SortTestHelper::testSort("Quick Sort2", quickSort2,arr3,n);	
	delete [] arr;// because we use the new in generateRandomArray
	delete [] arr2;
	delete [] arr3;
	return 0;
}

