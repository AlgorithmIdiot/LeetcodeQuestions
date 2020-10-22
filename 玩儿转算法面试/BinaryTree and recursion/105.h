#pragma once
#include"BinaryTree.h"
#include"TreeNode.h"
#include<vector>
using namespace std;
class Solution {
private:
	int preindex = 0;
	TreeNode* Construct(vector<int>& preorder, vector<int>& inorder, int indexL, int indexR)
	{
		if (indexL > indexR) return nullptr;
		// indexL is the root node of left sub tree when sliced in preorder traversal
		TreeNode* root = new TreeNode(preorder[preindex++]);
		// find the root from inorder vector
		int temp = 0;
		for (int i = indexL; i <= indexR; i++)
		{
			if (root->val == inorder[i])
			{
				temp = i;
				break;
			}
		}
		root->left = Construct(preorder, inorder, indexL, temp-1);
		root->right = Construct(preorder, inorder, temp + 1, indexR);
		return root;
	}
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty()) return nullptr;
		int n = inorder.size() ;
		return Construct(preorder, inorder, 0, n - 1);
	}
};

class Solution2 {

public:
	int preindex = 0;
	TreeNode* ctree(vector<int>& pre, vector<int> & in, int is, int ie) {
		if (is > ie) return NULL;
		TreeNode* root = new TreeNode(pre[preindex++]);
		int inindex;
		for (int i = is; i <= ie; i++) {
			if (in[i] == root->val) {
				inindex = i;
				break;
			}
		}
		root->left = ctree(pre, in, is, inindex - 1);
		root->right = ctree(pre, in, inindex + 1, ie);
		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		return ctree(preorder, inorder, 0, n - 1);
	}
};