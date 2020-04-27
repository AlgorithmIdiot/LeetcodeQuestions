//#include"98.h"
//#include"450.h"
//#include"108.h"
//#include"230.h"
#include"236.h"
#include"BinaryTree.h"
#include<iostream>

int main() {
	// generate input data from the solution class
	BinaryTree a(input);
	std::cout << Solution().lowestCommonAncestor(a.root,p,q)<< std::endl;
	std::cin.get();
	return 0;
}