//类型识别
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int func(int a)
{
	cout << a << endl;
	return a;
}

void func2()
{
	cout << "func2（）" << endl;
}

void testAuto()
{
	map<string, string> m;
	m["123"] = "456";
	m["789"] = "012";

	std::map<std::string, std::string>::iterator it = m.begin();
	//auto: 编译时根据初始化表达式进行类型推导
	// auto: 编译时类型识别
	auto it2 = m.begin();

	//decltype: 运行时类型识别
	decltype(1 + 2) a;

	decltype(func(10)) b;
	//decltype: 如果有参数列表，推导返回值类型
	cout << "b: type: " << typeid(b).name() << endl;
	//decltype: 如果没有参数列表，只有函数名，推导为函数的接口类型
	cout << typeid(decltype(func)).name() << endl;
}
