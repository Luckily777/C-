#include <iostream>
using namespace std;

int main() {
	//int a = 10;
	//int& ra1 = a;
	//int& ra2 = a;
	//ra2 = 30;
	//ra1 = 100;
	//a = 100;
	//cout << &a << endl;
	//cout << &ra1 << endl;
	//cout << &ra2 << endl;
	//如果引用定义必须初始化
	//也就是不能够出现 int& ra3;
	//int b = -1;
	//ra1 = b;//赋值 引用定义之后，不会再去更改实体的指向
	//ra1 = -100;
	const int a = 10;
	const int& r = 10;
	const int& ra = a;
	//a = 20;
	//r = a;
	double d = 2.0;
	int c = d;
	const int& rd = d;
	//rd = 10;
	return 0;
}


void test()
{
	String s("01234");
	printString(s);
	s.resize(3, 'a');
	printString(s);
	s.resize(6, 'a');
	printString(s);
}

void test2()
{
	String s("0123456789");
	printString(s);
	s.erase(3, 4);// 012789
	printString(s);
	s.erase(4, 2); // 0127
	printString(s);
	s.erase(2, 100);  //01
	printString(s);
}

void test3()
{
	String s("0123456789");
	size_t pos = s.find("789");
	pos = s.find("0123489");
	if (pos == String::npos)
	{
		cout << "not find" << endl;
	}
}

void test4()
{
	String s("0123");
	cout << s << endl;
	s.resize(10);
	cout << s << "结束" << endl;

	string s1("0123");
	cout << s1 << endl;
	s1.resize(10);
	cout << s1 << "结束" << endl;
}

void test5()
{
	String s("0123");
	String s2("456");
	String s3 = s + s2;
	String s4 = s + "789";
	String s5 = s + 'a';
}

//int main()
//{
//	//test();
//	//test2();
//	//test3();
//	//test4();
//	test5();
//	return 0;
//}