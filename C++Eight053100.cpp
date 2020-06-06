//模板函数 实例化

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
T add(const T& a, const T& b)
{
	return a + b;
}

template <class T1,class T2>
T2 Add(const T1& a, const T2& b)
{
	return a + b;
}

void Test()
{
	int a = 1, b = 2;
	char c = 'a', d = 'b';
	add(a, b);

	add<int>(a, c);

	Add(a, c);

	Add(a, b);
}


int Add(const int& a, const int& b)
{
	return a + b;
}

void TestOne()
{
	int a = 1, b = 2;
	char c = 'a', d = 'b';

	//普通函数与模板函数共存时，如果普通函数的参数类型可以完全匹配，则执行普通函数，不进行模板函数的实例化
	//也就意味着可以直接吃现成的饭
	Add(a, b);

	//普通函数与模板函数共存时，普通函数的参数类型不能够完全匹配
	//但是实例化的函数可以完全匹配参数的类型，则进行实例化，意味着饭不好吃，重新做
	Add(a, c);

	//普通函数与模板函数共存时，但是指定了需要实例化，则进行实例化
	Add<int>(a,b) 
}
