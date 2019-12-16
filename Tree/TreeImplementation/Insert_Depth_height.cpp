#include"BinarySearchTree.h"
#include<iostream>
#include<string>
/* funtion of this code 
* insert items into an empty tree
* comput height of a tree
* comput depth of a tree
* print the tree in three orders using recursive calls 
*/
int main()
{
    // insert tree from the input 
    std::cout << "Please select the input type: \n";
    std::cout << "1: int \n" << "2: string \n";
    int comparable = 0;  std::cin >> comparable;
    switch (comparable)
    {
    case 1:
    {
        /* code */
        BinarySearchTree<int> Tree;
        int input;
        break;
    }
    case 2:
    {
        BinarySearchTree<std::string> Tree;
        std::string input;
        break;
    }
    default:
    {
        BinarySearchTree<int> Tree;
        int input;
    }

    }


    return 0;

}