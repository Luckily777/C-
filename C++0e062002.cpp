//函数模板
#include <iostream>
using namespace std;

template <class T>
T Add(T& a, T& b)
{
	return a + b;
}

template <>
char* Add<char*>(char*& a, char*& b)
{
	strcat(a, b);
	return a;
}

//对于函数模板不能处理的特殊类型，一般会定义一个此类型的普通函数
//函数模板的特化比较少用
char* Add(char*& a, char*& b)
{
	strcat(a, b);
	return a;
}

template <class T1, class T2>
T1 sub(T1& a, T2& b)
{
	cout << "sub(T1, T2)" << endl;
	return a;
}

void test()
{
	int a = 1, b = 2;
	float c = 1.5, d = 2.5;
	char e = 'a', f = 'b';
	char* ptr = new char[100];
	strcpy(ptr, "123");
	char* ptr2 = new char[100];
	strcpy(ptr2, "abc");

	Add(a, b);
	Add(c, d);
	Add(e, f);
	Add(ptr, ptr2);

	int* pa = &a;
	int* pb = &b;

}

//模板参数：类型模板参数(class, typename)， 非类型模板参数(数值类型）
//非类型模板参数： 可以作为常量使用， 它的值需要在编译时确定
template <class T, size_t N>
class Array
{
private:
	T _array[N];
};

void test2()
{
	Array<int, 20> array;
}