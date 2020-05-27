//单参构造函数

#include <iostream>
using namespace std;
class A {
public:
	//explicit:禁掉单参构造的隐式类型转换
	//explicit
	A(int a)
		:_a(a)
	{
		cout << "A(int)" << endl;
	}

	A(int a, int b)
		:_a(a)
	{
		cout << "A(int)" << endl;
	}

	A(const A& a)
		:_a(a._a)
	{
		cout << "A(const A&)" << endl;
	}

	A& operator=(const A& A) {
		if (this != &a) {
			_a = a._a;
		}
		cout << "A& operator=(const A& a)" << endl;
		return *this;
	}
private:
	int _a;
};

void Test() {
	A a(1);//创建对象
	A a2 = 2;//创建对象：单参构造函数的隐式类型转换--->调用构造创建一个匿名对象 + 拷贝构造（通过匿名对象拷贝构造a2对象）
	a2 = 3;//作为参数传如构造函数，创建匿名对象，调用赋值，使用匿名对象给a2赋值

	//只支持单参构造函数的隐式类型转换，下面代码不支持
	//A a4=5，6
}


int main() {
	//test8();
	test9();
	return 0;
}