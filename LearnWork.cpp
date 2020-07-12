#include <stdio.h>
#include <iostream>
using namespace std;


struct A {
	void foo() {
		printf("foo");
	}

	virtual void bar() {
		printf("bar");
	}

	A() {
		bar();
	}
};

struct B :A {
	void foo() {
		printf("b_foo");
	}

	void bar() {
		printf("b_bar");
	}
};
//
//int main() {
//	A* p = new B;
//	p->foo();
//	p->bar();
//}


/*class A {
public:
	void foo() {
		printf("1");
	}

	virtual void fun() {
		printf("2");
	}
};

class B:public A {
public:
	void foo() {
		printf("3");
	}

	void fun() {
		printf("4");
	}
};

int main() {
	A a;
	B b;
	A* p = &a;
	p->foo();
	p->fun();

	p = &b;
	p->foo();
	p->fun();
	A* ptr = (A*)&b;
	ptr->foo();
	ptr->fun();
	return 0;
}*/