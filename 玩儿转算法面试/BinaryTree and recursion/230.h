#ifndef __230__
#define __230__

#include"TreeNode.h"
#include<vector>
#include<string>

std::vector<std::string> input{ "3","1","4","null","2" };

class Solution {
public:
	int count = 0; 
	int kthSmallest(TreeNode* root, int k) {
		int res = 0;
		inorderTraversal(root, k, res);
		return res;
	}

	void inorderTraversal(TreeNode* root, int k, int& res)
	{
		if (!root) return;
		inorderTraversal(root->left, k, res);
		count++;
		if (count == k) res = root->val;
		inorderTraversal(root->right, k, res);
	}
};

#endif // !__230__

