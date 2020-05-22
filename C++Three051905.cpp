//构造函数
#include <iostream>
using namespace std;


class AA {
	//6个成员函数
public:
	AA() {

	}
	AA(int a) {

	}
};

class Data {
public:

	//构造函数： 函数名和类名相同， 无返回值， 可以重载，编译器在创建是自动调用
	//只有当类没有定义任何构造函数时，编译器才会自动生成一个无参构造， 如果类中已经定义了构造函数
	//编译器不会再自动生成，即使类中没有显式定义无参构造

	//默认构造：只能存在一个
	// 1. 编译器默认生成
	// 2. 显示定义的无参构造
	// 3. 全缺省构造函数
	/*Date()
	{

	}*/
	//全缺省默认构造
	Date(int y = 2020, int m = 5, int d = 20)
	{
		_year = y;
		_month = m;
		_day = d;
	}
	//重载的构造函数
	Date(float f)
	{

	}

	void Display()
	{
		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
		//this = nullptr;
		this->_year = 2022;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void fun1()
	{
		cout << "Date::fun1()" << endl;
	}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
	//如果类中存在自定义成员， 则构造函数会自动调用自定义成员的默认构造，完成自定义成员的初始化，
	//如果自定义成员没有默认构造函数，则会产生编译错误
	AA _aa;
};


void test6()
{
	Date d;
	d.SetDate(2020, 5, 15);
	d.Display();

	Date d2(2020, 5, 20);
	d2.Display();

	Date d3();//声明一个函数，不会调用无参构造

	//Date d4(2020);

	Date d5(2.0f);

	AA a1;
	AA a2(3);

	int i = 3;
}

int main()
{
	test6();
	return 0;
}



