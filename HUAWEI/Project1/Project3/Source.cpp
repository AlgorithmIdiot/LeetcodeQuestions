#include<iostream>
using namespace std;

struct linkedList {
	linkedList *next = nullptr;
	int index;
	linkedList(int index) {
		this->index = index;
	}
};

int main() {
	linkedList *head, *tail;
	int num=249;
		head = new linkedList(0);
		linkedList *cur = head;
		for (int i = 1; i < num; i++) {
			cur->next = new linkedList(i);
			cur = cur->next;
		}
		tail = cur;
		tail->next = head;

		// delete every two nodes
		cur = head;
		while (cur->next->next->next != cur) {
			linkedList *toDelete = cur->next->next;
			cur->next->next = toDelete->next;
			cur = cur->next->next;
		}
		cout << cur->index << endl;
		cout << cur->next->index << endl;
		cout << cur->next->next->index << endl;
		system("pause");
}