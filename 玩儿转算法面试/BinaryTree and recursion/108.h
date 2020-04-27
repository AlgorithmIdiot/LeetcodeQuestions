#ifndef __108__
#define __108
#include<vector> 
#include<string>
#include"TreeNode.h"
using namespace std;

vector<int> input = { -10,-3,0,5,9 }; // we assume there is no nullptr


class Solution {
public:
	TreeNode* sortedArrayToBST( vector<int>& nums) {
		TreeNode * root = BST(nums, 0, nums.size()-1 );
		return root;
	}

	// this recursive function is used for generating subtree within range [left, right]
	TreeNode* BST(vector<int>& nums, int left, int right)
	{
		TreeNode* temp = nullptr;
		if (right < left) return temp;
		if (right == left)
		{
			temp = new TreeNode(nums[left]);
			return temp;
		}

		if (right - left == 1)
		{
			temp = new TreeNode(nums[right]);
			temp->left = new TreeNode(nums[left]);
			return temp; 
		}
		int mid = (right- left) / 2 + left ; // find the mid number as the root of subtree
		temp = new TreeNode(nums[mid]);
		temp->left = BST(nums, left , mid-1 );
		temp->right = BST(nums, mid+1, right );
		return temp; 
	}
};

#endif // ! __108__