// partition arr[l...r]
// return p, to make arr[l...p-1]< arr[p]; arr[p+1...r] >arr[p]
template<typename T>
int __partition(T arr[], int l,int r)
{
	std::swap(arr[rand()%(r-l+1)+l],arr[l] );
	// arr[l+1...j]< arr[l] ; arr[j+1...i) > arr[l]
	int j = l;
	for (int i = l+1; i <= r ; i++)
	{
		if (arr[i] < arr[l]){
			std::swap(arr[j+1],arr[i]);
			j++;
		}
	}
	std::swap(arr[l],arr[j]);
	return j;
}

template<typename T>
void __quickSort(T arr[], int l,int r){
	if (l>=r)
		return;
	int p = __partition(arr,l,r);
	__quickSort(arr,l,p-1);
	__quickSort(arr,p+1,r);
}

template<typename T>
void quickSort(T arr[], int n)
{
	srand(time(NULL));
	__quickSort(arr,0,n-1);
}