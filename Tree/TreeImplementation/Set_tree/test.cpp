#include"Set.h"
//#include<iostream>
#include<string>
/* funtion of this code 
* test the implementation of Set 
*/
int main()
{
    // Implement by using the stack 
    // another way is to use the base class + the pointer 
    Set<int> set;
    set.insert(4); set.insert(0);
    set.insert(2); set.insert(7);
    set.insert(0); set.insert(2);
    set.insert(3); set.insert(1);
    set.insert(5); set.insert(6);
    set.insert(8); set.insert(9);
    set.insert(10);
    set.printTree();

    std::cout<< "the minimum value is : \n";
    std::cout<< set.findMin()<< std::endl;
    std:: cout<< "the maximum value is : \n";
    std::cout<< set.findMax()<< std::endl;

    return 0;
}