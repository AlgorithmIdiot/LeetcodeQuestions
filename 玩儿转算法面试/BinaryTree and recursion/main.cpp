//#include"98.h"
//#include"450.h"
//#include"108.h"
//#include"230.h"
#include"114.h"
#include"BinaryTree.h"
#include<iostream>
#include<vector>

int main() {
	// generate input data from the solution class
	std::vector<int> preorder{ 3,9,20,15,7 };
	std::vector<int> inorder{ 9,3,15,20,7 };
	Solution().buildTree(preorder, inorder);
	std::cin.get();
	return 0;
}