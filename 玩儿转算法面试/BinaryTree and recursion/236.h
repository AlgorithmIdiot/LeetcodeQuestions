#ifndef __236__
#define __236__
#include"TreeNode.h"

#include<vector>
#include<string>
#include<algorithm>

std::vector<std::string> input{ "3","5","1" ,"6", "2", "0", "8", "null", "null", "7", "4" };
TreeNode* p = new TreeNode(5);
TreeNode* q = new TreeNode(4);

// if found p or q, return this node to its parent node
class Solution1 {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root ) return root;
		if (root->val == q->val || root->val == p->val) return root;
		TreeNode* left  = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		//if (!right && !left ) return nullptr;

		if (right  && left) return root;

		return (left ) ? left : right;
	}

};

// find the path of p and q, then compare the path
class Solution2 {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		std::vector<TreeNode*> p_path, q_path;
		if (FindPath(root, p, p_path) && FindPath(root, q, q_path))
		{
			int p_index = p_path.size() - 1;
			int q_index = q_path.size() - 1;
			while (p_index >= 0 && q_index >= 0) {
				if (q_path[q_index] != p_path[p_index])
				{
					return q_path[q_index + 1];
				}
				p_index--;
				q_index--;
			}
			// one node is the parent of the other node, their paths overlapped with each other
			return (q_index >= p_index ? q_path[q_index + 1] : p_path[p_index + 1]);
		}
		return nullptr;
	}

	// find the path in a binary tree
	bool FindPath(TreeNode* root, TreeNode* node, std::vector<TreeNode* >& path)
	{
		if (!root) return false;
		if (root->val == node->val)
		{
			path.push_back(root);
			return true;
		}
		bool left = FindPath(root->left, node, path);
		bool right = FindPath(root->right, node, path);
		if (left || right)
		{
			path.push_back(root);
			return true;
		}
		return false;
	}

};

#endif // !236

