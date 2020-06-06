//类模板
#include <iostream>
#include <string>
#include <vector>
using namespace std;


template <class T1, class T2, class T3>
class Date
{
public:
	Date(T1 year, T2 month, T3 day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	void Display();
	/*{
		cout << _year << "-" << _month << "-" << _day << endl;
	}*/
private:
	T1 _year;
	T2 _month;
	T3 _day;
};
//如果在类外定义类模板的成员函数，需要加上泛型的声明
//作用域为 "类名<泛型参数>"
template <class T1, class T2, class T3>
void Date<T1, T2, T3>::Display()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

void test2()
{
	//类模板不行进行隐式实例化
	//Date d;
	//类模板
	//类型和类名不同
	//类型：类名<模板实际参数类型>
	Date<int, int, int> d(2020, 5, 31);
	d.Display();
}


void printString(const string& str)
{
	string::const_iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << " ";
		//*it = 'a';
		++it;
	}
	cout << endl;
}