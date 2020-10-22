#pragma once
#include"TreeNode.h"
#include<queue>
using namespace std;

class Solution {

private:
	queue<int> temp;
	void Helper(TreeNode* root) {
		if (!root) return;
		temp.push(root->val);
		Helper(root->left);
		Helper(root->right);
		return;
	}
public:
	void flatten(TreeNode* root) {
		if (!root) return;
		Helper(root);
		//int i =1;
		TreeNode* newRoot = new TreeNode(root->val);
		while (!temp.empty() && !newRoot) {
			newRoot->right = new TreeNode(temp.front());
			newRoot->left = nullptr;
			newRoot = newRoot->right;
			temp.pop();
		}
		root = newRoot;
		return;
	}
};