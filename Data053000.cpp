#include <stdlib.h>
#include <iostream>
using namespace std;
void test()
{
	int array[10];  //都为随机值
	int array2[10] = { 1, 2, 3 };  //除过前三个，其它都为0
	int array3[10] = { 0 };  //所有位置都为0
}

void test1()
{
	//malloc:只进行空间申请，不进行初始化
	int* ptr = (int*)malloc(sizeof(int));
	*ptr = 4;
	//calloc: 进行空间申请 + 零初始化
	int* ptr2 = (int*)calloc(1,sizeof(int));
	//realloc:  第一个参数为nullptr/NULL, 功能等价于malloc
	int* ptr3 = (int*)realloc(nullptr, sizeof(int));
	//调整空间大小：
	// 1. 直接原地调整大小
	// 2. 重新开空间： 重新申请空间，内容拷贝，释放原有空间
	int* ptr4 = (int*)realloc(ptr, sizeof(int)* 4);
	char* ptr5 = (char*)realloc(ptr2, sizeof(char));

	free(ptr3);
	free(ptr4);
	free(ptr5);
	//传入realloc中的空间后续不需要显式释放，会导致二次释放的问题
	/*free(ptr);
	free(ptr2);*/
}

class Date
{
public:
	Date(int year = 1)
		:_year(year)
	{}
	~Date()
	{
		cout << "~Date()" << endl;
	}
private:
	int _year;

};

void test2()
{
	Date d(2020);
	Date* pd = (Date*)malloc(sizeof(Date));
	Date* pd2 = (Date*)calloc(1,sizeof(Date));
	
}

void test3()
{
	int* ptr = (int*)malloc(sizeof(int));
	int* ptr2 = (int*)malloc(sizeof(int) * 10);

	// 单个类型的空间：new + 类型
	// 连续空间：new + 类型[个数]
	// 单个类型空间申请 + 初始化： new + 类型(初始值)
	// 基本类型用new申请连续空间，不能初始化
	int* ptr3 = new int;
	int* ptr4 = new int[10];
	int* ptr5 = new int(5);  //初始化为5

	//释放空间
	//单个空间： delete 指针
	//连续空间： delete[] 指针
	//申请和释放的操作匹配使用： malloc free,  new delete,  new [] delete[]
	delete ptr3;
	delete ptr5;
	delete[] ptr4;
}

void test4()
{
	//动态创建自定义类型的对象：
	//new：动态开空间 + 调用构造函数初始化
	//申请单个空间： new 自定义类型(参数列表)
	Date* pd = new Date(2020);
	Date* pd2 = new Date(2030);
	Date* pd4 = new Date;  //调用默认构造：无参，全缺省

	//申请连续的空间:new 自定义类型[个数], 自动调用默认构造进行初始化，如果没有默认构造，编译器报错
	Date* pd3 = new Date[10];

	//释放自定义类型的空间
	//delete: 调用析构函数清理资源 + 释放空间
	delete pd;
	delete pd2;
	delete pd4;
	//连续空间： 调用N次析构 +  释放空间
	delete[] pd3;
}

void test5()
{
	//void* operator new(size_t n)： 不是运算符重载函数，而是一个全局函数
	//                            : 使用方式和malloc类似
	//                            : 封装malloc + 异常
	//new 10;
	//new的执行过程(自定义类型)：operator new --> malloc  --> 构造函数

	char* ptr = (char*) operator new(sizeof(char));
	char* ptr2 = (char*)malloc(sizeof(char));

	//void operator delete(void* ptr):不是运算符重载函数，而是一个全局函数
	//                               :使用方式和free类似
	//                               ：封装free 
	// delete执行过程(自定义类型)： 析构 --> operator delete --> free
	operator delete(ptr);
	free(ptr2);
	free(nullptr);
	operator delete(nullptr);
}

struct Node
{
public:
	Node()
	{
		cout << "Node()" << endl;
	}
	//定制节点空间的申请方式
	void* operator new (size_t n)
	{
		//内存池申请
		void* ptr = allocator<Node>().allocate(1);
		cout << "mem pool allocate" << endl;
		return ptr;
	}

	void operator delete(void* ptr)
	{
		allocator<Node>().deallocate((Node*)ptr, 1);
		cout << "mem pool deallocate" << endl;
	}

private:
	int _data;
	Node* _next;
};

void test6()
{
	Date* pd = new Date;
	Date* pd2 = new Date[10];

	Node* pn = new Node;
	Node* pn2 = new Node[10];

	delete pd;
	delete[] pd2;

	delete pn;
	delete[] pn2;
}

void test7()
{
	Date* pd = (Date*)malloc(sizeof(Date));
	//new定位表达式： new (地址) 类型(参数列表)
	//	：在已经开好的空间上显式调用构造函数
	new (pd)Date(2030);
	Date* pd2 = (Date*)malloc(sizeof(Date));
	new (pd2)Date;
}

void test8()
{
	//char* ptr = new char[0x7fffffff];
	try
	{
		char* ptr = new char[10000];

		char* ptr2 = new char[0xfffffffful];
		
		cout << "delete " << endl;
		delete[] ptr;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	
}
//
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}

//泛型编程并没有减少实际的代码量，只是把重复的代码交给机器自动生成，
//减少开发人员的重复的工作量，提高工作效率，增加幸福感
/*
template < typename / class 泛型参数1， typename / class泛型参数2，.....>
函数定义
*/
//函数模板
//函数模板实例化：用实际参数类型，生成可执行的函数
template <class T>
void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}

template <class T>
T add(T a, T b)
{
	return a + b;
}

void test9()
{
	int a = 1, b = 2;
	char c = 'a', d = 'b';
	//隐式实例化：编译器更加参数进行自动推导，产生直接可执行的代码
	Swap(a, b);
	Swap(c, d);

	Date d1(2020);
	Date d2(2030);
	Swap(d1, d2);

	//Swap<int>(a, c);
	add(a, b);

	add<int>(a, c);
	add<char>(a, c);
	add(a, (int)c);
	//显式实例化： 函数名 + <类型> +(参数列表）
	Swap<int>(a, b);
}

int main()
{
	//test();
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	test9();
	return 0;
}