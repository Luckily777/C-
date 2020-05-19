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

//内联函数： 编译器编译时，会进行函数指令的展开，没有栈帧的开销，提高代码的效率
//代替宏函数使用
inline int Add(int a, int b)
{
	return a + b;
}
//inline只是一个建议，编译器会根据实际情况进行判断，如果代码简单，直接展开，代码复杂，不会展开
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
	int c = Add(a, b);  //调用函数，函数栈帧， 开销大于执行成本
	int d = ADD(a, b);  //宏替换， int d = a + b
	int e = ADD(a + b, b);  //宏替换  int e = a + b + b
	int f = MUL(a + b, b);  // a + b * b;
	int g = fun5();
	int i = sub(a, b);
}

void test5()
{
	//auto int a = 0;  //C++不支持
	//auto: C++中的作用： 自动类型推导，不代表具体类型，
	//编译时，根据初始化表达式自动推导
	//auto相当于类型的占位符，具体类型在编译时进行推导
	auto b = 2;
	auto f = 3.0;
	auto c = 'a';
	auto d = 'a' + 'b';
	cout << typeid(b).name() << endl;
	cout << typeid(f).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;

	//auto定义的变量必须初始化
	//auto e;
	//auto可以定义多个变量
	auto a1 = 3, c1 = 4;
	//auto在定义多个变量时，每一个的表达式的类型要一致
	//auto a2 = 1.5, c2 = 2;
	//auto对于长类型变量的定义，比较简单
	//std::unordered_map<std::string, std::unordered_map<std::string, std::string>>::iterator it;
	//auto定义指针是， 加不加*,没有区别
	auto pb = &b;  
	auto* pb2 = &b;
	cout << typeid(pb).name() << endl;
	cout << typeid(pb2).name() << endl;
	//定义引用类型时，必须加&符号
	auto& ra = b;  // int&
	auto ra2 = b;  // int


}
//函数参数类型不能使用auto
//void fun6(auto a, auto b);
//定义数组不能使用auto
//auto array[] = { 1, 2, 3, 4, 45, 6 };

//范围for:  要迭代的变量   :   迭代的范围
void test6()
{
	int array[] = { 1, 2, 3, 4, 5, 6 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		cout << array[i] << " ";
	cout << endl;
	//范围for: 使用场景： 数据范围确定
	for (auto e : array)
		cout << e << " ";
	cout << endl;
}

/*
void test7(int array[])
{
	//array变成一个指针类型，没有确定的数据范围
	for (auto e : array)
		cout << e << " ";
	cout << endl;
}
*/

void test8()
{
	int* p = NULL;  // int* p = 0;
	int* p2 = 0;  //和上面指令没有区别
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
	fun6(NULL);  //编译器默认NULL为整形的0，而不是指针空值
	fun6((int*)NULL); // NULL: 二义性， 指针空值，整形0
	//nullptr: 指针空值， 建议用nullptr表示指针空值，意义明确
	fun6(nullptr);
	//nullptr可以隐式转换成任意指针类型(内置和自定义)
	int* p = nullptr;
	char* p1 = nullptr;
	float* p2 = nullptr;
	AS* pas = nullptr;
	//nullptr类型： nullptr_t
	cout << typeid(nullptr).name() << endl;
	cout << sizeof(nullptr) << endl;
	auto p3 = nullptr;
	cout << typeid(p3).name() << endl;
}

//C++struct: 可以定义数据和函数
//C++定义类的方式：
// 1. struct + 类名 + {} + ";"
// 2. class + 类名 + {} + ";"

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
//C++的封装的语法体现： 类， 访问限定符
//访问权限：public, protected, private
//只限制成员在类外的访问权限，类内部不受访问限定符的限制
class Student2
{
public: //公有的成员在类外可见
	//成员函数
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
private:  //私有的成员在类外不可见
	//成员变量， 属性
	int _number;
	int _id;
protected:  // 保护的成员在类外不可见
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