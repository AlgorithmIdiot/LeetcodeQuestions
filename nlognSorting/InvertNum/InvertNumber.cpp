#include<iostream>

// use the merge sort idea to calculate the inverse pair number
template<typename T>
class Invert
{
    T *arr;
    int size;
    int pair = 0;
    public:
    explicit Invert(T arr_1[], int n)
    {
        arr = new T(n);
        for (int i = 0; i < n; i++)
            arr[i] =  arr_1[i];
    }
    ~Invert(){
        delete [] arr;
    }
    
    void __merge(int l,int mid, int r){
    T aux[r-l+1];
    for (int i = l; i<= r; i++)
        aux[i-l] = arr[i];
    int i=l , j=mid+1 ;
    for (int k = l; k<=r ; k++){
        if(i> mid){
            arr[k] = aux[j-l];
            j++;
        }
        else if(j > r){
            arr[k] = aux[i-l];
            i++;
        }
        else if(aux[i-l] < aux[j-l]){
            arr[k] = aux[i-l];
            i++;
        }
        else{
            arr[k] = aux[j-l];
            j++;
            pair= pair + mid - i + 1;
        }
    }
    delete [] aux;
    }
    void MergeCount(int l , int r)
    {
        if(l>=r) return;
        int mid = l+ (r - l) /2 ;
        MergeCount( l, mid);
        MergeCount(mid+1, r);
        if (arr[mid] > arr[mid+1])
        __merge( l, mid , r);
    }

    void printPair(){
        std::cout<< "The invert order number is: "<< pair << std::endl;
    }
};

int main() {
    int arr[] = {1,3,2,4,5};
    Invert<int>  a(arr, 5);
    a.MergeCount(0,4);
    a.printPair();
    return 0;
}