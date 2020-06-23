//类模板
#include <iostream>
using namespace std;

//类模板的特化
// 1. 全特化--> 所有的参数都为具体类型

//特化之前需要存在基础类模板
template <class T1, class T2>
class A
{
public:
	A()
	{
		cout << "A(T1, T2)" << endl;
	}
private:
	T1 _t1;
	T2 _t2;
};

//全特化
template <>
class A<int, char>
{
public:
	A()
	{
		cout << "A(int, char)" << endl;
	}
private:
	int _t1;
	char _t2;
};



//2.偏特化： a. 部分特化，  b. 对模板参数做进一步的限制
template <class T1>
class A<T1, double>
{
public:
	A()
	{
		cout << "A(T1, double)" << endl;
	}
private:
	T1 _t1;
	double _t2;
};

template <class T1>
class A<T1, char>
{
public:
	A()
	{
		cout << "A(T1, char)" << endl;
	}
private:
	T1 _t1;
	double _t2;
};

template <class T1, class T2>
class A<T1&, T2&>
{
public:
	A()
	{
		cout << "A(T1&, T2&>" << endl;
	}
};

void test3()
{
	A<int, int>  a;
	A<int, char> b;
	A<float, char> f;
	A<int, double> c;
	A<int&, int&> d;
	A<int&, double&> e;
}
