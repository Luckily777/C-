//1. 对引用和正常传参的效率比较

#include <time.h>
#include <iostream>
#include <string.h>
using namespace std;

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


// 引用其实和指针相差无几
void test3()
{
	int a = 10;
	int* pa = &a;
	*pa = 20;

	int& ra = a;
	ra = 30;
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