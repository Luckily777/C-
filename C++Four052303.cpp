//运算符重载
#include <iostream>
using namespace std;

//运算符重载函数，增强代码的可读性
//函数名特殊：定义和使用方式和普通函数一样
//返回值 operator +需要重载的运算符（参数列表）{}
//运算符重载函数如果是成员函数，则参数的个数比运算符需要的个数少一个，这里编译器会传如this指针作为第一个参数
//this指针始终站着运算符操作数的第一个位置


class Date {
public:
	//构造函数
	Date(int y = 1, int m = 1, int d = 1) {
		_year = y;
		_month = m;
		_day = d;
	}
	//拷贝构造
	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(const Date& d)" << endl;
	}


	bool IsEqual(const Date& d) {
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	
	bool operator==(const Date& d) {//底层接口 bool operator==(Date* const this, const Date& d)
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
private:
	int _year;
	int _month;
	int _day;
	//A _a;//a可能指向带有资源的空间
};

//普通的运算符重载函数
bool operator==(const Date& d1, const Date& d2) {
	return d1._year == d2._year
		&& d1._month == d2._month
		&& d1._day == d2._day;
}

//输出运算符重载函数
ostream& operator<<(ostream& _cout, const Date& date) {
	_cout << date._year << " " << date._month << " " << date._day << endl;
	return _cout;
}


void Test() {
	//创建
	Date d(2020, 1, 1);
	Date d2(d);//拷贝构造

	Date d3(2020, 5, 23);

	cout << d.IsEqual(d2) << endl;
	cout << d.IsEqual(d3) << endl;

	cout << (d == d2) << endl;//等价于的d.operator==(d2);
	cout << d.operator==(d2) << endl;
	cout << (d == d3) << endl;//等价于的d.operator==(d3);
	cout << d.operator==(d3) << endl;
	//cout<<d<<endl;
}

