//auto自动类型推导
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

//auto：C++中的作用，自动进行类型推导，不代表具体类型
//编译时，会根据初始化的表达式进行自动推导
//auto相当于类型的占位符，具体类型在编译时进行推导
void test5()
{
	//auto int a = 0;  //C++不支持
	auto b = 2;
	auto f = 3.0;
	auto c = 'a';
	auto d = 'a' + 'b';
	cout << typeid(b).name() << endl;//整型
	cout << typeid(f).name() << endl;//浮点型
	cout << typeid(c).name() << endl;//字符型
	cout << typeid(d).name() << endl;//整型也可能是字符型

	//auto定义的变量必须初始化 
	auto e; //这是错误的
	
			
			//auto可以定义多个变量
	auto a1 = 3, c1 = 4;
	
	
	//auto在定义多个变量时，每一个的表达式的类型要一致
	//auto a2 = 1.5, c2 = 2;
	
	
	//auto对于长类型变量的定义，比较简单
	//std::unordered_map<std::string, std::unordered_map<std::string, std::string>>::iterator it;
	
	
	//auto定义指针， 加不加*,没有区别
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