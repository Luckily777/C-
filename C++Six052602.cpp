//输出输入流
//返回输出流是为了支持连续赋值
#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& outputS, Date& d);
	friend istream& operator >> (istream& inputS, Date& d);

	Date(int year = 2020, int month = 12, int day = 20)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int ,int ,int)" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date&)" << endl;
	}

	//这种输出不能够进行连续赋值操作
	//void operator<<(ostream& _cout)  // void operator<<(this, ostream& _cout)
	//{
	//	_cout << _year << "-" << _month << "-" << _day << endl;
	//}
private:
	int _year = 1;
	int _month = 1;
	int _day = 1;

};



ostream& operator<<(ostream& outputS, Date& d)
{
	outputS << d._year << "-" << d._month << "-" << d._day << endl;
	return outputS;
}

istream& operator >> (istream& inputS, Date& d)
{
	inputS >> d._year >> d._month >> d._day;
	return inputS;
}

void test3()
{
	Date d(2020, 5, 26);
	Date d2(2020, 10, 26);
	//从左向右输出
	cout << d << d2;
	operator<<(operator<<(cout, d), d2);
	//d << cout;
	//从左向右输入
	cin >> d >> d2;// 等价于 operator>>(operator>>(cin, d), d2);
	cout << d << d2;
}

int main() {
	Date d;
	cnt += 100;
	//若不进行输出流，则会构成
	//d << cout; 不符合常理


	cout << cnt << endl;
}