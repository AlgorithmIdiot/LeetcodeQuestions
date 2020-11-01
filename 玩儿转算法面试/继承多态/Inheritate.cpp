#include<iostream>

using namespace std;

class A {
public:
	A() {  }
	virtual void p() = 0;// why cannot i make this as pure, if i call it,then i cannot make it virtual
	virtual ~A() { }
};
class B :public A {
public:
	B() { p(); }
	void p() { cout << "B"; }
	~B() { p(); }
};
int main(int, char**) {
	A* a = new B();
	delete a;
	return 0;
}