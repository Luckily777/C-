// 列表初始化
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class   A
{
public:
	A(int a, int b)
		:_a(a)
		, _b(b)
	{}

	A(int a)
		:_a(a)
		, _b(0)
	{}
private:
	int _a;
	int _b;
};
template <class T>
class Vector
{
public:
	Vector(int n, int a)
		:_array(new T[n])
		, _size(0)
		, _capacity(n)
	{}

	Vector(const initializer_list<T>& lst)
		:_array(new T[lst.size()])
		, _size(0)
		, _capacity(lst.size())
	{
		for (auto& e : lst)
			_array[_size++] = e;
	}

private:
	T* _array;
	int _size;
	int _capacity;
};

void test()
{
	int array[] = { 1, 2, 3, 5 };

	//C++11： 支持内置类型的列表初始化
	int a = 1;
	int b = { 1 };
	int c{ 1 };
	float d = { 1.2f };

	//C++11： 支持自定义类型的列表初始化
	vector<int> array3{ 1, 2, 3, 4, 5 };
	vector<int> array2 = { 1, 2 };

	pair<int, int> p = { 1, 1 };
	map<int, int>   m = { { 1, 1 }, { 2, 2 }, { 3, 3 } };

	//自定义类型：创建单个对象
	A a3 = { 1, 2 };
	A a2(3, 4);
	//单参构造函数的隐式类型转换
	A a4 = 5;

	//自定义类型：初始化多个元素  ----> 不是天然支持列表初始化
	// 需要显示定义参数类型为initializer_list的构造函数

	// 三个元素
	Vector<int> vec = { 1, 2, 3 };

	//匹配第一个有两个参数的构造函数
	//没有实际元素的空的Vector
	Vector<int> vec2(10, 0);
	Vector<int> vec3{ 20, 1 };
}
