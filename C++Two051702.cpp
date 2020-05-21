//2.内联函数
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
#include "sub.h"
//inline内联函数：编译编译时，会将函数指令的展开，没有栈帧的开销，更好的提高了代码的效率
//能够代替宏函数的使用


#define ADD(a, b)  a + b
#define MUL(a, b)  a * b

inline int Add(int a, int b)
{
	return a + b;
}

//inline只是一个建议，编译器回根据实际情况来进行判断，如果代码简单则直接展开，代码负责不会展开会按照函数运行
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