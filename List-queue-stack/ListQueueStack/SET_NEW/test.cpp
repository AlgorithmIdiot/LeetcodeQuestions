#include <iostream>
#include "Set_new.h"


int main()
{
	Set<int> set;
	set.insert(4); set.insert(0);
	set.insert(2); set.insert(7);
	set.insert(0); set.insert(2);
	set.insert(6); set.insert(4);
	set.insert(12); set.insert(11);
	set.insert(8); set.insert(1);
	set.insert(5); set.insert(0);
	set.insert(3); set.insert(2);
	set.insert(7); set.insert(1);
	set.insert(1); set.insert(1);
	set.insert(9); set.insert(7);
	set.insert(11); set.insert(1);

	Set<int> set2 = set;

	set2.print();

	set2.remove(4);
	set2.print();
	system("pause");
}