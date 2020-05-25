//析构函数
#include <string.h>
#include <iostream>
using namespace std;

class A {
public:
	~A()
	{
		cout << "~A()" << endl;
	}
	int _a;
};

class Date {
public:
	//构造函数
	Date(int y = 1, int m = 1, int d = 1) {
		_year = y;
		_month = m;
		_day = d;
	}

	//析构函数：清理资源，不是销毁对象，在对象生命周期结束时，编译器自动调用
	//如果没有资源需要清理，可以不用显式写析构函数，直接使用编译器默认生成的析构函数

	~Date(){
		//自动调用自定义类型的析构函数，完成自定义类型成员的资源清理工作
		cout << "~Date()" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	//A _a;//a可能指向带有资源的空间
};
