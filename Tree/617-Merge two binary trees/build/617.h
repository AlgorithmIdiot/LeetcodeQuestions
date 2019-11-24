#ifndef __617__
#define __617__
#include<iostream>
#include"TreeNode.h"
#include<vector>
// create an alias so that i can directly paste my code into Leetcode
#define datatype int
using TreeNode = TreeNodeT<datatype> ;
// typedef TreeNode<int> TreeNode

class Solution // this is adjucted according to the problems
{
public:
Solution ()
{
    //t1 and t2 must have the same depth
    VectorToTree (&t1, {1,2,3} );
    PrintTree(t1);
    std::cout<< std:: endl;
    VectorToTree (&t2, {1,2,3} );
    PrintTree(t2);
    std::cout<< std::endl;
}

// receives a pointer to a pointer so that the function can modify pointer's value
void VectorToTree (TreeNode** ptr, std::vector<datatype> a)
{
    // initialize a tree from a vector (array)
    for (const datatype i : a )
    {
        VectorToTreeHelper(ptr, i);
    }
}

// receives a pointer to a pointer so that the function can modify pointer's value
void VectorToTreeHelper (TreeNode** ptr, datatype i)
{

    if(*ptr == nullptr)
        *ptr = new TreeNode(i);
    else 
    {
        // data to insert is less than data in current node
        if(i < (*ptr)->val)
            VectorToTreeHelper( &((*ptr)->left),i);
        else 
        {
            VectorToTreeHelper( &((*ptr)->right),i );
        }
       
    }
}
void PrintTree (TreeNode * t)
{
    if(t!=nullptr) 
    {
        PrintTree(t->left); // traverse left subtree
        std::cout<< t->val << ' ';
        PrintTree(t->right);// 
    }
}
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if(t1== nullptr) return t2;
    if(t2== nullptr) return t1;
    t1->val = t1->val + t2->val;
    mergeTrees(t1->left, t2->left);
    mergeTrees(t1->right,t2->right);
    return t1;
}

void run(){
        TreeNode* res = mergeTrees(t1,t2);
        PrintTree(res);
    }

private:
    TreeNode* t1;
    TreeNode* t2;
};

#endif

