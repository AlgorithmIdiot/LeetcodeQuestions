#include<iostream>
#include"LinkedList.h"
using namespace std;


int main() {
	int arr[] = { 1,2,3,4,5 };
	int n = sizeof(arr) / sizeof(int);
	ListNode * head = createLinkedList(arr, n);
	printLinkedList(head);

	ListNode* head2 = Solution().reverseList(head);
	printLinkedList(head2);

	deleteLinkedList(head2);

	return 0;
}