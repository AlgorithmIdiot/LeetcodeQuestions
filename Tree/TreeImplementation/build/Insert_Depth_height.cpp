#include"BinarySearchTree.h"
//#include<iostream>
#include<string>
/* funtion of this code 
* insert items into an empty tree
* comput height of a tree
* comput depth of a tree
* print the tree in three orders using recursive calls 
*/
int main()
{
    // Implement by using the stack 
    // another way is to use the base class + the pointer 
    std::cout << "Please input the tree: \n";
    BinarySearchTree<std::string> BSTtree ; 
    std::string input ; 
    do 
    {   std::cin>> input;
        BSTtree.insert(input);
    }while (std::getchar() != '\n' );
    std::cout << "The tree being input is : \n";
    BSTtree.printTree();  
    return 0;

}