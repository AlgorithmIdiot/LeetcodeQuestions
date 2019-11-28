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
the idea is to find the right most node first and start to add onto the sum
finish the right  subtree of a given node first and add it to val
then start the left subtree
*/
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        if (!root)
            return nullptr;
        else 
        {
            Transform(sum, root);
            return root;
        }
        
    }
    void Transform (int& sum , TreeNode* subtree)
    {
        if(!subtree)
            return ;
        if(subtree->right)
            Transform(sum,subtree->right);
        // only appear once 
        sum += subtree->val;
        subtree->val = sum;
        
        if (subtree->left)
            Transform(sum, subtree->left);
    }
};