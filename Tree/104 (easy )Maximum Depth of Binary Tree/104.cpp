/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
Ideas: 
need to compare the left and right tree
use the recursive method to get the depth of each tree
the criteria is  (!root)
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (! root) return 0;
        return std::max( maxDepth(root->left), maxDepth(root->right) ) +1;
    }
};