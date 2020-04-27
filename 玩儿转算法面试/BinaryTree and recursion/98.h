#ifndef __98__
#define __98__
#include<vector>
#include<string>
#include"BinaryTree.h"
#include"TreeNode.h"
std::vector< std::string > input1{ "1","null" ,"1" }; // ˫�������ַ�������������һ���ַ���ʵ������һ������
std::vector<int> input2{ "5","1","4","null","null","3","6" };

class Solution {
public:

	bool isValidBST(TreeNode* root) {
		return validate(root, LONG_MIN, LONG_MAX);
	}
	bool validate(TreeNode* root, long min, long max)
	{
		if (!root)
			return true;
		if ((long)root->val <= min || (long)root->val >= max)
			return false;

		return (validate(root->left, min, root->val) &&
			validate(root->right, root->val, max));
	}
};

#endif // !__98__
