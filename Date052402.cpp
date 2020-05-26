#include <iostream>
using namespace std;
class Time
{
public:
	Time(int a = 1)
		:_a(a)
	{
		cout << "Time(int)" << endl;
	}
private:
	int _a;
};

class Date1
{
public:
	Date1(int y = 1, int m = 1, int d = 1)
		//初始化列表： : 成员(初始化值/表达式), 成员2()......
		//每一个成员变量只能在初始化列表中出现一次
		//对象的成员变量定义的地方： 初始化列表
		//如果有引用成员，const成员，没有默认构造函数的自定义成员，必须在初始化列表中进行初始化
		//其它成员可以不进行显式初始化
		//对于自定义成员，最好在初始化列表中初始化，即使不在初始化列表中显式初始化，
		//编译器也会在初始化列表中自动调用自定义成员的默认构造完成初始化
		//成员变量在初始化列表中初始化顺序:和声明顺序一致，与其在初始化列表中的顺序无关
		//注意：最好初始化列表中的成员顺序和声明顺序保持一致
		: _a(_year)
		,_year(y)
		, _month(2 * _year)
		,_day(3 * _year)
		,_b(d)
		//, _time(10)
	{
		_year = y;
		_month = m;
		_day = d;
		//给_time重新复制，并不是初始化
		_time = Time(10);
	}



private: //成员变量声明的地方
	int _year;
	int _month;
	int _day;
	int& _a;  //引用在定义时必须初始化，此处不是定义的地方
	const int _b;  //const变量在定义时必须初始化，此处不是定义的地方
	Time _time;

};

class A
{
public:
	//explicit: 禁掉单参构造的隐式类型转换
	/*explicit*/ A(int a)
		:_a(a)
	{
		cout << "A(int)" << endl;

	}
	A(int a, int b)
		:_a(a)
	{
		cout << "A(int)" << endl;

	}

	A(const A& a)
		:_a(a._a)
	{
		cout << "A(const A&)" << endl;
	}

	A& operator=(const A& a)
	{
		if (this != &a)
		{
			_a = a._a;
		}
		cout << "A& operator=(const A& a)" << endl;
		return *this;
	}

private:
	int _a;
};


void test8()
{
	Date1 d(2020, 5, 25);
}

void test9()
{
	A a(1); //创建对象
	A a2 = 2; //创建对象:单参构造函数的隐式类型转换 --> 调用构造创建一个匿名对象，+ 拷贝构造（通过匿名对象拷贝构造a2对象)
	a2 = 3;  //3作为参数传入构造函数， 创建匿名对象， 调用赋值，使用匿名对象给a2赋值
	
	//只支持单参构造函数的隐式类型转换,下面代码不支持
	//A a4 = 5, 6;
}
int main()
{
	//test8();
	test9();
	return 0;
}