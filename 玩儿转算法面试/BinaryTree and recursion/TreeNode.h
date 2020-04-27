#pragma once
#ifndef __TREENODE__
#define __TREENODE__

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif // !__TREENODE__
