// 内存申请
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
	int* ptr2 = (int*)calloc(1, sizeof(int));
	//realloc:  第一个参数为nullptr/NULL, 功能等价于malloc
	int* ptr3 = (int*)realloc(nullptr, sizeof(int));
	//调整空间大小：
	// 1. 直接原地调整大小
	// 2. 重新开空间： 重新申请空间，内容拷贝，释放原有空间
	int* ptr4 = (int*)realloc(ptr, sizeof(int) * 4);
	char* ptr5 = (char*)realloc(ptr2, sizeof(char));

	free(ptr3);
	free(ptr4);
	free(ptr5);
	//传入realloc中的空间后续不需要显式释放，会导致二次释放的问题
	/*free(ptr);
	free(ptr2);*/
}

void test2()
{
	Date d(2020);
	Date* pd = (Date*)malloc(sizeof(Date));
	Date* pd2 = (Date*)calloc(1, sizeof(Date));

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