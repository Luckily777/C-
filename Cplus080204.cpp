//�ƶ����� move
#include <thread>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;

void testR()
{
	int a = 10;
	//std::move:  �ƶ�����--> �ѱ��������Ա����ֵ 
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

	//�ƶ�������ȷ������
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
	//�ƶ��������ʾ������һ��������õ�����ֵ�����һ����ֵ
	String copy(move(str));

	cout << str._str << endl;
	//�ƶ�������ȷ��ʹ�ó�������Ҫ��֤���Ա��޸ĵ���ֵ���治�����õ�
}

void Fun(int& x) { cout << "lvalue ref" << endl; }
void Fun(int&& x) { cout << "rvalue ref" << endl; }
void Fun(const int& x) { cout << "const lvalue ref" << endl; }
void Fun(const int&& x) { cout << "const rvalue ref" << endl; }

//���⣺ ģ������� T&& δ����������---> ��Ҫ��ģ��������յ�ʵ�����ͣ���ʵ������ƥ��
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