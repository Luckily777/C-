//抽象类

#include <iostream>
using namespace std;

//抽象类：包含纯虚函数的类
//抽象类不能实例化对象
//意义： 实现多态
//体现：接口继承
class A
{
public:
	//纯虚函数： 没有函数体的虚函数
	virtual void fun() = 0;
};

class B : public A
{
public:
	virtual void fun()
	{
		cout << "B::fun()" << endl;
	}
};

void test2()
{
	/*A a;
	a.fun();*/

	B b;
	A* pb = &b;
	b.fun();
	pb->fun();
}
