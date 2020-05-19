#include <time.h>
#include <iostream>
#include <string.h>
using namespace std;

#include "sub.h"
struct A
{
	int array[10000];
};
void fun1(A a)
{}

void fun2(A& a)
{}

A g;

A fun3()
{
	return g;
}

A& fun4()
{
	return g;
}


void test1()
{
	A a;
	int n = 100000;
	size_t begin = clock();
	for (int i = 0; i < n; ++i)
		fun1(a);
	size_t end = clock();
	cout << "fun1(int): " << end - begin << endl;

	begin = clock();
	for (int i = 0; i < n; ++i)
		fun2(a);
	end = clock();
	cout << "fun2(int&): " << end - begin << endl;
}

void test2()
{
	A a;
	int n = 100000;
	size_t begin = clock();
	for (int i = 0; i < n; ++i)
		fun3();
	size_t end = clock();
	cout << "A fun3(): " << end - begin << endl;

	begin = clock();
	for (int i = 0; i < n; ++i)
		fun4();
	end = clock();
	cout << "A& fun2(): " << end - begin << endl;
}

void test3()
{
	int a = 10;
	int* pa = &a;
	*pa = 20;

	int& ra = a;
	ra = 30;
}
#define ADD(a, b)  a + b
#define MUL(a, b)  a * b

//���������� ����������ʱ������к���ָ���չ����û��ջ֡�Ŀ�������ߴ����Ч��
//����꺯��ʹ��
inline int Add(int a, int b)
{
	return a + b;
}
//inlineֻ��һ�����飬�����������ʵ����������жϣ��������򵥣�ֱ��չ�������븴�ӣ�����չ��
inline int fun5()
{
	int e = 0;
	for (int i = 0; i < 10000; ++i)
	{
		int a = i;
		int b = a * i;
		int c = b * i;
		int d = c * i;
		e += d;
	}
	return e;
}

void test4()
{
	int a = 1;
	int b = 2;
	int c = Add(a, b);  //���ú���������ջ֡�� ��������ִ�гɱ�
	int d = ADD(a, b);  //���滻�� int d = a + b
	int e = ADD(a + b, b);  //���滻  int e = a + b + b
	int f = MUL(a + b, b);  // a + b * b;
	int g = fun5();
	int i = sub(a, b);
}

void test5()
{
	//auto int a = 0;  //C++��֧��
	//auto: C++�е����ã� �Զ������Ƶ���������������ͣ�
	//����ʱ�����ݳ�ʼ�����ʽ�Զ��Ƶ�
	//auto�൱�����͵�ռλ�������������ڱ���ʱ�����Ƶ�
	auto b = 2;
	auto f = 3.0;
	auto c = 'a';
	auto d = 'a' + 'b';
	cout << typeid(b).name() << endl;
	cout << typeid(f).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;

	//auto����ı��������ʼ��
	//auto e;
	//auto���Զ���������
	auto a1 = 3, c1 = 4;
	//auto�ڶ���������ʱ��ÿһ���ı��ʽ������Ҫһ��
	//auto a2 = 1.5, c2 = 2;
	//auto���ڳ����ͱ����Ķ��壬�Ƚϼ�
	//std::unordered_map<std::string, std::unordered_map<std::string, std::string>>::iterator it;
	//auto����ָ���ǣ� �Ӳ���*,û������
	auto pb = &b;  
	auto* pb2 = &b;
	cout << typeid(pb).name() << endl;
	cout << typeid(pb2).name() << endl;
	//������������ʱ�������&����
	auto& ra = b;  // int&
	auto ra2 = b;  // int


}
//�����������Ͳ���ʹ��auto
//void fun6(auto a, auto b);
//�������鲻��ʹ��auto
//auto array[] = { 1, 2, 3, 4, 45, 6 };

//��Χfor:  Ҫ�����ı���   :   �����ķ�Χ
void test6()
{
	int array[] = { 1, 2, 3, 4, 5, 6 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		cout << array[i] << " ";
	cout << endl;
	//��Χfor: ʹ�ó����� ���ݷ�Χȷ��
	for (auto e : array)
		cout << e << " ";
	cout << endl;
}

/*
void test7(int array[])
{
	//array���һ��ָ�����ͣ�û��ȷ�������ݷ�Χ
	for (auto e : array)
		cout << e << " ";
	cout << endl;
}
*/

void test8()
{
	int* p = NULL;  // int* p = 0;
	int* p2 = 0;  //������ָ��û������
}

void fun6(int a)
{
	cout << "fun6(int)" << endl;
}

void fun6(int* pa)
{
	cout << "fun6(int*)" << endl;
}

struct AS
{

};

void test9()
{
	fun6(NULL);  //������Ĭ��NULLΪ���ε�0��������ָ���ֵ
	fun6((int*)NULL); // NULL: �����ԣ� ָ���ֵ������0
	//nullptr: ָ���ֵ�� ������nullptr��ʾָ���ֵ��������ȷ
	fun6(nullptr);
	//nullptr������ʽת��������ָ������(���ú��Զ���)
	int* p = nullptr;
	char* p1 = nullptr;
	float* p2 = nullptr;
	AS* pas = nullptr;
	//nullptr���ͣ� nullptr_t
	cout << typeid(nullptr).name() << endl;
	cout << sizeof(nullptr) << endl;
	auto p3 = nullptr;
	cout << typeid(p3).name() << endl;
}

//C++struct: ���Զ������ݺͺ���
//C++������ķ�ʽ��
// 1. struct + ���� + {} + ";"
// 2. class + ���� + {} + ";"

struct Student
{
	void display()
	{}

	void setId(int id)
	{
		_id = id;
	}

	void setNumber(int number)
	{
		_number = number;
	}

	int _number;
	int _id;
	char name[10];
	char gender[10];
	char major[10];
};
//C++�ķ�װ���﷨���֣� �࣬ �����޶���
//����Ȩ�ޣ�public, protected, private
//ֻ���Ƴ�Ա������ķ���Ȩ�ޣ����ڲ����ܷ����޶���������
class Student2
{
public: //���еĳ�Ա������ɼ�
	//��Ա����
	void display()
	{}

	void setId(int id)
	{
		_id = id;
	}

	void setNumber(int number)
	{
		_number = number;
	}
private:  //˽�еĳ�Ա�����ⲻ�ɼ�
	//��Ա������ ����
	int _number;
	int _id;
protected:  // �����ĳ�Ա�����ⲻ�ɼ�
	char name[10];
	char gender[10];
	char major[10];
};

void test10()
{
	Student st;
	strcpy(st.name, "123");
	st.setId(20);

	Student2 st2;
	st2.display();
	st2._id = 10;
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test9();
	return 0;
}