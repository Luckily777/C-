#include <iostream>
using namespace std;
class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		//判断日期是否合法
		if (year > 0 && month > 0 && month < 13
			&& day > 0 && day <= getMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "日期不合法： " << year << "-" << month << "-" << day << endl;
			cout << "重置为默认值： 2000-1-1" << endl;
			_year = 2000;
			_month = 1;
			_day = 1;
		}
		
	}

	int getMonthDay(int year, int month)
	{
		static int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		//如果是2月且为闰年，+1
		if (month == 2
			&& (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
			++day;
		return day;
	}
	// a += b
	Date& operator+=(int day)
	{
		// a += -b  --> a -= b
		if (day < 0)
			return *this -= -day;

		//2020.5.1  + 20  --> 2020.5.21
		//2020.5.21 + 20 --> 2020.5.41 --> 进位 --> -31 -->月份进位 --> 2020.6.10
		//2020.12.6 + 90 --> 2020.12.96 --> 进位 --> -31 -->月份进位 --> 2020.13.65 -->年进位
		// --> 2021.1.65--> --> 进位 --> -31 -->月份进位 --> 2021.2.34 --> --> 进位 --> -28 -->月份进位 --> 2021.3.6
		_day += day;
		//判断日期是否溢出,溢出需要进位
		while (_day > getMonthDay(_year, _month))
		{
			//减去当月的天数，月份进位
			_day -= getMonthDay(_year, _month);
			++_month;
			//判断月份是否溢出
			if (_month == 13)
			{
				//进位到下一年的1月
				_month = 1;
				_year++;
			}
		}
		return *this;
	}

	//前置++: ++d: 首先++，返回++之后的值
	Date& operator++()
	{
		return *this += 1;
		//return (*this).operator+=(1);
		//return *this;
	}

	//后置++: d++: 本身++， 返回++之前的值
	//前置++， 后置++都为单目运算符
	//如果为成员函数，则本质上不需要显式传参，编译器会自动传入this指针
	//int： 形参不是一个真正的参数，只是一个标记参数，编译器看到这样的定义，通过语法树搜索，可以解释为后置++
	Date operator++(int)
	{
		//保存++之前的值
		Date ret(*this);
		//++
		*this += 1;
		//返回++之前的值
		return ret;		
	}

	Date& operator-=(int day)
	{
		if (day < 0)
			return *this += -day;
		_day -= day;
		//判断_day是否为负值或者0, 退位
		//2020.5.24 - 30 --> 2020.5.-6 --> 月份退位 --> +30 --> 2020.4.24
		while(_day <= 0)
		{
			//月份退位
			--_month;
			//月份是否为负值或者0
			if (_month == 0)
			{
				_month = 12;
				//年份退位
				--_year;
			}
			_day += getMonthDay(_year, _month);
		}
		return *this;
	}

	Date& operator--()
	{
		return *this -= 1;
	}

	Date operator--(int)
	{
		Date ret = *this;
		//Date ret(*this);
		*this -= 1;
		return ret;
	}
	// +, -运算符：不能修改操作数的内容
	// c = a + b
	Date operator+(int day)
	{
		Date ret = *this;
		ret += day;
		return ret;
	}

	Date operator-(int day)
	{
		Date ret = *this;
		ret -= day;
		return ret;
	}

	bool operator==(const Date& date)
	{
		return _year == date._year
			&& _month == date._month
			&&_day == date._day;
	}

	bool operator>(const Date& date)
	{
		if (_year > date._year)
			return true;
		else if (_year == date._year)
		{
			if (_month > date._month)
				return true;
			else if (_month == date._month)
			{
				if (_day > date._day)
					return true;
			}
		}
		return false;
	}

	bool operator>=(const Date& date)
	{
		return (*this > date) || (*this == date);
	}

	bool operator<(const Date& date)
	{
		return !(*this >= date);
	}

	bool operator<=(const Date& date)
	{
		return !(*this > date);
	}

	bool operator!=(const Date& date)
	{
		return !(*this == date);
	}


	void printD()  // 等价于 printD(Date* const this)
	{
		cout << _year << " " << _month << " " << _day << endl;
		//可以修改内容
		//this->_year = 100;
		//可以调用const成员函数
		fun();
	}
	//const成员函数中的const修饰的为第一个参数，即this指针
	//const成员函数内部补能修改成员变量的值
	void printD() const  //等价于 printD(const Date* const this)
	{
		cout << _year << " " << _month << " " << _day << endl;
		//不能修改内容
		//this->_year = 100;
		//补能调用非const成员函数，读写的权限不能被放大
		//++*this;

	}

	void fun()const
	{

	}

	int operator-(Date& date)
	{
		Date d1(*this);
		Date d2(date);
		//d1 - d2
		int num = 0;
		if (d1 > d2)
		{
			while (d1 > d2)
			{
				--d1;
				++num;
			}
			return num;
		}
		else
		{
			//d1 <= d2
			while (d1 < d2)
			{
				++d1;
				++num;
			}
			return -num;
		}
	}

	/*Date operator-(Date& date)
	{

	}*/

	//取地址运算符重载函数: operator&
	//一般不需要显示定义，直接用默认即可
	Date* operator&()
	{
		//return (Date*) 0x1234;
		return this;
	}

	const Date* operator&() const
	{
		//return nullptr;
		return this;
	}

//private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout, const Date& date)
{
	_cout << date._year << " " << date._month << " " << date._day << endl;
	return _cout;
}


void test()
{
	Date d(2020, 5, 1);
	d.printD();
	d += 20;
	d.printD();
	d += 20;
	Date d2(2020, 12, 6);
	d2.printD();
	d2 += 90;
	d2.printD();
	d2 += 3650;
	d2.printD();
	++d2;
	//前置++
	d2.operator++();
	d2.printD();
	//后置++
	d2.operator++(0);
	d2.printD();
	d2++;
	d2.printD(); //等价d2.operator++(0);
}

void test2()
{
	Date d(2020, 5, 23);
	d.printD();
	cout << "前置++" << endl;
	cout << (++d) << endl;
	d.printD();
	cout << "后置++" << endl;
	cout << (d++) << endl;
	d.printD();
}

void test3()
{
	Date d(2020, 5, 24);
	d.printD();
	d -= 30;
	d.printD();
	d -= -30;
	d.printD();
	d -= 3650;
	d.printD();
	d += -3650;
	d.printD();
}

void test4()
{
	Date d1(2020, 5, 25);
	Date d2(2020, 5, 25);
	Date d3(2020, 5, 26);
	Date d4(2020, 5, 23);
	cout << (d1 > d4) << endl;
	cout << (d1 > d4) << endl;
	cout << (d1 < d4) << endl;
	cout << (d1 <= d4) << endl;
	cout << (d3 > d1) << endl;
	cout << (d1 >= d1) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
}

void test5()
{
	Date d1(2020, 5, 25);
	Date d2 = d1 + 3650;
	cout << (d1 - d2) << endl;
	cout << (d2 - d1) << endl;
	Date d3 = d2 + 189;
	cout << (d2 - d3) << endl;
	cout << (d3 - d2) << endl;
	
}


void test6()
{
	Date d1(2020, 5, 25);
	const Date d2(d1);
	d1.printD(); //非const对象(即可读可写)调用非const成员函数， 也可以调用const成员函数， 原因：读写权限没有被放大
	d2.printD(); //const对象(只读)调用const成员函数, 不能调用非const成员函数的，原因：读写权限不能被放大
}

void test7()
{
	Date d1;
	const Date d2;
	Date* pd1 = &d1;   // 等价于 d1.operator&();
	const Date* pd2 = &d2;  //等价于 d2.operator&() const;
}

//int main()
//{
//	//test();
//	//test2();
//	//test3();
//
//	//test4();
//	//test5();
//	//test6();
//	test7();
//	return 0;
//}