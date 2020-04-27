#include"LinkedList.h"

class Solution
{
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;

		ListNode* cur = dummyHead;
		while (cur->next != nullptr) {
			if (cur->next->val == val) {
				// delete cur->next
				ListNode* delNode = cur->next;
				cur->next = delNode->next;
				delete delNode;
			}
			else {
				cur = cur->next;
			}
		}
		ListNode* retNode = dummyHead->next;
		delete dummyHead;
		return retNode;
	}
};

int main() {
	int arr[] = { 1,2,2,3,4,5 };
	int n = sizeof(arr) / sizeof(int);
	ListNode * head = createLinkedList(arr, n);
	printLinkedList(head);

	ListNode* head2 = Solution().removeElements(head,2);
	printLinkedList(head2);

	deleteLinkedList(head2);
	cin.get();
	return 0;
}