//友元函数和友元类
#include <iostream>
using namespace std;
class Date
{
public:
	//友元函数尽量少用，它是一种突破封装的语法
	//友元函数： friend + 正常函数的定义/声明
	//友元函数可以访问类的私有成员
	//友元函数不是类的成员函数，它是普通的非成员函数
	//只需要在类中声明友元函数，不需要在类中定义
	//友元函数可以声明在类的任何地方，不受访问限定符的限制

	friend ostream& operator<<(ostream& outputS, Date& d);
	friend istream& operator >> (istream& inputS, Date& d);
	friend class B;
	/*Date()
	{}*/

	Date(int year = 2020, int month = 12, int day = 25)
		:_year(year)
		, _month(month)
		, _day(day)

	{
		cout << "Date(int,int,int)" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._month)
	{

		cout << "Date(const Date&)" << endl;
	}


	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		//非静态成员函数可以访问静态成员函数/变量
	}


private:
	int _year = 1;
	int _month = 1;
	int _day = 1;

};

class B
{
	//友元关系是单向了，类似于单相思
	//如果一个类是另一个类的友元类，则此类中的所有成员函数即为另一个类的友元函数
	//友元关系不能传递， 类似于朋友的朋友不一定是自己的朋友
public:
	//disPlay, fun, fun1都为Date类的的友元函数
	void disPlay(const Date& d)
	{
		cout << d._year << d._month << d._day << endl;
	}

	void fun(const Date& d)
	{
		cout << d._year << d._month << d._day << endl;
	}

	void fun1(const Date& d)
	{
		cout << d._year << d._month << d._day << endl;
	}
};

void test4()
{
	B b;
	Date d(2020, 5, 26);
	b.disPlay(d);
}