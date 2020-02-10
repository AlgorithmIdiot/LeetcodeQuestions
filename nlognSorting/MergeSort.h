template<typename T>
void __merge(T arr[], int l, int mid, int r){
	T aux[r-l+1];
	for (int i = l; i <= r; i ++)
		aux[i-l] = arr[i];
	int i =l, j = mid +1;
	for (int k =l; k <=r; k++){
		if (i>mid){
			arr[k] = aux[j-l];
			j++;
		}
		else if(j>r){
			arr[k] = aux[i-l];
			i++;
		}
		else if (aux[i-l]<aux[j-l]){
			arr[k] =aux[i-l];
			i++;
		}
		else{
			arr[k] = aux[j-l];
			j++;
		}
	}
}

// recursive merge sorting , sort arr[l..r[]
template<typename T>
void __mergeSort(T arr[], int l, int r)
{
	if (l >= r) 
		return;
	int mid = (l+r)/2; // l+r might overflow
	__mergeSort(arr,l,mid);
	__mergeSort(arr,mid+1,r);
	if (arr[mid] > arr[mid+1])// this work well for nearly ordered test
	__merge(arr,l,mid,r);

}

template<typename T>
void mergeSort(T arr[], int n)
{
	// private function for mergeSort to call
	__mergeSort(arr, 0, n-1);
}

template<typename T>
void mergeSortBU(T arr[],int n )
{
	// use this to sort the linked list
	for (int sz = 1; sz <= n ; sz += sz)
		for (int i = 0; i + sz < n ; i+= sz + sz)
		// merge arr[i...i+sz-1] and arr[i+sz... i+2*sz-1]
			__merge(arr, i, i+sz-1,std::min( i+sz+sz-1, n-1));
}