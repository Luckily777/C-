//静态成员的练习
#include <iostream>
using namespace std;

//int cnt = 0;  //定义全局变量的话，安全性较低，容易篡改

class Date
{
public:
	Date(int year = 2020, int month = 12, int day = 20)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		++cnt;
		cout << "Date(int ,int ,int)" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		++cnt;
		cout << "Date(const Date&)" << endl;
	}


	//静态成员函数：函数内部没有this指针
	static int getCount()
	{
		//静态成员函数不能访问非静态成员函数/变量——>因为非静态成员需要this指针，但是静态成员函数内部缺少this指针，所以不能访问
		return 1;
	}


	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		//非静态成员函数可以访问静态成员函数/变量
		getCount();
		cout << cnt << endl;
	}
private:
	int _year = 1;
	int _month = 1;
	int _day = 1;

	//静态成员变量，所有对象共享此成员变量，可以看成类成员
	//静态成员变量不能再生命的时候给默认
	//静态成员不在对象模型中，一般存放在数据段，不能在初始化列表中初始化

public:
	static int cnt;
};

//静态成员必须在类外初始化
int Date::cnt = 0;


Date fun(Date d) //拷贝构造
{
	cout << &d.cnt << endl;
	return d;
}

void Test()
{
	Date d;//构造
	Date d2 = fun(d);//拷贝函数 fun：进行优化，只有两次拷贝构造，传参创建d2

	//静态成员变量/静态成员函数访问方式：
	// 1. 对象访问
	cout << d.getCount() << endl;
	cout << d2.getCount() << endl;
	cout << &d.cnt << endl;
	cout << &d2.cnt << endl;
	// 2. 类名 + 作用域限定符
	cout << &Date::cnt << endl;
	cout << Date::cnt << endl;
	cout << Date::getCount() << endl;
	//普通成员只能通过对象访问，不能通过类名访问
	d.Display();
	//Date::Display(); //不支持
}

int main() {
	Test();
}