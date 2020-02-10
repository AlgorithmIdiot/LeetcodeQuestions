
// 3Wayssort to sort arr[l...r]
// seperate arr[l...r] into <v ; ==v ; >v three parts
// recursively use 3ways to sort the two parts as <v ; > v
template<typename T>
void __quickSort3Ways(T arr[], int l,int r){
	if (l>=r)
		return;

	//partition part
	std::swap(arr[l],arr[rand()%(r-l+1)+l ]);
	T v = arr[l];
	
	int lt = l;// arr[l+1...lt] < v
	int gt = r+1; // arr[gt...r] >v
	int i = l+1; // arr[lt+1...i) == v
	while (i<gt ){
		if(arr[i]<v){
			std::swap(arr[i],arr[lt+1]);
			lt ++;
			i++;
		}
		else if (arr[i]>v){
			std::swap(arr[i],arr[gt-1]);
			gt--; 
		}
		else {
			i++;
		}
	}
	std::swap(arr[l],arr[lt]);
	__quickSort3Ways(arr,l,lt-1);
	__quickSort3Ways(arr,gt,r);
}

template<typename T>
void quickSort3Ways(T arr[], int n)
{
	srand(time(NULL));
	__quickSort3Ways(arr,0,n-1);
}
