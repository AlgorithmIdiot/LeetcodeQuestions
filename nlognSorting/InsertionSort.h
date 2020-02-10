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