#include<algorithm>
#include<iostream>
#include<numeric>
using namespace std;

bool MySort(int a, int b)
{
	return a > b;
}
void Display(int a )
{
	cout << a << " ";
}
template<class T>
inline bool MySortT(T const& a, T const& b)
{
	return a > b;
}
template<class T>
inline void DisplayT(T const& a)
{
	cout << a << " ";
}
struct MySortF{
	bool operator()(int a, int b)
{
	return a > b;
}
};
struct DisplayF {
	void operator() (int a){
		cout << a << " ";
	}
};



int main() {
	//c++ way
	int arr[] = { 4,3,2,1,7 };
	sort(arr, arr + 5, MySort);
	for_each(arr, arr + 5, Display);
	cout << endl;

	//c++ template
	int arr2[] = { 4,3,2,1,7 };
	sort(arr2, arr2 + 5, MySortT<int>);
	for_each(arr2, arr2 + 5, DisplayT<int>);
	cout << endl;

	//c++ functor
	int arr3[] = { 4,3,2,1,7 };
	sort(arr3, arr3 + 5, MySortF());
	for_each(arr3, arr3 + 5, DisplayF());
	cout << endl;
	system("pause");
	return 0;
}