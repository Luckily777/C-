//类的作用域
#include <stdio.h>
#include <iostream>
using namespace std;


struct A
{
public:
	int _a;
	void fun() {
		cout << "struct A fun()" << endl;
	}
};

class B
{
private:
	int _a;

	void fun() {
		cout << "class B fun()" << endl;
	}
	void fun2();
};

void fun2() {//所定义的是一个全局域的
	cout << "fun2()" << endl;
}

void B::fun2() {//类域之中的fun2的定义
	cout << "B::fun2()" << endl;
}