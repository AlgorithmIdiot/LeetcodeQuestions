#include<iostream>
#include<vector>

struct ListNode{
	int val;
	ListNode * next;
	ListNode(int x) : val(x),next(nullptr){}
};

ListNode * VectorToList (std::vector<int> a)
{
	ListNode * head = new ListNode(a[0]);
	ListNode* res = head;
	for (int i =1;i < a.size(); i++ )
	{
		head->next = new ListNode(a[i]);
		head = head->next;
	}
	head->next = nullptr;
	return res;
	
}

ListNode * addTwoNumbers(ListNode* l1, ListNode* l2)
{
	// base case 
	if (l1 == nullptr && l2==nullptr)
		return nullptr;
	if (l1 == nullptr) return l2;
	if (l2 == nullptr) return l1;
	int intl1 =0,intl2=0,tempInt =0, carry =0; 
	ListNode * head = new ListNode(tempInt);
	ListNode * res = head;
	while (l1!= nullptr || l2!= nullptr)
	{
		// create new nodes for next iteration
		if ( head == nullptr) return nullptr;
		if (l1)
			intl1 = l1->val;
		else 
			intl1 = 0;
		if (l2)
			intl2 = l2->val;
		else 
			intl2 = 0;
		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
		if (intl1 + intl2 + carry >= 10)
		{
			head->val = (intl1 + intl2 + carry) % 10 ;
			carry =1;
			// check if all the iterations are finished
			if (l1 == nullptr && l2 == nullptr)
			{
				head->next = new ListNode(0);
				head = head->next;
				head->val = carry; 
				break; 
			}
		}
		else 
		{
			head->val = intl1 +intl2 + carry;
			carry = 0;
		}
		if (l1!=nullptr || l2 != nullptr)
		{
			head->next = new ListNode(0);
			head = head->next;
			if (head == nullptr) return nullptr;
		}
	}//end of while loop
	head->next = nullptr;
	return res;
}

void PrintList (ListNode * res)
{
	while (res)
	{
		std::cout << res->val<< "->";
		res = res->next;
	}
	std::cout << std::endl;
}

int main()
{
	ListNode * l1 = VectorToList({2,4,3});
	ListNode * l2 = VectorToList({5,6,4});
	ListNode * result = addTwoNumbers(l1, l2);
	PrintList (result);
	return 0;
}

