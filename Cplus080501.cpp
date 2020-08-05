//只能在堆和栈上创建对象的类
#include <mutex>
#include <thread>
#include <iostream>
using namespace std;

//
//只能在堆上创建对象的类
// 1. 构造函数私有
// 2. 提供一个静态的堆上创建对象的方法
// 3. 防拷贝(拷贝构造声明为私有，且不实现， 或者声明为delete函数）
class HeapOnly
{
public:
	static HeapOnly* getInstance()
	{
		//堆上创建对象
		return new HeapOnly;
	}
private:
	HeapOnly()
	{}

	//HeapOnly(const HeapOnly& ho);
	HeapOnly(const HeapOnly& ho) = delete;
};

//HeapOnly g;
void test()
{
	//HeapOnly ho;

	HeapOnly* ptr = HeapOnly::getInstance();

	//HeapOnly copy(*ptr);
}

//只能在栈上创建对象的类
// a.
// 1. 构造函数私有
// 2. 提供一个公有的静态的栈上创建对象的方法
class StackOnly
{
public:
	static StackOnly getInstance()
	{
		return StackOnly();
	}
private:
	StackOnly() {};
};

//StackOnly so;
void testStackOnly()
{
	//StackOnly* ptr = new StackOnly;
	StackOnly so = StackOnly::getInstance();
}

//只能在栈上创建对象的类
// b.
// 1. 构造函数私有
// 2. 提供一个公有的静态的栈上创建对象的方法
// 3. 把operator new函数声明为delete函数
class StackOnly2
{
public:
	static StackOnly2 getInstance()
	{
		return StackOnly2();
	}
	void* operator new(size_t n) = delete;
private:
	StackOnly2() {};
};

void testStackOnly2()
{
	//StackOnly2* so2 = new StackOnly2;
	StackOnly2 so2 = StackOnly2::getInstance();
}