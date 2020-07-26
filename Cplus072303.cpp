//左右值
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

void testLR()
{
	//简单理解：
	//左值：既可以出现在=的两边、或者可以取地址的
	int a = 10;
	int b = a;
	int* p = &a;
	int* p2 = &b;

	//右值：只能出现在=的右边，或者不可以取地址
	/*10 = 20;
	int* p3 = &10;*/

	//C++中： 右值
	//纯右值： 常量， 临时变量/匿名变量
	// 将亡值： 声明周期即将结束

	// 不是右值的都为左值

	//临时变量/匿名变量：函数以值返回的变量， 调用类的构造函数创建的变量
	/*getA(a) = b;
	int* p4 = &(getA());*/
}

class D
{

public:
	D(int d)
		:_d(d)
	{
		cout << "D(int)" << endl;
	}
	D(const D& d)
	{
		cout << "D(const D&)" << endl;
	}

private:
	int _d;
};

D getD(D d)
{
	return d;
}

void func3(const D& d)
{

}
void testRef()
{
	int a = 10;
	//左值引用：引用的实体既可以为左值，也可以为右值

	//ra ： 实体为左值
	int& ra = a;

	// : ri实体为右值
	const int& ri = 10;

	//右值引用：引用的实体只能是右值

	//右值引用： 实体为常量
	int&& lr = 10;
	//右值引用： 实体为临时变量
	int&& lr2 = getA(a);

	const int& r3 = getA(a);

	//右值引用： 不能引用左值
	//int&& r4 = a;
}


class String
{
public:
	String(char* str = "")
		:_str(new char[strlen(str) + 1])
		, _size(strlen(str))
		, _capacity(strlen(str))
	{
		strcpy(_str, str);
		cout << "String(char*)" << endl;
	}

	String(const String& str)
		:_str(new char[strlen(str._str) + 1])
	{
		strcpy(_str, str._str);
		_size = _capacity = strlen(str._str);
		cout << "String(const String&)" << endl;
	}
	//移动构造： 提高拷贝效率
	String(String&& str)
		:_str(str._str)
	{
		str._str = nullptr;
		_size = _capacity = str._size;
		cout << "String(String&&)" << endl;
	}

	String& operator=(const String& str)
	{
		if (this != &str)
		{
			delete[] _str;
			_str = new char[strlen(str._str) + 1];
			strcpy(_str, str._str);
			_size = _capacity = strlen(str._str);
			cout << "String& operator=(const String&)" << endl;
		}
		return *this;
	}

	//移动赋值
	String& operator=(String&& str)
	{
		if (this != &str)
		{
			swap(_str, str._str);
			_size = _capacity = str._size;
			cout << "String operator=(String&&)" << endl;
		}

		return *this;
	}

	~String()
	{
		cout << "调用析构" << endl;
		if (_str)
		{

			delete[] _str;
			cout << "~String()" << endl;
		}

	}

private:
	char* _str;
	int _size;
	int _capacity;
};

String getString()
{
	String str("123");
	return str;
}

void testString()
{
	////浅拷贝： 移动构造， 直接获取将亡值（右值）的资源
	//String ret = getString();

	////深拷贝： 拷贝构造， ret为左值
	//String copy(ret);

	//String ret2 = String("456");  // 构造 + 拷贝构造 ， 优化： 构造


	String ret;

	ret = String("789");

	int a = 10;
}

int main()
{
	//test();
	//testAuto();
	//testDelete();
	//testRef();
	testString();
	return 0;
}