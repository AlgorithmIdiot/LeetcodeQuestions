#ifndef __236__
#define __236__
#include"TreeNode.h"

#include<vector>
#include<string>

std::vector<std::string> input{ "3","5","1","6","2","0","8","null","null","7","4" };
TreeNode* p = new TreeNode(5);
TreeNode* q = new TreeNode(1);

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* res = nullptr;
		postTraversal(root, p, q, res);
		return res;
	}

	void postTraversal(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* res)
	{
		if (!root) return;
		postTraversal(root->left, p, q, res);
		postTraversal(root->right, p, q, res);
		if (p && root->val == p->val) p = nullptr;
		if (q && root->val == q->val) q = nullptr;
		if (!p && !q) res = root;
	}
};

#endif // !236

