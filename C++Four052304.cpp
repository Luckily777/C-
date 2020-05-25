//赋值运算符重载
#include <iostream>
using namespace std;

class Date
{
public:
	Date(int y = 1, int m = 1, int d = 1)
	{
		_year = y;
		_month = m;
		_day = d;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(const Date& d)" << endl;
	}

	//赋值运算符重载函数： d=d2——修改已经存在的对象的内容，不是去创建新的对象
	//如果不写，编译器也会默认生成，默认生成的也是字节拷贝，即浅拷贝
	//如果当前类中有资源的话，则必须显式定义赋值运算符重载函数，完成深拷贝

	Date& operator=(const Date& d2)
	{
		//判断是否给自己赋值
		if (this != &d2)
		{
			_year = d2._year;
			_month = d2._month;
			_day = d2._day;
		}

		cout << "operator=(const Date& d2)" << endl;
		//返回当前调用此函数的对象本身
		return *this;
	}

	//private:
	int _year;
	int _month;
	int _day;
};


void Test() {
	Date d(2020, 5, 22);
	Date d2(2019, 1, 1);

	//如果对象都存在，调用赋值运算符重载函数，如果左边对象不存在，则调用拷贝构造
	d2 = d;
	d2.operator==(d);// 同上等价
	d2 = d2;
	Date d3(2018, 10, 1);

	//连续赋值：从右向左赋值
	d = d2 = decltype;
	d.operator=(d2.operator=(d3));//同上面等价
	Date d4 = d3;//因为d4不存在，则调用拷贝构造，用d3创建d4对象
}
