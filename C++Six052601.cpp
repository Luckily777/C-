//C++11的初始化方式：相当于给一个缺省值
#include <iostream>
using namespace std;

class Date
{
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


	//最后一个候选，前面如果有就先使用前面的
	//如果有缺省的构造函数，那么就使用缺省构造函数的数据
private:
	int _year = 1;
	int _month = 1;
	int _day = 1;
};
