// 范围for + NULL的值
// for：要迭代的变量：迭代的范围
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std

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


void test7(int array[])
{
	//array变成一个指针类型，没有确定的数据范围，所以不能够使用范围for
	for (auto e : array)
		cout << e << " ";
	cout << endl;
}





//NULL即是0
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