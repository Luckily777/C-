//移动语义 move
#include <thread>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;

void testR()
{
	int a = 10;
	//std::move:  移动语义--> 把变量的属性变成右值 
	int&& rr = move(a);
}


class Person
{
public:
	Person(const String& name)
		:_name(name)
	{}

	Person(const Person& person)
		:_name(person._name)
	{
		cout << "Person(const Person&)" << endl;
	}

	//移动语义正确场景：
	Person(Person&& person)
		:_name(move(person._name))
	{
		cout << "Person(Person&&)" << endl;
	}
private:
	String _name;
};

Person getPerson()
{
	Person per("bite");
	return per;
}

void testMove()
{
	Person copy(getPerson());
}

void testMove2()
{
	String str("123");
	//移动语义错误示例：把一个后面会用到的左值变成了一个右值
	String copy(move(str));

	cout << str._str << endl;
	//移动语义正确的使用场景：需要保证属性被修改的左值后面不会再用到
}

void Fun(int& x) { cout << "lvalue ref" << endl; }
void Fun(int&& x) { cout << "rvalue ref" << endl; }
void Fun(const int& x) { cout << "const lvalue ref" << endl; }
void Fun(const int&& x) { cout << "const rvalue ref" << endl; }

//特殊： 模板参数： T&& 未定引用类型---> 主要看模板参数接收的实际类型，和实际类型匹配
template<typename T>
//void PerfectForward(const T& t){ Fun(t); }
void PerfectForward(T&& t) { Fun(std::forward<T>(t)); }
void testForward()
{
	PerfectForward(10); // rvalue ref
	int a = 0;
	PerfectForward(a); // lvalue ref
	PerfectForward(std::move(a)); // rvalue ref
	const int b = 8;
	PerfectForward(b); // const lvalue ref
	PerfectForward(std::move(b)); // const rvalue ref

}