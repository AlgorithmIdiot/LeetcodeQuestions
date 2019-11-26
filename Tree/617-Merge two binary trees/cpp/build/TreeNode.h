#ifndef _TREENODET_
#define _TREENODET_

/* from LeetCode
* Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
*/
class Solution;
//class-template definition same as LeetCode
template <typename NODETYPE> 
class TreeNodeT
{
    friend class Solution; // in order to get access to private variable left and right
public:
    TreeNodeT(const NODETYPE & x): val(x),left(nullptr),right(nullptr)
    {}
private:
    NODETYPE val;
    TreeNodeT<NODETYPE>* left; 
    TreeNodeT<NODETYPE>* right; 

};

#endif