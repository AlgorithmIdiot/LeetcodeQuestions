#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
struct Command {
	string s;
	TreeNode* node;
	Command(string s, TreeNode* node) : s(s), node(node) {}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
			return res;
		stack<Command> stack;
		stack.push(Command("go", root));
		while(!stack.empty()) {
			Command command = stack.top();
			stack.pop();

			if (command.s == "print")
				res.push_back(command.node->val);
			else
			{
				assert(command.s == "go");
				if (command.node->right)
					stack.push(Command("go", command.node->right));
				if (command.node->left)
					stack.push(Command("go", command.node->left));
				stack.push(Command("print", command.node));
			}
		}
		return res;
};