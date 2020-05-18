#include <stdio.h>
#include <iostream>
using namespace std;


//输入输出
void test() {
	int a = 10;
	int b;
	printf("%d\n", a);//标准化的c输出
	scanf("%d", &b);//标准化的c输入

	//C++输入输出
	//不需要显示指定输入输出变量的格式，支持连续的输出
	std::cout << a << "\n" << std::endl;
	std::cin >> b >> a;//c++的输入
	cout << a << "\n" << endl;
	cin >> b >> a;
}

void testSting() {
	char* p = "1234";
	int* pa = &p;
	cout << pa << endl;//非字符串指针输出地址
	cout << p << endl;//字符串指针输出内容
}