#include <stdio.h>
#include <iostream>
using namespace std;
namespace bite
{
	void print(int a)
	{
		printf("%d \n", a);
	}

	int a;
	int b;
	//嵌套定义
	namespace bite_69
	{
		void fun1(int a)
		{
			printf("%d \n", a);
		}
			int a;
			int b;
		
	}
}

//可以分段定义，编译器会合并相同的命名空间，
//相同的命名空间不能定义重复的变量和函数
namespace bite
{
	int c;
	int d;
	void fun2()
	{
		printf("fun2()\n");
	}
	void fun3()
	{
		printf("fun3()\n");
	}
}

void fun2()
{
	printf("fun2()\n");
}

void fun1(int a)
{
	printf("%d \n", a);
}

void print(int a)
{
	printf("%d \n", a);
}

int a;
int b;

//命名空间成员使用方式
// 1. 命名空间 + :: + 成员 --> 推荐使用这种方式
// 2. 引入成员 using + 命名空间 + :: + 成员： 后面使用成员时，不需要加作用域, 注意：成员暴露在全局域中，如果全局域中有同名成员，会导致命名冲突
// 3. 展开命名空间 using + 命名空间 ： 命名空间中所有的成员暴露在全局域中
//using bite::fun3;
//using bite::a;
//using namespace bite;
void test()
{
	bite::a = 1;
	bite::print(bite::a); //bite命名空间下的成员a
	bite::print(a); //全局a
	bite::bite_69::a = 2;
	bite::c = 3;
	bite::fun2();
	bite::fun3();
	bite::fun3();
	//fun2();
	//print(a);

}


void fun4(int a)
{
	a = 10;  //局部域
	bite::a = 20; //命名空间域
	bite::bite_69::a = 30;  //命名空间域
	::a = 40; //全局作用域


}

void test2()
{
	int a = 10;
	int b;
	printf("%d\n", a);
	//scanf("%d", &b);
	//C++输入输出：头文件<iostream> + std命名空间
	// 不需要显示指定输入输出变量的格式，支持连续的输入输出
	std::cout << a << "\n" << std::endl;
	//std::cin >> b >> a;
	char* p = "1234";
	//*p = '9';
	int* pa = &a;
	std::cout << pa << std::endl; //非字符串指针输出地址
	std::cout << p << std::endl;  //字符串指针输出内容
}

//缺省参数：给参数定义一个默认值， 实际使用时，如果没有传参，对应的形参使用默认值
//全缺省
void fun5(int a = 1, int b = 2, int c = 3)
{
	std::cout << a << b << c << std::endl;
}

//半缺省: 部分参数有缺省值
void fun6(int a, int b = 1, int c = 2)
{
	std::cout << a << b << c << std::endl;
}
//半缺省参数： 必须从右向左一次连续赋值，中间不能有间隔
//void fun7(int a = 1, int b = 2, int c);
//void fun7(int a = 1, int b, int c = 2);
//缺省值只能出现在声明或者定义的地方，不能同时出现
//声明
void fun8(int a, int b, int c);
//定义
void fun8(int a = 100, int b = 200, int c = 300)
{
	std::cout << a << b << c << std::endl;
}

//函数重载： 函数名相同，参数不同， 且在同一个作用域， C++支持，C不支持
//参数不同： 类型， 个数，顺序不同
//仅仅是返回值不同，不能构成函数重载
int Add(int a = 1, int b = 2)
{
	return a + b;
}


float Add(float a, float b)
{
	return a + b;
}

int Add(int a, int b, int c)
{
	return a + b + c;
}

int Add(char a, int b)
{
	return a + b;
}

int Add(int a, char b)
{
	return a + b;
}
/*
void Add(int a, char b)
{
	int c = a + b;
}
*/
//extern "C" 让编译器按照C语言的编译规则进行编译
extern "C" {
	int sub(int a, int b); 
	int mul(int a, int b);
}
void test4()
{
	int a = 1;
	int b = 2;
	float c = 1.5;
	float d = 2.5;
	char f = 'a';
	int e = 3;
	Add(a, b);
	Add(c, d);
	Add(a, b, e);
	Add(a, f);
	Add(f, a);
}

//void test5()
//{
//	sub(4, 2);
//	mul(4, 2);
//}

void test6()
{
	//引用：类型 + & + 引用名称 
	int a = 10;
	//a的别名
	int& ra = a;
	int& ra2 = a;
	ra2 = 30;
	ra = 100;
	a = 1000;
	cout << &a << endl;
	cout << &ra << endl;
	cout << &ra2 << endl;
	//引用定义时必须初始化
	//int& ra3;
	int b = -1;
	ra = b; //赋值, 引用定义之后，不会再去更改实体的指向
	ra = -100;
}

void test7()
{
	//const引用
	const int a = 10;
	const int& ra = a;
	const int& r = 10;
	double d = 2.0;
	double& rd = d;
	int c = d;
	//d隐式类型转换，生成一个临时的整形变量，rd2指向的为此临时变量，临时变量具有常性
	const int& rd2 = d;
}

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Swap(int& ra, int& rb)
{
	int tmp = ra;
	ra = rb;
	rb = tmp;
}

//不能完成交换
/*
void Swap(int ra, int rb)
{
	int tmp = ra;
	ra = rb;
	rb = tmp;
}
*/
void test8()
{
	int a = 1;
	int b = 2;
	Swap(&a, &b);
	Swap(a, b);
}

int& Add10(int& a)
{
	return ++a;
}
//引用做返回值： 注意返回变量的生命周期一定要大于函数的生命周期
int& Add20(int a)
{
	return ++a;
}

void test9()
{
	int a = 0;
	int& b = Add10(a);
	int c = Add10(a);
	int& d = Add20(a);  //3
	cout << d << endl;
	cout << a << endl;
	cout << d << endl;
	
}


int main()
{
	//test();
	//test2();
	//fun5(1, 2, 3);
	//fun5();
	//fun5(100, 200, 300); 
	////参数接收值的顺序： 从左向右
	//fun6(5);
	//fun6(5, 6);
	//fun6(7, 8, 9);
	//fun8();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	test9();
	return 0;
}

