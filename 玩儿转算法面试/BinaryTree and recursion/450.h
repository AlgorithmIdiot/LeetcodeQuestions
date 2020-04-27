#ifndef __450__
#define __450__
#include<vector>
#include<string>
#include"TreeNode.h"
std::vector<std::string> input_root = { "5","3","6","2","4","null","7" };
int input_key = 3;
///
class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) 
	{
		TreeNode* parent = nullptr;
		TreeNode* target = findNode(root, key, parent);
		if (target == nullptr)
		{
			return root; // key is not found 
		}
		// when target is leaf
		if (!target->left && !target->right)
		{
			// this tree only has the root
			if (parent == nullptr)
				return nullptr;
			if (parent->left == target)
			{
				parent->left = nullptr;
			}
			if (parent->right == target)
			{
				parent->right = nullptr;
			}
		}
		// find successor down the right subtree
		if (target->right)
		{
			TreeNode* succ = target->right;
			TreeNode* succParent = target; 
			while (succ->left)
			{
				succParent = succ;
				succ = succ->left;
			}
			// if target right child does not have left child, then successor is the first right node
			if (succParent == target)
				succParent->right = succ->right;
			else// if target has left child, left most node will replace target
				succParent->left = succ->right;
			target->val = succ->val;
		}
		else // no right successor, then must have left successor
		{
			TreeNode* pred = target->left; 
			TreeNode* predParent = target;
			while (pred->right)
			{
				predParent = pred;
				pred = pred->right;
			}
			if (predParent == target)
				predParent->left = pred->left;
			else
				predParent->right = pred->left; 
			target->val = pred->val;
		}
		return root;
	}

	TreeNode* findNode(TreeNode* root, int key, TreeNode* parent)
	{
		while (root)
		{
			if (key < root->val)
			{
				parent = root;
				root = findNode(root->left, key, parent);
			}
			else if (key > root->val)
			{
				parent = root;
				root = findNode(root->right, key, parent);
			}
			else
				return root;
		}
		return nullptr;
	}
};


#endif // !__450__


