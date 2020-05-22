//类的实例化
//创建一个类类型变量的过程
//也就是类只是一张设计图，通过类创建出变量才是将其真正的转化为一个实物
#include <stdio.h>
#include <iostream>
using namespace std;

struct A
{
public:  //默认public
	int _a;

	void fun()
	{
		cout << "struct A fun()" << endl;
	}
};

class B
{
private: //默认私有
	int _a;

	void fun()
	{
		cout << "class B fun()" << endl;
	}

	void fun2();
};

void fun2()
{
	cout << "fun2()" << endl;
}

void B::fun2()
{
	cout << "B::fun2()" << endl;
}

void Test() {
	A a;
	B b;
	//变量：对象 ——自定义类型的变量一般习惯称为对象

	//struct定义的成员默认访问权限为public
	//class定义的成员默认访问权限为private
	a._a;
	a.fun;
	//二者不成立
	//b._a;
	//b.fun();
}