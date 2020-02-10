#include<iostream>
#include<ctime>
#include<cassert>
#include<algorithm>
#include"TestHelper.h"

// partition process
// can we use 2ways and 3ways ?
template<typename T>
int __partition(T arr[], int l, int r)
{
    int p = rand()%(r-l+1) +l;
    std::swap(arr[l],arr[p]);
    int j = l; // [l+1...j] < p ; [lt+1...i) > p
    for(int i = l+1; i <=r; i++){
        if(arr[i]<arr[l])
            std::swap(arr[i],arr[++j]);
    }
    std::swap(arr[l],arr[j]);
    return j;
}

// calculate the kth smallest number in arr[l...r]
template<typename T>
T __selection(T arr[], int l, int r, int k)
{
    if(l==r)
        return arr[l];
    // after partition, arr[p] is at the right index p
    int p = __partition(arr,l,r);
    if(k == p) // if k == p, return arr[p]
        return arr[p];
    else if (k<p)
        return __selection(arr,l,p-1,k);
    else 
        return __selection(arr,p+1,r,k);
    
}

template<typename T>
T selection(T arr[], int n, int k)
{
    assert(k>=0 && k<n);
    srand(time(NULL));
    return __selection(arr,0,n-1,k);
}

int main (){
    int arr[7] = {1,2,3,4,5,6,7};
    //test the selection
    int a = selection(arr,7,2);
    std::cout<< a <<std::endl;
}