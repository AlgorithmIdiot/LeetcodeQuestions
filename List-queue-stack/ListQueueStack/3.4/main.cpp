#include<list>
#include<iostream>
using namespace std;
/*
Given two sorted lists, L1 and L2, 
write a procedure to compute L1 กษ L2 using only the basic list operations.
*/
template <typename Object>
list<Object> intersection(const list<Object>& L1, const list<Object>& L2)
{
	list<Object> intersectionList;
	typename list<Object>::const_iterator iterL1 = L1.begin();
	typename list<Object>::const_iterator iterL2 = L2.begin();
	while (iterL1 != L1.end() && iterL2 != L2.end())
	{
		if (*iterL1 == *iterL2)
		{
			intersectionList.push_back(*iterL1);
			iterL1++;
			iterL2++;
		}
		else if (*iterL1 < *iterL2)
			iterL1++;
		else
			iterL2++;
	}
	return intersectionList;
}

template<typename Object>
list<Object> Union(const list<Object>& L1, const list<Object> & L2)
{
	list<Object> result;
	typename list<Object>::const_iterator iterL1 = L1.begin();
	typename list<Object>::const_iterator iterL2 = L2.begin();
	while (iterL1 != L1.end() && iterL2 != L2.end())
	{
		if (*iterL1 == *iterL2)
		{
			result.push_back(*iterL1);
			iterL1++;
			iterL2++;
		}
		else if (*iterL1 < *iterL2) {
			result.push_back(*iterL1);
			iterL1++;
		}
		else {
			result.push_back(*iterL2);
			iterL2++;
		}
	}
	if (iterL2 != L2.end())
	{
		result.push_back(*iterL2);
		iterL2++;
	}
	if (iterL1 != L1.end())
	{
		result.push_back(*iterL1);
		iterL1++;
	}
	return result;
}

template <typename Object>
void showlist(list <Object> g)
{
	typename list<Object>::iterator it;
	for (it = g.begin(); it != g.end(); ++it)
		cout << '\t' << *it;
	cout << '\n';
}

int main()
{
	const list<int> L1{1,2,3,4};
	const list<int> L2{ 3,4,5,6 };

	// test exercise 3.4 in Chapter 3 
	list<int> a = intersection(L1, L2);
	showlist(a);
	// test exercise 3.5 in Chapter 3
	list<int> b = Union(L1, L2);
	showlist(b);
 
	system("pause");
	return 0;
}