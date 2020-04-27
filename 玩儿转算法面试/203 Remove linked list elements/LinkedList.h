#pragma once
#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createLinkedList(int arr[], int n) {
	if (n == 0)
		return nullptr;
	ListNode* head = new ListNode(arr[0]);
	ListNode* curNode = head;
	for (int i = 1; i < n; i++) {
		curNode->next = new ListNode(arr[i]);
		curNode = curNode->next;
	}
	return head;
}

void deleteLinkedList(ListNode* head) {
	ListNode* curNode = head;
	while (curNode != nullptr) {
		ListNode* delNode = curNode;
		curNode = curNode->next;
		delete delNode;

	}
}

void printLinkedList(ListNode* head) {
	ListNode* curNode = head;
	while (curNode != nullptr) {
		cout << curNode->val << " -> ";
		curNode = curNode->next;
	}
	cout << "nullptr" << endl;
	return;
}

#endif