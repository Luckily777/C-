//string的三种遍历方式
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void test10()
{
	string str("0123456789");

	//1. 迭代器
	string::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//2. operator[]: 可读可写接口，如果越界，非法访问
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str.operator[](i) << " ";
		str[i] = 'a';
	}
	cout << endl;
	//operator[]简写
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str[i] << " ";
	}

	//str[100] = 'c';
	cout << endl;
	//at:可读可写， 但是可读性不强, 如果越界，抛异常
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;
	//str.at(100) = 'c';
	//3. 范围for遍历: 支持读写, 如果需要修改，则接收类型为引用类型
	//   底层通过迭代器实现
	for (auto& ch : str)
	{
		cout << ch << " ";
		ch = 'X';
	}
	cout << endl;

	for (auto& ch : str)
	{
		cout << ch << " ";
		ch = 'X';
	}
	cout << endl;
}