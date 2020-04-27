#ifndef __BINARYTREE__
#define __BINARYTREE__

#include<vector> 
#include<string>
#include<iostream>
#include<algorithm>
#include"TreeNode.h"

class BinaryTree
{
public:
	TreeNode* root = nullptr;
	// generate the binary tree from a vector
	BinaryTree(std::vector<std::string> nums)
	{
		root = insertLevelOrder(nums, root, 0, nums.size());	
	}
	~BinaryTree() // the destructor is checked by the stack 
	{
		deleteBinaryTree(root);
	}
	TreeNode* insertLevelOrder(std::vector<std::string> arr, TreeNode* root, int i, int n)
	{
		if (i < n) {
			TreeNode* temp = nullptr;
			if (arr[i] != "null")
				temp = new TreeNode(std::stoi(arr[i]) );
			else
				return nullptr;
			root = temp;
			// insert left child
			root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
			root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
		}
		return root;
	}

	void deleteBinaryTree(TreeNode* root)
	{
		if (!root) return;
		deleteBinaryTree(root->left);
		deleteBinaryTree(root->right);
		delete root;
	}

	// maximum height of a tree is the number of edges from root to deepest leaf
	// height of a node is the number of edges from node to deepest leaf
	int getMaxHeight(TreeNode* root)
	{
		if (!root) return 0;
		return std::max(getMaxHeight(root->left), getMaxHeight(root->right)) + 1;
	}

	// print the binary tree vertically
	static void printBinaryTree(TreeNode* root)
	{
		if (!root) return;
		printBinaryTree(root->left); 
		printBinaryTree(root->right);
		std::cout << root->val << " "; 
	}
};
#endif // !__BINARYTREE__
