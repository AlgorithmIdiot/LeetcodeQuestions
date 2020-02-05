#include<iostream>
#include<algorithm>
#include"Student.h"
#include"SortTestHelper.h"
template<typename T>
void selectionSort(T arr[], int n){ // can use function pointer to pass
	for(int i= 0; i < n ; i++)
	{
		// find the minimum in (i,n)
		int minIndex = i ;
		for (int j = i+1; j < n; j++)
			if (arr[j]<arr[minIndex]) minIndex = j;
		std::swap(arr[i],arr[minIndex]);
	}
}

template<typename T>
void insertionSort(T arr[], int n)
{
	for (int i = 1; i < n ; i++)
	{
		// look for arr[i] position
		T e = arr[i];
		int j;// j to save the position to insert
		for ( j = i; j>0 && arr[j-1]>e; j --){
			arr[j] = arr[j-1];
		}
		arr[j] = e ;
	}
}
/*
template<typename T>
void bubbleSort(T arr[], int n)
{
	
}
*/

/*
void shellSort(T arr[],int n)
{

}
*/

int main(){
	int n = 10000;
	int *arr= SortTestHelper::generateNearlyOrderedArray(n,10);
	int *arr2 = SortTestHelper::copyIntArray(arr,n);
	//selectionSort(arr,n);
	//SortTestHelper::printArray(arr,n);
	SortTestHelper::testSort("Selection Sort", selectionSort,arr,n);
	SortTestHelper::testSort("Insertion Sort", insertionSort,arr2,n);	
	delete [] arr;// because we use the new in generateRandomArray
	delete [] arr2;
	return 0;
}

